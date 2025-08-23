#include <stdint.h>
#include <string.h>
#include <kernel/idt.h>
#include <kernel/interrupt.h>


extern void istub0(void), istub1(void), istub2(void), istub3(void), istub4(void), istub5(void), istub6(void), istub7(void),
            istub8(void), istub9(void), istub10(void), istub11(void), istub12(void), istub13(void), istub14(void), istub15(void),
            istub16(void), istub17(void), istub18(void), istub19(void), istub20(void), istub21(void), istub22(void), istub23(void),
            istub24(void), istub25(void), istub26(void), istub27(void), istub28(void), istub29(void), istub30(void), istub31(void),
            istub32(void);

#define IDT_MAX 256
#define INT_GATE 0x8E

static idt_entry_32_t idt[IDT_MAX];
static idt_ptr_t   idt_ptr;

static inline void idt_load(const idt_ptr_t *idt_ptr) {
    asm volatile("lidt %0" : : "m"(*idt_ptr));
}

void idt_init(void) {
    const uint16_t KERNEL_CS = 0x08; // Kernel code segment selector
    const uint8_t  KERNEL_INT = 0x8E; // Interrupt gate
    
    memset(idt, 0, sizeof(idt));
    
    idt_set_gate(0,  (uint32_t)istub0,  KERNEL_CS, INT_GATE);
    idt_set_gate(1,  (uint32_t)istub1,  KERNEL_CS, INT_GATE);
    idt_set_gate(2,  (uint32_t)istub2,  KERNEL_CS, INT_GATE);
    idt_set_gate(3,  (uint32_t)istub3,  KERNEL_CS, INT_GATE);
    idt_set_gate(4,  (uint32_t)istub4,  KERNEL_CS, INT_GATE);
    idt_set_gate(5,  (uint32_t)istub5,  KERNEL_CS, INT_GATE);
    idt_set_gate(6,  (uint32_t)istub6,  KERNEL_CS, INT_GATE);
    idt_set_gate(7,  (uint32_t)istub7,  KERNEL_CS, INT_GATE);
    idt_set_gate(8,  (uint32_t)istub8,  KERNEL_CS, INT_GATE);
    idt_set_gate(9,  (uint32_t)istub9,  KERNEL_CS, INT_GATE);
    idt_set_gate(10, (uint32_t)istub10, KERNEL_CS, INT_GATE);
    idt_set_gate(11, (uint32_t)istub11, KERNEL_CS, INT_GATE);
    idt_set_gate(12, (uint32_t)istub12, KERNEL_CS, INT_GATE);
    idt_set_gate(13, (uint32_t)istub13, KERNEL_CS, INT_GATE);
    idt_set_gate(14, (uint32_t)istub14, KERNEL_CS, INT_GATE);
    idt_set_gate(15, (uint32_t)istub15, KERNEL_CS, INT_GATE);
    idt_set_gate(16, (uint32_t)istub16, KERNEL_CS, INT_GATE);
    idt_set_gate(17, (uint32_t)istub17, KERNEL_CS, INT_GATE);
    idt_set_gate(18, (uint32_t)istub18, KERNEL_CS, INT_GATE);
    idt_set_gate(19, (uint32_t)istub19, KERNEL_CS, INT_GATE);
    idt_set_gate(20, (uint32_t)istub20, KERNEL_CS, INT_GATE);
    idt_set_gate(21, (uint32_t)istub21, KERNEL_CS, INT_GATE);
    idt_set_gate(22, (uint32_t)istub22, KERNEL_CS, INT_GATE);
    idt_set_gate(23, (uint32_t)istub23, KERNEL_CS, INT_GATE);
    idt_set_gate(24, (uint32_t)istub24, KERNEL_CS, INT_GATE);
    idt_set_gate(25, (uint32_t)istub25, KERNEL_CS, INT_GATE);
    idt_set_gate(26, (uint32_t)istub26, KERNEL_CS, INT_GATE);
    idt_set_gate(27, (uint32_t)istub27, KERNEL_CS, INT_GATE);
    idt_set_gate(28, (uint32_t)istub28, KERNEL_CS, INT_GATE);
    idt_set_gate(29, (uint32_t)istub29, KERNEL_CS, INT_GATE);
    idt_set_gate(30, (uint32_t)istub30, KERNEL_CS, INT_GATE);
    idt_set_gate(31, (uint32_t)istub31, KERNEL_CS, INT_GATE);
    idt_set_gate(32, (uint32_t)istub32, KERNEL_CS, INT_GATE);


    idt_ptr.base = (uint32_t)&idt;
    idt_ptr.limit = sizeof(idt) - 1;

    idt_load(&idt_ptr);

}


void idt_set_gate(uint8_t vec, uint32_t handler, uint16_t selector, uint8_t type_attr) {
    idt[vec].offset_1 = handler & 0xFFFF;
    idt[vec].offset_2 = (handler >> 16) & 0xFFFF;
    idt[vec].selector = selector;
    idt[vec].zero = 0;
    idt[vec].type_attr = type_attr;
}

