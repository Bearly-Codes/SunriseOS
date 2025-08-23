.extern irq_dispatcher
.extern excp_dispatcher
#include <arch/include/interrupts.h>

.macro EXCEPTION vec
        .globl istub\vec;
_istub##vec:
        pushal                                  
        pushl %esp                             
        pushl $\vec                               
        call excp_dispatcher                         
        addl $8, %esp;  Clear the args        
        popal                                   
        iret                                    
.endm



/* Exception handlers 0-47 */
EXCEPTION(0x00)
EXCEPTION(0x01)
EXCEPTION(0x02)
EXCEPTION(0x03)
EXCEPTION(0x04)
EXCEPTION(0x05)
EXCEPTION(0x06)
EXCEPTION(0x07)
EXCEPTION(0x08)
EXCEPTION(0x09)
EXCEPTION(0x0A)
EXCEPTION(0x0B)
EXCEPTION(0x0C)
EXCEPTION(0x0D)
EXCEPTION(0x0E)
EXCEPTION(0x0F)
EXCEPTION(0x10)
EXCEPTION(0x11)
EXCEPTION(0x12)
EXCEPTION(0x13)
EXCEPTION(0x14)
EXCEPTION(0x15)
EXCEPTION(0x16)
EXCEPTION(0x17)
EXCEPTION(0x18)
EXCEPTION(0x19)
EXCEPTION(0x1A)
EXCEPTION(0x1B)
EXCEPTION(0x1C)
EXCEPTION(0x1D)
EXCEPTION(0x1E)
EXCEPTION(0x1F)
EXCEPTION(0x20)
EXCEPTION(0x21)
EXCEPTION(0x22)
EXCEPTION(0x23)
EXCEPTION(0x24)
EXCEPTION(0x25)
EXCEPTION(0x26)
EXCEPTION(0x27)
EXCEPTION(0x28)
EXCEPTION(0x29)
EXCEPTION(0x2A)
EXCEPTION(0x2B)
EXCEPTION(0x2C)
EXCEPTION(0x2D)
EXCEPTION(0x2E)
EXCEPTION(0x2F)