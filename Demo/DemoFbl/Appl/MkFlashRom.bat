:: Create ROM-array of Flash-Driver
if "%1" == "" goto end

@echo [C_EXPORT]                                                                          >  %~dp0\%~n1.ini
@echo Decryption=0         ;  0=Off,  1=On                                                >> %~dp0\%~n1.ini
@echo Decryptvalue=0x00    ; Value for encryption using XOR with each uchar/ushort/ulong  >> %~dp0\%~n1.ini
@echo Prefix=DemoFbl                                                                     >> %~dp0\%~n1.ini
@echo WordSize=0           ; 0=uchar, 1=ushort, 2=ulong                                   >> %~dp0\%~n1.ini
@echo WordType=0           ; 0=Intel, 1=Motorola (only used if wordsize > 0).             >> %~dp0\%~n1.ini


%~dp0..\..\..\Misc\HexView\hexview.exe %1 /s /FA /FPFF -e:%~n1.log /XC -o %~dp0..\FlashRom.c
