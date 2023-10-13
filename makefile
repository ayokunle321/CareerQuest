CC = gcc
CFLAGS = -Wall -std=c99

SRCDIR = ./  
BUCKETSTACKDIR = ./bucketstack
SQUEUEDIR = ./stackqueue

all: career_quest

career_quest: main.o bucketstack.o squeue.o
	$(CC) $(CFLAGS) -o career_quest $(SRCDIR)/main.o $(BUCKETSTACKDIR)/bucketstack.o $(SQUEUEDIR)/squeue.o

main.o: $(SRCDIR)/main.c $(SQUEUEDIR)/squeue.h $(BUCKETSTACKDIR)/bucketstack.h
	$(CC) $(CFLAGS) -c -o $(SRCDIR)/main.o $(SRCDIR)/main.c

squeue.o: $(SQUEUEDIR)/squeue.c $(SQUEUEDIR)/squeue.h
	$(CC) $(CFLAGS) -c -o $(SQUEUEDIR)/squeue.o $(SQUEUEDIR)/squeue.c

bucketstack.o: $(BUCKETSTACKDIR)/bucketstack.c $(BUCKETSTACKDIR)/bucketstack.h
	$(CC) $(CFLAGS) -c -o $(BUCKETSTACKDIR)/bucketstack.o $(BUCKETSTACKDIR)/bucketstack.c

clean:
	rm -f $(SRCDIR)/*.o career_quest





