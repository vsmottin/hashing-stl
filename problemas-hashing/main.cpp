#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iostream>

/*Retorna: um dicionario com a frequencia de cada inteiro, onde a chave é o inteiro
e o valor é a frequência.*/

using namespace std;

std::unordered_map<int,int> contarFrequencia(std::vector<int>& arr){
    unordered_map<int,int> dicionario;

    for (size_t i = 0; i < arr.size(); i++){
        int elem = arr[i];
        dicionario[elem]++;
    }

    return dicionario;
}

int primeiroUnico(std::vector<int>& arr){
    unordered_map<int,int> contagem;
    contagem = contarFrequencia(arr);

    for (size_t i = 0; i < arr.size(); i++){
        int elem = arr[i];
        if(contagem[elem] == 1){
            return i;
        }
    }

    return -1;
}

std::pair<int, int> twosum(std::vector<int>& arr, int k){
    unordered_map<int,int> valores = contarFrequencia(arr);
    auto init = valores.begin();
    while (init++ != valores.end()){
        int elem = init-> first;
        int num = k - elem;
        if(valores[num] > 0){
            return std::make_pair(elem, num);
        }
    }

    return make_pair(-1, -1);
}

void imprimeMap(std::unordered_map<int,int> map){
    auto init = map.begin();
    while (init != map.end()){
        std::cout << "<" << init-> first << ","  << init-> second << ">" << endl;
        init++;
    }
}

bool temDuplicatas(std::vector<int>& arr){
    
}

int main(){
    std::vector<int> arr = {1, 2, 1, 1, 5, 7, 8, 2, 3, 5, 2};
    //imprimeMap(contarFrequencia(arr));

    std::pair<int, int> par = twosum(arr, 15);
    std::cout << "<" << par.first << ","  << par.second << ">" << endl;

    return 1;
}