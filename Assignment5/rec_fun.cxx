// rec_fun.cxx

#include <iostream>
#include <cassert>
#include "rec_fun.h"
#include <string>

using namespace std;

namespace asif_space {

	void rec_fun:: binary_print(ostream& outs, unsigned int n){
	
		if (n == 0 ){
		   outs<< 0 ;
		   }
		if ( n > 1){
			binary_print( outs ,n/2);
			}
	    if ( n%2 == 0 && n!=0){
			   outs << 0;}
	    else {
		   outs << 1;
	    }
	   
	  }
	void rec_fun::traingle( ostream& outs , unsigned int m , unsigned int n){
	
	//assert (m<=n);
	if ( m <= n) {
	//unsigned int l= 2*(n-m+1);
	for ( size_t i=1; i<= m; i++){
		outs << "*"; }
		cout << endl;
	traingle ( outs, m+1, n);
	
	for ( size_t i=1; i<= m; i++){
		outs << "*"; }
	cout << endl;	
	
	//outs << '* m;

	}
	}
	
	double rec_fun:: pow (double x, int n ){
	
	if(x == 0){
			assert(n > 0);
			return 0;}
		
		else if (x<1){
		    return pow(-x,n);}
		
		else if(n == 0){
			return 1;}
		
		else if(n == 1){
			return x;}
		
		else if(n >0){
			return ( pow(x,(n/2)) * pow(x,(n/2))*pow(x,(n%2)) );}
		
		else{
			return 1/pow(x, -n);}
	}
	
	void rec_fun::indented_sentences (size_t m , size_t n){
	
	if (m<=n) {
	
	   char c = ' ';
	   cout << string( m,c)<< "This was written by calling number " << m << "."<<endl;
	   //cout << endl;
	   indented_sentences ( m+1, n);
	   
	   cout << string ( m,c) << "This was Also written by calling number " << m<< "."<<endl;
	   }
	   	
	
	}
	
	
}