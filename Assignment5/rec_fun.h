
// Name: Asif Saifullah

// rec_fun.h

#ifndef asif_space_H
#define asif_space_H
#include <iostream>
using namespace std;


namespace asif_space {
	class rec_fun
	{
	public:
	
	void binary_print(ostream& outs, unsigned int n);
	void traingle( ostream& outs , unsigned int m , unsigned int n);
	double pow (double x, int n );
	void indented_sentences (size_t m , size_t n);
	
	};
	
}
#endif