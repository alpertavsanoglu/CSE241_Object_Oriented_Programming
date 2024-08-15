#include <iostream>
#include <cmath>
using namespace std;

int main(){
int i,n;

	for (i=3;i<101;i++){				//starting from 3 to 100
	bool isPrime=true;				//Unless stated otherwise,assuming the isPrime true
		for(n=2;n<=i/2;n++){
		if(i%n==0)	isPrime=false;		//If it is divisable by any number,isPrime is false
		}
	if(isPrime==true)	cout<<i<<" is a prime number"<<endl;

}
return 0;

}
