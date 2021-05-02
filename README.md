# arm-mcu-OS

1.Create a keil project for STM32F103C8
<br>

2.Copy "source" into your project folder where the <project_name>.uvprojx is.
<br>
Like :

    --<project Folder>
    ------DebugConfig
    ------Listings
    ------Objects
    ------RTE
    ------source
    ------arm-mcu.uvguix.user
    ------arm-mcu.uvoptx
    ------arm-mcu.uvoptx
    ------EventRecorderStub.scvd
    ------source        <<----- source code form this branch

<br>
3.In keil : Add all the source code into your project.

<br>
4.Go to "startup_stm32f10x_md.s"
<br>
Modified Line33 : "Stack_Size      EQU     0x00000400"
<br>
to

    Stack_Size      EQU     0x00004000

<br>

5.Options for target setup :

<br>
MCU : STM32F103C8<br>
Target --> Xtal(MHz) : 8.0<br>
Target --> Check "Use MicroLIB"<br>
Target --> ARM Compiler : Use default compiler version 6

<br>
C/C++(AC6) --> Language C : c99<br>
C/C++(AC6) --> Optimization : -O0

<br>
Debug --> Check "Use Simulator"<br>
Debug --> Dialog DLL : DARMSTM.DLL<br>
Debug --> Parameter: -pSTM32F103C8 (Same line as Dialog DLL)

<br>
6.Compile it and run.
