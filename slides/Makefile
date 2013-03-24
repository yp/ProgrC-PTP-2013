.PHONY: base

all: custom/tango-bigger.css out/index.html

out/index.html: config.cfg slides_src/index.md
	@mkdir -p out ; \
	bash ./compile.sh config.cfg
