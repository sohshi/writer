CC		= gcc

CFLAGS		= `pkg-config --cflags gtk+-2.0`

LDFLAGS		= `pkg-config --libs-only-L gtk+-2.0`

LIBS		= `pkg-config --libs-only-l gtk+-2.0`

SRCS		= writer.c

OBJS		= $(SRCS:.c=.o)

PROGRAM		= writer

all:		$(PROGRAM)

$(PROGRAM):	$(OBJS) $(HDRS) 
		$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;		rm -f *.o *~ $(PROGRAM)

###                                                         End of Makefile
