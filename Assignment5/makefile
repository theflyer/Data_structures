rec: recursion.o rec_fun.o   
	g++ -Wall recursion.o rec_fun.o -o rec
recursion.o: rec_fun.h recursion.cxx 
	g++ -Wall -c recursion.cxx  

rec_fun.o: rec_fun.h  rec_fun.cxx
	g++ -Wall -c rec_fun.cxx


clean:
	rm *.o rec