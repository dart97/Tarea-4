
PuntoNemo.pdf: Plots.py mapamundi.txt
		python Plots.py

mapamundi.txt: a.out
		./a.out

a.out: GeographicPoint.c
		cc GeographicPoint.c -lm 
