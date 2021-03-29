#ifndef hierarquia
#define hierarquia
#include <string>
#include "cache.hpp"

using namespace std;

class Hierarquia
{
private:
    string *memoria_dados;
    Cache *memoria_cache;
    void converter_endereco(int endereco, int *tag, int *index, int *offset);

public:
    Hierarquia();
    void escreverNaCache(int endereco, string dado);
};

#endif