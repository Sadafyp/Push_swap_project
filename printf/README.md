*This project has been created as part of the 42 curriculum by syazdanp*

## Description:
ft_printf is a reimplementation of a limited version of the C standard library function printf.
The project produces a static library named libftprintf.a containing:

int ft_printf(const char *format, ...);

The implementation should support the following conversions:

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

Output is written directly to standard output.

## Instructions:
### Project Structure
.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
├── ft_print_type.c
├── ft_print_char.c
├── ft_print_str.c
├── ft_print_nbr.c
├── ft_print_unsigned.c
├── ft_print_hex.c
├── ft_print_ptr.c
└── libft/
    ├── Makefile
    ├── libft.h
    └── ft_*.c
### Compilation
Run:

make


- Builds libft/libft.a through the Libft Makefile.
- Compiles the ft_printf source files into object files.
- Copies the Libft archive into libftprintf.a.
- Adds the ft_printf object files to libftprintf.a.
- The project is compiled with: cc -Wall -Wextra -Werror
- The static library is created with: ar rcs

### Usage

Example:
```
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Name: %s, value: %d, hex: %x\n",
            "example", 42, 42U);
    ft_printf("Printed characters: %d\n", count);
    return (0);
}
```
Compile it with:

cc -Wall -Wextra -Werror main.c libftprintf.a -o output

Run it with:

./output

## Algorithm and Technical Choices

### Format-string parsing

ft_printf scans the format string from left to right.

Ordinary characters are printed directly.

When % is encountered, the following character is treated as a conversion specifier.

The conversion is delegated to ft_print_type.

Each printing helper returns the number of characters it printed.

ft_printf accumulates these return values and returns the final total.

Conceptually:

format string
    |
    +-- ordinary character --> print directly
    |
    +-- '%' --> inspect next character
                  |
                  +-- retrieve the matching variadic argument
                  +-- call the corresponding printing helper

### Variadic arguments

The function uses the concept from <stdarg.h>:

va_list stores the traversal state.

va_start initializes traversal after the named parameter format.

va_arg retrieves the next argument using the type required by the conversion.

va_end finishes the traversal.

The conversion specifier determines the type requested from va_arg.

Examples:

- %c -> int
- %s -> char *
- %d -> int
- %u -> unsigned int
- %p -> void *


ft_print_type maps each supported conversion specifier to a dedicated helper.

This way ft_printf itself is only focused on parsing.

### Decimal number printing

Signed and unsigned integers are printed recursively.

For a decimal number:

n / 10 removes the last digit.

n % 10 obtains the last digit.

Recursion prints the more significant digits first.

Adding '0' converts a digit from 0 through 9 to its character representation.

Signed integers are first converted to long so that INT_MIN can be safely negated.

### Hexadecimal printing

Hexadecimal output uses the same recursive structure with base 16:

n / 16 removes the final hexadecimal digit.

n % 16 selects the final hexadecimal digit.

A lookup string converts values from 0 through 15 into characters.

Lowercase:

"0123456789abcdef"

Uppercase:

"0123456789ABCDEF"

### Pointer printing

Pointers are retrieved as void *, converted to an unsigned integer type wide enough for the target platform, and printed in lowercase hexadecimal.

The 0x prefix is formatting added by the pointer helper. It is not part of the stored pointer value.

A null pointer naturally becomes 0x0 on the target macOS environment used during development.

### Return-value counting

Every helper returns the number of characters it prints.

Examples:

ft_print_char('A')       -> 1
ft_print_str("hello")    -> 5
ft_print_nbr(-42)        -> 3
ft_print_hex(255, ...)   -> 2

ft_printf adds these values and returns the complete count.


### Testing

The implementation was compared against the system printf for:

ordinary strings;

empty strings;

multiple conversions in one call;

%c and %%;

null strings;

0, positive numbers, and negative numbers;

INT_MIN and INT_MAX;

UINT_MAX;

lowercase and uppercase hexadecimal;

valid pointers and null pointers;

## Resources:

- man 3 printf
- man stdarg
- man va_start
- man va_arg
- man va_copy
- man va_end
- man 2 write
- https://github.com/Kuninoto/42_ft_printf/blob/master/srcs/prt_ptr.c
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/



