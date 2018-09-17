destdir = ./bin
dest_PROGRAMS = pwn-sandbox
pwn_sandbox_SOURCES = src/main.c \
                       src/protect.c \
                       src/utils.c \
                       src/*.h

EXTRA_DIST = analyser.py

README: README.md
	cp README.md README
dist: README
