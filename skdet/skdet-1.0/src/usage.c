/* usage.c - print usage information */

#include <stdio.h>
#include "../include/skdet.h"

void usage(char *prog)
{
    fprintf(stderr, "usage: %s [options] <pid>\n", prog);
    fprintf(stderr, "options:\n");
    fprintf(stderr, "  -c       - check for rootkits\n");
    fprintf(stderr, "  -p <pid> - show the status file for specified pid\n");
    fprintf(stderr, "  -s       - scan localhost (show open ports)\n");
    fprintf(stderr, "  -v       - print the version of the program\n\n");
    exit(1);
}
