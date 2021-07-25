#include "../include/Fifo.hpp"
#include "../include/Celula.hpp"
#include "../include/Comando.hpp"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Fifo::Fifo()
{
    // Célula cabeça;
    frente = new Celula(); 
    tras = frente;
}

Fifo::~Fifo()
{
    Limpa();
    delete frente;
}

int Fifo::getTamanho()
{
    return this->tamanho;
}

bool Fifo::Vazia()
{
    if(tamanho == 0)
    {
        return 1;
    }

    return 0;
}

char Fifo::getChave()
{
    return this->chave;
}

void Fifo::setChave(char c)
{
    this->chave = c;
}

void Fifo::Enfileira(Comando item)
{
    Celula *nova;
    nova = new Celula();
    nova->item = item;
    nova->item.setIdentificador();       
    tras->prox = nova;     
    nova->ant = tras;      
    tras = nova;    
    tamanho++;
    nova->Executa();
}

Comando Fifo::Desenfileira() {
    Celula *p;
    Comando aux;

    if (tamanho == 0)
        cout << "Fila está vazia!";    

    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;
    delete p;

    tamanho--;
    return aux;
}

void Fifo::Limpa()
{
    Celula *p;
    p = frente->prox;
    
    while(p!=nullptr)
    {
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }

    tamanho = 0;
    tras = frente;
}

void Fifo::Saida()
{
    Celula *c;
    c = tras;        

    while( c->ant != frente->ant )
    {
        c->item.Imprime();        
        c = c->ant;                
    }
    delete c;
}

