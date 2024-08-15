#include <iostream>
#include <cstdlib>
using namespace std;

class HotDogStand{
public:
        HotDogStand(int _id = 0, unsigned int _soldCount = 0);
        void JustSold();
         int GetID();
        unsigned int GetSoldNumber() const;
        static unsigned int GetTotalSoldNumber();
private:
        int ID;				
        unsigned int soldCount;
        static unsigned int totalSoldCount;
};
int HotDogStand::GetID(){		//Accessing name on class
    return ID;
}
HotDogStand::HotDogStand(int _id, unsigned int _soldCount) : ID(_id), soldCount(_soldCount){
    totalSoldCount += soldCount;
}

void HotDogStand::JustSold(){				//Increment the number of hotdogs in stand
    soldCount++;        
    totalSoldCount++;
}
unsigned int HotDogStand::GetSoldNumber() const{
    return soldCount;
}
unsigned int HotDogStand::GetTotalSoldNumber(){
    return totalSoldCount;
}
unsigned int HotDogStand::totalSoldCount = 0;

int main(){
    HotDogStand standA(1, 0), standB(2, 0), standC(3, 0);       // stands starts with 0 sold hotdogs
    
    standA.JustSold();
    standA.JustSold();
    standB.JustSold();                              // Inform user about number of sold hotdogs
    cout    << "Stand " <<    standA.GetID() << " sold " << standA.GetSoldNumber() << "\n"  
            << "Stand " <<    standB.GetID() << " sold " << standB.GetSoldNumber() << "\n"
            << "Stand " <<    standC.GetID() << " sold " << standC.GetSoldNumber() << "\n"<< "-------------------"<< "\n"
            << "Total sold = " << HotDogStand::GetTotalSoldNumber() << "\n\n";

    for(int i = 0; i < 30; ++i){     //sold some more
        standA.JustSold();              //30 hotdog sold
        if(!(i % 2)) standB.JustSold();  //15 hotdog sold
        if(!(i % 3)) standC.JustSold(); //10 hotdog sold
    }                                   // in total  55 new hotdogs were sold

   	// Inform user about final state of number of sold hotdogs
    cout << "Stand " <<    standA.GetID() << " sold " << standA.GetSoldNumber() << "\n"
         << "Stand " <<    standB.GetID() << " sold " << standB.GetSoldNumber()<< "\n"
         << "Stand " <<    standC.GetID() << " sold " << standC.GetSoldNumber() << " \n"<< "-------------------"<< "\n"
         << "Total sold = " << HotDogStand::GetTotalSoldNumber()<< "\n";

    return 0;
}
