#include "termcolor.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
    int result = tcol_printf("{+}{R}H{G}e{Y}l{C}l{M}o{W}, {G}w{C}o{R}r{B}l{W}d{Y}!{0}\n");
    if (result != TermColorErrorNone) {
        printf("error: %s\n", tcol_errorstr(result));
        return 1;
    }

    char buffer[128];
    result = tcol_snprintf(buffer, 128, "{*}Blink{0}\n");
    if (result != TermColorErrorNone) {
        printf("error: %s\n", tcol_errorstr(result));
        return 1;
    } else {
        printf(buffer);
    }
    return 0;
}
