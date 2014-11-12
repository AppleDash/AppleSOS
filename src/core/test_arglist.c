#include <stdio.h>
#include "arg_list.h"

int main(int argc, char *argv[])
{
	arg_list list = make_arg_list(argv[1]);
	
	for(int i = 0; i < list.size; i++)
	{
		printf("%s = %s\n", list.param[i].name, list.param[i].value);
	};

	return 0;
}
