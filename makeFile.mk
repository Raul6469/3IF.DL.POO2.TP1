
# make -f makeFile.mk FLAGS2 ?= -D MAP
# make -f makeFile.mk clean

FLAGS1 = -g -Wall
FLAGS2 = 

GestionVoyages: Trajet.o TrajetSimple.o TrajetCompose.o ListeTrajets.o Catalogue.o
	g++ $(FLAGS1) $(FLAGS2) Trajet.o TrajetSimple.o TrajetCompose.o ListeTrajets.o Catalogue.o -o GestionVoyages

ListeTrajets.o: ListeTrajets.h Trajet.h
	g++ $(FLAGS1) $(FLAGS2) -c ListeTrajets.cpp
	
Catalogue.o: Catalogue.cpp Catalogue.h Trajet.h ListeTrajets.h
	g++ $(FLAGS1) $(FLAGS2) -c Catalogue.cpp

Trajet.o: Trajet.cpp Trajet.h
	g++ $(FLAGS1) $(FLAGS2) -c Trajet.cpp
	
TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h ListeTrajets.h
	g++ $(FLAGS1) $(FLAGS2) -c TrajetSimple.cpp
	
TrajetCompose.o: TrajetCompose.cpp ListeTrajets.h Trajet.h TrajetCompose.h
	g++ $(FLAGS1) $(FLAGS2) -c TrajetCompose.cpp
