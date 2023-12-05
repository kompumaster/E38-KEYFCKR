# coding:utf-8

##  GM AcDelco E38 ECU KeyFCKR
##               by Flash/Tune
##
## Power control - LLine (pin15)
## Use PowerBox or similar devce
##
## PS. Use x32 Python (3.12)
## PPS.Code written by my monkey
##       danсing on the keyboard
##       t.me/obd2help

import configparser
import datetime
import os
import sys
import time
from ctypes import *

import J2534
from J2534.Define import *

## -------------------------------------- Default Settings ------------------------------------- ##

devIndex = 999  # index of default J2534 interface
defaultKeyAlgo = 0x92  # Default algo for E38 ECU (proto gmlan)
showErr = False  # Show debug info
powerPause = 0.5  # pause between power off and on
seedPause = 0.5  # pause between askSeed commands
phase = 0  # 0 = default key, 1 = 256 standard algos, 2 = bruteforce
runForward = False  # Key from 0000 to FFFF, or backward
swapByte = True  # Swap high and low Key Byte

cfg = configparser.ConfigParser()

if runForward:  # Forward order
    ikeyLast = 0
    ikBeg = 0
    ikEnd = 0xFFFF
    ikEnc = 1
    phase = 0
else:  # Reverse order
    ikeyLast = 0xFFFF
    ikBeg = 0xFFFF
    ikEnd = 0
    ikEnc = -1
    phase = 0

algoLast = 0
bkeyLast = 0

cfg['DEFAULT'] = {'ikeyLast': str(ikBeg),
                  'ikBeg': str(ikBeg),
                  'ikEnd': str(ikEnd),
                  'ikEnc': str(ikEnc),
                  'swapByte': str(swapByte),
                  'algoLast': str(algoLast),
                  'bkeyLast': str(bkeyLast),
                  'phase': str(0)}


def dtn():
    return str(datetime.datetime.now())[:-4]


logfile = 'logs\\' + dtn().replace(':', '_')[:-3] + ' E38-KEYFCKR.log'


class Logger(object):
    def __init__(self, filename=logfile):
        self.terminal = sys.stdout
        self.log = open(filename, "a", encoding="utf-8")

    def write(self, message):
        self.terminal.write(message)
        self.log.write(message)
        self.terminal.flush()
        self.log.flush()

    def flush(self):
        self.terminal.flush()
        self.log.flush()


sys.stdout = Logger()

J2534.SetErrorLog(showErr)
ProtoISO = ProtocolID.ISO15765
ProtoCAN = ProtocolID.CAN

so_file = os.path.dirname(__file__) + "\\gm-seed-key-so\\gm-seed-key.so"  # connect GM algo's Key gen
so = CDLL(so_file)


## ------------------------------------------- SUBs -------------------------------------------- ##


def clrbCAN():  # clear CAN buffer
    J2534.ClearRxBuf(chCAN)
    J2534.ClearTxBuf(chCAN)


def clrbISO():  # clear ISO buffer
    J2534.ClearRxBuf(chISO)
    J2534.ClearTxBuf(chISO)


def bytes(num):  # Split "word" to high and low byte
    return num >> 8, num & 0xFF


def mirrorByte(num):  # "mirror" byte order (12 -> 21)
    mHexStr = addZ(hex(num)[2:], 2)
    return int(mHexStr[1] + mHexStr[0], 16)


def addZ(s, n):  # add "0" x n in begining of hex value
    while len(s) < n:
        s = '0' + s
    return s.upper()


def strMsg(msg, msgLen):  # message to Hex
    s = ''
    for x in range(msgLen):
        hexbyte = hex(msg[x])[2:]
        s = s + addZ(hexbyte, 2) + ' '
    return s.upper()


def sendISO(msgTxData, msgNum):  # Send message via ISO
    msgTx = J2534.ptTxMsg(ProtoISO, 0x00000040)
    msgTx.setIDandData(0x07E0, msgTxData)
    J2534.ptWtiteMsgs(chISO, msgTx, 1, 600)
    if showErr:
        print(dtn(), '>>', strMsg(msgTx.Data, msgTx.DataSize))
    msgRx = J2534.ptRxMsg()
    for i in range(msgNum):
        J2534.ptReadMsgs(chISO, msgRx, 1, 600)
    if showErr:
        print(dtn(), '<<', strMsg(msgRx.Data, msgRx.DataSize))
    return msgRx


