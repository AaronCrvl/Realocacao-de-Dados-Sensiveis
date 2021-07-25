#include "../include/Comando.hpp"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Comando::Comando(Chave c)
{
    chave = c;
}

void Comando::SetChave(char c)
{    
    this->chave = c;
}

void Comando::setServidor(char c)
{
    this->servidor = c;
}

int Comando::getServidor()
{
    return this->servidor;
}

int Comando::GetChave()
{
    return this->chave;
}

void Comando::setComando(string s)
{
    this->comando = s;    
}

string Comando::getComando()
{
    return this->comando;
}

char Comando::getIdentificador()
{
    return this->identificador;
}

void Comando::Imprime()
{
    cout << this->comando << endl;
}

void Comando::setIdentificador()
{
    identificador = comando[0];
}

void Comando::Info(char servidor, string dados)
{   
    string T_dado;           
    for(int i = 8; i <dados.size(); i++)
    {
        if(dados[i] == '"'){}
        else
        {
            T_dado += dados[i];
        }
    }
    this->comando = T_dado;
    this->Executado = true;
}

void Comando::Warn(char servidor, int posicao){}
void Comando::Tran(char servidor1, char servidor2){}
