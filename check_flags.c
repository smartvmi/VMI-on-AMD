#include <stdio.h>
#include <stdint.h>

#define X86_EFLAGS_TF (1 << 8)

int main()
{
	uint64_t eflags = 0;

	fprintf(stdout, "Press any key to start!\n");
	getchar();

	__asm__ volatile("int $0x03");
	eflags = __builtin_ia32_readeflags_u64();
	__asm__ volatile("int $0x03");

	fprintf(stdout, "X86_EFLAGS_TF: %lu\n", !!(eflags & X86_EFLAGS_TF));

	return 0;
}
