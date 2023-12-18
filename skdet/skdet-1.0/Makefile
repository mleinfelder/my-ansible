CC=gcc
LD=$(CC)
CFLAGS= -O2 -pipe
STRIP=strip
SRC=src
BINARY=skdet

all: $(BINARY)

$(BINARY):
	$(CC) $(CFLAGS) -c $(SRC)/det-rootkit.c -o det-rootkit.o
	$(CC) $(CFLAGS) -c $(SRC)/pid-info.c -o pid-info.o
	$(CC) $(CFLAGS) -c $(SRC)/scanner.c -o scanner.o
	$(CC) $(CFLAGS) -c $(SRC)/skdet.c -o skdet.o
	$(CC) $(CFLAGS) -c $(SRC)/usage.c -o usage.o
	$(CC) $(CFLAGS) -c $(SRC)/version.c -o version.o
	$(LD) $(CFLAGS) det-rootkit.o pid-info.o scanner.o skdet.o usage.o version.o -o $(BINARY)
	@rm -rf det-rootkit.o pid-info.o scanner.o skdet.o usage.o version.o
	@$(STRIP) $(BINARY)
    
clean:
	rm -rf $(BINARY) 