def sendCAN(msgTxData):  # Send message via CAN
    msgTx = J2534.ptTxMsg(ProtoCAN, 0x00000000)
    msgTx.setIDandData(0x07E0, msgTxData)
    J2534.ptWtiteMsgs(chCAN, msgTx, 1, 600)
    if showErr:
        print(dtn(), '>>', strMsg(msgTx.Data, msgTx.DataSize))
    msgRx = J2534.ptRxMsg()
    J2534.ptReadMsgs(chCAN, msgRx, 1, 600)
    if showErr:
        print(dtn(), '<<', strMsg(msgRx.Data, msgRx.DataSize))
    return msgRx


def startDiag():  # start diagnostic session
    msgRx = sendCAN([0x02, 0x10, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00])
    if msgRx.Data[4] == 0x01 and msgRx.Data[5] == 0x50:
        return True
    else:
        return False


def disableComm():  # disable normal communication
    msgRx = sendCAN([0x01, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
    if msgRx.Data[4] == 0x01 and msgRx.Data[5] == 0x68:
        return True
    else:
        return False


def askSeed():  # Asking the Seed

    print(dtn(), 'Start diag ', end='')
    while not startDiag():  # Wait for start diagnostic
        time.sleep(seedPause)
        print('.', end='')
    print('')

    print(dtn(), 'Disable comm. ', end='')
    while not disableComm():  # wait for disable communication
        time.sleep(seedPause)
        print('.', end='')
    print('')

    print(dtn(), 'ASK SEED ', end='')

    aseed = 0
    while aseed == 0:
        msgRx = sendCAN([0x02, 0x27, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00])

        # 00 00 07 e8 04 [67 01] XX XX - Seed
        if msgRx.Data[5] == 0x67 and msgRx.Data[6] == 0x01:
            aseed = msgRx.Data[7] * 256 + msgRx.Data[8]
            print(' = ' + addZ(hex(aseed)[2:], 4))
            return aseed

        # 00 00 07 e8 01 60 aa aa aa aa aa aa - ????

        # 00 00 07 e8 03 [7f 27 37] - Time Delay not Expired
        if msgRx.Data[5] == 0x7F and msgRx.Data[6] == 0x27 and msgRx.Data[7] == 0x37:
            clrbCAN()
            time.sleep(seedPause)
            print('.', end='')
        else:
            clrbCAN()
            print(',', end='')


def tryKey(highK, lowK):
    keyAnswer = False

    while not keyAnswer:
        msgRx = sendCAN([0x04, 0x27, 0x02, highK, lowK, 0x00, 0x00, 0x00])

        # 00 00 07 e8 02 [67 02] - Key accepted
        if msgRx.Data[5] == 0x67 and msgRx.Data[6] == 0x02:
            os.system('color A')
            print(' CORRECT (!!!!!!)')
            print(dtn(), '<< ' + strMsg(msgRx.Data, msgRx.DataSize))
            keyAnswer = True
            return True

        # 00 00 07 e8 03 [7f 27 35] - Invalid Key
        if msgRx.Data[5] == 0x7F and msgRx.Data[6] == 0x27 and msgRx.Data[7] == 0x35:
            print(' WRONG')
            keyAnswer = True
            return False

        # 00 00 07 e8 03 [7f 27 37] - Time Delay not Expired
        # 00 00 07 e8 03 [7f 27 22] - ?

        print('.', end='')
        clrbCAN()
        time.sleep(seedPause)
        if showErr:
            print(dtn(), '<<', strMsg(msgRx.Data, msgRx.DataSize))


def printECUid(name, msg):  # convert ECU id message to int value
    s = ''
    id = 0
    for i in range(6, msg.DataSize):
        if msg.Data[6] > 0: s = s + hex(msg.Data[i])[2:]
    if len(s) > 0:
        id = int(s, 16)
        print(dtn(), name, id)
    return id


def printECUidStr(name, msg):  # convert ECU id message to string value
    s = ''
    for i in range(6, msg.DataSize):
        if msg.Data[i] > 0: s = s + chr(msg.Data[i]).upper()
    if len(s) > 0: print(dtn(), name, s)
    return s


def saveCfg():  # oh yea, save config
    cfg.set('DEFAULT', 'ikeyLast', str(ikeyLast))
    cfg.set('DEFAULT', 'ikBeg', str(ikBeg))
    cfg.set('DEFAULT', 'ikEnd', str(ikEnd))
    cfg.set('DEFAULT', 'ikEnc', str(ikEnc))
    cfg.set('DEFAULT', 'swapByte', str(swapByte))
    cfg.set('DEFAULT', 'algoLast', str(algoLast))
    cfg.set('DEFAULT', 'bkeyLast', str(bkeyLast))
    cfg.set('DEFAULT', 'phase', str(phase))
    with open('history\\' + VIN + '.last.ini', 'w') as config_file:
        cfg.write(config_file)


def powerOn():
    J2534.ptSetProgrammingVoltage(deviceID, 15, -2)


def powerOff():
    os.system('color B  ')
    J2534.ptSetProgrammingVoltage(deviceID, 15, -1)
    print(dtn(), 'Power RESET')
    os.system('color F')


## ----------------------------------------- MAIN CODE ----------------------------------------- ##

devices = J2534.getDevices()
for id in devices:  # List of J2534 devices
    if id + 1 == devIndex:
        print('> ', end='')
    else:
        print('  ', end='')
    print(id + 1, devices[id])
    path = devices[id]['FunctionLibrary'].rsplit('\\', 1)[0] + '\\'
    os.add_dll_directory(path)  # Add .dll path to python searh for dependencies

while not devIndex in range(1, len(devices) + 1):  # if default devIndex not in list - choose device
    print('Select: ', end='')
    devIndexStr = input()
    if devIndexStr.isnumeric(): devIndex = int(devIndexStr)

J2534.setDevice(devIndex - 1)
ret, deviceID = J2534.ptOpen()

powerOff()
time.sleep(powerPause)
powerOn()
time.sleep(powerPause)

## -------------------------------- ISO Proto init / Get VIN ----------------------------------- ##

ret, chISO = J2534.ptConnect(deviceID, ProtoISO, 0x00000000, BaudRate.B500K)
print(dtn(), '[ ISO15765 Connected ]')

maskMsg = J2534.ptMskMsg(0x00000040)
maskMsg.setID(0xffffffff)
patternMsg = J2534.ptPatternMsg(0x00000040)
patternMsg.setID(0x000007e8)
flowcontrolMsg = J2534.ptPatternMsg(0x00000040)
flowcontrolMsg.setID(0x000007e0)
ret, filterid = J2534.ptStartMsgFilter(chISO, FilterType.FLOW_CONTROL_FILTER, maskMsg, patternMsg, flowcontrolMsg)

VIN = printECUidStr('VIN:', sendISO([0x1a, 0x90], 3))

if not VIN.isalnum():
    print(dtn(), 'VIN READ ERROR! Check connection and ECU!')
    clrbISO()
    powerOff()
    exit(666)

clrbISO()
J2534.ptStopMsgFilter(chISO, filterid)
J2534.ptDisconnect(chISO)

time.sleep(powerPause * 2)

## -------------------------------------- CAN Proto init --------------------------------------- ##

ret, chCAN = J2534.ptConnect(deviceID, ProtoCAN, 0x00000800, BaudRate.B500K)
print(dtn(), '[ CAN Connected ]')

maskMsg = J2534.ptMskMsgCAN(0x00000000)
maskMsg.setID(0xFFFFFFFF)
patternMsg = J2534.ptPatternMsgCAN(0x00000000)
patternMsg.setID(0x000007E8)
flowcontrolMsg = J2534.ptPatternMsgCAN(False)
J2534.ptStartMsgFilter(chCAN, FilterType.PASS_FILTER, maskMsg, patternMsg, flowcontrolMsg)

## --------------------------- Try to read last State (with this VIN) -------------------------- ##

if not os.path.exists('history'):
    os.mkdir('history')
if os.path.exists('history\\' + VIN + '.last.ini'):
    cfg.read('history\\' + VIN + '.last.ini')
    ikeyLast = int(cfg.get('DEFAULT', 'ikeyLast'))
    ikBeg = int(cfg.get('DEFAULT', 'ikBeg'))
    ikEnd = int(cfg.get('DEFAULT', 'ikEnd'))
    ikEnc = int(cfg.get('DEFAULT', 'ikEnc'))
    swapByte = eval(cfg.get('DEFAULT', 'swapByte'))
    algoLast = int(cfg.get('DEFAULT', 'algoLast'))
    bkeyLast = int(cfg.get('DEFAULT', 'bkeyLast'))
    phase = int(cfg.get('DEFAULT', 'phase'))
    if ikEnc > 0: runForward = True;

    print(dtn(), '[ Read settings from:', 'history\\' + VIN + '.last.ini ]')
    print('Last key:', addZ(hex(ikeyLast)[2:], 4), '\nStart key:', addZ(hex(ikBeg)[2:], 4), '\nEnd key:',
          addZ(hex(ikEnd)[2:], 4), '\nStep:', ikEnc, '\nswapByte:', swapByte, '\nalgoLast:', algoLast, '\nbkeyLast:',
          bkeyLast, '\nphase:', phase)
else:
    print(dtn(), '[ Begin from scratch (no config file) ]')

## --------------------------------- Generate Seed-Key list ------------------------------------ ##

print(dtn(), '[ Generate Seed-Key list ]')

keyAllgmlan = []
keyAllclass2 = []
keyAllothers = []

seed = askSeed()
for algo in range(000, 256):
    keyAllgmlan.append(abs(so.get_key(seed, algo, 1)))
    keyAllclass2.append(abs(so.get_key(seed, algo, 2)))
    keyAllothers.append(abs(so.get_key(seed, algo, 3)))

keyDefault = keyAllgmlan[defaultKeyAlgo]

## ---------------------------------- Phase 0 - Default KEY ------------------------------------ ##

if phase == 0:
    print(dtn(), '[ Phase 0 - Default KEY ]')
    print(dtn(), 'Default Key = ', hex(keyDefault)[2:], end='')
    high, low = bytes(keyDefault)
    if tryKey(high, low):
        exit(0)

    phase = 1
    clrbCAN()
    powerOff()
    saveCfg()
    time.sleep(powerPause)

## ---------------------------------- Phase 1 - Seed = KEY ------------------------------------ ##

if phase == 1:
    print(dtn(), '[ Phase 1 - Seed = KEY ]')
    print(dtn(), 'Default Key = ', hex(keyDefault)[2:], end='')
    high, low = bytes(keyDefault)
    if tryKey(high, low):
        exit(0)

    phase = 1
    clrbCAN()
    powerOff()
    saveCfg()
    time.sleep(powerPause)

## --------------------------------- Phase 2-4 - try all algo ---------------------------------- ##

while phase in range(2, 4 + 1):
    if phase == 1:
        keyAll = keyAllgmlan
        print(dtn(), '[ Phase', phase, '- try all GMlan algo ]')
    if phase == 2:
        keyAll = keyAllclass2
        print(dtn(), '[ Phase', phase, '- try all class2 algo ]')
    if phase == 3:
        keyAll = keyAllothers
        print(dtn(), '[ Phase', phase, '- try all other algo ]')

    startTime = time.time()
    algoLastLast = algoLast

    for algo in range(algoLastLast, 256):

        ikey = keyAll[algo]

        if ikey == keyDefault:  # Skip default Key
            continue
        if ikey == seed:  # Skip Seed = Key
            continue
        if phase == 3 and ikey in keyAllgmlan:  # skip gmlan keys on phase 2
            continue
        if phase == 4 and (ikey in keyAllgmlan or ikey in keyAllclass2):  # skip gmlan and class2 keys on phase 3
            continue

        powerOn()
        seed = askSeed()

        high, low = bytes(ikey)
        print(dtn(), 'Algo:', addZ(str(algo), 3), 'KEY: ' + addZ(hex(high)[2:], 2) + addZ(hex(low)[2:], 2), end='')

        if tryKey(high, low):
            powerOff()
            J2534.ptDisconnect(chISO)
            J2534.ptClose(deviceID)
            exit(0)
        else:
            clrbCAN()
            powerOff()
            algoLast = algo
            saveCfg()
            time.sleep(powerPause)

        if (algo - algoLastLast + 1) % 5 == 0 and algo > algoLastLast:
            runTime = (time.time() - startTime)
            estSec = (runTime / (algo - algoLastLast + 1) * (256 - algo))
            print(dtn(), 'Tested now:', (algo - algoLastLast + 1), 'total:', algo + 1, 'keys from', 256)
            print(dtn(), 'Runing time:', str(datetime.timedelta(seconds=runTime // 1)), end='')
            print(' // Est:', str(datetime.timedelta(seconds=estSec // 1)), '( phase', phase, ')')

    phase += 1
    algoLast = 0
    clrbCAN()
    powerOff()
    saveCfg()
    time.sleep(powerPause)

## ------------------- Phase 5, 6 - same High and Low byte and Mirror hi/lo byte --------------------- ##

while phase in range(5, 6 + 1):

    print(dtn(), '[ Phase', phase, '- same High and Low byte ]')

    startTime = time.time()
    bkeyLastLast = bkeyLast

    for bkey in range(bkeyLast, 256):

        if phase == 5:
            low = bkey
            high = bkey
        if phase == 6:
            low = bkey
            high = mirrorByte(bkey)
            if low == high: # skip phase 4 keys
                continue

        currKey = (high << 8) + low
        if (currKey == keyDefault
                or currKey == seed
                or currKey in keyAllgmlan
                or currKey in keyAllclass2
                or currKey in keyAllothers):  # skip algo and default keys
            continue

        powerOn()
        seed = askSeed()

        print(dtn(), 'bkey:', addZ(str(bkey), 3), 'KEY: ' + addZ(hex(high)[2:], 2) + addZ(hex(low)[2:], 2), end='')

        if tryKey(high, low):
            clrbCAN()
            powerOff()
            J2534.ptDisconnect(chISO)
            J2534.ptClose(deviceID)
            exit(0)
        else:
            clrbCAN()
            powerOff()
            bkeyLast = bkey
            saveCfg()
            time.sleep(powerPause)

        if (bkey - bkeyLastLast + 1) % 5 == 0 and bkey > bkeyLastLast:
            runTime = (time.time() - startTime)
            estSec = (runTime / (bkey - bkeyLastLast + 1) * (256 - bkey))
            print(dtn(), 'Tested now:', (bkey - bkeyLastLast + 1), 'total:', bkey + 1, 'keys from', 256)
            print(dtn(), 'Runing time:', str(datetime.timedelta(seconds=runTime // 1)), end='')
            print(' // Est:', str(datetime.timedelta(seconds=estSec // 1)), '( phase', phase, ')')

    phase += 1
    bkeyLast = 0
    clrbCAN()
    powerOff()
    saveCfg()
    time.sleep(powerPause)

## ----------------------------------- Phase 7 - Bruteforce ------------------------------------ ##

print(dtn(), '[ Phase', phase, '- Bruteforce ]')

startTime = time.time()
ikeyLastLast = ikeyLast

for ikey in range(ikeyLast, ikEnd, ikEnc):

    if not swapByte:
        high, low = bytes(ikey)  # high и low in normal order
    else:
        low, high = bytes(ikey)  # high и low changed!

    if phase == 8: # we already did it, and dont find seed key :-(
        print('All phase completed. Key not found.') 
        print('(damaged ECU? Bad connection? Bugs in this bruteforcer?)') 
        print('To run again - delete:') 
        print('history\\' + VIN + '.last.ini') 
        break

    currKey = ((high << 8) + low)
    if (currKey in keyAllgmlan  # check Key repeat in 0-5 phase
            or currKey in keyAllclass2
            or currKey in keyAllothers
            or high == low
            or high == mirrorByte(low)
            or currKey == keyDefault
            or currKey == seed): continue

    powerOn()
    seed = askSeed()

    print(dtn(), 'KEY: ' + addZ(hex(high)[2:], 2) + addZ(hex(low)[2:], 2), end='')

    if tryKey(high, low):
        break  # We found it!
    else:
        clrbCAN()
        powerOff()
        ikeyLast = ikey
        saveCfg()
        time.sleep(powerPause)

    if runForward:
        ikeysPass = (ikey - ikeyLastLast) + 1
    else:
        ikeysPass = (ikeyLastLast - ikey) + 1

    if (ikeysPass % 5 == 0  # Calculate run and time left.
            and ikeysPass > 5
            and ikey != ikeyLastLast
            and ikey != ikEnd):
        runTime = (time.time() - startTime)
        if runForward:
            leftSec = (runTime / ikeysPass * (ikEnd - ikey) / ikEnc)
            print(dtn(), 'Tested now:', ikeysPass, 'total:', ikey + 1, 'keys from', ikEnd + 1)
        else:
            leftSec = abs(runTime / ikeysPass * (ikey - ikEnd) / ikEnc)
            print(dtn(), 'Tested now:', ikeysPass, 'total:', ikBeg - ikey + 1, 'keys from', ikBeg + 1)

        print(dtn(), 'Runing time:', str(datetime.timedelta(seconds=runTime // 1)), end='')
        print(' // Left:', str(datetime.timedelta(seconds=leftSec // 1)), '( phase', phase, ')')

## ---------------------------------------- Program END ---------------------------------------- ##

phase += 1 # We have't phase 8. So, we can not find Seed Key.
saveCfg()
clrbCAN()
powerOff()
J2534.ptDisconnect(chISO)
J2534.ptClose(deviceID)
