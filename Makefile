CC = gcc
CFLGS = -g -Wall
SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR = bin
BIN = $(BINDIR)/myapp
FILEPATH = .

shared: libstdgb.so
test: $(BIN)

libstdgb.so: $(OBJS)
	$(CC) $^ -shared -o $@


$(BIN): $(OBJS) libstdgb.so
	echo $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -Wl,-rpath,$(FILEPATH) -L$(FILEPATH) -lstdgb


$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLGS) -c $^ -o $@ -fPIC

clean:
	rm -f bin/* $(OBJ)/* *.so