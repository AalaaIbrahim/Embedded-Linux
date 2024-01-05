cmake_minimum_required(VERSION 3.1..3.22)

project(Calculator)

set(SRC_FILES main.c)

set(LIB_SRC_FILES addition.c division.c modulus.c multiplication.c subtraction.c)

add_executable(main.elf ${SRC_FILES})

target_include_directories(main.elf INTERFACE ./)

add_library(operation
	    SHARED 
	    ${LIB_SRC_FILES})
	    
target_link_libraries(main.elf PUBLIC operation)
