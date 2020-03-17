#include "incl/header.h"

struct t_option parse_main(int ac, char **av)
{
	char			*flags = "";
	int				i = 1;
	struct t_option	out;

	out.path = ".";
	out.success = 0;

	while (i < ac)
	{
		if (av[i][0] == '-')
			flags = parse_arg(av[i], flags);
		else
			out.path = av[i];
		i++;
	}
	flags = unique(flags);

	if (!validate_flags(flags))
		return out;

	out.success = 1;
	out.flag = flags;

	if (DEBUG)
	{
		printf("flags = %s\n", out.flag);
		printf("path = %s\n", out.path);
	}

	return out;
}

char	*parse_arg(char *arg, char *flags)
{
	int		len = strlen(arg);
	int		i = 1;

	char *out = (char*)malloc(sizeof(char) * len);
	while (arg[i] != '\0')
	{
		out[i - 1] = arg[i];
		i++;
	}
	return massjoin(flags, out);
}

char	*massjoin(char *base, char *append)
{
	int		len_base = strlen(base);
	int		len_append = strlen(append);
	int		len_total = len_base + len_append;
	char	*out = (char*)malloc(sizeof(char) * (len_total + 1));

	out[len_total] = '\0';
	int i = 0;
	while (base[i] != '\0')
	{
		out[i] = base[i];
		i++;
	}
	int z = 0;
	while (append[z] != '\0')
	{
		out[i] = append[z];
		z++;
		i++;
	}
	return out;
}

char	*appendsymb(char *base, char append)
{
	int		len = strlen(base) + 1;
	char	*out = (char*)malloc(sizeof(char) * (len + 1));
	int		i = 0;

	while (base[i] != '\0')
	{
		out[i] = base[i];
		i++;
	}
	out[i] = append;
	out[i + 1] = '\0';
	return out;
}

int		inmass(char symb, char *mass)
{
	int		i = 0;

	while (mass[i] != '\0')
	{
		if (symb == mass[i])
			return 1;
		i++;
	}
	return 0;
}

char	*unique(char *flags)
{
	char	*un = "";
	int		i = 0;

	while (flags[i] != '\0')
	{
		if (!inmass(flags[i], un))
			un = appendsymb(un, flags[i]);
		i++;
	}
	return un;
}

int		validate_flags(char *flags)
{
	char	*valid = (char*)LEGAL_OPTION;
	int		i = 0;

	while (flags[i] != '\0')
	{
		if (!inmass(flags[i], valid))
			{
				printf("illegal option:    %c\n", flags[i]);
				printf("you must use only: %s\n", valid);
				return 0;
			}
		i++;
	}
	return 1;
}

// int		main(int argc, char **argv)
// {
// 	parse_main(argc, argv);
// }
