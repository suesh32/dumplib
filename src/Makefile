TARGET=libdumplib.so

CFLAGS	+= -g
LDFLAGS	+= -shared -fPIC 

$(TARGET): *.h *.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	-rm $(TARGET)