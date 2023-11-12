# This makefile redirects to the makefiles created by cmake

all:
	@cd ../build && $(MAKE)

debug:
	@cd ../debug && $(MAKE)

tests:
	@cd ../buildtest && $(MAKE) && $(MAKE) test

clean:
	@cd ../build && $(MAKE) clean

.PHONY: all debug clean
