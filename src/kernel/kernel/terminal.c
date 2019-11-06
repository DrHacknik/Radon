#include <stdio.h>

#include <kernel/term.h>

void terminal_main(void) {
	terminal_initialize();
	printf(">");
}
