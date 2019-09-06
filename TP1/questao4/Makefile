RM = rm -f
SRCSDIR = src/
INCLUDES = -I $(SRCSDIR)headers/
CC = @gcc
CFLAGS = -w -g
SRCS_ALGORITMOS = $(addsuffix .c, $(addprefix algoritmos/, heapsort quicksort))
SRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, helpers main) $(SRCS_ALGORITMOS))
OBJS = $(SRCS:.c=.o)
EXEC = main.exe

#########################
ifeq ($(VERBOSE), true)
	CFLAGS += -D VERBOSE
endif
ifeq ($(DEBUG), true)
	CFLAGS += -D DEBUG
endif
#########################

.PHONY: depend clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(EXEC)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

mostlyclean:
	@$(RM) $(OBJS)

generate:
	pipenv run scripts/generate_input.py $(N) B "__input.$(N)"
