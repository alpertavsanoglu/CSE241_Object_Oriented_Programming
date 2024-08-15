#ifndef TEMPLATE_H
#define TEMPLATE_H
template <class T>
class Catalog
{
public:
void data_st(T dat) { data.push_back(dat); }
string entries_gt(){
	stringstream ss;
	ss << data.size() << " unique entries" << "\n";
	string line = ss.str();
	return line;
}
string GetTitle(int i) { return data[i].GetTitle(); }
vector<string> get_field() { return data[0].entity_get(); }
bool check_cod_dup(string str){
	int i=0;
	while(i < data.size()){
		if (data[i].GetTitle() == str){
			return false;
		}
		i++;
	}
	return true;
}
void find(string str, int list, ofstream &ofstr){
	string part = "\"", temp,str_1;
	size_t x = 0;
	int count = 0;
	while ((x = str.find(part)) != string::npos){
		str_1 = str.substr(0, x);
		if (count == 1){
			temp = str_1;
		}
	str.erase(0, x + part.length());
	count++;
	}
	int i=0;
	while(i < data.size()){
		if (data[i].get_field(list).find(temp) != string::npos){
			ofstr << data[i].fields_gt();
		}
	i++;
	}
}
void sotring(int informations, ofstream &ofstr){
	T catalg;
	catalg.sort_one_by_one(data, informations, ofstr);
}
private:
	vector<T> data;
};

template <class T>
string entity_parse(T dat, string str){
	string part = "\"",str_1;
	size_t x = 0;
	int count = 0;
	vector<string> vec;
	while ((x = str.find(part)) != string::npos){
		str_1 = str.substr(0, x);
		if (count % 2 != 0){
		vec.push_back(str_1);
		}
	str.erase(0, x + part.length());
	count++;
	}
	dat->fields_st(vec);
	return vec[0];
}

template <class T>
void sort_catalog(Catalog<T> catalog, ofstream &ofstr){
	ifstream file_1("commands.txt");
	string str;
	while (getline(file_1, str)){
	try{
		stringstream ss(str);
		string sort_type;
		ss >> sort_type;
		bool check = true;
		vector<string> vectr = catalog.get_field();
		if (sort_type == "search"){
			string str1;
			ss >> str1;
			ss >> sort_type;
			if (sort_type == "in"){
				ss >> sort_type;
				int i=0;
				while(i < vectr.size()){
					if (sort_type == vectr[i]){
						ofstr << str << "\n";
						catalog.find(str1, i, ofstr);
						check = false;
					}
					i++;
				}
				if (check == true){
					throw (CommandException());
				}
			}
		}
		else if (sort_type == "sort"){
			ss >> sort_type;
			int i=0;
			while(i < vectr.size()){
				if (sort_type == vectr[i]){
					ofstr << str << "\n";
					catalog.sotring(i, ofstr);
					check = false;
				}
				i++;
			}
			if (check == true){
			throw (CommandException());
			}
		}
	}
	catch (CommandException& e){
		ofstr << e.what() << "\n";
		ofstr << str << "\n";
	}
	}
	file_1.close();
}
#endif//template.h
