#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/sunrise.kernel isodir/boot/sunrise.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "sunrise" {
	multiboot /boot/sunrise.kernel
}
EOF
grub-mkrescue -o sunrise.iso isodir
