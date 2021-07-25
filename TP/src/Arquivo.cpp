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
    //Fim do preenchimento das filas encadeadas base.
    
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

    //Envio de comandos tipo INFO para os respectivos servidores.
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

    //Tratativa de Comandos Warn, Tran e Erro nos respectivos servidores.
    while(tam2 >0)
    {
        --tam2;
        Comando aux;
        aux = f.Desenfileira();

        if(aux.getIdentificador() == 'W')
        {
            char id_serv, id_serv2;
            string dados = "";
            string x = aux.getComando();
            id_serv = x[5];
            id_serv2 = x[7];                                          
            int servidor = (int)id_serv - 48;
            int posicao = (int)id_serv2 - 48; 
            int size = servidores[servidor].getTamanho();
            //servidores[s1].Warn(s2);  
            
            if(posicao != 1 && servidores[servidor].getDadoBuffer(posicao) != "")
            {
                string st[size];
                string dado = servidores[servidor].getDadoBuffer(posicao);
                servidores[servidor].LimpaPos(posicao);

                for (int i = 0; i < size; i++)
                {                    
                    st[i] = servidores[servidor].getDadoBuffer(i);                    
                }                               
                
                if(servidores[servidor].getTamanho() == 29){}
                else
                { 
                    int c = 0;
                    for(int i = 1; i< size; i++)
                    {
                        servidores[servidor].addBuffer(st[c]);
                        ++c;
                    }
                    servidores[servidor].Warn(dado);
                }                                                                                          
            }   
            else{}                                                                  
        }
        
        if(aux.getIdentificador() == 'T')
        {
            char id_serv, id_serv2;
            string dados = "";
            string st[29]; 
            string x = aux.getComando();
            id_serv =  x[5];
            id_serv2 = x[7];                                          
            int s1 = (int)id_serv - 48;
            int s2 = (int)id_serv2 - 48;                        
            int s1_tam = servidores[s1].getTamanho();
            int s2_tam = servidores[s2].getTamanho(); 
            int dif = 29 - s2_tam;

            if(s1_tam > 0)
            {
                for (int i = 0; i < s1_tam; i++)
                {                    
                    st[i] = servidores[s1].getDadoBuffer(i);                    
                }
            }
            else{}
            
            if(servidores[s2].getTamanho() == 29){}
            else
            { 
                int c = 0;
                for(int i = s2_tam; i<=dif; i++)
                {
                    servidores[s2].addBuffer(st[c]);
                    ++c;
                }
            }      
            servidores[s1].limpaBuffer();
            servidores[s1].setTamanho(0);                         
        }

        if(aux.getIdentificador() == 'E')
        {
            char id_serv;
            string x = aux.getComando();
            id_serv =  x[5];                                        
            int s1 = (int)id_serv - 48;                      
            int s1_tam = servidores[s1].getTamanho(); 
            cout << "Erro no Servidor " << s1 << endl; 
            servidores[s1].Imprime();
            cout << endl << endl;
            servidores[s1].limpaBuffer();
            servidores[s1].setTamanho(0);
        }
    }

    //Output Final     
    f_aux.Saida();      
    int i = numServ - 1;    
    for(i; i>0; --i)
    {              
        if(servidores[i].getTamanho() == 0){}
        else
        {
            servidores[i].Imprime();                      
        }                      
    }      
}