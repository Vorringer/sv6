set architecture i386:x86-64
target remote localhost:1234
symbol-file o.qemu/kernel.elf
br panic
br kerneltrap
set auto-load safe-path /
source tools/xv6-gdb.py
