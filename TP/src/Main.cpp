// cd TP\src
// g++ -o p Main.cpp Fifo.cpp Comando.cpp Celula.cpp Arquivo.cpp

#include "../include/Arquivo.hpp"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    Arquivo a;    
    string s;
    cin >> s;
    a.leArquivo(s);

    return 0;
}