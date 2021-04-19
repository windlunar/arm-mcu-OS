#
# 2021/4/20
#
# Created by Allen.YY
#

include toolchain.make

obj_destination_path = ./obj
bin_destination_path = ./bin
bin_name = amo

root_dir = $(shell pwd)

#Build
.PHONY : build
build:
	mkdir -p bin
	make -C ./source
	make -C ./obj
	
	@echo
	@echo Build sucessfully!


#Clean objects and bin
.PHONY : clean
clean :
	-rm $(bin_destination_path)/$(bin_name)
	-rm $(obj_destination_path)/*.o

.PHONY : clobj
clobj :
	-rm $(obj_destination_path)/*.o


.PHONY : clean_diasm
cldisasm :
	-rm $(bin_destination_path)/*.disasm


.PHONY : disasm
disasm:
	$(toolchain)-objdump -D ./$(bin_destination_path)/$(bin_name) > ./$(bin_destination_path)/$(bin_name).disasm


# "Exit : Ctrl-A and X"
# @代表不把命令輸出到終端
.PHONY : qemu
qemu:
	@qemu-system-arm -M stm32-p103 -nographic -kernel $(bin_destination_path)/$(bin_name).bin








