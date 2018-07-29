#!/bin/bash
export LD_LIBRARY_PATH=../src:.
./dumptest

gdb ./dumptest core <<EOS > test.dmp 2>&1
x/10s DUMP_AREA
q
EOS

diff test.dmp test.dmp.org
