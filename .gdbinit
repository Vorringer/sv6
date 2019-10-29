set architecture i386:x86-64
target remote localhost:8889
symbol-file o.josmp/kernel.elf
br panic
br kerneltrap
set auto-load safe-path /
source tools/xv6-gdb.py
