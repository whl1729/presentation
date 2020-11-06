Documents= linux_startup_process.pdf

all: $(Documents)

$(Documents): $(Documents:.pdf=.tex)
	xelatex -halt-on-error -file-line-error $^
	make clean-tmp

.PHONY: clean-tmp
clean-tmp:
	-rm -rf *.aux *.log *.nav *.out *.snm *.toc *.vrb

.PHONY: clean
clean:
	-rm -rf $(Documents)
