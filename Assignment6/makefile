bagexam: bagexam.o
	g++ -Wall -gstabs bagexam.o -o bagexam

bagexam.o: bagexam.cxx bag6.h bag6.template bintree.h bintree.template
	g++ -c -Wall -gstabs bagexam.cxx

clean:
	$(RM) *.o *.exe 