#ifndef hierarquia
#define hierarquia
#include <string>
#include "cache.hpp"

using namespace std;

class Hierarquia
{
private:
    string memoria_dados[4096];
    Cache *cache;
    void converter_endereco(int endereco, int *tag, int *index, int *offset);

public:
    void set_endereco(int endereco, string dado);
};

#endif