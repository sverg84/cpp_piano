CC = g++
CFLAGS = -Wall -Wextra -std=gnu++17
EXE = main
SFML_INCLUDE_PATH = -I /opt/homebrew/Cellar/sfml/2.5.1_2/include
SFML_LIB_PATH = -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib
SFML_LINK = -lsfml-graphics -lsfml-window -lsfml-system

${EXE}: Piano.o PianoKey.o PianoRunner.o main.o BlackPianoKey.o WhitePianoKey.o
	${CC} *.o -o main ${SFML_LIB_PATH} ${SFML_LINK}

main.o: Piano.o PianoKey.o PianoRunner.o BlackPianoKey.o WhitePianoKey.o play.cpp
	${CC} -c ${CFLAGS} play.cpp -o main.o ${SFML_INCLUDE_PATH}

Piano.o: BlackPianoKey.o WhitePianoKey.o impl/Piano.cpp
	${CC} -c ${CFLAGS} impl/Piano.cpp -o Piano.o ${SFML_INCLUDE_PATH}

PianoKey.o: impl/PianoKey.cpp
	${CC} -c ${CFLAGS} impl/PianoKey.cpp -o PianoKey.o ${SFML_INCLUDE_PATH}

PianoRunner.o: impl/PianoRunner.cpp
	${CC} -c ${CFLAGS} impl/PianoRunner.cpp -o PianoRunner.o ${SFML_INCLUDE_PATH}

BlackPianoKey.o: impl/BlackPianoKey.cpp PianoKey.o
	${CC} -c ${CFLAGS} impl/BlackPianoKey.cpp -o BlackPianoKey.o ${SFML_INCLUDE_PATH}

WhitePianoKey.o: impl/WhitePianoKey.cpp PianoKey.o
	${CC} -c ${CFLAGS} impl/WhitePianoKey.cpp -o WhitePianoKey.o ${SFML_INCLUDE_PATH}

clean: 
	rm *.o ${EXE}