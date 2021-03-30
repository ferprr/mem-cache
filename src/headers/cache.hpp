#ifndef cache
#define cache

#include "bloco.hpp"

using namespace std;

class Cache
{
private:
    Bloco *blocos;

public:
    Cache();
    string ler(string tag, string index, string offset);

    void escrever(string tag, string index, string offset, string valor);
    //bool get_sujo();
    //void set_dado(int pos_bloco, string endereco);
};

#endif