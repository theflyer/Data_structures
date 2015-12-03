#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "stats.h"

using namespace std;

namespace main_savitch_2C
{


       // CONSTRUCTOR
        statistician::statistician( ){
		
			count = 0;
			total = 0.0;
			largest;
			tinyest;
		}
        // MODIFICATION MEMBER FUNCTIONS
        void statistician:: next(double r)
		{
	
		
	            if (count <= 0) {
				
						count = 1;
						total = r;
						largest = r;
						tinyest = r;
						return;
					}
					else{

						count ++;
						total += r ;
						if (r < tinyest)
						{
						tinyest = r;
						}
						if (largest< r)
						{
						largest = r;
					}

		        }
	   }


        void statistician::reset( ){
		     
			count = 0;
			total= 0.0; 
			tinyest = 0.0;
			largest =0.0;
			  
			}
		
		
		
        // CONSTANT MEMBER FUNCTIONS
        int statistician::length( ) const{
            return count;

        }
        double statistician:: sum( ) const{
			return total;
		}
        double statistician:: mean( ) const{
			double m;
			if (count <= 0 ) { }
			if(count > 0) {
				m = ( total/count);
			
				return m;  }
		}
		
		
        double statistician:: minimum( ) const{
		    if ( count<= 0 ) { }
			if( count > 0){
				return tinyest;}
			
		}
		
        double statistician:: maximum( ) const{
		   
		    if ( count <= 0){}
			   if (count >0){
			   return largest;}
			
		}
		
		statistician operator + (const statistician& s1, const statistician& s2) {
			    statistician s3;
				if ( s1.length() == 0 && s2.length() != 0) {
					return s2;}
				else if ( s2.length () == 0 && s1.length() != 0){
					return s1;}
				else{
			
					s3.count = s1.length() + s2.length();
					s3.total =  s1.sum() + s2.sum();
					if ( s1.minimum() >= s2.minimum()){
						s3.tinyest = s2.minimum();}
					else { s3.tinyest = s1.minimum();}
				
					if (s1.maximum() >= s2.maximum()){
						s3.largest = s1.maximum() ;}
					else { s3.largest = s2.maximum() ;} 
				}      

			return s3; 
		}
		
		statistician operator * ( double scale, const statistician& s){
			statistician s2;
			
			s2.count = s.length();
			s2.total = scale * s.sum();
			
			if (scale >= 0){
				s2.tinyest = scale * s.minimum();
				s2.largest = scale * s.maximum();}
			else if ( scale < 0) {
				s2.tinyest = scale * s.maximum();
				s2.largest = scale * s.minimum();
			}
			
			
			return s2; 
		}
		
		bool operator == ( const statistician& s1 , const statistician& s2) {
		   
		    if ( s1.length() == 0 && s2.length() == 0 ) { return true;}  
			else {
			if ( s1.length() == s2. length() && s1.mean()== s2.mean() && s1.sum()==s2.sum() && s1.minimum()== s2.minimum() 
				&& s1.maximum() == s2.maximum() ){
				return true; 
				}
			}
        }
		

}	
		