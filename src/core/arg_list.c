#include <core/arg_list.h>

#define LOOKING_FOR_ANYTHING 0
#define READING_KEY 1
#define LOOKING_FOR_VALUE 2
#define READING_VALUE 3

#define isalnum(c) (c > 0x20 && c < 0x80)

arg_list make_arg_list(const unsigned char *the_string)
{
	arg_list list;
	int i = 0, curpos = 0;
	char state = LOOKING_FOR_ANYTHING;

	for(; *the_string; the_string++)
	{
		switch(state)
		{
		case LOOKING_FOR_ANYTHING:
		{
			if(!isalnum(*the_string))
				continue;
			state = READING_KEY;
		}
		case READING_KEY:
		{
			if(isalnum(*the_string))
			{
				if(*the_string == '=')
				{
					list.param[i].name[curpos++] = '\0';
					curpos = 0;
					state = LOOKING_FOR_VALUE;
				} else {
					list.param[i].name[curpos++] = *the_string;
				}
				continue;
			} else {
				curpos = 0;
				state = LOOKING_FOR_VALUE;
			}
		}
		case LOOKING_FOR_VALUE:
		{
			if(*the_string == ' ')
			{
				list.param[i].value[0] = 't';
				list.param[i].value[1] = 'r';
				list.param[i].value[2] = 'u';
				list.param[i].value[3] = 'e';
				list.param[i].value[4] = '\0';	// XXX TODO DEFAULT
				i++;
				curpos = 0;
				
				state = LOOKING_FOR_ANYTHING;
				continue;
			} else if(isalnum(*the_string)) {
				state = READING_VALUE;
			} else {
				continue;
			}
		}
		case READING_VALUE:
		{
			if(isalnum(*the_string))
			{
				list.param[i].value[curpos++] = *the_string;
			} else {
				list.param[i].value[curpos++] = '\0';
				i++;
				curpos = 0;
				state = LOOKING_FOR_ANYTHING;
			}
			continue;
		}
		}
	}
	
	list.param[i].value[curpos] = '\0';
	list.size = ++i;
	
	return list;
}
