TARGET=libdumplib.so

CFLAGS	+= -g -D_POSIX_C_SOURCE=200809L
LDFLAGS	+= -shared -fPIC 

$(TARGET): *.h *.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	-rm $(TARGET)
