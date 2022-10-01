parametrosCompilacao=-Wall --std=c90
nomePrograma=ru_na_pandemia

all: $(nomePrograma)

$(nomePrograma): ru_na_pandemia.o libpilha.o libfila.o liblista.o libpessoa.o
	gcc -o $(nomePrograma) ru_na_pandemia.o libpilha.o libfila.o liblista.o libpessoa.o $(parametrosCompilacao)

ru_na_pandemia.o: ru_na_pandemia.c
	gcc -c ru_na_pandemia.c $(parametrosCompilacao)

libpilha.o: libpilha.h libpilha.c
	gcc -c libpilha.c $(parametrosCompilacao)

libfila.o: libfila.h libfila.c
	gcc -c libfila.c $(parametrosCompilacao)

liblista.o: liblista.h liblista.c
	gcc -c liblista.c $(parametrosCompilacao)

libpessoa.o: libpessoa.h libpessoa.c
	gcc -c libpessoa.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
cleanr:
	rm -f *.o *.gch $(nomePrograma)
	clear