#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int (*fp_testfunc1)(char*);

int main(int argc, char* argv[]){
    void* handle = dlopen("libdumptest.so", RTLD_LAZY);
    if (NULL==handle){
        printf("%s\n", dlerror());
        return 1;
    }
    fp_testfunc1 = dlsym(handle, "testfunc1");
    if (NULL==fp_testfunc1){
        printf("%s\n", dlerror());
        return 1;
    }

    fp_testfunc1("hoge");

    return 0;
}