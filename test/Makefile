TESTLIB	=libdumptest.so
TARGET	=dumptest

INCLUDES += -I../src -I.
CFLAGS	+= -g $(INCLUDES)
LIBFLAGS +=  -shared -fPIC -L../src -Wl,-z,defs
LDFLAGS	+= 
TESTEE_SRC	= ../src/*.h ../src/*.c
LIBSRC	= testlib.c


all: $(TARGET)

$(TARGET): $(TESTLIB) test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test.c -ldl

$(TESTLIB): $(TESTEE_SRC) $(LIBSRC)
	$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ $(LIBSRC) -ldumplib

test: $(TARGET)
	./test.sh

clean:
	-rm $(TESTLIB) $(TARGET) core* test.dmp
