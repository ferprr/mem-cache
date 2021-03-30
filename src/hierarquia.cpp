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
    cout << "Nada por enquanto" << endl;
    //this->cache.set_dado(int endereco, string dado);

    //chama metodo converter endereco e buscar valores offset, index e tag
    //verificar se na cache, bloco com index==index está sujo
    //se estiver limpo: colocar dado na posição do index + offset na cache
    //se não: devemos pegar o valor que estiver na posição do index + offset + tag na cache
    //colocar valor encontrado acima na memória de dados e colocar dado na posição do index + offset na cache
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
        //this->memoria_cache->escrever(tag, index, offset, valorProcurado);
    }

    return resultado;
}