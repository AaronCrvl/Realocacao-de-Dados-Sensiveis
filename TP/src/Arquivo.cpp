#include "../include/Arquivo.hpp"
#include "../include/Servidor.hpp"
#include "../include/Comando.hpp"
#include "../include/Fifo.hpp"

#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

void Arquivo::leArquivo(string fileName)
{            
    Fifo f, f_serv, f_aux;                    
    fstream file;    
    string dado;
    fileName += ".txt";
    int tam1=0, tam2=0; 
    file.open(fileName, ios::in);
    cout << endl;
    int contador = 0, t=0;
    string numServidores = ""; 

    //Preenchimento de filas encadeadas.
    while (getline(file, dado)) {    
        
        if(contador == 0)
        {                
            t = (int)dado[0]-48;
            numServidores = dado;
        
        } 
        else
        {
            if(dado[0] == 'I')
            {
                tam1++;
                Comando novo;                  
                novo.setComando(dado);                                                                                                                                                        
                f_serv.Enfileira(novo);                                                                                                                        
            }
            else
            {
                tam2++;
                Comando novo;                                                          
                novo.setComando(dado);                                     
                f.Enfileira(novo);
                f_aux.Enfileira(novo);
            }                                                                                                                                                  
        }
        contador++;        
    }  
    stringstream ss;
    int numServ =0;
    ss << numServidores;
    ss >> numServ;
                
    
    //Instância de Servidores     
    Servidor servidores[numServ];    
    int aux = numServ -1;

    for(int i =0; i < aux; ++i)
    {
        servidores[i].limpaBuffer(); 
        servidores[i].setTamanho(0);       
    }  

    while(tam1 >0)
    {   
        --tam1;
        Comando aux;
        char id_serv;
        string dados = "";                      
        aux = f_serv.Desenfileira();        
        id_serv = aux.getServidor();               
        int a = (int)id_serv - 48;        
        dados = aux.getComando();        
        servidores[a].addBuffer(dados);                                         
    }

    //Tratativa de Comandos Warn e Tran        
    while(tam2 >0)
    {
        --tam2;
        Comando aux;
        aux = f.Desenfileira();

        if(aux.getIdentificador() == 'W')
        {
            char id_serv, pos;
            string dados = "";                                       
            id_serv = aux.getServidor();
            int p = aux.GetChave();                  
            int s = (int)id_serv - 48;             

            if(p < 1) {}
            else
            {
                servidores[s].Warn(p);                       
            }                                                                        
        }
    }

    //Impressão Final     
    f_aux.Saida();      
    int i = numServ - 1;    
    for(i; i>=0; --i)
    {              
        if(servidores[i].getTamanho() == 0){}
        else
        {
            servidores[i].Imprime();                      
        }               
    }       
}