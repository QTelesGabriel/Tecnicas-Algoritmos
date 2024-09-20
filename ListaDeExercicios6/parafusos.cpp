#include <iostream>
#include <vector>
#include <array>

int main()
{
  int c, q;
  std::cin >> c >> q;

  std::vector<std::array<int, 2>> parafusos;
  std::vector<int> tamanhoDesejado;

  for(int i = 0; i < c; i++) {
    std::array<int, 2> parafuso;
    std::cin >> parafuso[0] >> parafuso[1];
    parafusos.push_back(parafuso);
  }

  for(int i = 0; i < q; i++) {
    int desejado;
    std::cin >> desejado;
    tamanhoDesejado.push_back(desejado);
  }

  for(int i = 0; i < q; i++) {
    int quantidade = 0;
    for(int j = 0; j < c; j++) {
      if(tamanhoDesejado[i] >= parafusos[j][0] && tamanhoDesejado[i] <= parafusos[j][1]) {
        quantidade++;
      }
    }
    if(quantidade == 0) {
       std::cout << "Nao contem parafusos do tipo " << tamanhoDesejado[i] << std::endl; 
    }
    else {
      std::cout << "Contem " << quantidade << " parafuso(s) do tipo " << tamanhoDesejado[i] << std::endl;
    }
  }

  return 0;

}