#ifndef BOOK_H
#define BOOK_H
using std::string;
using std::vector;
using std::stringstream;
using std::ofstream;
class Book
{
public:
void fields_st(vector<string> vec){
	int i;
	vector<string>::iterator vec1 = vec.begin();
	i=0;
	while(vec1 != vec.end()){
		informations[i] = *vec1;
		i++;
		vec1++;
	}
	flag = i;
}
string fields_gt(){
	int i;
	stringstream ss;
	i=0;
	while(i < flag){
		ss << "\"" << informations[i] << "\"";
		if (i + 1 != flag){
			ss << " ";
		}
	i++;
	}
	ss << "\n";
	string lines = ss.str();
	return lines;
}
int number_of_fields()	{ return flag; }
string GetTitle()	{ return informations[0]; }
string get_field(int i)	{ return informations[i]; }
vector<string> entity_get()	{ return fields; }
void sort_one_by_one(vector<Book> boook, int i, ofstream &ofstr){
	if (i == 0){
		sort(boook.begin(), boook.end(), [](const Book &lhs, const Book &rhs)
			{ return lhs.informations[0] < rhs.informations[0]; });
	}
	else if (i == 1){
		sort(boook.begin(), boook.end(), [](const Book &lhs, const Book &rhs)
			{ return lhs.informations[1] < rhs.informations[1]; });
	}
	else if (i == 2){
		sort(boook.begin(), boook.end(), [](const Book &lhs, const Book &rhs)
			{ return lhs.informations[2] < rhs.informations[2]; });
	}
	else if (i == 3){
		sort(boook.begin(), boook.end(), [](const Book &lhs, const Book &rhs)
			{ return lhs.informations[3] < rhs.informations[3]; });
	}
	auto itr = boook.begin();
	while(itr != boook.end()){
		ofstr << itr->fields_gt();
		itr++;
	}
}
private:
	string informations[5];
	int flag;
	vector<string> fields{"\"title\"", "\"authors\"", "\"year\"", "\"tags\""};
};
#endif//BOOK_H
