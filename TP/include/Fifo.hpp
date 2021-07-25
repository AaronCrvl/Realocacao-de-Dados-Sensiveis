#ifndef _fifo_h
#define _fifo_h

#include "../include/Fifo.hpp"
#include "../include/Celula.hpp"

using namespace std;

class Fifo
{    
    public:
        //Construtor da classe
        Fifo();
        //Destrutor virtual da classe;
        virtual ~Fifo();
        //Retorna o tamanho da fila encadeada.
        int getTamanho();                     
        // Retorna a chave da fila encadeda.
        char getChave();     
        //Seta a chave da fila encadeada.       
        void setChave(char c);   
        //Limpa todas as posições da fila encadeada.
        void Limpa();
        //Imrpime a fila encadeada da forma solicitada.
        void Saida();                 
        //Enfileira uma celula na fila.
        void Enfileira(Comando item);
        //Retorna se esta fila está vazia ou não(tamanho == 0).
        bool Vazia(); 
        //Desenfileira uma celula da fila.
        Comando Desenfileira();            
                             
    private:    
        int tamanho;
        char chave = 'z';
        Celula *frente;
        Celula *tras;
};
#endif