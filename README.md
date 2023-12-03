# GM AcDelco ECU "E38 KeyFCKR"

by [Flash/Tune](https://t.me/obd2help)

# ** TESTING NEEDED!!!  **

- 2 bytes Seed Key brutforce tester (via J2534 device).
- Power control - LLine (pin15). Use PowerBox or similar devce.

![AcDelco E38 Pinout](pinout/AcDelco_E38_Pinout.png)


Script has 6 phases:
- **0** - Defaut Key
- **1** - All keys in "Gmlan" algo
- **2** - All keys in "class2" algo
- **3** - All keys in "others" algo
- **4** - All keys with same hi-lo byte (0101, 0202 ...)
- **5** - Bruteforce **all** 65536 keys

Script have settings:
- runForward - Key from 0000 to FFFF, or backward
- swapByte - Swap high and low Key Byte (0001, 0002 ... or 0100, 0200 ...)

and some more. Look inside.


Curren progress saves in "history\\%VIN%.last.ini" file.

- PP.  Use Windows and Python 3.12 x32
- PPS.Code written by my monkey danсing on the keyboard


Used:
- J2534 modified lib from https://github.com/NPYK/python_j2534
- gm-seed-key modified from https://github.com/YustasSwamp/gm-seed-key
