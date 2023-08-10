//Aqui sao as blibliotecas 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

//Namespace e para simplificar mais o codigo removendo o std::
using namespace std;

//Aqui é onde se da inicio a criação das variaveis, onde se faz a utilização de vetores para que haja os numeros aleatorios em numeros de 1 a 60 e em 6 algarismos
vector<int> gerarnumeroaleatorios (int totalnumeros, int valormaximo) {
vector<int> numeros;
    for (int i = 1; i <= valormaximo; ++i) {numeros.push_back(i);
    }
    
    random_shuffle(numeros.begin(), numeros.end());
    numeros.resize(totalnumeros);
    return numeros;
}
// Aqui se da de fato inicio ao codigo 
int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // utilizamos time/rand para que de certa forma possamos escolher o tempo em que os numeros devem parar de gerar em modo aleatorio 
    const int totalnumeros = 6; // Quantidade de algarismos possiveis no jogo 
    const int valormaximo = 60; // Quantidade limite de numeros que se pode escolher ou seja ate a casa da dezena 6 ou 60
    vector<int> numerodojogador; // Criação de outro vetor
    
    cout << "Bem-vindo ao Simulador da Mega Sena!" << endl; // Mensagem que aparece apos inicio do jogo
    
    cout << "Escolha " << totalnumeros << " números de 1 a " << valormaximo << ":" << endl; // serve para limitar a escolha do jogador de 1 a 60, acima disso o codigo irá barrar 
    for (int i = 0; i < totalnumeros; ++i) { int escolhanumero; // serve para limitar o numero de de algarismos permitidos ou seja o maximo de numero sera 6, acima disso o codigo irá barrar
        do { // Do while serve para executar o codigo até acertar uma vez, depois para
            cout << "Número " << i + 1 << ": "; 
            cin >> escolhanumero;
        } while (escolhanumero < 1 || escolhanumero > valormaximo || find(numerodojogador.begin(), numerodojogador.end(), escolhanumero) != numerodojogador.end());
        numerodojogador.push_back(escolhanumero);
    }
    
    vector<int> numerosvencedores = gerarnumeroaleatorios(totalnumeros, valormaximo); // serve para declarar quais são os numeros, declarar o valor minimo e o valor maximo
    
    cout << "\nNúmeros sorteados: "; // serve para sortear os numeros 
    for (int i = 0; i < totalnumeros; ++i) {
        cout << numerosvencedores[i] << " ";
    }
    
    cout << "\nSeus números: "; // são os numeros escolhidos pelo usuário
    for (int i = 0; i < totalnumeros; ++i) {
        cout << numerodojogador[i] << " ";
    }
    
    int numerocorreto = 0; // serve para declarar os numeros corretos 
    for (int i = 0; i < totalnumeros; ++i) {
        if (find(numerosvencedores.begin(), numerosvencedores.end(), numerodojogador[i]) != numerosvencedores.end()) {
            numerocorreto++;
        }
    }
    
    int numeroincorreto = totalnumeros - numerocorreto;
    
    cout << "\nAcertos: " << numerocorreto << endl; // serve para mostrar o numero de acertos 
    cout << "Erros: " << numeroincorreto << endl; // serve para mostrar o numero de erros 
    
    if (numerocorreto == totalnumeros) {
        cout << "Parabéns, você ganhou!" << endl;
       } if (numerocorreto == 5) {
        cout << "Parabéns, você ganhou na quina! " << endl;
    } else if (numeroincorreto > 0) {
        cout << " Deseja tentar novamente? (S/N): ";
        char escolha;
        cin >> escolha;
        
        if (escolha == 'S' || escolha == 's') {
            main(); // Reiniciar o jogo
        } else {
            cout << "Obrigado por jogar!" << endl;
        }
    }
    
    return 0;
}

// Cauã Nunes de Sousa Martins 
// Antonio Brito  Xavier