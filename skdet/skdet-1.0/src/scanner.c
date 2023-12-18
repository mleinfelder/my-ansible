/* scanner.c - simple localhost portscanner...we don't need any signals(SIGINT) or alars since
   the scanned host is localhost */
   
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int port_scanner()
{
    int sock, ports;
    unsigned short int port;
    struct sockaddr_in local_addr;
    
    ports = 0;
    
    printf("open ports on localhost (127.0.0.1)\n");
    
    for(port = 0; port < 65535; port ++) {        
	sock =socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0) {
	    fprintf(stderr, "error: can't allocate socket\n");
	    return 1;
	}
    
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(port);
	local_addr.sin_addr.s_addr = INADDR_ANY;
    
	if((connect(sock, (struct sockaddr *)&local_addr, sizeof(local_addr))) == 0) {
	    fprintf(stdout, "%u      \topen \t\n", port);
	    ports++;
	}
	close(sock);
    }
    
    fprintf(stdout, "scan completed (%d open ports)\n", ports);
    
    return 0;
}

