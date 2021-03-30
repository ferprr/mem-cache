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
    string precisa_write_back(string index, string tag, string offset);
    void escrever(string tag, string index, string offset, string valor);
    string get_valor(string index, string offset);
};

#endif