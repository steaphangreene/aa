CC=     gcc -O3
CFLAGS=	`../user/U2-CFlags`
USER=	/usr/local/include/user
ALL=    Makefile
LIBS=	`../user/U2-Libs`

aa:	aa.o alien.o death.o $(ALL)
	$(CC) $(CFLAGS) -o aa aa.o alien.o death.o $(LIBS)

aa.o:	aa.cpp alien.h $(DEPH)
	$(CC) $(CFLAGS) -c aa.cpp
	
alien.o:	alien.cpp alien.h $(DEPH)
	$(CC) $(CFLAGS) -c alien.cpp
	
death.o:	death.cpp
	$(CC) $(CFLAGS) -c death.cpp
