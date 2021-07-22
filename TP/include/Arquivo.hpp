#ifndef _arquivo_h
#define _arquivo_h

#include "../include/Fifo.hpp"
#include "../include/Comando.hpp"
#include "../include/Servidor.hpp"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Arquivo
{
    public:         
        Arquivo(){} 
        ~Arquivo(){} 

        //Lê o arquivo base.     
        void leArquivo(string fileName);                                                                
};
#endif