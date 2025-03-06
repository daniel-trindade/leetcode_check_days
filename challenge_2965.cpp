#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

  int n = grid.size();
  map<int, bool> numbers;
  vector<int> ans(2, -1);

  cout << "criando map" << endl;

  for(int x=1; x<=(n*n); x++){
    numbers.insert({x, false});
  }

  cout << "map Criado" << endl;

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(numbers[grid[i][j]] == true){
        ans[0]=grid[i][j];
        cout << "Achado Valor Igual" << endl;
      }else{
        numbers[grid[i][j]] = true;
        cout << "Setando true" << endl;
      }
    }
  }

  cout << "Bucando valor faltante" << endl;

  for(const auto& par : numbers){
    if(par.second == false){
      ans[1]=par.first;
      cout << "Encontrado" << endl;
      break;
    }
    continue;
  }
  
  cout << "Processo Terminado" << endl;
  return ans;
}

int main (){

  vector<vector<int>> grid = {{1,3},{2,2}};
  vector<int> ans = findMissingAndRepeatedValues(grid);
  cout << "A: " << ans[0] << endl;
  cout << "B: " << ans[1] << endl;
  return 0;
}