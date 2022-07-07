SRC:=coverity_test.c

all:	gcc clang coverity

gcc:
	gcc -fanalyzer -Wall -Wextra -pedantic -fanalyser ${SRC}

clang:
	scan-build-10 gcc -fanalyzer -Wall -Wextra -pedantic -fanalyser ${SRC}

coverity:
	cov-build --dir idir gcc -c ${SRC}
	cov-analyse --dir idir --all -aggressiveness-level high gcc -c ${SRC}
	cov-format-errors --dir idir -x --html-output html
