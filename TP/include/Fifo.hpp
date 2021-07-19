#ifndef _fifo_h
#define _fifo_h

#include "../include/Fifo.hpp"
#include "../include/Celula.hpp"

using namespace std;

class Fifo
{    

    public:
        Fifo();
        virtual ~Fifo();

        int getTamanho();
        int getMaxTam();        
        void setMaxTam(int t);
        bool Vazia();

        Celula* getFrente(){ return this->frente; }
        void setChave(int c);                    

        void Enfileira(Comando item);
        Comando Desenfileira();    
        void Limpa();
            
    private:    
        int maxTam,tamanho;
        int chave;
        Celula *frente;
        Celula *tras;
};
#endif