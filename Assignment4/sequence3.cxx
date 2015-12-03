// INVARIANT for the sequence ADT:
//   1. The items in the sequence are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.
//   4. the tail pointer of the list is stored in the member variable as tail_ptr.
//   5. The current item pointer of the list is stored in the member variable as cursor_ptr.
//   6. The previous item pointer of the current pointer of the list
//       is stored in the member variable as precursor_ptr.

#include<iostream>
#include<cassert>
#include "sequence3.h"
#include "node1.h"

using namespace std;

namespace main_savitch_5 
{

        // CONSTRUCTORS and DESTRUCTOR
        sequence::sequence( ){										
		// since the fuction consists of all kinds of assignments , so the big O is constants for 
		// for this fuction , its O(n).
		
			head_ptr= NULL;												
			tail_ptr = head_ptr;
			cursor_ptr = head_ptr;
			precursor_ptr = cursor_ptr;
			many_nodes = 0;
		
		}
		
        sequence::sequence(const sequence& source){			
		// the copy constructor function consist of calling another funtion from node1.h which is linear and also a for loop
		// that runs constant amount of time for each item on the source, so the function
		// is a linear functoin, the notaion is O(n).	
			list_copy(source.head_ptr, head_ptr, tail_ptr);				
	        many_nodes = source.many_nodes;	
			cursor_ptr = head_ptr;							
			
			node* current;
			node* head;
					
			for ( head=source.head_ptr, current= source.cursor_ptr; head != current; head = head->link()){    
				precursor_ptr = cursor_ptr;
			    cursor_ptr = cursor_ptr->link();
				}
		
		
				
		}
		
        sequence::~sequence( ){										
		// the function consist of a calling of another function list_insert which has while statement 
		// that runs linearly for each item untill the head_ptr in NULL, so the big O for the function is linear 
		// so it's O(n)
		
			list_clear ( head_ptr);									
			many_nodes = 0;
		
		
		}
		
        // MODIFICATION MEMBER FUNCTIONS
        void sequence::start( ){								 
		 // the big O for this function is constant since it's consist of all assignments, big O is constant
		 // that means its O(1)
			
			cursor_ptr = head_ptr;									
			precursor_ptr = cursor_ptr;								
		
		}
        void sequence::advance( ){
		// the big O notation for the funtion the function is linear 
		// since the loop goes through for each item take constant amount of time.
		// so the notaion is O(n)
		
			assert ( is_item() == true);							
			
			if (is_item() == true){									
			precursor_ptr = cursor_ptr;								
			cursor_ptr = cursor_ptr->link();						
			}
			else {return;}
		
		}
        void sequence::insert(const value_type& entry){				
		// the big O notation for this function is linear, because the conditoinal statement 
		// of this function runs one tim for each of the funcion, so it's O(n)
			
			if ( is_item() == false || head_ptr == cursor_ptr){      
				list_head_insert ( head_ptr, entry);					
				cursor_ptr = head_ptr;								
				precursor_ptr = cursor_ptr;							
				
				}
				else{
				if ( cursor_ptr == NULL){							
				list_head_insert ( head_ptr, entry);				
				cursor_ptr = head_ptr;								
				precursor_ptr = cursor_ptr;							
				}
				else{
				
				list_insert ( precursor_ptr, entry);				
				cursor_ptr = precursor_ptr-> link();				
				}
			}
			++many_nodes;											
			
		}
        void sequence::attach(const value_type& entry){		
		// The fuction consist of some conditional loops and assignments, since each comapring 
		// always takes constant amount of time for each object so the big O is constatn for this function.
			
			if ( is_item() == false && head_ptr == NULL) {			
				list_head_insert ( head_ptr, entry);				

				cursor_ptr = head_ptr;								
				precursor_ptr = cursor_ptr;							
								
				}
			else{ 
				if ( is_item() == false){							
				
					list_insert( precursor_ptr,entry);				
					cursor_ptr= precursor_ptr->link();				
					}
				else{ 
					  list_insert(cursor_ptr,entry);				
					  precursor_ptr = cursor_ptr;					
			          cursor_ptr = precursor_ptr->link();			
					
					  }
				
				}
				++many_nodes;										
		
		}
		
        void sequence::remove_current( ){						
		// big O notation for this funtoin for this fuction is constant because this fuction consist of 
		// a conditional loops which takes constant times for each item  so the big O is linear O(n)
			assert ( is_item() == true);							
		
			if (cursor_ptr == head_ptr)															
			{
				list_head_remove(head_ptr);							
				cursor_ptr = head_ptr;								
				precursor_ptr = head_ptr;							
		
			}
			else { 
				cursor_ptr = cursor_ptr->link();					
				list_remove(precursor_ptr);							
		
			}
			--many_nodes;											
		
		}
        void sequence::operator =(const sequence& source){			
		// the big O notation for this fuction is linear because it call function list_ clear and list_copy which is linear 
		// and a for loop which runs oone time for each item, so the big O for this function is linear
		// so it O(n))
		
			if (this == &source)									
				return;
	
			list_clear(head_ptr);									
			list_copy(source.head_ptr, head_ptr, tail_ptr);				
			many_nodes = source.many_nodes;							
			cursor_ptr = head_ptr;																
			
			node* current;
			node* head;
			
			for ( head = source.head_ptr,current = source.cursor_ptr; head != current; head= head->link()){
			
					precursor_ptr = cursor_ptr;						
				    cursor_ptr = cursor_ptr->link();					
			   }
		
		}
		
        // CONSTANT MEMBER FUNCTIONS
        size_t sequence::size( ) const{                       
		// the big O notation for this fuction is constant it's O(1)
		
		return many_nodes;
		
		}
		
        bool sequence::is_item( ) const{    
		// this functon all only checks if there is any current item on the sequence
		// so the only need constant an=mount of time , so big O notation for this function is
		// O(1)
		                 
		
		if ( cursor_ptr != NULL){
			return true;
			}
		else{
			return false;
			}
		
		}
		
        sequence::value_type sequence::current( ) const{  
		 // the big notation for this function is constanat so it's O(1)
		
			assert(is_item() == true);						
			return cursor_ptr->data();
		
		}
  


}
