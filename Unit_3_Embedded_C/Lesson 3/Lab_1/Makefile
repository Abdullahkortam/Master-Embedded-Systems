#@coptright : Abdullah K.

CC =arm-none-eabi
CFLAGS =-mcpu=arm926ej-s -g
INCS=-I .

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

AS=$(wildcard *.s)
ASOBG=(AS:.s=.o)


project_name= abdullah

all : $(project_name).bin
	@echo "=========BUILD DONE=========" 
startup.o : startup.s
	$(CC)-as.exe $(CFLAGS) $< -o  $@

%.o : %.c
	$(CC)-gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

uart.o : uart.c
	$(CC)-gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) startup.o
	$(CC)-ld.exe -T linker_script.ld $(OBJ) $(ASOBJ) -o $@ 

$(project_name).bin : $(project_name).elf
	$(CC)-objcopy.exe -O binary $< $@

remove_all :
	rm *.o *.elf *.bin
remove :
	rm *.elf *.bin
