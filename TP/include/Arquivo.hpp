#ifndef _arquivo_h
#define _arquivo_h

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Arquivo
{
    public:
        Arquivo(){} 
        ~Arquivo(){}      
        void leArquivo(string fileName);    
};
#endif