#ifndef _celula_h
#define _celula_h

#include "../include/Comando.hpp"

using namespace std;

class Celula
{    
    public:
        Celula(); 
        //Retorna a chave da célula.    
        int getChave();
        //Seta a chave da célula.        
        void setChave(char c);   
        //Faz a tratativa dos comandos INFO.
        //Agrega os identificadores, servidores e posições
        // conforme tipo de comando.
        void Executa();                          
        
    private:
        int servidor;
        Comando item;
        int chave=0;
        Celula *prox;
        Celula *ant;       

    friend class Fifo;        
};
#endif