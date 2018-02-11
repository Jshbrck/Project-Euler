
#include <iostream>
#include <math.h>


/*
 * Calculates the Special Pythagorean Triple Product using Dickson's method
 */
int main(int argc, char** argv) {
   double a,b,c, r,q,p;
    for( b = 1; b<500; b++){
        for( a = 1; a < b; a++){
            c = sqrt(b*a*2);
            r = a + c;
            q = b + c;
            p = a + b + c;
            if (r + q + p == 1000){
                std::cout<<"Product:"<<r*p*q<<std::endl;
            }
        }
    }
   
 
 
}

