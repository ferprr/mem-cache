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

    void set_sujo(bool sujo);
    bool is_sujo();

    void set_tag(string tag);
    string get_tag();

    void set_valor(int offset, string valor);
    string get_valor(int offset);
    //void set_endereco(string endereco);
};

#endif