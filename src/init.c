#include <core/arg_list.h>
#include <core/k_print.h>

extern void arch_boot(void *arch_param);

void k_main(arg_list list, void *arch_param)
{
	int i = 0;

	printf("AppleSOS version %s [build %s]\n", KERN_VERSION, BUILD_ID);
	printf("Copyright 2014 AppleSOS Team.  Licensed under <license here>.\n");

	arch_boot(arch_param);

	for(; i < list.size; i++)
	{
		printf("Boot Parameter: %s = %s\n", list.param[i].name,
			list.param[i].value);
	}

	printf("Bye\n");

	while(true);

	/* NOTREACHED */
}

