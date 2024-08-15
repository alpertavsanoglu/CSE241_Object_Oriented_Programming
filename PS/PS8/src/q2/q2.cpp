#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
class Pair {
private:
	T1 first;
	T2 second;
public:
	Pair(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}
	T1 getFirst() const{
        	return first;
	}
	T2 getSecond() const{
        	return second;
	}
	void setFirst(T1 first){
		this->first = first;
	}
	void setSecond(T2 second){
		this->second = second;
	}
};
int main(){
	Pair<char, char> p('A','B');
	cout<<"First is " <<p.getFirst()<<endl;
	p.setFirst('Z');
	cout << "First changed to "<<p.getFirst()<<endl;
	cout << "The pair is: "<<p.getFirst()<<", "<<p.getSecond()<<endl;

	Pair<int, string> p2(34, "Bill");
	Pair<string, int> p3("Bill", 34);
	cout<<"The pair is: "<<p2.getFirst()<<", "<<p2.getSecond()<<endl;
	return 0;
}
