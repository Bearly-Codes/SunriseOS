#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/startscreen.h>

void kernel_main(void) {
	terminal_initialize();
	print_start_screen();
}
