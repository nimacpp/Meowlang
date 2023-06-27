#include <iostream>
#include <regex>
#include <string>
#include <map>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;
string letters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/*-+";

vector<string> split(string s, string delimiter)
{

    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}
string readfile(string name)
	{
    ifstream file(name.c_str());
    if(name.substr(name.find_last_of(".")+1) == "Meow") {

    if(!file){
    	cout<<name<<": No such file or directory "<<endl;
    	return "";
    }else{
    string line;
    string all = "";
    vector<string> rf;
    while (getline(file, line))
    {
        all = all + line;

    }
    return all;
}
}
else
	cout<<name<<": The file format must be .Meow"<<endl;
	return "";

}
void help(){
	cout<<"First, We write the required number of 'Meow'.\nAfter finishing a comma,"
	"we put it at the end and\ndo it many times so that we can create a sentence or word with it.\n"
	"[!] The list of Meows at the end \n"
	"[word] -> Number of repetitions "<<endl;
	for(int i=0;i<letters.length();i++){
		if(i%4==0){
			cout<<endl;
		}
		cout<<"["<<letters[i]<<"] -> "<<i+1<<"\t";
	}
}

string translate(string text){
	string rtn = "";int no; 
	for(auto a : split(text,",")){

		no = split(a,"Meow").size()-2;

		rtn = rtn+letters[no];

	}
 return rtn;
}

int main(int argc, char const *argv[])
{
	if(!argv[1]){
		cout<<"try 'Meow --help' for more information"<<endl;
	}else{
		string rg = argv[1];
		if(rg == "--help"){
			help();
		}else if(rg == "-f"){
			string file = argv[2];
			cout<<translate(readfile(file));
		}
	}
	return 0;
}
