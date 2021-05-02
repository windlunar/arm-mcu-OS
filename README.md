# arm-mcu-OS

1. Create a keil project for STM32F103C8
<br>

2. Copy "source" into your project folder where the <project_name>.uvprojx is.
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

3. In keil : Add all the source code into your project.

<br>
4. Go to "startup_stm32f10x_md.s"
Modified Line33 : "Stack_Size      EQU     0x00000400"
to
    "Stack_Size      EQU     0x00004000"

<br>
5. Options for target setup :

<br>
MCU : STM32F103C8
Target --> Xtal(MHz) : 8.0
Target --> Check "Use MicroLIB"
Target --> ARM Compiler : Use default compiler version 6

<br>
C/C++(AC6) --> Language C : c99
C/C++(AC6) --> Optimization : -O0

<br>
Debug --> Check "Use Simulator"
Debug --> Dialog DLL : DARMSTM.DLL
Debug --> Parameter: -pSTM32F103C8 (Same line as Dialog DLL)

6. Compile it and run.
