#include <iostream>
#include <string>
#include <fstream>
#include "array_stack.h"

using namespace std;

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

string convertClosingToOpeningTag(string closingTag) {
    string convertedTag = '<' + closingTag.substr(2);
    return convertedTag;
}

bool xmlValidator(char fileName[100]) {

    int lineCount = 0;
    structures::ArrayStack<string> arrayStack(10);
    string line;
    ifstream in(fileName);

    while (getline(in, line)) {
        
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '<') {
                if (line[i+1] != '/') {
                    arrayStack.push(getTag(line.substr(i)));
                } else {
                    if (arrayStack.size() < 1 || convertClosingToOpeningTag(getTag(line.substr(i))) != arrayStack.top()) {
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