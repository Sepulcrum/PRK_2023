MAKE=make
GCC=gcc


BINDIR="./bin"
BINFILE="ll.bin"
TESTDIR="../tests"
TEST_OK_FILE="test_ok.txt"
TEST_NOT_FILE="test_nook.txt"

all: clean
	@$(MAKE) -s ll.bin 
	@$(MAKE) -s test_ok
	@$(MAKE) -s test_nook
	@if [ $(PRINT_OUTPUT) ]; then cat $(BINDIR)/$(TEST_OK_FILE).report; fi
	@if [ $(PRINT_OUTPUT) ]; then cat $(BINDIR)/$(TEST_NOT_FILE).report; fi

%.bin: %.lex
	@flex $< 
	@$(GCC) $(GCCOPTS) lex.yy.c
	@mv a.out $(BINDIR)/$@

test_ok:
	@./$(BINDIR)/ll.bin < $(TESTDIR)/$(TEST_OK_FILE) >$(BINDIR)/$(TEST_OK_FILE).report

test_nook:
	@./$(BINDIR)/ll.bin < $(TESTDIR)/$(TEST_NOT_FILE) >$(BINDIR)/$(TEST_NOT_FILE).report


clean:
	@rm -rf $(BINDIR)/*
