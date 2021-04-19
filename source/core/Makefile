#
# 2021/4/20
#
# Makefile created by Me
#

include ../../toolchain.make

obj_destination_path = ../../obj


# -fno-common, which specifies that the compiler places uninitialized global 
# variables in the BSS section of the object file.

# -nostdlib implies the individual options -nodefaultlibs and -nostartfiles. 
# -nodefaultlibs disables linking with those default libraries; the only libraries 
# linked are exactly those that you explicitly name to the linker using the -l flag.

# -nostartfiles instructs the linker to not use the standard system startup functions
#  nor link the code containing those functions.

# -g : 使用 GDB debug
# -O : 最佳化
CFLAGS  += -fno-common -O0 -std=gnu99 -g -mcpu=cortex-m3 -mthumb -nostdlib 

c_obj=system_stm32f10x.o
asm_obj=startup_stm32f10x_md.o

.PHONY : all
all: $(c_obj) $(asm_obj) move


%.o : %.s
	$(toolchain)-as $^ -o $@


%.o : %.c
	$(toolchain)-gcc $(CFLAGS) -c $^ -o $@


.PHONY : move
move : 
	cp *.o $(obj_destination_path)
	rm -rf *.o	
	rm -rf *.su


#Clean objects
.PHONY : clean
clean :
	-rm $(obj_destination_path)/$(src_objects)













