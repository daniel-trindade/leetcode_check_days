#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequence;
    vector<bool> used;
    int n, length;
    
    // Função de backtracking que tenta preencher a sequência a partir do índice 'index'
    bool backtrack(int index) {
        // Se todos os índices foram preenchidos, encontramos uma solução
        if(index == length)
            return true;
        
        // Se a posição já está preenchida, vá para a próxima posição
        if(sequence[index] != 0)
            return backtrack(index + 1);
        
        // Tente colocar os números de n até 1 para obter a sequência lexicograficamente maior
        for (int num = n; num >= 1; num--) {
            if(used[num])
                continue;
            
            if(num == 1) {
                // Número 1 aparece apenas uma vez
                sequence[index] = 1;
                used[1] = true;
                if(backtrack(index + 1))
                    return true;
                // Backtrack: desfaz a colocação
                sequence[index] = 0;
                used[1] = false;
            } else {
                // Para números maiores que 1, precisamos colocar duas ocorrências com distância 'num'
                int j = index + num; // A segunda ocorrência deve estar em index + num
                if(j < length && sequence[j] == 0) {
                    sequence[index] = num;
                    sequence[j] = num;
                    used[num] = true;
                    if(backtrack(index + 1))
                        return true;
                    // Backtrack: desfaz as colocações
                    sequence[index] = 0;
                    sequence[j] = 0;
                    used[num] = false;
                }
            }
        }
        // Não foi possível preencher a posição 'index' de forma válida
        return false;
    }
    
    // Função que inicializa a sequência e chama o backtracking
    vector<int> constructSequence(int n) {
        this->n = n;
        length = 2 * n - 1;
        sequence.assign(length, 0);
        used.assign(n + 1, false);
        backtrack(0);
        return sequence;
    }
};

int main(){
    int n;
    cout << "Digite n: ";
    cin >> n;
    
    Solution sol;
    vector<int> result = sol.constructSequence(n);
    
    cout << "Sequência gerada: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
