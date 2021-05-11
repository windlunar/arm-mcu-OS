#
# 2021/4/20
#
# Created by ME
#

include ../../toolchain.make

obj_destination_path = ../../obj
CFLAGS  += -fno-common -O0 -std=gnu99 -g -mcpu=cortex-m3 -mthumb -nostdlib 
#CFLAGS += -mcpu=cortex-m3 -mthumb -gdwarf-2 -MD -Wall -O0 -mapcs-frame -mthumb-interwork


c_obj=gpio.o usart.o systick.o


.PHONY : all
all: $(c_obj) move


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













