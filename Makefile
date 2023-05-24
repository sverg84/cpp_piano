CC = g++
CFLAGS = -c -Wall -Werror -Wextra -std=gnu++17
EXE = main
SFML_INCLUDE_PATH = -I /opt/homebrew/Cellar/sfml/2.5.1_2/include
SFML_LIB_PATH = -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib
SFML_LINK = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

${EXE}: main.o Note.o Piano.o PianoKey.o PianoRunner.o BlackPianoKey.o WhitePianoKey.o
	${CC} *.o -o main ${SFML_LIB_PATH} ${SFML_LINK}

main.o: play.cpp
	${CC} ${CFLAGS} play.cpp -o main.o ${SFML_INCLUDE_PATH}

Note.o: impl/Note.cpp
	${CC} ${CFLAGS} impl/Note.cpp -o Note.o ${SFML_INCLUDE_PATH}

Piano.o: impl/Piano.cpp
	${CC} ${CFLAGS} impl/Piano.cpp -o Piano.o ${SFML_INCLUDE_PATH}

PianoKey.o: impl/PianoKey.cpp
	${CC} ${CFLAGS} impl/PianoKey.cpp -o PianoKey.o ${SFML_INCLUDE_PATH}

PianoRunner.o: impl/PianoRunner.cpp
	${CC} ${CFLAGS} impl/PianoRunner.cpp -o PianoRunner.o ${SFML_INCLUDE_PATH}

BlackPianoKey.o: impl/BlackPianoKey.cpp
	${CC} ${CFLAGS} impl/BlackPianoKey.cpp -o BlackPianoKey.o ${SFML_INCLUDE_PATH}

WhitePianoKey.o: impl/WhitePianoKey.cpp
	${CC} ${CFLAGS} impl/WhitePianoKey.cpp -o WhitePianoKey.o ${SFML_INCLUDE_PATH}

clean: 
	rm *.o ${EXE}