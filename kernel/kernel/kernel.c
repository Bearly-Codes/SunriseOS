#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/startscreen.h>
#include <kernel/idt.h>

void kernel_main(void) {
	terminal_initialize();
	idt_init();
	print_start_screen();
	asm volatile("int $0x20");
	while (1) {
		asm volatile("hlt");
	}
}
