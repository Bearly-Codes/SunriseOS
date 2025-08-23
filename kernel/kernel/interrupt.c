#define TRAPS 16
#define CPU_EXCP 32
#include <stdint.h>
#include <stdio.h>


void excp_dispatcher(uint32_t num, uint32_t *stk) {
    
    // Currently ignoring hardware interrupts
    if (num < CPU_EXCP) {
        

        printf("Trap %d\n", num);
        if (num < TRAPS) {
            printf("%s\n", trap_names[num]);
        }

        while(1) {
            __asm__ volatile("hlt");
        }
    }
}


char *trap_names[TRAPS] =
{
    "divide by zero",
    "debug exception",
    "non-maskable interrupt",
    "breakpoint",
    "overflow",
    "bounds check failure",
    "invalid opcode",
    "coprocessor not available",
    "double fault",
    "coprocessor segment overrun",
    "invalid TSS",
    "segment not present",
    "stack fault",
    "general protection violation",
    "page fault",
    "coprocessor error",
    "floating point exception",
    "alignment check",
    "machine check",
};

