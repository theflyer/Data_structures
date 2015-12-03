bagtest: bagtest.o
	g++ -Wall -gstabs bagtest.o -o bagtest

bagtest.o: bagtest.cxx bag6.h bag6.template bintree.h bintree.template
	g++ -c -Wall -gstabs bagtest.cxx

clean:
	$(RM) *.o *.exe 