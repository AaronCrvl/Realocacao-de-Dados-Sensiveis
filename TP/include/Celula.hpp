#ifndef _celula_h
#define _celula_h

#include "../include/Comando.hpp"

using namespace std;

class Celula
{    
    public:
        //Construtor da classe
        Celula(); 
          
        //Faz a tratativa dos comandos INFO.
        //Agrega os identificadores, servidores e posições
        // conforme tipo de comando.
        void Executa();                          
        
    private:        
        Comando item;        
        Celula *prox;
        Celula *ant;       

    friend class Fifo;        
};
#endif