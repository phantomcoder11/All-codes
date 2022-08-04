// Program to find the Nth Prime Number
//Asked to Soumya Sen Daa

// Input : 5 
// Output : 11

// Input : 16 
// Output : 53

// Input : 1049 
// Output : 8377 

// Approach:  

// Find the prime numbers up to MAX_SIZE using Sieve of Eratosthenes.
// Store all primes in a vector.
// For a given number N, return the element at (N-1)th index in a vector.
// Below is the implementation of the above approach: 

#include<bits/stdc++.h>
#define maxsize 1000005
using namespace std;
int main(){
    long long n;
    cin>>n;
    bool isPrime[maxsize];
    memset(isPrime,true,sizeof(isPrime));
    for(long long i=2;i*i<maxsize;i++){
        if(isPrime[i]){
            
           for(long long j=i*i;j<maxsize;j=j+i)  isPrime[j]=false;
        }
    }
    vector<long long>v;
    for(int i=2;i<maxsize;i++){
        
        if(isPrime[i])
        v.push_back(i);
        
        if(v.size()>n) break;
    }
    
    cout<<v[n-1];
    return 0;
}