#include "incl/header.h"

void files_main(struct t_option opt)
{
    files(opt);
}

void files(struct t_option opt)
{
    char            *filename = opt.path;
    char            *flags = opt.flag;
    DIR             *dfd;
    struct dirent   *dp;

    if ((dfd = opendir(filename))  == NULL)
    {
        printf("%s\n", filename);
        return ;
    }

    while ((dp = readdir(dfd)) != NULL)
    {
        if (dp->d_name[0] == '.' && inmass('a', flags))
			printf("%s ", dp->d_name);
        if (dp->d_name[0] != '.')
			printf("%s ", dp->d_name);
    }
    closedir(dfd);
    printf("\n");
}
