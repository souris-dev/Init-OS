#include "misc.h"

char get_char_ascii() {
    char ascii_code;
    read_char();
    __asm volatile("movb %%al, %0" : "=r" (ascii_code));
}

char get_char_bios_scan_code() {
    char bios_scan_code;
    read_char();
    __asm volatile("movb %%ah, %0" : "=r" (bios_scan_code));
}
