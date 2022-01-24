CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror=vla -MMD
OBJECTS = a4q2.o lifegame.o grid.o cell.o ruleone.o ruletwo.o rulethree.o rulefour.o rulefive.o decorator.o basecell.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = game

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
