SRCS=$$(ls *.c)
LIBS=$$(pkg-config --libs x11 --libs xt --libs xft)
CFLAGS=$$(pkg-config --cflags freetype2)
BIN=x11-ssh-askpass
MAN=x11-ssh-askpass.1
INSDIR=/usr/local/bin
MANDIR=/usr/share/man/man1

all:
	clang $(CFLAGS) $(LIBS) $(SRCS) -o $(BIN)

clean:
	rm -f $(BIN)

install:
	install -D $(BIN) $(INSDIR)
	install -D $(MAN) $(MANDIR)

uninstall:
	rm -f $(INSDIR)/$(BIN)
	rm -f $(MANDIR)/$(MAN)

.PHONY: all
.PHONY: clean
.PHONY: install
.PHONY: uninstall
