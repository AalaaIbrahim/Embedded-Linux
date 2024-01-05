CC = avr-gcc
CFLAGS = -c

ArchiveTool = avr-ar
ArchiveFLAGS= -rcs

fileSrc1 = ./03-APP/main.c
fileSrc2 = ./01-MCAL/01-PORT/PORT.c
fileSrc3 = ./01-MCAL/01-PORT/PORT_config.c
fileSrc4 = ./01-MCAL/00-DIO/DIO.c
fileSrc5 = ./UTIL/DELAY/DELAY.c

fileObj1 = main.o
fileObj2 = ./01-MCAL/01-PORT/PORT.o
fileObj3 = ./01-MCAL/01-PORT/PORT_config.o
fileObj4 = ./01-MCAL/00-DIO/DIO.o
fileObj5 = ./UTIL/DELAY/DELAY.o

headerDir1 = ./01-MCAL/01-PORT
headerDir2 = ./01-MCAL/00-DIO
headerDir3 = ./00-LIB
headerDir4 = ./UTIL/DELAY

staticLib = mcal
FinalTargetName = main.elf

# Directories of included header files
allHeaderDirs = -I $(headerDir1) -I $(headerDir2) -I $(headerDir3) -I $(headerDir4) 
# Source files of the static library
staticLibSrcs = $(fileSrc2) $(fileSrc3) $(fileSrc4) 
# Object files of the static library
staticLibObjs = $(staticLibSrcs:.c=.o)

$(FinalTargetName) : $(staticLib) 
	$(CC) $(fileSrc1) $(fileSrc5) -o $@ -l$< -L ./01-MCAL $(allHeaderDirs)
	
$(staticLib) : $(staticLibObjs)
	$(ArchiveTool) $(ArchiveFLAGS) ./01-MCAL/lib$@.a $^
	
$(staticLibObjs): %.o : %.c
	$(CC) $(CFLAGS) $< $(allHeaderDirs) -o $@

.PHONY: clean
	
clean:
	rm $(FinalTargetName) ./01-MCAL/*.a $(staticLibObjs)
	

