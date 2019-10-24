#!/bin/sh

sudo ../QEMU/x86_64-softmmu/qemu-system-x86_64 -smp 8 -m 10G -serial mon:stdio -nographic -enable-kvm -machine kernel-irqchip=off -cpu host -kernel o.josmp/kernel.elf -local-cpu 4,start=0,iplist="172.16.0.1 172.16.0.1" & > /dev/null
sleep 2
sudo ../QEMU/x86_64-softmmu/qemu-system-x86_64 -smp 8 -m 10G -serial mon:stdio -nographic -enable-kvm -machine kernel-irqchip=off -cpu host -kernel o.josmp/kernel.elf -local-cpu 4,start=0,iplist="172.16.0.1 172.16.0.1"

stty echo
