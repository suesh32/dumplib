#include "dumplib.h"
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

//extern int DUMP_SIZE;
char DUMP_AREA[DUMP_SIZE+1] = {0};
//char *DUMP_AREA=NULL;
#define ERROR_MESSAGE_SIZE  1024
char error_message[ERROR_MESSAGE_SIZE]={0};

void dump(int sign){
    write(STDOUT_FILENO, DUMP_AREA, DUMP_SIZE);
}

__attribute__((constructor)) void constructor(void) {
    // DUMP_AREA = (char*)malloc(DUMP_SIZE+1);
    // if (NULL==DUMP_AREA){
    //     abort();
    // }
    memset(DUMP_AREA, 0, DUMP_SIZE+1);

    struct sigaction oldact;
    struct sigaction act = {0};
    act.sa_handler = &dump;
    int rtn = sigaction(SIGINT, &act, &oldact);
    if (-1==rtn){
        strerror_r(errno, error_message, ERROR_MESSAGE_SIZE-1);
        write(STDERR_FILENO, error_message, ERROR_MESSAGE_SIZE);
        abort();
    }
}

__attribute__((destructor)) void destructor(void) {
}

