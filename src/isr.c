/********************************************************/
// File: isr.c - High level interrupt service routines 
//               and interrupt request handlers
/********************************************************/

#include "common.h"
#include "isr.h"
#include "monitor.h"
#include "colors.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
    struct colors Color;
    struct Positions pos ;
    pos.x=0;
    pos.y=0;
    Color.bgcolor=8;
    Color.fgcolor=14;
    monitor_write("recieved interrupt: ", Color.bgcolor, Color.fgcolor, pos.x, pos.y);
    monitor_write_dec(regs.int_no, Color.bgcolor, Color.fgcolor, pos.x, pos.y);
    monitor_put('\n', Color.bgcolor, Color.fgcolor, pos.x, pos.y);
}
