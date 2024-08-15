#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of suitors: ";
    cin >> n;
    
    if(n <= 0){									//error checking
        cout << "Not enough suitors." << endl;
        exit(1);
    }

      if(n == 1)
        cout << "You would stand first in line." << endl;
    else
    {
    vector<int> suitors(n);
    for (int i = 0; i < n; i++) {
        suitors[i] = i + 1;
    }

    int index = 0;				//current suitor the princes will examine
    while (suitors.size() > 1) {	
        index = (index + 2) % suitors.size();			// The index is calculated.
        cout << "Suitors: ";
        for (int i = 0; i < suitors.size(); i++) {
            cout << suitors[i]<< " ";
        }
        cout << endl;
        cout << "Eliminated suitor: " << suitors[index] << endl;
        suitors.erase(suitors.begin() + index);				//eliminate contestant current
    }

    cout << "The winning suitor is: " << suitors[0] << endl;
}
    return 0;
}

