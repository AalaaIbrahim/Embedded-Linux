CC = gcc
CFLAGS = -c

ArchiveTool = ar
ArchiveFLAGS= -rcs

fileSrc1 = ./src/main.c
fileSrc2 = ./src/addition.c
fileSrc3 = ./src/subtraction.c
fileSrc4 = ./src/division.c
fileSrc5 = ./src/multiplication.c
fileSrc6 = ./src/modulus.c

headerDir = ./inc
libDir = ./lib

staticLib = operation
FinalTargetName = main.elf

# Source files of the static library
staticLibSrcs = $(fileSrc2) $(fileSrc3) $(fileSrc4) $(fileSrc5) $(fileSrc6) 
# Object files of the static library
staticLibObjs = $(staticLibSrcs:.c=.o)

$(FinalTargetName) : $(staticLib) $(libDir)
	$(CC) $(fileSrc1) -o $@ -l$< -L $(libDir) -I $(headerDir)
	
$(staticLib) : $(staticLibObjs)
	$(ArchiveTool) $(ArchiveFLAGS) $(libDir)/lib$@.a $^
	
$(libDir) : 
	mkdir lib
	
$(staticLibObjs): %.o : %.c
	$(CC) $(CFLAGS) $< -I $(headerDir) -o $@

.PHONY: clean
	
clean:
	rm $(FinalTargetName) $(libDir)/*.a $(staticLibObjs)
	

