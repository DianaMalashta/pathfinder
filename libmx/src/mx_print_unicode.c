#include "libmx.h"

void mx_print_unicode(wchar_t c){
    char utf8[4];
    int len = 0;
    
    if (c < 0x80) {
        utf8[0] = (char)c;
        len = 1;
    }
    else if (c < 0x800) {
        utf8[0] = (char)((c >> 6) | 0xC0);
        utf8[1] = (char)((c & 0x3F) | 0x80);
        len = 2;
    }
    else if (c < 0x10000) {
        utf8[0] = (char)((c >> 12) | 0xE0);
        utf8[1] = (char)(((c>> 6) & 0x3F) | 0x80);
        utf8[2] = (char)((c & 0x3F) | 0x80);
        len = 3;
    }
    else if (c <= 0x10FFFF) {
        utf8[0] = (char)((c >> 18) | 0xF0);
        utf8[1] = (char)(((c >> 12) & 0x3F) | 0x80);
        utf8[2] = (char)(((c >> 6) & 0x3F) | 0x80);
        utf8[3] = (char)((c & 0x3F) | 0x80);
        len = 4;
    }
    
    write(1, utf8, len);
}

