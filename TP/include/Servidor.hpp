#ifndef _servidor_h
#define _servidor_h

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Servidor
{
    public:    
        //Adiciona dados ao buffer do servidor.                      
        void addBuffer(string dado);  
        //Retorna os dados do buffer em uma determinada posição.        
        string getDadoBuffer(int pos);
        //Seta o tamanho do buffer.
        void setTamanho(int a); 
        //Imprime os dados do buffer do servidor.                        
        void Imprime();
        //Limpa todas as posições do buffer.
        void limpaBuffer();
        //Retorna o tamanho atual do buffer.
        int getTamanho(){return this->tamanho;}
        //Esta função limpa o buffer na posição indicada.
        void LimpaPos(int pos);        
        //Seta a primeira posição do buffer com a posição indica no parâmetro.
        void Warn(string dado);        

    private:                    
        //string *buffer;
        string buffer[30];        
        int tamanho=0;       
};  
#endif 
