#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/radon.kernel isodir/boot/radon.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "radon" {
	multiboot /boot/radon.kernel
}
EOF
grub-mkrescue -o radon.iso isodir
