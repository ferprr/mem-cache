#ifndef bloco
#define bloco
#include <string>

using namespace std;

class Bloco
{
private:
    string *palavras;
    string tag;
    bool sujo;

public:
    Bloco();

    bool is_sujo();
    string get_tag();
    //void set_endereco(string endereco);
};

#endif