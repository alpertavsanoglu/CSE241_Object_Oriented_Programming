#include <iostream>									//libraries
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <limits>
const int MAX_VALUE = 255;								//max value 
using namespace std;
class ImageEditor {
public:
void main_menu(){									//main menu
	int choice;
	cout << "MAIN MENU" << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Open An Image(D)" << endl;
	cout << "2 - Save Image Data(D)" << endl;
	cout << "3 - Scripts(D)" << endl;
	cin >> choice;
	switch (choice){
	case 0:										// if user enter 0 exit
		exit(0);
	break;
	case 1:										// if user enter 1 take file informations
		take_file();
	break;
	case 2:										// if user enter 2 save file informations
		image_save();
	break;
	case 3:										// if user enter 3 ask three value for convert each color to grayscale
		scripts();
	break;
	default:									// if user enter somethng not from menu
		cout << "Invalid choice." << endl;
		exit(1);
	break;
	}
}
void take_file(){
	int select;
	cout << "OPEN AN IMAGE MENU" << endl;
	cout << "0 - UP" << endl;
	cout << "1 - Enter The Name Of The Image File" << endl;
	cin >> select;
	switch (select){
	case 0:										// if user enter 0 go back menu
		main_menu();
	break;
	case 1:										// if user enter 1 take file informations
		take_file_function();
	break;
	default:									// if user enter somethng not from menu
		cout << "Invalid choice." << endl;
		exit(1);
	break;
	}
}
void take_file_function(){								//Implement member functions for reading image files and writing image data to files
	int i,j,max;
	string format = "P3";
	string filename;
	ifstream image;
	cin >> filename;								//take file name from user
	image.open(filename);
	if(!image){									//Unable to open file
	cout << "File didnt create" << endl;
	exit(1);
	}
	image >> format >> w >> h >> max;						//cout << h<<"\n" ;		//cout << w<<"\n" ;		// take informations from file
	r.resize(w);
	g.resize(w);
	b.resize(w);									//resize vectors with width value
	i = 0;
	while(i<w){
	r[i].resize(h);
	g[i].resize(h);
	b[i].resize(h);									//resize vectors with height value
	i++;
	}
		i = 0;
		while(i<h){
			j = 0;
			while(j<w){
			image >> r[j][i] >> g[j][i] >> b[j][i];				// take image informations from file
			j++;
			}
		i++;
		}
	image.close();									// close file
	take_file();									//go back to secondry menu which asking 1 to take informations from file
}
void image_save(){
	int select;
	cout << "SAVE IMAGE DATA MENU" << endl;
	cout << "0 - UP" << endl;
	cout << "1 - Enter A File Name" << endl;
	cin >> select;
	switch (select){
	case 0:										// if user enter 0 go back menu
		main_menu();
	break;
	case 1:										// if user enter 1 save file informations
		image_save_function();
	break;
	default:									// if user enter somethng not from menu
		cout << "Invalid choice." << endl;
		exit(1);
	break;
	}
}
void image_save_function(){								//Implement member functions for reading image files and writing image data to files
	int i,j;
	string format = "P3";
	string output_filename;
	ofstream new_file;
	cin >> output_filename;								//take file name from user
	new_file.open(output_filename);
	if(!new_file){									//Unable to open file
	cout << "File didnt create" << endl; 
	exit(1);
		}
	new_file << format << endl << w << " " << h << endl << MAX_VALUE << endl;	// save image informations from file (format,w, h, max valu which is 255)
	i = 0;
	while(i<h){
		j = 0;
		while(j<w){
		new_file << r[j][i] << " " << g[j][i] << " " << b[j][i] << " ";		// save image informations from file (r g b)
		j++;
		}
	new_file << endl;
	i++;
	}
	new_file.close();								//close file
	image_save();									//go back to secondry menu which asking 1 to save informations from file
}
void scripts(){
	int select;
	int choice_for_grayscale;
	cout << "SCRIPTS MENU" << endl;
	cout << "0 - UP" << endl;
	cout << "1 - Convert To GrayScale(D)" << endl;
	cin >> select;
	switch (select){
	case 0:										// if user enter 0 go back menu
		main_menu();
	break;
	case 1:										// if user enter 1 go to grayscale menu
		cout << "CONVERT TO GRAYSCALE MENU" << endl;
		cout << "0 - UP" << endl;
		cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
		cin >> choice_for_grayscale;
		switch (choice_for_grayscale){
		case 0:									// if user enter 0 go back scripts
			scripts();
		break;
		case 1:									// if user enter 1 ask to user enter 1 for enter 3 value 
			convert_to_gs();
		break;
		default:								// if user enter somethng not from menu
			cout << "Invalid choice." << endl;
			exit(1);
		break;
		}
	break;
	default:									// if user enter somethng not from menu
			cout << "Invalid choice." << endl;
			exit(1);
	break;
	}
}
void convert_to_gs(){
	int select_menu,i,j,RED, BLUE, GREEN;
	double c_r, c_g, c_b;
	while(true){
	cin >> c_r >> c_g >> c_b;
		if(cin.fail() || c_r < 0 || c_r >= 1 || c_g < 0 || c_g >= 1 || c_b < 0 || c_b >= 1){		//check if user enter other than[0,1) and enter char condt.
		cout << "Invalid input. Please try again." << endl;
 		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		continue;
		}
		if(cin.peek() != '\n'){										// check if user enter more than 3 input
		cout << "Invalid input. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		continue;
		}
	i=0;
	while(i<h){
		j=0;
		while(j<w){
			RED   = (c_r*r[i][j]) + (c_g*g[i][j]) + (c_b*b[i][j]);		//cout << RED<<"\n" ;
			GREEN = (c_r*r[i][j]) + (c_g*g[i][j]) + (c_b*b[i][j]);	    	//cout << GREEN<<"\n" ;
			BLUE  = (c_r*r[i][j]) + (c_g*g[i][j]) + (c_b*b[i][j]);		//cout << BLUE<<"\n" ;
			
		if(RED>MAX_VALUE){    r[i][j] = MAX_VALUE; }							//check max value which is 255
		else if(RED<=MAX_VALUE){  r[i][j] = RED; }
                
		if(BLUE>MAX_VALUE){    b[i][j] = MAX_VALUE; }							//check max value which is 255
		else if(BLUE<=MAX_VALUE){  b[i][j] = BLUE; }
                
		if(GREEN>MAX_VALUE){    g[i][j] = MAX_VALUE; }							//check max value which is 255
		else if(GREEN<=MAX_VALUE){  g[i][j] = GREEN; }
		j++;
		}
	i++;
	}
	break;
	}
	cout << "CONVERT TO GRAYSCALE MENU" << endl;
	cout << "0 - UP" << endl;
	cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
	cin >> select_menu;
	switch (select_menu){
	case 0:											// if user enter 0 go back scripts
		scripts();
	break;
	case 1:											// if user enter 1 take 3 value
		convert_to_gs();
	break;
	default:										// if user enter somethng not from menu
		cout << "Invalid choice." << endl;
		exit(1);
	break;
	}
}
private:
	vector<vector<int>> r;									//define 2d vectors
	vector<vector<int>> g;
	vector<vector<int>> b;
	int w=0;
	int h=0;
};
int main(){
	ImageEditor image;
	image.main_menu();
	return 0;
}
