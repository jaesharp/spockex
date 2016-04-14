MIX = mix
CFLAGS = -g -O3 -fPIC -std=iso9899:2011 -pedantic -Wall -Wextra -Wno-unused-parameter

ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CFLAGS += -I$(ERLANG_PATH)

VULKAN_HEADER_PATH = "/usr/include/vulkan"
CFLAGS += -I$(VULKAN_HEADER_PATH)

LDFLAGS += -L/usr/lib/

.PHONY: default spockex clean test

default: test

spockex: priv/spockex.so
	$(MIX) compile

test: spockex
	$(MIX) test

priv/spockex.so: src/spockex.c
	mkdir -p priv
	$(CC) $(CFLAGS) -shared $(LDFLAGS) -o $@ src/spockex.c -lvulkan

clean:
	$(MIX) clean
	$(RM) priv/spockex.so
