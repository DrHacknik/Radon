#include <stdio.h>

#include <kernel/term.h>

void kernel_main(void) {
	terminal_initialize();
	printf(">\n");
}