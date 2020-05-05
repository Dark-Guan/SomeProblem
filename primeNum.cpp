#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNum(long n){
	if(n < 2){
	   return false;
	}else if(n == 2){
		return true;
    }
    long maxIndex = sqrt(n);
	for(long i =2; i<=maxIndex; i++){
	    if(n%i == 0){
	    return false;
	    }
	}
	return true;
}

int main()
{
	long n;
	long number = 0;
	
	cin >> n;
	for(int i = 2; i < n; i++){
	    if(isPrimeNum(i)){
	      number++;
	    }
	}
	cout << number;
	return 0;
}
