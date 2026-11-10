CC      = gcc
CFLAGS  = -Wall -Wextra -Wno-unused-result -std=c11 -O2

.PHONY: all run clean

all:
	@mkdir -p bin
	@for f in practical_*/*.c; do \
	  n=$$(basename $$f .c); \
	  $(CC) $(CFLAGS) $$f -o bin/$$n || exit 1; \
	  echo "built bin/$$n"; \
	done

# regenerate every output.txt from its input.txt
run: all
	@for d in practical_*; do \
	  n=$$(basename $$d/*.c .c); \
	  (cd $$d && ../bin/$$n < input.txt > output.txt); \
	  echo "ran $$d"; \
	done

clean:
	rm -rf bin practical_15_sorting_case_study/results.csv
