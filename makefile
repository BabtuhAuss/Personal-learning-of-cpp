CC = g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=result
ACTUALWORK_MAIN=main_mystere.o
ACTUALWORK_MAIN_LIBS=TP_mystere/main_mystere.h

all: $(EXEC)

result: $(ACTUALWORK_MAIN) main.o
	$(CC) -o $@ $^ $(LDFLAGS)

allocation_tableau.o: allocation_tableau/main_allocation_tableau.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main_fondamentaux.o: fondamentaux/main_fondamentaux.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main_mystere.o : TP_mystere/main_mystere.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp $(ACTUALWORK_MAIN_LIBS)
	$(CC) -o $@ -c $< $(CFLAGS)

check:
	@echo 'ok'

distcheck:
	@echo 'ok'
	
clean:
ifeq ($(OS),Windows_NT)
	del /s /q *.o
else
	rm -rf *.o
endif

mrproper: clean
ifeq ($(OS),Windows_NT)
	del /s /q $(EXEC).exe
else
	rm -rf $(EXEC)
endif



