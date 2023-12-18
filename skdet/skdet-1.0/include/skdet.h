/* skdet.h - definions and functions */

#define MAX_PIDS 0x8000

#define VERSION "1.0"
#define AUTHOR "slider"
#define EMAIL "slider@decebal.org"

void usage(char *prog);
int check_for_rootkit();
int pid_info(char *pid);
int print_version();
int port_scanner();
