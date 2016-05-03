CXX = g++
LIBS = -pthread -std=c++11
COMPILE_FLAG = -c
O_FLAG = -o

OBJS = vectorList.o matrixList.o lab3.o

#This is a comment

matrix : ${OBJS}
	${CXX} ${O_FLAG} $@ ${LIBS} ${OBJS}

vectorList.o : vectorList.cc
	${CXX} ${COMPILE_FLAG} vectorList.cc

matrixList.o : matrixList.cc
	${CXX} ${COMPILE_FLAG} matrixList.cc

lab3.o : lab3.cpp
	${CXX} ${COMPILE_FLAG} ${LIBS} lab3.cpp

clean :
	rm $(OBJS)
