#ifndef cache
#define cache
#include <string>
#include "bloco.hpp"

using namespace std;

class Cache
{
private:
    Bloco *bloco;
    string *tag;
    bool *sujo;

public:
    Bloco();
    bool get_sujo();
    void set_dado(int pos_bloco, string endereco);
};

#endif