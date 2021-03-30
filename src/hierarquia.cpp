#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include "headers/hierarquia.hpp"

using namespace std;

const int QTDE_MEMORIA_DADOS = 4096;

Hierarquia::Hierarquia()
{
    this->memoria_dados = new string[QTDE_MEMORIA_DADOS];
    this->memoria_cache = new Cache();
    for(int i=0; i<QTDE_MEMORIA_DADOS; i++){
        memoria_dados[i]= "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    }
}

void Hierarquia::converter_endereco(int endereco, string *tag, string *index, string *offset)
{
    string representacaoBinaria = bitset<12>(endereco).to_string();
    //cout << endereco << " --> " << representacaoBinaria << endl;

    *tag = representacaoBinaria.substr(0, 2);
    *index = representacaoBinaria.substr(2, 8);
    *offset = representacaoBinaria.substr(10, 2);
}

void Hierarquia::escrever(int endereco, string dado)
{
    string tag, index, offset;

    this->converter_endereco(endereco, &tag, &index, &offset);

    string resultado = this->memoria_cache->precisa_write_back(index, tag, offset);

    if(resultado == "MISS"){
        string valorCache = this->memoria_cache->get_valor(index, offset);
        this->memoria_dados[endereco] = valorCache;
    }
    this->memoria_cache->escrever(tag, index, offset, dado);

}
string Hierarquia::ler(int endereco)
{
    string tag, index, offset;

    this->converter_endereco(endereco, &tag, &index, &offset);

    /*cout << "Tag: " << tag << endl;
    cout << "Index: " << index << endl;
    cout << "Offset: " << offset << endl;*/

    string resultado = this->memoria_cache->ler(tag, index, offset);

    if (resultado == "MISS")
    {
        string valorProcurado = this->memoria_dados[endereco];
        this->memoria_cache->escrever(tag, index, offset, valorProcurado);
    }

    return resultado;
}