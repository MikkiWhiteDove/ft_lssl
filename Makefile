all:
	@rm -rf ft_ls
	@gcc files.c main.c parse.c -I incl -o ft_ls

hard:
	@rm -rf ft_ls
	@gcc -Wall -Werror -Wextra files.c main.c parse.c -I incl -o ft_ls
