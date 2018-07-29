# dumplib

This is dump area utility for light C lang users.

Usage
 - Include "dumplib.h" on your app.
 - Link libdumplib.so to your app.
   ```
   $ gcc -shared -fPIC -I<dir of dumplib.h> -L<dir of libdumplib.so> <app sources> -o <app name> -ldumplib
   ```
 - Save data to be dumped to DUMP_AREA by memcpy() or snprintf() etc...
 - When core dumped, then open the core file by gdb and see DUMP_AREA like following.
   You can see DUMP_AREA from that.
   ```
   ~/dumplib/test$ gdb ./dumptest core
   (gdb) x/10s DUMP_AREA
   0x7efbfe2df080 <DUMP_AREA>:	"hoge"
   0x7efbfe2df085 <DUMP_AREA+5>:	""
   0x7efbfe2df086 <DUMP_AREA+6>:	""
   0x7efbfe2df087 <DUMP_AREA+7>:	""
   0x7efbfe2df088 <DUMP_AREA+8>:	""
   0x7efbfe2df089 <DUMP_AREA+9>:	""
   0x7efbfe2df08a <DUMP_AREA+10>:	""
   0x7efbfe2df08b <DUMP_AREA+11>:	""
   0x7efbfe2df08c <DUMP_AREA+12>:	""
   0x7efbfe2df08d <DUMP_AREA+13>:	""
   (gdb) 
   ```
