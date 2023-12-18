/* skdet.c - main program */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int c;
    uid_t uid;
                                                                                                                                
    if(argc<=1) {
        usage(argv[0]);
        exit(1);
    }
    
    uid = getuid();
    if(uid != 0) {
	fprintf(stderr, "You need root to run this program (uid=%d).\n", uid);
	return 1;
    }
    			                                                                                                                                
    while((c = getopt (argc, argv, "hdvcsp:")) != EOF) {
        switch(c)
	{
	    case 'h':
	        usage(argv[0]);
	        break;
	    case 'd':
	        usage(argv[0]);
	        break;
	    case 'p':
	        pid_info(argv[2]);
	        break;
	    case 'c':
	        check_for_rootkit();
	        break;
	    case 's':
		port_scanner();
		break;
	    case 'v':
	        print_version();
	        break;
	    default:
	        usage(argv[0]);
	}
    }
    return 0;
}

