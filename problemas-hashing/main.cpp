#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

/*Retorna: um dicionario com a frequencia de cada inteiro, onde a chave é o inteiro
e o valor é a frequência.*/

using namespace std;

std::unordered_map<int,int> contarFrequencia(std::vector<int>& arr){
    unordered_map<int,int> dicionario;

    for (int i : arr){
        dicionario[i]++;
    }

    return dicionario;
}

int primeiroUnico(std::vector<int>& arr){
    unordered_map<int,int> contagem = contarFrequencia(arr);
    
    for (int i : arr) {
        if (contagem[i] == 1) {
            return i; 
        }
    }

    return -1;
}

std::pair<int, int> twosum(std::vector<int>& arr, int k){
    std::unordered_set<int> valores;
    for (int i : arr) {
        int complemento = k - i;
        if (valores.count(complemento)) {
            return std::make_pair(complemento, i);
        }

        valores.insert(i);
    }
    return std::make_pair(-1, -1);
}

bool temDuplicatas(std::vector<int>& arr){
    std::unordered_set<int> valores;
    for(int i : arr){
        if(valores.count(i) > 0){
            return true;
        }

        valores.insert(i);
    }

    return false;
}

std::vector<int> semDuplicatas(std::vector<int>& arr){
    std::unordered_set<int> valores;
    std::vector<int> vetor;
    for(int i : arr){
        if(valores.count(i) == 0){
            vetor.push_back(i);
        }

        valores.insert(i);
    }

    return vetor;
}

vector<vector<string>> agruparAnagramas(vector<string>& palavras){
    unordered_map<string, vector<string>> anagramas;

    for (const string& palavra : palavras) {
        string chave = palavra;
        sort(chave.begin(), chave.end());
        anagramas[chave].push_back(palavra);
    }

    vector<vector<string>> resultado;
    for (auto const& par : anagramas) {
        resultado.push_back(par.second);
    }
    
    return resultado;
}

int maiorSequenciaConsecutivos(std::vector<int>& arr){
    std::unordered_set<int> valores(arr.begin(), arr.end());

    int max_count = 0;
    for (int num : valores) {
    
        if (valores.count(num - 1) == 0) {
            int count_atual = 1;
            int num_atual = num;

            while (valores.count(num_atual + 1) > 0) {
                num_atual++;
                count_atual++;
            }

            max_count = max(max_count, count_atual);
        }
    }

    return max_count;
}

#include <vector>
#include <unordered_set>

/**
 * Verifica se existe um subvetor (contíguo) cuja soma é 0.
 *
 * @param arr O vetor de entrada.
 * @return true se tal subvetor existe, false caso contrário.
 */
bool temSubvetorSomaZero(std::vector<int>& arr) {
    std::unordered_set<long long> somasPrefixo;

    long long somaAtual = 0;
    somasPrefixo.insert(0);

    for (int num : arr) {
        somaAtual += num;
        if (somasPrefixo.count(somaAtual) > 0) {
            return true;
        }
        somasPrefixo.insert(somaAtual);
    }

    return false;
}

void imprimeMap(std::unordered_map<int,int> map){
    auto init = map.begin();
    while (init != map.end()){
        std::cout << "<" << init-> first << ","  << init-> second << ">" << endl;
        init++;
    }
}

int main(){
    std::vector<int> arr = {1, 2, 6, 1, 5, 3, 8, 7, 4, 5, 2};
    // Exemplo para contarFrequencia
    // std::vector<int> arr = {1, 2, 1, 1, 5, 7, 8, 2, 3, 5, 2};
    //imprimeMap(contarFrequencia(arr));

    std::pair<int, int> par = twosum(arr, 15);
    std::cout << "<" << par.first << ","  << par.second << ">" << endl;
    // Exemplo para twosum
    // std::vector<int> arr = {1, 2, 1, 1, 5, 7, 8, 2, 3, 5, 2};
    // std::pair<int, int> par = twosum(arr, 15);
    // std::cout << "<" << par.first << ","  << par.second << ">" << endl;

    // Exemplo para agruparAnagramas
    vector<string> palavras = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> anagramas_agrupados = agruparAnagramas(palavras);

    for(const auto& grupo : anagramas_agrupados){
        for(const auto& palavra : grupo){
            cout << palavra << " ";
        }
        cout << endl;
    }

    int count = maiorSequenciaConsecutivos(arr);
    cout << "Sequência: " << count << endl;

    return 1;
}