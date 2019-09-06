RM = rm -f
SRCSDIR = src/
INCLUDES = -I $(SRCSDIR)headers/
CC = @gcc
CFLAGS = -w -g
SRCS_ALGORITMOS = $(addsuffix .c, $(addprefix algoritmos/, heapsort quicksort))
SRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, helpers main) $(SRCS_ALGORITMOS))
OBJS = $(SRCS:.c=.o)
EXEC = main.exe
EXEC_DEBUG = main_with_debug.exe

#########################
ifeq ($(VERBOSE), true)
	CFLAGS += -D VERBOSE
endif
ifeq ($(DEBUG), true)
	CFLAGS += -D DEBUG
	EXEC = $(EXEC_DEBUG)
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
	pipenv run scripts/generate_input.py $(N) $(SCENARIO) "__input.$(N)"

check:
	bash scripts/run_and_validate.sh $(ALGORITHM) $(N) "$(INPUT)"
	@$(RM) $(EXEC_DEBUG)
