#include <iostream>
#include <string>
#include "parser.h"
#include "scanner.h"
// #include <regex>
using namespace std;

// string normalize(const string& s){
// 	regex space("[ \\n\\r]+");//remove all space
// 	string temp = regex_replace(s,space,"");
// 	regex equal_sign("[=]");//add space beside '='
// 	temp = regex_replace(temp,equal_sign," = ");
// 	regex seperator("[;,]");//add space after ';' or ','
// 	temp = regex_replace(temp,seperator,"$& ");
// 	return temp;
// }

int main(){
	string input, parserText="", output;
	Parser * parser;
	while(true){
		do{
			if(parserText == "")
				cout << "?- ";
			else	
				cout << "|  ";
			getline(cin, input);
			if (input != "")
                while (input[0] == ' ')
                    input = input.substr(1, input.size() - 1);
			parserText += input;
		}while(input == "" || parserText.back() != '.');
		if(parserText =="halt.")
			break;
		parser = new Parser(Scanner(parserText));
		try{
			parser->buildExpression();
			output = parser->getResult();
			cout<< output << endl;
		}catch (string &msg){
            cout << msg << endl;
		}
		parserText.clear();
	}
}