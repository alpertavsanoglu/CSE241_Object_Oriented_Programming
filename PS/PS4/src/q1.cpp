#include <iostream>
#include <cstdlib>

using namespace std;

class Vector2D 			// Vector2D Class
{
public:

Vector2D(){
    x = 0;
    y = 0;
    }
Vector2D(int set_x, int set_y){
    x = set_x;
    y = set_y;
}
void SetX_Y(int set_x, int set_y){
    x = set_x;
    y = set_y;
}
int GetX(){
    return(x);
}
int GetY(){
    return(y);
}
int operator*(const Vector2D& new_){		//Overloading * operator
    return x * new_.x + y * new_.y;			//Multiplying the same named variables and returning the sum
}
private:

    int x, y;
};

int main()
{	//Code Tester
    Vector2D v1(5,0), v2(0,5), v3(10,10), v4(7,8);		//Class declaration

    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX() << "," << v2.GetY() << ") = " << v1*v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX() << "," << v3.GetY() << ") = " << v2*v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX() << "," << v4.GetY() << ") = " << v3*v4 << endl;
    return 0; 
}
