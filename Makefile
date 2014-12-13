GRAPH = gnuplot

CC = clang
CFLAGS = -Wall -O3 
LFLAGS = -O3
LIBS = -lgsl -lm 

all: mc-ell

mc-ell: ellipse_mc.o mc.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

res: mc-ell
	./mc-ell > res

mc-pi1.png: mc-pi1.gp res
	$(GRAPH) mc-pi1.gp

clean:
	rm -f *.o *~ mc-pi

veryclean: clean
	rm -f res mc-pi1.png
