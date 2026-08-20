*This project has been created as part of the 42 curriculum by syazdanp*

## Description:
The projects aims for creating a custom C library by reimplementiing essential functions from the C standard library and creating additional utility functions from scratch. 

## Instructions:
### Project Structure
.
├── Makefile
├── libft.h
├── ft_*.c
└── libft.a
### Compilation
Build the static library:
make
Clean object files:
make clean
Remove object files and library:
make fclean
Rebuild the project:
make re

### Usage
Include the header in your project:
#include "libft.h"
Compile while linking the library:
cc main.c libft.a

## Resources:
Linux Man Pages (man strlen, man malloc, etc.)
C Library Documentation
https://www.geeksforgeeks.org/c/linked-list-in-c/
https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
AI was used as a learning aid for clarifying and reviewing concepts


