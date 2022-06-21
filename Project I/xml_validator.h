#include <iostream>
#include <string>
#include <fstream>
#include "array_stack.h"

using namespace std;

// Função feita para pegar a tag completa quando um '<' for encontrado.
string getTag(string line) {

    string tag = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != '>') {
            tag += line[i];
        } else {
            tag += line[i];
            break;
        }
    }

    return tag;

}

// Função para converter uma tag de encerramento para uma de abertura.
string convertClosingToOpeningTag(string closingTag) {

    string convertedTag = '<' + closingTag.substr(2);
    return convertedTag;

}

//Função para validar arquivos XML.
bool xmlValidator(char fileName[100]) {

    // Variáveis declaração de algumas variáveis.
    int lineCount = 0;
    structures::ArrayStack<string> arrayStack(10);
    string line;
    ifstream in(fileName);

    while (getline(in, line)) {
        
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '<') { // Se encontrar um '<'.
                if (line[i+1] != '/') { // Se for uma tag de abertura.
                    arrayStack.push(getTag(line.substr(i)));
                } else { // Se for uma tag de encerramento.
                    if (arrayStack.size() < 1 || convertClosingToOpeningTag(getTag(line.substr(i))) != arrayStack.top()) { // Se a pilha estiver vazia ou o topo da pilha ser diferente da tag sendo fechada.
                        return 0;
                    } else {
                        arrayStack.pop();
                    }
                }
            }
        }

        lineCount++;
    }

    if (arrayStack.size() > 0) {
        return 0;
    }

    return 1;

}