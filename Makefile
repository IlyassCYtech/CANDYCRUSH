CC = gcc

LIBS = -lncursesw

SRCS = main.c menu.c move.c printtab.c saves.c score.c Tab.c verif.c
OBJS = $(SRCS:.c=.o)
EXEC = candy

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC)  $(OBJS) -o $@ $(LIBS)

%.o: %.c
	$(CC)  -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
