#include <iostream>
#include <cassert>
#include "sequence1.h"


using namespace std;

namespace main_savitch_3
{
	sequence:: sequence () {
	
			used = 0;
			current_index = 0;

	}
	
	 
	 void sequence::start( ){
		current_index=0;	 
	 
	 }
	 void sequence:: advance( ){
		if (is_item() == true ) {
			current_index++;}
		else if(is_item() == false) {}
			
	 }
	 void sequence:: insert(const value_type& entry){
	 
		size_t i;
		assert (size() < CAPACITY);
		if (is_item() == false) {
		
			current_index = 0;
			for (i=used; i> current_index; i--){
				data[i] = data[i-1];}
				data[current_index] = entry;
				used++;
			}
		else{
		
			for ( i = used; i> current_index ; i--){
				data[i] = data[i-1];}
				data[current_index]= entry;
				used++;
			
		}
	 
	 }
	 void sequence:: attach(const value_type& entry){
		
		size_t i;
		assert (size() < CAPACITY);
		
		if ( is_item()==false) { 
		    current_index = used;
			data[current_index] = entry;
			used++;
		}
		else{
			for (i= used;i > (current_index + 1); i--){
				data[i]= data[i-1]; 
			 }
			data[current_index + 1 ]= entry;
			current_index++;
			used++;
		}
	 }
	 
	 void sequence::remove_current( ){
		assert ( is_item() == true);
		size_t i;
		for( i= current_index +1 ; i<used; ++i){
			data[i-1] = data[i];
			}
			used--;
		
	 
	 }
	 // CONSTANT MEMBER FUNCTIONS
	 sequence::size_type sequence::size( ) const{
	 
		return used;
	 
	 
	 }
	 bool sequence::is_item( ) const{
	 
		return current_index < used;
		
	 
	 }
	 sequence::value_type sequence::current( ) const{
		assert ( is_item() == true);
	 
		return data[current_index];
	 
	 }



}