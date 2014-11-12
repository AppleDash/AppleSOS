#define assert(x)

unsigned long strlen(const char *str)
{
	unsigned long count;

	assert(str != 0);

	while(*str++) count++;
	return count;
}
