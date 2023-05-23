CC = g++
CFLAGS = -Wall -Werror -Wextra -std=gnu++17
EXE = main
SFML_INCLUDE_PATH = -I /opt/homebrew/Cellar/sfml/2.5.1_2/include
SFML_LIB_PATH = -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib
SFML_LINK = -lsfml-graphics -lsfml-window -lsfml-system

${EXE}: main.o
	${CC} main.o -o main ${SFML_LIB_PATH} ${SFML_LINK}

main.o: play.cpp
	${CC} -c ${CFLAGS} play.cpp -o main.o ${SFML_INCLUDE_PATH}

clean: 
	rm *.o ${EXE}