#ifndef _celula_h
#define _celula_h

#include "../include/Comando.hpp"
//#include "../include/Fifo.hpp"

using namespace std;

class Celula
{    
    public:
        Celula();
        void Executa();
        
    private:
        Comando item;
        Celula *prox;       

    friend class Fifo;        
};
#endif