
// INVARIANT for the dynamic sequence class:
//   1. The number of items in the sequence is in the member variable used;
//   2. The actual items of the sequence are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable data;
//   4. the member varaible current_index stored the data on which the cursor is on in the sequence.
//   3. The size of the dynamic array is in the member variable capacity.
//   


#include<iostream>
#include<algorithm>
#include <cassert>
#include "sequence2.h"

using namespace std;

namespace main_savitch_4 
{

		const sequence::size_type sequence::DEFAULT_CAPACITY;
		
        sequence::sequence(size_type initial_capacity ){
			data = new value_type [initial_capacity];
			capacity = initial_capacity;
			used = 0;
			current_index = 0;
		
		}
       sequence::sequence (const sequence& source){
		
			data = new value_type [source.capacity];
			capacity = source.capacity;
			used = source.used;
			current_index = source.current_index;
			copy (source.data, source.data+used, data);	
		
		}
		sequence:: ~sequence( ){
		
			delete [] data;
		}
		
        void sequence::start( ){
		
			current_index = 0;
		
		}
		
        void sequence::advance( ){
			if (is_item() == true ) {
				current_index++;}
			else if(is_item() == false) {}
			
		
		}
		
        void sequence::insert(const value_type& entry){
			
				if (used == capacity){
					resize(used+1);
				}
				if (!is_item()){
					current_index = 0;
				}
						
				for(size_t i = used; i > current_index; i--){
					data[i] = data[i-1];
					}
				data[current_index] = entry;
				++used;
 
		}
		
        void sequence::attach(const value_type& entry){

		
				if(used == capacity){
					resize(used+1);
				}
				if(!is_item()){
					current_index = used;
				}
				
				size_t i;
		
				for( i = used; i > (current_index + 1); i--){
					data[i] = data[i-1];
				}
				data[i] = entry;
				current_index = i;
				++used;
			
		}
		
        void sequence::remove_current( ){
		
				assert ( is_item() == true);
				size_t i;
				for( i= current_index +1 ; i<used; ++i){
					data[i-1] = data[i];
				}
				used--;
		}

        void sequence::resize(size_type new_capacity){
				value_type *new_data;
			
				if( new_capacity == capacity){
					return;
					}
					
				if ( new_capacity < used){
					new_capacity = used;}
					
					new_data= new value_type [ new_capacity];
					copy  ( data, data+used, new_data);
					delete [] data;
					data = new_data;
					capacity = new_capacity;

		}
		
        void sequence::operator=(const sequence& source){
			
			value_type *new_data;
		
			if (this == &source)
				return;
		
			if (capacity != source.capacity){

				new_data = new value_type[source.capacity];
				delete [ ] data;
				data = new_data;
				capacity = source.capacity;

		}

			used = source.used;
			copy(source.data, source.data + used, data);
			current_index = source.current_index;
		
		}
		
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
		
		void sequence::operator += ( const sequence& source) {
			
			
			if ( used + source.capacity > capacity)
				capacity = capacity + source.capacity;
				resize (capacity);
			
			 copy(source.data, source.data + source.used, data + used);
			 used += source.used;
			 		 
			 }
			 
		void sequence:: operator + (const sequence& source) {
			value_type *new_data;
			
			if (used + source.capacity > capacity)
				resize ( used + source.capacity);
			
			new_data = new value_type [used+source.capacity];
			
			copy( data, data+used, new_data);
			
			copy ( source.data, source.data+ source.used, new_data+ used);
			
			used = used + source.used;
			capacity = used + source.capacity;
			delete [] data;
			
			data = new_data;
			
			} 
			
		sequence:: value_type sequence::operator[](sequence::size_type index)const{
		
			return data[index];
		}

}

