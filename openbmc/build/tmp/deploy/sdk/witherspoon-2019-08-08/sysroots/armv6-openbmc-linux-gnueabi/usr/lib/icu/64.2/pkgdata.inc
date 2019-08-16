GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.64.2
COMPILE=arm-openbmc-linux-gnueabi-gcc  -march=armv6 -marm -mtune=arm1176jz-s  -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_HAVE_STRTOD_L=1 -DU_HAVE_XLOCALE_H=0  -DU_ATTRIBUTE_DEPRECATED= -O2 -pipe -g -feliminate-unused-debug-types  -std=c11 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -c
LIBFLAGS=-I/usr/include -DPIC -fPIC
GENLIB=arm-openbmc-linux-gnueabi-gcc  -march=armv6 -marm -mtune=arm1176jz-s  -O2 -pipe -g -feliminate-unused-debug-types  -std=c11 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -Wl,-O1 -Wl,--hash-style=gnu   -shared -Wl,-Bsymbolic
LDICUDTFLAGS=
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=arm-openbmc-linux-gnueabi-gcc-ar
ARFLAGS=r
RANLIB=arm-openbmc-linux-gnueabi-gcc-ranlib
INSTALL_CMD=install -c
