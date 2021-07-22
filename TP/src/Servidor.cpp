#include "../include/Servidor.hpp"
#include "../include/Fifo.hpp"
#include "../include/Celula.hpp"
#include "../include/Comando.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

void Servidor::setTamanho(int a)
{
    this->tamanho = a;
}

void Servidor::Warn(int pos)
{
    string aux = "";
    aux = buffer[pos];

    for (int  i = 0; i < 14; i++)
    {   
        if(i == 0){}
        else
        {
            string aux = buffer[i];
            buffer[i] = buffer[i-1];
            buffer[i-1] = aux;        
        }                                                          
    }
    buffer[0] = aux;           
}

void Servidor::addBuffer(string dado)
{     
    buffer[tamanho] = dado;
    tamanho++;   
}

void Servidor::limpaBuffer()
{
    for(int i = 0; i<= 14; i++)
    {
        this->buffer[i].clear();
    }
}

void Servidor::Imprime()
{            
    for(int t =0; t<14; ++t)
    {           
        if(buffer[t] == ""){}
        else
        {                         
            cout << buffer[t] << endl;             
        }        
    }     
}

