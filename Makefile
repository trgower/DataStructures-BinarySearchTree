project10: Main.o StudentTree.o Student.o
	g++ Main.o StudentTree.o Student.o -o project10

Main.o: Main.cpp StudentTree.h Student.h
	g++ -c Main.cpp

StudentTree.o: StudentTree.cpp StudentTree.h
	g++ -c StudentTree.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp
