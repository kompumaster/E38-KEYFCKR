# GM AcDelco ECU "E38 KeyFCKR"

by [Flash/Tune](https://t.me/obd2help)

# **TESTING NEEDED!!!**


Intro:

A long time ago,
in a galaxy far, far away..  
The E38 unit came into my hands after the EEPROM was damaged. The Seed/Key pair was irretrievably lost, the standard one did not fit...  after about a couple of days (or rather nights) of trying to recover the key, this script was born.



Features:
- 2 bytes Seed Key brutforce tester (via J2534 device).
- Power control - L-Line (pin15). Use [PowerBox](https://megabonus.com/y/plZVk) or [similar devce](img/obd2_to_ecu_with_power_control.png).


![AcDelco E38 Pinout](img/AcDelco_E38_Pinout.png)


Script has 8 phases:
- **0** - Defaut Key (gmlan 0x92 algo)
- **1** - Key = Seed
- **2** - All algo keys in "gmlan" proto
- **3** - All algo keys in "class2" proto
- **4** - All algo keys in "others" proto
- **5** - All keys with same hi-lo byte (0101, 0202 ...)
- **6** - All keys with mirror hi-lo byte (0110, 0220 ...)
- **7** - Bruteforce **all** 65536 keys

Script have settings:
- runForward - Key from 0000 to FFFF, or backward
- swapByte - Swap high and low Key Byte (0001, 0002 ... or 0100, 0200 ...)

and some more. Look inside.


Curren progress saves in "history\\%VIN%.last.ini" file.

- PS.  Use Windows and [Python 3.12 x32](https://www.python.org/ftp/python/3.12.0/python-3.12.0.exe)
- PPS.Code written by my monkey danсing on the keyboard[.](img/monkey.gif)
- PPPS. Have you found a Key and want to share your Joy? ;-)
- USDT: *TQzFrezTpgY7AknMsxMRPsBsAzDi9tHZJ3* (TRC20)


Used:
- [NPYK J2534](https://github.com/NPYK/python_j2534) modified lib
- [YustasSwamp gm-seed-key](https://github.com/YustasSwamp/gm-seed-key) modified to .so
- [MD Flasher](https://mdflasher.online/catalog/moduli_dlya_programmnogo_kompleksa_mdflasher/litsenziya_090_gm_acdelco_e37_e38_ecu_bench_obdii/) license #90 logs made by [joeyoravec j2534-logger](https://github.com/joeyoravec/j2534-logger)
