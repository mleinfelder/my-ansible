/* det-rootkit.c - check if a rootkit is installed (hidden process) 
    
   tested rootkits:
	SucKIT v0.3b
	adore 0.53
	adore-ng 0.24
	t0rnkit v8
	t0rnkit v9
	bobKIT
	shv4
	
    all rootkits that use fake ps and pstree are detected. */

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include "../include/skdet.h"

int check_for_rootkit()
{
    pid_t pid;
    char proc[100];
    char *p_name;
    FILE *status;
		                                                                                                                                
    p_name = proc;
    for(pid=1; pid<=MAX_PIDS; pid++) {
        memset(proc, 0, sizeof(proc));
        snprintf(proc, sizeof(proc), "/proc/%d/status", pid);
        errno = 0;
        getpriority(PRIO_PROCESS, pid);
        if(!errno) {
            printf("%d\t", pid);
            if((status = fopen(proc, "r")) != NULL) {
                fread(proc, sizeof(proc), 1, status);
                if((strlen(proc)) <= 8) {
                    continue;
                    fclose(status);
                }
                p_name = strstr(proc, "Name");
                *index(p_name, '\n') = '\0';
                p_name +=5;
                fclose(status);
                printf("\b\b\b\b\b%s\n", p_name);
            }
            else {
                printf("[invisible]\n");
            }
	}
    }
    return 0;
}

