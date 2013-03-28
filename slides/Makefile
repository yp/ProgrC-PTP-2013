.PHONY: base

all: out/index.html out/1-probl-algo.html out/2-ling-C-basi.html out/3-ling-C-interm.html out/4-ling-C-adv.html out/5-complete-example.html

out/index.html: config.cfg custom/tango-bigger.css slides_src/frontpage.md slides_src/download-slides.md slides_src/index.md
	@mkdir -p out ; \
	bash ./compile.sh config.cfg

out/1-probl-algo.html: config-1.cfg custom/tango-bigger.css slides_src/frontpage.md slides_src/intro.md slides_src/algoritmi.md
	@mkdir -p out ; \
	bash ./compile.sh config-1.cfg

out/2-ling-C-basi.html: config-2.cfg custom/tango-bigger.css slides_src/frontpage.md slides_src/c-intro.md slides_src/c-basi.md slides_src/c-if-while-for.md slides_src/c-funzioni.md
	@mkdir -p out ; \
	bash ./compile.sh config-2.cfg

out/3-ling-C-interm.html: config-3.cfg custom/tango-bigger.css slides_src/frontpage.md slides_src/c-funzioni.md
	@mkdir -p out ; \
	bash ./compile.sh config-3.cfg

out/4-ling-C-adv.html: config-4.cfg custom/tango-bigger.css slides_src/frontpage.md slides_src/c-array.md slides_src/c-puntatori.md slides_src/c-file.md slides_src/conclusions.md
	@mkdir -p out ; \
	bash ./compile.sh config-4.cfg

out/5-complete-example.html: config-5.cfg custom/tango-bigger.css slides_src/frontpage.md slides_src/esempio-fst.md
	@mkdir -p out ; \
	bash ./compile.sh config-5.cfg
