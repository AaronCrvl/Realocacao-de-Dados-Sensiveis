#include "../include/Arquivo.hpp"
#include "../include/Comando.hpp"
#include "../include/Fifo.hpp"

#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void Arquivo::leArquivo(string fileName)
{
    Fifo f;
    fstream file;    
    string dado;
    file.open(fileName, ios::in);
    cout << endl;
    int contador = 0; 

    while (getline(file, dado)) {    
        
        if(contador == 0)
        {    
            try
            {
                int t = stoi(dado);            
                f.setMaxTam(t);
            }
            catch(exception e)
            {
                throw "Erro ao setar tamanho máximo de servidores\n";
            }
        }
        else
        {
            Comando novo;
            novo.setComando(dado);
            f.Enfileira(novo);
        }
        contador++;
    }    
    
    Comando c;
    cout << "Impressao de Dados:"<< endl;
    while(!f.Vazia())
    {
        c = f.Desenfileira();        
        c.Imprime();        
        cout << endl;
    }
    
    cout << "Dados Tratados:" << endl;
    
        
} 

