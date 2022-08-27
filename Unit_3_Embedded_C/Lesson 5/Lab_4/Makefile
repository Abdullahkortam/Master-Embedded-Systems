CC =arm-none-eabi
CFLAGS = -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

AS=$(wildcard *.s)
ASOBG=(AS:.s=.o)


project_name=abdullah_cortex_m3

all : $(project_name).bin
	@echo "=========BUILD DONE=========" 


%.o : %.c
	$(CC)-gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

uart.o : uart.c
	$(CC)-gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) startup.o
	$(CC)-ld.exe -T linker_script.ld $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

$(project_name).bin : $(project_name).elf
	$(CC)-objcopy.exe -O binary $< $@

remove_all :
	rm *.o *.elf *.bin
remove :
	rm *.elf *.bin
