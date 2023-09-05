CC = c++
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
NAME = snake

FILE =  main utils game snake food


SRCS = $(addsuffix .cpp, $(FILE))
OBJS = $(addsuffix .o, $(FILE))

%.o : %.cpp 
	@$(CC) $(CPPFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	${CC} $(OBJS)  ${CFLAGS} -o $(NAME)

clean:
	rm -rf $(NAME) $(OBJS)