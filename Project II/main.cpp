// Copyright [2022] <Matheus Aparicio da Silva>

#include "prefix_tree.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{

    using namespace std;
    using structures::ArrayList;
    using structures::PrefixTree;

    // Definições
    string filename;
    string word;
    PrefixTree prefix_tree;
    std::ifstream dicFile;

    cin >> filename;
    dicFile.open(filename);

    // Abrir o arquivo especificado
    if (dicFile.is_open())
    {

        bool reading_prefix;
        string line;
        string prefix = "";
        unsigned long position = 0; // Posição do caractere

        while (getline(dicFile, line))
        {
            for (std::size_t i = 0; i < line.size(); ++i)
            {
                if (i == 0)
                {
                    reading_prefix = true;
                }
                else if (reading_prefix && (line[i] >= 'a' && line[i] <= 'z'))
                {
                    prefix.push_back(line[i]);
                }
                else
                {
                    reading_prefix = false;
                }
            }

            prefix_tree.insert(prefix, position, line.size());
            prefix.clear();
            position += line.size() + 1;
        }

        dicFile.close();
    }
    else
    {
        throw std::out_of_range("File not found");
    }

    unsigned long prefix_count;
    unsigned long position;
    unsigned long length;

    // Ler os inputs até encontrar 0
    while (1)
    {

        cin >> word;

        if (word.compare("0") == 0)
        {
            break;
        }

        // Obtém a quantidade de prefixos contidos na palavra
        prefix_count = prefix_tree.prefix_search(word);

        // Se tiver mais que 1 palavra
        if (prefix_count > 0)
        {

            cout << word << " is prefix of " << prefix_count << " words" << endl;

            position = prefix_tree.position_search(word);
            length = prefix_tree.length_search(word);

            if (length != 0)
            {
                cout << word << " is at (" << position << "," << length << ")" << endl;
            }
        }
        else
        { // Caso nenhuma palavra tenha sido encontrada.
            cout << word << " is not prefix" << endl;
        }
    }

    return 0;
}
