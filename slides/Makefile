.PHONY: base

all: custom/tango-bigger.css out/index.html out/1-probl-algo.html

out/index.html: config.cfg slides_src/frontpage.md slides_src/index.md
	@mkdir -p out ; \
	bash ./compile.sh config.cfg

out/1-probl-algo.html: config-1.cfg slides_src/frontpage.md slides_src/intro.md slides_src/algoritmi.md
	@mkdir -p out ; \
	bash ./compile.sh config-1.cfg
