CC = g++
CFLAGS = -Wall -Werror -Wextra -std=gnu++17
EXE = main
SFML_INCLUDE_PATH = -I /opt/homebrew/Cellar/sfml/2.5.1_2/include
SFML_LIB_PATH = -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib
SFML_LINK = -lsfml-graphics -lsfml-window -lsfml-system

${EXE}: Piano.o PianoKey.o PianoRunner.o main.o
	${CC} *.o -o main ${SFML_LIB_PATH} ${SFML_LINK}

main.o: Piano.o PianoKey.o PianoRunner.o play.cpp
	${CC} -c ${CFLAGS} play.cpp -o main.o ${SFML_INCLUDE_PATH}

Piano.o: impl/Piano.cpp
	${CC} -c ${CFLAGS} impl/Piano.cpp -o Piano.o ${SFML_INCLUDE_PATH}

PianoKey.o: impl/PianoKey.cpp
	${CC} -c ${CFLAGS} impl/PianoKey.cpp -o PianoKey.o ${SFML_INCLUDE_PATH}

PianoRunner.o: impl/PianoRunner.cpp
	${CC} -c ${CFLAGS} impl/PianoRunner.cpp -o PianoRunner.o ${SFML_INCLUDE_PATH}

clean: 
	rm *.o ${EXE}