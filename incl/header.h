#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>

# define NAME_MAX 256
# define LEGAL_OPTION "a"
# define DEBUG 0 			// set '1' if you want see messages

/* struct parse arg */
struct		t_option
{
	char	*flag;
	char	*path;
	int		success;
};

/* parse.c */
struct t_option	parse_main(int argc, char **argv);
char			*parse_arg(char *arg, char *flags);
char			*massjoin(char *base, char *append);
char			*appendsymb(char *base, char append);
int				inmass(char symb, char *mass);
char			*unique(char *flags);
int				validate_flags(char *flags);

/* files.c */
void			files_main(struct t_option opt);
void			files(struct t_option opt);

#endif