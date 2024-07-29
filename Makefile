# make build script.
#
# usage:
# 
#    make clean: clean compiled file
#    make cleanAndCompile: clean compiled file and compile the project
#    make compile: compile the project
#    make compileAndRun: compile the project and run the compiled file
#    make run: run the compiled file
#    make all: clean compiled file, compile the project and run the compiled file
#
# author: Manoel NogueiraMelo Filho

currentFolderName := $(lastword $(notdir $(shell pwd)))
compiledFile := $(currentFolderName).out
CFLAGS := -O1 -Wall -Wextra -Wno-unused-parameter -pedantic-errors -std=c99 -Wno-missing-braces -I include/lib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm -f $(compiledFile)

compile:
	gcc *.c -o $(compiledFile) $(CFLAGS)

run:
	./$(compiledFile)

cleanAndCompile: clean compile
compileAndRun: compile run
all: clean compile run