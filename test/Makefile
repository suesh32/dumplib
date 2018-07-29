TESTLIB	=libdumptest.so
TARGET	=dumptest

INCLUDES += -I../src -I.
CFLAGS	+= -g $(INCLUDES)
LIBFLAGS +=  -shared -fPIC -L../src -ldumplib -Wl,-z,defs
LDFLAGS	+= 
TESTEE_SRC	= ../src/*.h ../src/*.c
LIBSRC	= testlib.c


all: $(TARGET)

$(TARGET): $(TESTLIB) test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ test.c -ldl

$(TESTLIB): $(TESTEE_SRC) $(LIBSRC)
	$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ $(LIBSRC) -ldumplib

test: $(TARGET)
	LD_LIBRARY_PATH=../src:. ./$(TARGET)

clean:
	-rm $(TESTLIB) $(TARGET)
