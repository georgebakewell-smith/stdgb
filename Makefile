CC = gcc
CFLGS = -g -Wall
SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR = bin
TESTDIR = test
TEST = $(TESTDIR)/main.c
BIN = $(BINDIR)/main
FILEPATH = .

shared: libstdgb.so
test: $(BIN)

libstdgb.so: $(OBJS)
	$(CC) $^ -shared -o $@


$(BIN): $(OBJS) $(TEST) libstdgb.so
	$(CC) $(CFLAGS) $(OBJS) $(TEST) -o $@ -Wl,-rpath,$(FILEPATH) -L$(FILEPATH) -lstdgb


$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLGS) -c $^ -o $@ -fPIC

clean:
	rm -f bin/* $(OBJ)/* *.so