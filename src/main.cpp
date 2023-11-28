#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include"components/tokenizer.h"
#include"components/parser.h"
#include"components/interpreter.h"
#include"components/structs.h"
using namespace std;

void tokenizer(string line, int lineCount, vector<Token>& lineObject);
Node* parser(vector<Token>& lineObject);
void interpreter(Node* root);
void lastTest();

int main(int argc, char* argv[]){
    string filename = (argc > 1) ? argv[1] : "inputTests/basic.faf";
    ifstream inputFile(filename); 
    if (!inputFile.is_open()){
        cout << "Error opening the file." << endl;
        return 1;
    }


    string line;
    int lineCount = 0;
    while(getline(inputFile, line)){
        lineCount += 1;
        
        vector<Token> lineObject;
        tokenizer(line, lineCount, lineObject);
        if(lineObject.size() == 0) continue;
    
        Node* root = new Node();
        root = parser(lineObject);

        interpreter(root);
    }

    inputFile.close();

    lastTest();  // check if loops and if-stats are closed
    return 0;
}







