#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "ft_printf.h"

void	test_basic(char *arg)
{
	int	ft_result;
	int	printf_result;

	printf("======== BASIC ========\n");

	ft_result = ft_printf(arg) + ft_printf("\n");
	printf_result = printf("%s\n", arg);

	printf("ft_printf returned: %d\n", ft_result);
	printf("printf returned:    %d\n\n", printf_result);

/*
	ft_result = ft_printf("Hello\n");
	printf_result = printf("Hello\n");

	printf("ft_printf returned: %d\n", ft_result);
	printf("printf returned:    %d\n\n", printf_result);

	ft_printf("");
	ft_printf("A");
	ft_printf("Hello\n");
	ft_printf("100%% complete\n");
	ft_printf("A%c%%Villain\n", 'I');
	printf("A%c%%Villain\n", 'I');
	*/
}

void	test_chars(void)
{
	int	ft_count;
	int	printf_count;

	printf("\n======== CHAR ========\n");

	ft_count = ft_printf("Character: %c\n", 'A');
	printf_count = printf("Character: %c\n", 'A');
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n\n", printf_count);

	ft_count = ft_printf("Percent: %%\n");
	printf_count = printf("Percent: %%\n");
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n\n", printf_count);

	ft_count = ft_printf("%c%c%c\n", 'A', 'B', 'C');
	printf_count = printf("%c%c%c\n", 'A', 'B', 'C');
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);
}

void	test_strings(void)
{
	int	ft_count;
	int	printf_count;

	printf("\n======== STRING ========\n");

	ft_count = ft_printf("NULL: %s\n", (char *)NULL);
	printf_count = printf("NULL: %s\n", (char *)NULL);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%s\n", "hello");
	printf_count = printf("%s\n", "hello");
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("[%s]\n", "");
	printf_count = printf("[%s]\n", "");
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%s %s\n", "first", "second");
	printf_count = printf("%s %s\n", "first", "second");
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);
}

void	test_numbers(void)
{
	int	ft_count;
	int	printf_count;

	printf("\n======== NUMBER ========\n");

	ft_count = ft_printf("INT_MIN: %d\n", INT_MIN);
	printf_count = printf("INT_MIN: %d\n", INT_MIN);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%d\n", -42);
	printf_count = printf("%d\n", -42);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%i %i %i\n", -10, 0, 500);
	printf_count = printf("%i %i %i\n", -10, 0, 500);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);
}

void	test_unsigned(void)
{
	int	ft_count;
	int	printf_count;

	printf("\n======== UNSIGNED ========\n");

	ft_count = ft_printf("%u\n", 0U);
	printf_count = printf("%u\n", 0U);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%u\n", 42U);
	printf_count = printf("%u\n", 42U);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%u\n", UINT_MAX);
	printf_count = printf("%u\n", UINT_MAX);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%u %u %u\n", 0U, 100U, UINT_MAX);
	printf_count = printf("%u %u %u\n", 0U, 100U, UINT_MAX);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);
}

void	test_hex(void)
{
	int	ft_count;
	int	printf_count;

	printf("\n======== HEX ========\n");

	ft_count = ft_printf("%x\n", 0U);
	printf_count = printf("%x\n", 0U);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%X\n", 255U);
	printf_count = printf("%X\n", 255U);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("%X\n", UINT_MAX);
	printf_count = printf("%X\n", UINT_MAX);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	printf("\n-------- SIZE OF --------\n");
	printf("unsigned int:  %zu\n", sizeof(unsigned int));
	printf("unsigned long: %zu\n", sizeof(unsigned long));
	printf("void *:        %zu\n", sizeof(void *));
	printf("[%p]\n", (void *)0);
}

void	test_pointers(void)
{
	int		ft_count;
	int		printf_count;
	int		n;
	char	c;
	char	*str;

	printf("\n======== POINTER ========\n");

	n = 42;
	c = 'A';
	str = "hello";

	ft_count = ft_printf("n:   %p\n", &n);
	printf_count = printf("n:   %p\n", &n);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("c:   %p\n", &c);
	printf_count = printf("c:   %p\n", &c);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("str: %p\n", str);
	printf_count = printf("str: %p\n", str);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);

	ft_count = ft_printf("null: %p\n", (void *)0);
	printf_count = printf("null: %p\n", (void *)0);
	printf("ft_printf: %d\n", ft_count);
	printf("printf:    %d\n", printf_count);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s [base|char|str|nbr|unsigned|hex|ptr|all]\n", argv[0]);
		return (1);
	}

	if (strcmp(argv[1], "base") == 0)
		test_basic(argv[2]);
	else if (strcmp(argv[1], "char") == 0)
		test_chars();
	else if (strcmp(argv[1], "str") == 0)
		test_strings();
	else if (strcmp(argv[1], "nbr") == 0)
		test_numbers();
	else if (strcmp(argv[1], "unsigned") == 0)
		test_unsigned();
	else if (strcmp(argv[1], "hex") == 0)
		test_hex();
	else if (strcmp(argv[1], "ptr") == 0)
		test_pointers();
	else if (strcmp(argv[1], "all") == 0)
	{
		test_basic(argv[2]);
		test_chars();
		test_strings();
		test_numbers();
		test_unsigned();
		test_hex();
		test_pointers();
	}
	else
	{
		printf("Unknown test: %s\n", argv[1]);
		return (1);
	}
	return (0);
}
