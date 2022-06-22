#include <iostream>
#include <string>
#include <fstream>
#include "xml_validator.h"

using namespace std;


// Função feita para pegar a tag completa quando um '<' for encontrado.
int getSize(string line) {

    string valueString = "";
    bool canGetValue = false;
    string tag = "";

    for (int i = 0; i < line.length(); i++) {

        if (canGetValue) {
            valueString += line[i];
        }

        if (line[i] == '>') {
            canGetValue = true;
        } else if (line[i] == '<') {
            break;
        }
    }

    int valueInt = atoi(valueString.c_str());

    return valueInt;

}


void xmlComponentCounter(char fileName[100]) {
    if (xmlValidator(fileName)) {
        
        int lineCount = 0;
        bool canGetData = false;
        int width = 0;
        int height = 0;
        int data[width][height];

        string line;
        ifstream in(fileName);

        while (getline(in, line)) {
            
            for (int i = 0; i < line.length(); i++) {

                // Define o tamanho da imagem.
                if (line[i] == '<') {
                    if (getTag(line.substr(i)) == "<width>") {
                        width = getSize(line.substr(i));
                        cout << "AAAAAA " << width << endl;
                    } else if ((getTag(line.substr(i)) == "<height>")) {
                        height = getSize(line.substr(i));
                        cout << "AAAAAA " << height << endl;
                    }
                }

                // Define quando é possível pegar a imagem.
                if (line[i] == '<') {
                    if (getTag(line.substr(i)) == "<data>") {
                        canGetData = true;
                        int data[width][height];
                    } else if ((getTag(line.substr(i)) == "</data>")) {
                        canGetData = false;
                    }
                    break;
                }

                if (canGetData) {
                    cout << line[i] << " ";
                    //data[i][lineCount] = line[i];
                }

            }
                
            lineCount++;
            cout << endl;
        }

    } else {
        cout << "error" << endl;
    }
}