CFLAGS   += -Isrc -fPIC
WARNINGS += -Wall -Wextra

SRC      := $(shell find src -type f -name '*.c')
OBJ      := ${SRC:.c=.o}
PRG      := libtermcolor

ifeq ($(shell uname), Darwin)
AR = /usr/bin/libtool
AR_OPT = -static $^ -o $@
else
AR = ar
AR_OPT = rcs $@ $^
endif

ifeq (${BUILD_ON_WINDOWS}, 1)
$(info building libtermcolor on windows
CFLAGS  += -Wl,--export-all-symbols
LDFLAGS += -static -Wl,--export-all-symbols -Wl,--out-implib=lib${PRG}.dll.a
endif

CFLAGS += ${WARNINGS}

all: dynamic demo

.PHONY:  static dynamic
.PHONY:  static
static:  ${PRG}.a
dynamic: ${PRG}.so

${PRG}.a: ${OBJ}
	${AR} ${AR_OPT}

${PRG}.so: ${OBJ}
	${CC} -shared $< -o $@

demo: ${PRG}.a
	${CC} ${CFLAGS} main.c $< -o demo

.c.o:
	${CC} ${CFLAGS} $< -c -o ${<:.c=.o}

clean:
	rm -rf ${PRG}.a ${PRG}.so ${OBJ}
