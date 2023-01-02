SRCS=$$(ls *.c)
LIBS=$$(pkg-config --libs x11 --libs xt)
BIN=x11-ssh-askpass

all:
	clang $(LIBS) $(SRCS) -o $(BIN)

clean:
	rm -f $(BIN)
