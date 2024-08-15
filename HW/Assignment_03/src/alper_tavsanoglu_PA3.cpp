#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
const int MAX_VALUE = 255;			//max value 
const int MIN_VALUE = 0;			//min value 
using namespace std;

class ppmImage
{
public:
	ppmImage(){}
	int image_save_function(string output_filename)const;
	int take_file_function(string output_filename);
	void change_pixel_value(char selected_colour, int new_colour, int index_1, int index_2);
	int get_h()const {return h;}
	int get_w()const {return w;}
	friend ppmImage operator +(const ppmImage& first_image, const ppmImage& second_image);		//Adds two ppmImage objects
	friend ppmImage operator -(const ppmImage& first_image, const ppmImage& second_image);		//subtracts one image from the other
	friend ostream& operator <<(ostream& print_img_info, const ppmImage& img);			// Prints image details and image data to stdout.
	int& operator () (int w, int h, int color_channel);						//Function-call operator
private:
	int h=0;
	int w=0;
	vector<vector<int>> r;									//define 2d vectors
	vector<vector<int>> g;
	vector<vector<int>> b;
};
//Standalone Functions
int read_ppm(const string source_ppm_file_name, ppmImage& destination_object){   		// reads ppm data from file named as source_ppm_file_name.
	return destination_object.take_file_function(source_ppm_file_name);
}
int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object){		// writes ppm data from source_object to the file named destination_ppm_file_name.
	return source_object.image_save_function(destination_ppm_file_name);   
}
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3){	// reads images from filename_image1 and filename_image2. Adds them and saves the result
	ppmImage img1, img2;
	read_ppm(filename_image1, img1);
	read_ppm(filename_image2, img2);
	ppmImage sum_obj = img1 + img2;
	return write_ppm(filename_image3, sum_obj);
}
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){	//reads images from filename_image1 and filename_image2. subs. them and saves the result
	ppmImage img1, img2;
	read_ppm(filename_image1, img1);
	read_ppm(filename_image2, img2);
	ppmImage sum_obj = img1 - img2;
	return write_ppm(filename_image3, sum_obj);
}
int test_print(const string filename_image1){								// reads images from filename_image1 and prints it to stdout
	ppmImage img;
	int operation = read_ppm(filename_image1, img);
	cout << img;
	if(!operation)
	return 0;
	return 1;
}
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice){				// this function swaps the color values of every pixel in a given ppm image
int i,j;
int store_w = image_object_to_be_modified.get_w();
int store_h = image_object_to_be_modified.get_h();
int store_red,store_green,store_blue;
switch(swap_choice){
	case 1:												// if choice number is 1
		i=0;
		while(i<store_w){
			j=0;
			while(j<store_h){
					store_red  = image_object_to_be_modified(i, j, 1);		//store pixels
					store_green= image_object_to_be_modified(i, j, 2);
					store_blue = image_object_to_be_modified(i, j, 3);
					image_object_to_be_modified.change_pixel_value('R', store_green, i, j);		//change pixels
					image_object_to_be_modified.change_pixel_value('G', store_red, i, j);
			j++;
			}
		i++;
		}
		return 1;
	break;
	case 2:												// if choice number is 2
		i=0;
		while(i<store_w){
			j=0;
			while(j<store_h){
					store_red  = image_object_to_be_modified(i, j, 1);		//store pixels
					store_green= image_object_to_be_modified(i, j, 2);
					store_blue = image_object_to_be_modified(i, j, 3);
					image_object_to_be_modified.change_pixel_value('R', store_blue, i, j);		//change pixels
					image_object_to_be_modified.change_pixel_value('B', store_red, i, j);
			j++;
			}
		i++;
		}
		return 1;
	break;
	case 3:												// if choice number is 3
		i=0;
		while(i<store_w){
			j=0;
			while(j<store_h){
					store_red  = image_object_to_be_modified(i, j, 1);		//store pixels
					store_green= image_object_to_be_modified(i, j, 2);
					store_blue = image_object_to_be_modified(i, j, 3);
					image_object_to_be_modified.change_pixel_value('G', store_blue, i, j);		//change pixels
					image_object_to_be_modified.change_pixel_value('B', store_green, i, j);
			j++;
			}
		i++;
		}
		return 1;
	break;
	default:
		return 1;
	break;
	}
return 0;
}
ppmImage single_color(const ppmImage& source, int color_choice){		// this function swaps the color values of every pixel in a given ppm image

ppmImage image = source;
int i,j;
int store_w = image.get_w();
int store_h = image.get_h();

switch(color_choice){
	case 1:										// if choice number is 1
		i=0;
		while(i<store_w){
			j=0;
			while(j<store_h){
					image.change_pixel_value('G', 0, i, j);		//change pixels
                			image.change_pixel_value('B', 0, i, j);
			j++;
			}
		i++;
		}
	break;
	case 2:										// if choice number is 2
		i=0;
		while(i<store_w){
			j=0;
			while(j<store_h){
					image.change_pixel_value('R', 0, i, j);		//change pixels
                			image.change_pixel_value('B', 0, i, j);
			j++;
			}
		i++;
		}
	break;
	case 3:										// if choice number is 3
		i=0;
		while(i<store_w){
			j=0;
			while(j<store_h){
					image.change_pixel_value('G', 0, i, j);		//change pixels
                			image.change_pixel_value('R', 0, i, j);
			j++;
			}
		i++;
		}
	break;
	default:
		exit(0);
	break;
	}
return image;
}
// Main Function
int main(int argc, char** argv){
ppmImage image;
ppmImage newimage;

	if(argc < 3 && argc > 5)							//check command-line arguments
		return 0;

int choice = atoi(argv[1]);								//save command-line argument
string ppm_file_name1 = argv[2];
	
string ppm_file_name2;
	if(argc == 4 || argc == 5)
		ppm_file_name2 = argv[3];						//save command-line argument

string ppm_file_name3;
	if(argc == 5) 
		ppm_file_name3 = argv[4];						//save command-line argument
		
switch(choice){
	case 1:										// if choice number is 1
		if(argc != 5) return 0;
        	test_addition(ppm_file_name1, ppm_file_name2, ppm_file_name3);
	break;
	case 2:										// if choice number is 2
		if(argc != 5) return 0;
		test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
	break;
	case 3:										// if choice number is 3
		read_ppm(ppm_file_name1, image);
		swap_channels(image, 2);
		write_ppm(ppm_file_name2, image);
	break;
	case 4:										// if choice number is 4
		read_ppm(ppm_file_name1, image);
		swap_channels(image, 3);
		write_ppm(ppm_file_name2, image);
	break;
	case 5:										// if choice number is 5
		read_ppm(ppm_file_name1, image);
		newimage = single_color(image, 1);
		write_ppm(ppm_file_name2, newimage);
	break;
	case 6:										// if choice number is 6
		read_ppm(ppm_file_name1, image);
		newimage = single_color(image, 2);
		write_ppm(ppm_file_name2, newimage);
	break;
	case 7:										// if choice number is 7
		read_ppm(ppm_file_name1, image);
		newimage = single_color(image, 3);
		write_ppm(ppm_file_name2, newimage);
	break;
	default:									// if user enter somethng not from menu
			cout << "Invalid choice." << endl;
			return 0;
	break;
	}
return 0;
}
int ppmImage::image_save_function(string output_filename)const{					//Implement member functions for reading image files and writing image data to files
	int i,j;
	string format = "P3";
	ofstream new_file;							//take file name from user
	new_file.open(output_filename);
	if(!new_file){									//Unable to open file
	cout << "File didnt create" << endl; 
	return 0;
		}
	new_file << format << endl << h << " " << w << endl << MAX_VALUE << endl;	// save image informations from file (format,w, h, max valu which is 255)
	i = 0;
	while(i<w){
		j = 0;
		while(j<h){
		new_file << r[i][j] << " " << g[i][j] << " " << b[i][j] << " ";		// save image informations from file (r g b)
		j++;
		}
	new_file << endl;
	i++;
	}
	new_file.close();								//close file
	return 1;
}
int ppmImage::take_file_function(const string output_filename){				//Implement member functions for reading image files and writing image data to files
	int i,j,max;
	string format = "P3";
	ifstream image;
	image.open(output_filename);
	if(!image){									//Unable to open file
	cout << "File didnt create" << endl;
	return 0;
	}
	image >> format >> h >> w >> max;						//cout << h<<"\n" ;		//cout << w<<"\n" ;		// take informations from file
	r.resize(h);
	g.resize(h);
	b.resize(h);									//resize vectors with width value
	i = 0;
	while(i<h){
	r[i].resize(w);
	g[i].resize(w);
	b[i].resize(w);									//resize vectors with height value
	i++;
	}
		i = 0;
		while(i<w){
			j = 0;
			while(j<h){
			image >> r[i][j] >> g[i][j] >> b[i][j];				// take image informations from file
			j++;
			}
		i++;
		}
	image.close();									// close file
	return 1;
}
void ppmImage::change_pixel_value(char selected_colour, int new_colour, int index_1, int index_2){	//A member function which changes individual pixel values.
switch(selected_colour){
	case 'R':
		r[index_1][index_2] = new_colour;
	break;
	case 'G':
		g[index_1][index_2] = new_colour;
	break;
	case 'B':
		b[index_1][index_2] = new_colour;
	break;
	default:
		exit(1);
	break;
	}
}
ppmImage operator +(const ppmImage& first_image, const ppmImage& second_image){				//Adds two ppmImage objects
int i,j,RED, BLUE, GREEN;
ppmImage add;

add.h = first_image.h;
add.w = first_image.w;
add.r.resize(first_image.w);										//resize vectors with width value
add.g.resize(first_image.w);
add.b.resize(first_image.w);

i=0;
while(i < first_image.w){										//resize vectors with height value
	add.r[i].resize(first_image.h);
	add.g[i].resize(first_image.h);
	add.b[i].resize(first_image.h);
i++;
}
	i=0;
	while(i<first_image.get_w()){
		j=0;
		while(j<first_image.get_h()){
			RED = first_image.r[i][j] + second_image.r[i][j]; 				//Adds two ppmImage objects
			if(RED>MAX_VALUE){    add.r[i][j] = MAX_VALUE; }				//check max value which is 255
			else if(RED<=MAX_VALUE){  add.r[i][j] = RED; }

			GREEN = first_image.g[i][j] + second_image.g[i][j]; 				//Adds two ppmImage objects
			if(GREEN>MAX_VALUE){    add.g[i][j] = MAX_VALUE; }				//check max value which is 255
			else if(GREEN<=MAX_VALUE){  add.g[i][j] = GREEN; }

			BLUE = first_image.b[i][j] + second_image.b[i][j]; 				//Adds two ppmImage objects
			if(BLUE>MAX_VALUE){    add.b[i][j] = MAX_VALUE; }				//check max value which is 255
			else if(BLUE<=MAX_VALUE){  add.b[i][j] = BLUE; }
		j++;
		}
	i++;
	}
return add;
}
ppmImage operator -(const ppmImage& first_image, const ppmImage& second_image){				//subtracts one image from the other
int i,j,RED, BLUE, GREEN;
ppmImage add;

add.h = first_image.h;
add.w = first_image.w;
add.r.resize(first_image.w);										//resize vectors with width value
add.g.resize(first_image.w);
add.b.resize(first_image.w);

i=0;
while(i < first_image.w){										//resize vectors with height value
	add.r[i].resize(first_image.h);
	add.g[i].resize(first_image.h);
	add.b[i].resize(first_image.h);
i++;
}
	i=0;
	while(i<first_image.get_w()){
		j=0;
		while(j<first_image.get_h()){
			RED = first_image.r[i][j] - second_image.r[i][j];				//subtracts one image from the other
			if(RED<MIN_VALUE){    add.r[i][j] = MIN_VALUE; }				//check min value which is 0
			else if(RED>=MIN_VALUE){  add.r[i][j] = RED; }

			GREEN = first_image.g[i][j] - second_image.g[i][j]; 				//subtracts one image from the other
			if(GREEN<MIN_VALUE){    add.g[i][j] = MIN_VALUE; }				//check min value which is 0
			else if(GREEN>=MIN_VALUE){  add.g[i][j] = GREEN; }

			BLUE = first_image.b[i][j] - second_image.b[i][j]; 				//subtracts one image from the other
			if(BLUE<MIN_VALUE){    add.b[i][j] = MIN_VALUE; }				//check min value which is 0
			else if(BLUE>=MIN_VALUE){  add.b[i][j] = BLUE; }
		j++;
		}
	i++;
	}
return add;
}
ostream& operator <<(ostream& print_img_info, const ppmImage& img){				// Prints image details and image data to stdout.
int i,j;
string format = "P3";
print_img_info << format << endl << img.h << " " << img.w << endl << MAX_VALUE << endl;		// save image informations from file (format,w, h, max valu which is 255)
	i=0;
	while(i<img.w){
		j=0;
		while(j<img.h){
			print_img_info << img.r[i][j] << " " << img.g[i][j] << " " << img.b[i][j];	// save image informations from file (r g b)
			if(j==img.h-1){ print_img_info << endl; }					//checking for extra spaces
			else print_img_info << " ";
		j++;
		}
	i++;
	}
return print_img_info;
}
int& ppmImage::operator()(int w, int h, int color_channel){		 //Function-call operator
switch(color_channel){
	case 1:
		return this->r[w][h];
	break;
	case 2:
		return this->g[w][h];
	case 3:
		return this->b[w][h];					//This operator returns a reference to the pixel value
	break;
	default:
		exit(1);
	break;
	}
}
