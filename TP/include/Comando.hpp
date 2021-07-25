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
        //Construtor da classe
        Comando(){} 
        //Segunda construtor(opcional) da classe
        Comando(Chave c);        
        //Retorna chave(posicao) do comando.
        int GetChave();
        //Retorna o dado(string) armazenado.               
        string getComando();
        //Retorna o servidor especificado no comando.
        int getServidor(); 
        //Retorna um char que contém primeira letra do comando.
        char getIdentificador();
        //Seta o valor da chave(posicao) do comando.
        void SetChave(char c);
        //Seta o servidor especificado no comando.
        void setServidor(char c);        
        //Seta o dado(string) pertencente ao comando INFO.        
        void setComando(string s);                
        //Seta o char que contém a primeira letra do comando.
        void setIdentificador();
        //Imprime o comando.
        void Imprime();       

        //Funções de Interesse:        
        void Info(char servidor, string dados);
        void Warn(char servidor, int posicao);
        void Tran(char servidor1, char servidor2);
    
    private:
        bool Executado = false;
        string comando;        
        char chave;
        char identificador; 
        char servidor;                           
};
#endif