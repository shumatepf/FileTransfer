EXE=ftransfer

OBJS=transfer.o main.o

CC=gcc
CFLAGS += -O2

default: $(EXE)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXE)

.PHONY: default install
