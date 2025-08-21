#include <stdio.h>

#include <kernel/tty.h>

void print_start_screen(void) {
	terminal_writestring("Welcome to the Kernel!\n");
	terminal_writestring("Initializing...\n");
}
