tarea:
	gcc -o tarea2cn main.c src/biseccion.c src/funciones.c src/newton.c src/puntofijo.c \
	src/secante.c src/misc.c src/horner.c src/muller.c -lm

clean:
	rm tarea2cn *.txt