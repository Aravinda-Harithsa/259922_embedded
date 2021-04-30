PROJ_NAME = Ltts_Embedded
ELFFILE = $(PROJ_NAME).elf
BUILD_DIR = Build

SRC = Main.c\
src/activity1.c\
src/activity2.c\
src/activity3.c\
src/activity4.c


INC = -I inc

ifdef OS	# All configurations for Windwos OS
   RM = rm -rf
   FixPath = $(subst /,\,$1)
   CC = avr-gcc.exe
   AVR_OBJ_CPY = avr-objcopy
else #All configurations for Linux OS
   ifeq ($(shell uname), Linux)
      RM = rm -rf		
      FixPath = $1				
	  CC = avr-gcc  
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif


.PHONY:all analysis clean doc

all:$(BUILD_DIR)
	# Compile the code and generate the ELF file
	$(CC) -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):
	# Create directory to store the built files
	mkdir $(BUILD_DIR)

hexfile:
	#Creates activity2.hex file
	$(AVR_OBJ_CPY) -O ihex $(BUILD_DIR)/$(ELFFILE) $(BUILD_DIR)/$(PROJ_NAME).hex

analysis: $(SRC)
	#This will Analyse the code using Cppcheck
	cppcheck --enable=all $^

clean:
	# This will Remove all the required  build files and generated document files
	$(RM) $(call FixPath,$(BUILD_DIR))
	make -C documentation clean