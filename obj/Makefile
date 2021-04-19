#
# 2020/7/21
#
# Created by Allen.YY
#

include ../toolchain.make

bin_destination_path = ../bin
bin_name = amo

#LIB_GCC = /opt/gcc-arm-none-eabi-6-2017-q2-update/lib/gcc/arm-none-eabi/6.3.1
LIB_GCC = /opt/gcc-arm-none-eabi-9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1


#Build
#all objects
### -L $(LIB_GCC) -lgcc 
### －Ｌ是指定載入靜態連結函式庫檔案的路徑
###－ｌ是指定載入的靜態連結函式庫檔案。
### 除法需要 libgcc.a這個靜態函式庫
$(bin_name) : $(total_objects)
	$(toolchain)-ld *.o -T main.ld -o $(bin_destination_path)/$(bin_name).elf  -L $(LIB_GCC) -lgcc 
	$(toolchain)-objcopy -Obinary $(bin_destination_path)/$(bin_name).elf $(bin_destination_path)/$(bin_name).bin
	$(toolchain)-objdump -S $(bin_destination_path)/$(bin_name).elf > $(bin_destination_path)/$(bin_name).disasm.list

#Clean objects and bin
.PHONY : clean
clean :
	-rm ./*.o
	-rm $(bin_destination_path)/$(bin_name)














