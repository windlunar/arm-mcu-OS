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
<br>
4.Go to "startup_stm32f10x_md.s"

<br>
Modified Line33 : "Stack_Size      EQU     0x00000400"
<br>
to

    Stack_Size      EQU     0x00004000

<br>
5.Options for target setup :

MCU : STM32F103C8
<br>
Target --> Xtal(MHz) : 8.0
<br>
Target --> Check "Use MicroLIB"
<br>
Target --> ARM Compiler : Use default compiler version 6
<br>
<br>
C/C++(AC6) --> Language C : c99
<br>
C/C++(AC6) --> Optimization : -O0
<br>
<br>
Debug --> Check "Use Simulator"
<br>
Debug --> Dialog DLL : DARMSTM.DLL
<br>
Debug --> Parameter: -pSTM32F103C8 (Same line as Dialog DLL)
<br>
<br>
6.Compile it and run.





# Build the Project under Linux(Ubuntu)

PART 1 : Install Cross compiler for arm architecture machine
=

Install : "gcc-arm-none-eabi-9-2020-q2-update" 
<br><br>
Make sure compiler was installed at "/opt" .<br> 
Or you can check "obj/MakeFile" , and modified the path where the compiler is actually installed.<br>

	/opt/gcc-arm-none-eabi-9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1
<br>


PART 1 : Install qemu_stm32
=
Clone the project "qemu_stm32" :

    git clone https://github.com/beckus/qemu_stm32

Compile it :

    ./configure --enable-debug --disable-werror --target-list="arm-softmmu"

    make
    sudo make install


PART 2 : Compile this project
=

First ,clone the project. 

    git clone -b ubuntu-gcc-main https://github.com/windlunar/arm-mcu-OS

Or :

    git clone -b ubuntu-gcc-hello-world https://github.com/windlunar/arm-mcu-OS

Compile :

    make
    make qemu

Press "Ctrl+a" and then press "x" to exit emulator

<br>
Use gdb debug
<br>
First terminal :

    make qemu-gdb

Second terminal :

    make gdb
    

PART3 : Install ST-Link
=

If you had installed STM32CUBEIDE ,then uninstall first :

    sudo apt purge st-stlink-server
    sudo apt purge st-stlink-udev-rules
    sudo apt purge st-stm32cubeide-1.6.1

Go to:
<br>
https://github.com/stlink-org/stlink/releases
<br>
And Download "stlink-1.6.1-1_amd64.deb"
<br>
Move to the directory where your "stlink-1.6.1-1_amd64.deb" is.

    sudo dpkg --install ./stlink-1.6.1-1_amd64.deb



PART3 : Compile and install ST-Link from source

Download "Source code (zip)"  version 1.6.1 from https://github.com/stlink-org/stlink/releases

    cd stlink-1.6.1

    cmake .
    make

    cd bin
    sudo cp st-* /usr/local/bin
    cd ../lib
    sudo cp *.so* /lib

    sudo cp stlink/config/udev/rules.d/49-stlinkv* /etc/udev/rules.d/
    sudo udevadm control --reload-rules
    sudo udevadm trigger

Check STLink :

    lsusb

You should see "STMicroelectronics ST-LINK/V2"

    sudo st-info --probe

You should see "Found 1 stlink programmers"


PART4 : Write binary to STM32F103C8

    sudo st-flash --reset write ./bin/amo.bin 0x08000000
 
OR :
    make stflash

You should see "Flash written and verified! jolly good!" at the last line


You can read out the binary from flash and store it to ./bin/output.bin:

    st-flash read ./bin/output.bin 0x08000000 <size of bytes>
    (like "st-flash read ./bin/output.bin 0x08000000 0x08")