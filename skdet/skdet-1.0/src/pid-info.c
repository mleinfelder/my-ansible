/* pid-info.c - prints /proc/pid */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int pid_info(char *pid)
{
    char file[33];
    char *line;
    FILE *status;
	                                                                                                                                
    if((line = malloc(sizeof(char)*256)) == NULL) {
        perror("malloc");
        return 1;
    }
				                                                                                                                                
    snprintf(file, 33, "/proc/%s/status", pid);
    if((status = fopen(file, "r")) == NULL) {
        fprintf(stderr, "error: pid %s does not exist or is hidden\n", pid);
        return 1;
    }
								                                                                                                                            
    while((fgets(line, 256, status)) != NULL)
        fprintf(stdout, "%s", line);
    return 0;
}

