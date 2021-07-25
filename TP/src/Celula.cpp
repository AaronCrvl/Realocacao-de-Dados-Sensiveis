#include "../include/Celula.hpp"
#include "../include/Comando.hpp"
#include "../include/Fifo.hpp"

#include <string>
#include <cstring>

using namespace std;

Celula::Celula()
{    
    prox = NULL;
    ant = NULL;
}  

void Celula::Executa()
{
    char identificador = item.getIdentificador();
    string data = item.getComando(); 
    int chave;
    int serv;
    char servidor,servidor2, posicao;
    
    switch(identificador)
    {
        case 'I':             
            servidor = data[5];                        
            item.setServidor(servidor);                                                                                            
            item.Info(servidor, data);            
        
        case 'W':
            servidor = data[5]; 
            posicao = data [7];  
            item.setServidor(servidor);                     
            item.SetChave(posicao);             
        
        case 'T':
            servidor = data[5];
            servidor2 = data[7];
            item.setServidor(servidor);            
            item.SetChave(servidor2);             

        case 'E':
            servidor = data[5];
            item.setServidor(servidor);
            item.SetChave(servidor);                               
    }
}
