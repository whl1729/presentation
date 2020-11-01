CC = gcc
CFLAGS = -g
PROGS = naughty_proc divide_zero null_ptr double_free big_stack many_fork

all: clean $(PROGS)

$(PROGS):
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -rf $(PROGS) *.o a.out core
