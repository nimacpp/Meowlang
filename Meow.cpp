#include "Meow.h"

using namespace std;

//vector<string> setting;

int main(int argc, char const *argv[])
{
	string ag ;
	for(int i=1;i< argc;i++){
		//cout<<"|"<<argv[i]<<"|"<<endl;
		ag = argv[i];
		if((ag == "-h")||(ag == "--help")){
			cout<<"usage: Meow <operation> [...]\n"
				  "operations:\n"
				  "\tMeow {-h --help}\n"
				  "\tMeow {-v --version}\n"
				  "\tMeow {-l --list}\n"
				  "\tMeow {-d --decode}  [file]\n"
				  "\tMeow {-e --encode}  [file]\n"
				  "use 'Meow {-h --help}' with an operation for available options\n"
				  <<endl;
			//setting.insert("help");
		}else if((ag == "-d")||(ag == "--decode")){
			 string file = argv[i+1];
			 i++;
			 cout<<decode(readfile(file))<<endl;
		}else if((ag == "-e")||(ag == "--encode")){
			 string file = argv[i+1];
			 i++;
			 cout<<encode(readfile(file))<<endl;
		}else if((ag == "-v")||(ag == "--version")){
			cout<<
"       _                        \n"
"       \\`*-.                   Meowlang v1.2.1 - c++ v.11 \n"
"        )  _`-.                copyright (C) 2023 Nimacpp(nioxteam) \n"
"       .  : `. .               it's the Meow lang and the only reason\n"
"       : _   '  \\              to make it is to bring a smile to your\n"
"       `-.-'          `-.      face .\n"
"         ;       `       `.     \n"
"         :.       .        \\    \n"
"         . \\  .   :   .-'   .   \n"
"         '  `+.;  ;  '      :   \n"
"         :  '  |    ;       ;-.    github.com/Nimacpp/Meowlang\n"
"         ; '   : :`-:     _.`* ;   Inventor: Nimacpp    \n"
"[bug] .*' /  .*' ; .*`- +'  `*' \n"
"      `*-*   `*-*  `*-*'\n";

		}else if((ag == "-l")||(ag == "-list")){
			help();

		}else{
			cout<<"error: invalid option '"<<ag<<"'"<<endl;
		}
	}
	return 0;
}