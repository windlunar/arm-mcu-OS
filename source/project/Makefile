#
# 2021/4/20
#
# Created by Allen.YY
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
CFLAGS  += -fno-common -fno-builtin -O0 -std=gnu99 -g -mcpu=cortex-m3 -mthumb -nostdlib 
#CFLAGS  += -fno-common -O0 -std=gnu99 -g -mcpu=cortex-m3 -mthumb -nodefaultlibs -nostartfiles
#CFLAGS  += -fno-common -O0 -std=gnu99 -g -mcpu=cortex-m3 -mthumb -nostartfiles

c_obj= entry.o systick_int.o
asm_obj=

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













