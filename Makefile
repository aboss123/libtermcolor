CFLAGS   += -Isrc -fPIC
WARNINGS += -Wall -Wextra

ifneq( ${BUILD_ON_WINDOWS}, 1)
SRC      := $(shell find src -type f -name '*.c')
else
SRC      := $(shell dir src *.c /b/s)
endif
OBJ      := ${SRC:.c=.o}
PRG      := libtermcolor

ifeq ($(shell uname), Darwin)
AR = /usr/bin/libtool
AR_OPT = -static $^ -o $@
else
AR = ar
AR_OPT = rcs $@ $^
endif

CFLAGS += ${WARNINGS}

all: static dynamic demo

.PHONY:  static dynamic
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
