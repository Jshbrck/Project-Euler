/*
 * Implementation of the Sieve of Eratosthenes, applied to solve the 10001st prime problem.
 */


#include <iostream>
#include <cmath>
#include <vector>



//Implementation of the sieve_of_eratosthenes
std::vector<int> sieve_of_eratosthenes(int n){
    std::vector<int> vector;   
    //Creates a vector containing all integers from 2 to n
    vector.reserve(n);
    for(int i = 2; i < n; i++){
        vector.push_back(i);        
    }

    //Performs sieve of eratosthenes on the vector
    for(int i = 2; i <= sqrt(n); i++){
        if(vector[i-2] > 0 ){  
            for(int k = i*i; k < n; k = k+i){
                vector[k-2] = 0;   
            }
        }
    }
    return vector;
}

/*
 * Finds the nth prime using the sieve_of_eratosthenes
 * Accepts an integer n, and prints out the nth prime
 */
void nth_prime(int n){
   
   std::vector<int> primes;
    long long bound = n, cnt, flip = 1;
    
    while(flip){
        cnt = 0;
        primes = sieve_of_eratosthenes(bound);
        for(int i = 0; i < primes.size(); i++){      
            if(primes[i] > 0){
                cnt++;
                if(cnt == n){
                    std::cout<<primes[i]<<std::endl;
                    flip = 0;
                    break;
                }
            }
              
        }
        if (flip == 1)
            bound = 10*bound;
    }
}




/*
 * 
 */
int main(int argc, char** argv) {
    nth_prime(10001);
    return 0;
}

