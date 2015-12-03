#include <iostream>
#include <cstdlib>

using namespace std;

void search ( const int a[], size_t first, size_t last, int target, bool& found, size_t& location)
{
	size_t middle;
	//assert ( first <= last);
	if ( first == last )
		found = false;
	else
	{    middle = (first - last)/2;  
		if ( target == a[middle])
		{
			location = middle;
			found = true;
		}
	    else if ( target < a[middle])
			search( a, first,middle-1, target, found, location);
		else 
			search ( a, middle+1, last, target, found ,location);
		}
		
	cout << location;
}		

int main() {
	//size_t i;
	int a[10] = { 1, 2, 3, 4,5,6,7,8,9,10};

	bool found = true;
	size_t loc= 0;
	search (a, 1 ,9, 6, found,loc);
	 //cout << loc;
	return 0;
	}

