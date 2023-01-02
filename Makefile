SRCS=$$(ls *.c)
LIBS=$$(pkg-config --libs x11 --libs xt --libs xft)
CFLAGS=$$(pkg-config --cflags freetype2)
BIN=x11-ssh-askpass

all:
	clang $(CFLAGS) $(LIBS) $(SRCS) -o $(BIN)

clean:
	rm -f $(BIN)
