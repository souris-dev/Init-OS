// bios_ints.h
// has functions that use BIOS interrupts
// and miscellaneous functions

extern void read_char();
extern void set_text_atrributes();

char get_char_ascii();
char get_char_bios_scan_code();
