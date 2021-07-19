#ifndef _comando_h
#define _comando_h

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
typedef int Chave; // TipoChave é um inteiro

class Comando
{
    public:
        Comando(){} //{ SetChave(-1); };
        Comando(Chave c);

        void SetChave(Chave c);
        Chave GetChave();

        void setComando(string s);
        string getComando();
        char getIdentificador();
        void setIdentificador();
        void Imprime();        

        //Funções de Interesse:        
        void Info(char servidor, string dados);
        void Warn(char servidor, int posicao);
        void Tran(char servidor1, char servidor2);
        void Erro(char servidor);
        void Send();
        void Flush();
 

    
    private:
        bool Executado = false;
        string comando;        
        Chave chave;
        char identificador;       
                
    // outros membros           
};
#endif