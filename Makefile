CC := gcc
SRCFOLDER := src
BUILDFOLDER := build
SRCFILE := $(wildcard ${SRCFOLDER}/*.c)
OBJECTFILE := $(patsubst ${SRCFOLDER}/%.c,${BUILDFOLDER}/%.o,${SRCFILE})
CFLAGS := -g -Wall -std=c11

PHONY: all clean main
all: clean main
main: ${BUILDFOLDER}/main
${BUILDFOLDER}/main: ${OBJECTFILE}
	${CC} ${CFLAGS} -o $@ $^
${BUILDFOLDER}/%.o: ${SRCFOLDER}/%.c
	${CC} ${CFLAGS} -c -o $@ $<
clean:
	rm -rf ${BUILDFOLDER}
	mkdir ${BUILDFOLDER}