#include <iostream>
#include <string>
#include <fstream>
#include "xml_validator.h"

using namespace std;

void xmlComponentCounter(char fileName[100]) {
    if (xmlValidator(fileName)) {
        //
    } else {
        cout << "error" << endl;
    }
}