#include "../include/Celula.hpp"
#include "../include/Comando.hpp"

#include <string>
#include <cstring>

using namespace std;

Celula::Celula()
{
    item.SetChave(-1);
    prox = NULL;
}  

void Celula::Executa()
{
    char identificador = item.getIdentificador();
    string data = item.getComando(); 
    char servidor,servidor2, posicao;
    
    switch(identificador)
    {
        case 'I':            
            servidor = data[5];
            item.Info(servidor, data);        
        
        case 'W':
            servidor = data[5];
            posicao = data [7];
            item.Warn(servidor, posicao);
        
        case 'T':
            servidor = data[5];
            servidor2 = data [7];
            item.Tran(servidor, servidor2);

        case 'E':
            servidor = data[5];
            item.Erro(servidor);      

        case 'S':
            item.Send();

        case 'F':
            item.Flush();                              
    }
}