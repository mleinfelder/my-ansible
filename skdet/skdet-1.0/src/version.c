/* version.c - print program version */

#include <stdio.h>
#include "../include/skdet.h"

int print_version()
{
    fprintf(stdout, "\nskdet v%s\n", VERSION);
    fprintf(stdout, "coded by: %s\n", AUTHOR);
    fprintf(stdout, "contact: %s\n\n", EMAIL);
    return 0;
}

