#!/bin/sh
set -e
<<<<<<< Updated upstream
. radon-kernel/build/headers.sh
=======
. ./headers.sh
>>>>>>> Stashed changes

for PROJECT in $PROJECTS; do
  (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done
