# arm-mcu-OS

PART 1 : Install Cross compiler for arm architecture machine
=

Install : "gcc-arm-none-eabi-9-2020-q2-update" 
<br><br>
Make sure the compiler was installed at /opt 下.<br> 
Or you can check "obj/MakeFile" , and modified this line to the path where the compiler is actually installed.<br>

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

    make
    make qemu

Press "Ctrl+a" and then press "x" to exit emulator

