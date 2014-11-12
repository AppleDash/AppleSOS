#include <core/k_print.h>

void putchar(unsigned c)
{
	int res;
	//asm ("syscall" : "=a" (res) : "a"(1), "D"(1), "S"(&c), "d"(1));
	asm ("int $0x80" : "=a" (res) : "a"(4), "b"(1), "c"(&c), "d"(1));
	return;
}

int main(void)
{
	printf("Hi.\n");
	printf("Numbers: %d %d %d\n", 1337, 9001, -5);
	printf("Strings: %s %s %s %s\n", "Fox", "penis", "is", "fun");
	printf("Pointer: %p\n", "lol");
	return 0;
}
