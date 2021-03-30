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
    void converter_endereco(int endereco, string *tag, string *index, string *offset);

public:
    Hierarquia();

    void escrever(int endereco, string dado);

    string ler(int endereco);
};

#endif