CPP    = g++
RM     = rm -f
OBJS   = main.o

LIBS   =
CFLAGS =

.PHONY: contato.exe clean clean-after

all: contato.exe

clean:
	$(RM) $(OBJS) contato.exe

clean-after:
	$(RM) $(OBJS)

contato.exe: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

main.o: main.cpp
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

