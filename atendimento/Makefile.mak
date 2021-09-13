CPP    = g++
RM     = rm -f
OBJS   = main.o

LIBS   =
CFLAGS =

.PHONY: atendimento.exe clean clean-after

all: atendimento.exe

clean:
	$(RM) $(OBJS) atendimento.exe

clean-after:
	$(RM) $(OBJS)

atendimento.exe: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

main.o: main.cpp
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

