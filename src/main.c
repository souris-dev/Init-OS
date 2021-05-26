//////////////////////////////////////////
// File: main.c - kernel entry point
/////////////////////////////////////////

#include "monitor.h"
#include "descriptor_tables.h"
#include "multiboot.h"
#include "colors.h"
#include "misc.h"

int cmain(struct multiboot *mboot_ptr)
{
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();

    struct colors Color;
    struct Positions pos ;
    // Initialise the screen (by clearing it)
    monitor_clear();
    pos.x=0;
    pos.y=0;
    Color.bgcolor=8;
    Color.fgcolor=14;
    monitor_setBG();
    // Write out a sample string
    monitor_write("Welcome to Aplenite OS!\n",Color.bgcolor,Color.fgcolor, pos.x,pos.y);
    pos.x=0;
    pos.y=1;
    monitor_write("\nType in 'help' for a list of commands, and 'about'\nfor version info.\n\n",Color.bgcolor,Color.fgcolor, pos.x,pos.y);
    
    // execute some asm statements (instructiosns)
    __asm volatile("int $0x3");
    __asm volatile("int $0x4");

    return 0;
}

int cmain2(struct multiboot *mboot_ptr)
{   
    /*if (mboot_ptr. != MULTIBOOT_HEADER_MAGIC)
    {
      printf ("Invalid magic number: 0x%x\n", (unsigned) magic);
      return;
    }*/
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    struct colors Color;
    struct Positions pos ;
    pos.x=0;
    pos.y=0;
    Color.bgcolor=13;
    Color.fgcolor=15;
    monitor_clear();
    monitor_setBG();
    // Initialise the screen (by clearing it)
    // Write out a sample string
    monitor_write("Welcome to Init OS!\n", Color.bgcolor, Color.fgcolor, pos.x, pos.y);
    pos.x=0;
    pos.y=2;
    monitor_write("\nType in 'help' for a list of commands, and 'about'\nfor version info.\n\n", Color.bgcolor, Color.fgcolor, pos.x, pos.y);
    
    //char inp;
    //inp = get_char_ascii();

    // execute some asm statements (instructiosns)
    //__asm volatile("int $0x3");
    //__asm volatile("int $0x4");

    return 0;
}
