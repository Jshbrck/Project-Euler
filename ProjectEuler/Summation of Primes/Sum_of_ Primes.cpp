
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Function that finds all primes less than the integer n using the sieve of eratosthenes
 * Takes integer n as argument and returns vector containing 0's and primes
 */
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



//Calculates the sum of all primes less than n
int main(int argc, char** argv) {
    std::vector<int> primes;
    unsigned long long sum_of_vector = 0, n = 2000000;
    primes = sieve_of_eratosthenes(n);
    for(int i = 0; i < primes.size(); i++){
        std::cout<<primes[i]<<std::endl;
        sum_of_vector = sum_of_vector + primes[i];
    }
    std::cout<<"Sum of primes up to "<<n<<": "<<sum_of_vector<<std::endl;

    return 0;
}

