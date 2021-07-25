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

string Servidor::getDadoBuffer(int pos)
{
    return this->buffer[pos];
} 

void Servidor::Warn(string dado)
{    
    buffer[0] = dado;        
}

void Servidor::LimpaPos(int pos)
{
    this->buffer[pos].clear();
}

void Servidor::addBuffer(string dado)
{     
    buffer[tamanho] = dado;
    tamanho++; 
    
    //Tentativa de implementar buffer dinâmico.
    /*
    cout << "Tamanho: " << tamanho << endl;
    ++tamanho;   
    int newTam = tamanho+1;
    cout << "Tamanho2: " << tamanho << endl;
    string newBuffer[newTam];
    
    //ewBuffer = new string[]; 

    for (int i = 0; i < tamanho; ++i)
    {   
        cout << "Loop" << endl;             
        newBuffer[i] = buffer[i];
        cout << "Buffer: " << newBuffer[i]<< endl;                
    }
            
    cout << "Dado: " << dado << endl; 
    newBuffer[tamanho++] = dado;            
    delete[] buffer;
    buffer = newBuffer; 
    */   
}

void Servidor::limpaBuffer()
{
    for(int i = 0; i<= 29; i++)
    {
        this->buffer[i].clear();
    }
}

void Servidor::Imprime()
{            
    for(int t =0; t<29; ++t)
    {           
        if(buffer[t] == ""){}
        else
        {                         
            cout << buffer[t] << endl;             
        }        
    }     
}

