CC = gcc
CFLAGS = -c -g -Wall -fPIC

fileSrc1 = ./src/main.c
fileSrc2 = ./src/addition.c
fileSrc3 = ./src/subtraction.c
fileSrc4 = ./src/division.c
fileSrc5 = ./src/multiplication.c
fileSrc6 = ./src/modulus.c

headerDir = ./inc
libDir = ./lib

dynamicLib = operation
FinalTargetName = main.elf

# Source files of the static library
LibSrcs = $(fileSrc2) $(fileSrc3) $(fileSrc4) $(fileSrc5) $(fileSrc6) 
# Object files of the static library
LibObjs = $(LibSrcs:.c=.o)

$(FinalTargetName) : $(dynamicLib)
	$(CC) $(fileSrc1) -o $@ -l$< -L $(libDir) -I $(headerDir)
	
$(dynamicLib) : $(LibObjs)
	$(CC) -shared -o $(libDir)/lib$@.so $^
	
$(LibObjs): %.o : %.c
	$(CC) $(CFLAGS) $< -I $(headerDir) -o $@

.PHONY: clean
	
clean:
	rm $(FinalTargetName) $(libDir)/*.so $(LibObjs)
	

