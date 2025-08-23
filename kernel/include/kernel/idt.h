#pragma once
#include <stdint.h>

typedef struct  {
    uint16_t offset_1; // Handler [15:0]
    uint16_t selector; // Code segment selector
    uint8_t zero; // Reserved, must be zero
    uint8_t type_attr;  // Gate type, dpl, and p
    uint16_t offset_2; // Handler [31:16]


} __attribute__((packed)) idt_entry_32_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void idt_init(void);
void idt_set_gate(uint8_t vec, uint32_t handler, uint16_t selector, uint8_t type_attr);