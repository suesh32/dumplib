#include "dumplib.h"
#include <stdio.h>
#include <signal.h>

int testfunc1(char* str){
    snprintf(DUMP_AREA, DUMP_SIZE, "%s", str);
    
//    raise(SIGINT);
    abort();
    return 0;
}