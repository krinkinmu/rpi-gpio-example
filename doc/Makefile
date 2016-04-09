all: clean rpi.pdf

rpi.dvi: rpi.tex
	latex rpi
	latex rpi

rpi.ps: rpi.dvi
	dvips rpi.dvi

rpi.pdf: rpi.ps
	ps2pdf rpi.ps

.PHONY: clean
clean:
	rm -f *.dvi *.ps *.pdf *.aux *.toc *.log *.blg *.bbl *.out
