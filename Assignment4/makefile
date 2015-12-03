seq1_ex: seq_ex3.o sequence3.o node1.o  
	g++ -Wall seq_ex3.o sequence3.o node1.o -o seq1_ex
seq_ex3.o: sequence3.h seq_ex3.cxx 
	g++ -Wall -c seq_ex3.cxx  

sequence3.o: sequence3.h  sequence3.cxx
	g++ -Wall -c sequence3.cxx

node1.o: node1.h node1.cxx
	g++ -Wall -c node1.cxx

clean:
	rm *.o seq1_ex
	
	