#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "exceptions.h"
#include "music.h"
#include "movie.h"
#include "book.h"
#include "template.h"
using namespace std;
int main()
{
	ifstream file_in("data.txt");
	ofstream file_out("output.txt");
	string str;
	file_in >> str;
	if (str == "book"){
		file_out << "Catalog Read: book" << "\n";
		Catalog<Book> catalog;
		Book *boook = new Book;
		getline(file_in, str);
		while (getline(file_in, str)){
		try{
			if (catalog.check_cod_dup(entity_parse(boook, str))){
				if (4 != boook->number_of_fields()){
					throw (MissingException());
				}
				else{
					catalog.data_st(*boook);
				}
			}
			else{
				if (4 != boook->number_of_fields()){
					throw (MissingException());
				}
				else{
					throw (DuplicateException());
				}
				file_out<<boook->fields_gt();
			}
		}
		catch (MissingException& e){
			file_out << e.what() << "\n";
			file_out<< boook->fields_gt();
		}
		catch (DuplicateException& e){
			file_out << e.what() << "\n";
			file_out<< boook->fields_gt();
		}
		}
		file_out<< catalog.entries_gt();
		sort_catalog(catalog, file_out);
		file_out.close();
		file_in.close();
	}
	else if (str == "music"){
		file_out << "Catalog Read: music" << "\n";
		Catalog<Music> catalog;
		Music *msc = new Music;
		getline(file_in, str);
		while (getline(file_in, str)){
		try{
			if (catalog.check_cod_dup(entity_parse(msc, str))){
				if (4 != msc->number_of_fields()){
					throw (MissingException());
				}
				else{
					catalog.data_st(*msc);
				}
			}
			else{
				if (4 != msc->number_of_fields()){
					throw (MissingException());
				}
				else{
					throw (DuplicateException());
				}
				file_out<<msc->fields_gt();
			}
		}
		catch (MissingException& e){
			file_out << e.what() << "\n";
			file_out<< msc->fields_gt();
		}
		catch (DuplicateException& e){
			file_out << e.what() << "\n";
			file_out<< msc->fields_gt();
		}
		}
		file_out << catalog.entries_gt();
		sort_catalog(catalog, file_out);
		file_out.close();
		file_in.close();
	}
	else if (str == "movie"){
		file_out << "Catalog Read: movie" << "\n";
		Catalog<Movie> catalog;
		Movie *mvie = new Movie;
		getline(file_in, str);
		while (getline(file_in, str)){
		try{
			if (catalog.check_cod_dup(entity_parse(mvie, str))){
				if (5 != mvie->number_of_fields()){
					throw (MissingException());
				}
				else{
					catalog.data_st(*mvie);
				}
			}
			else{
				if (5 != mvie->number_of_fields()){
					throw (MissingException());
				}
				else{
					throw (DuplicateException());
				}
				file_out<< mvie->fields_gt();
			}
		}
		catch (MissingException& e){
			file_out << e.what() << "\n";
			file_out<< mvie->fields_gt();
		}
		catch (DuplicateException& e){
			file_out << e.what() << "\n";
			file_out<< mvie->fields_gt();
		}
		}
		file_out << catalog.entries_gt();
		sort_catalog(catalog, file_out);
		file_out.close();
		file_in.close();
	}
	else{
		return 0;
	}
}
