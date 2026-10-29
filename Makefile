CC = gcc
CFLAGS = -Iinclude 
LDFLAGS = -lssl -lcrypto -lm -lreadline -lcurl

TARGET = keylyzer

SRCS = src/main.c \
       src/define.c \
	   src/keytester.c \
	   src/network.c 
       

PREFIX ?= /usr

all:
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

	mkdir -p $(DESTDIR)/usr/share/apkx-hunter
	install -m644 assets/model.bin $(DESTDIR)/usr/share/apkx-hunter/model.bin 2>/dev/null || true

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	rm -f $(DESTDIR)/usr/share/apkx-hunter/model.bin

.PHONY: all clean install uninstall
