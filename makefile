Craps : LabAss3.o
	g++ LabAss3.o -o LabAss3

Craps.o : Craps.cpp
	g++ -c LabAss3.cpp

clean : 
	rm *.o LabAss3
