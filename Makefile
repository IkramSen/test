CC=g++
CFLAGS=-Wall
EXECUTABLE=list

SOURCES = main.cpp task/task.cpp  platform/processor.cpp  common/list.cpp 

list: common/list.o  task/task.o platform/processor.o main.cpp
	$(CC) $(CFLAGS) -g -Wall -o $(EXECUTABLE) $(SOURCES)



#subtask.o: task/subtask.hpp
#list.o: common/list.hpp

clean:
	rm -rf *.o *.gch $(EXECUTABLE)
	rm -rf common/*.o
	rm -rf task/*.o
	rm -rf platform/*.o	
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
