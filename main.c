#include "incl/header.h"

int main(int argc, char **argv)
{
	struct t_option opt = parse_main(argc, argv);
	if (opt.success == 0)
		return 0;
	files_main(opt);
	return 0;
}
