#include <iostream>
#include <iomanip>
using namespace std;

// Variaveis globais
const int num_fileiras = 15;
const int poltronas_por_fileira = 40;

// Inicializa o layout do teatro com todas as poltronas vazias
bool ocupacao_teatro[num_fileiras][poltronas_por_fileira] = {false};

void mostrarMapaDeOcupacao() {
    cout << "Mapa de ocupacao:" << endl;
    for (int i = 0; i < num_fileiras; ++i) {
        for (int j = 0; j < poltronas_por_fileira; ++j) {
            if (ocupacao_teatro[i][j]) {
                cout << setw(2) << "#"; // Poltrona ocupada
            } else {
                cout << setw(2) << "."; // Poltrona vazia
            }
        }
        cout << endl;
    }
}

void reservarPoltrona(int &total_lugares_ocupados, int lugares_ocupados_por_fileira[num_fileiras], int &valor_bilheteria) {
    int fileira, poltrona;
    cout << "Digite a fileira e a poltrona desejada (1-" << num_fileiras << ", 1-" << poltronas_por_fileira << ")" << endl;
    cout << "Numero da fileira: ";
    cin >> fileira;
    cout << "Numero da poltrona: ";
    cin >> poltrona;

    // Verifica se a fileira e a poltrona sao validas
    if (fileira < 1 || fileira > num_fileiras || poltrona < 1 || poltrona > poltronas_por_fileira) {
        cout << "Fileira ou poltrona invalida." << endl << endl;
        return;
    }

    // Converte para indices de array (subtrai 1 porque os arrays em C++ sao baseados em zero)
    int indice_fileira = fileira - 1;
    int indice_poltrona = poltrona - 1;

    // Verifica se a poltrona j� est� ocupada
    if (ocupacao_teatro[indice_fileira][indice_poltrona]) {
        cout << "Esta poltrona ja esta ocupada." << endl << endl;
    } else {
        ocupacao_teatro[indice_fileira][indice_poltrona] = true;
        lugares_ocupados_por_fileira[indice_fileira] += 1;
        total_lugares_ocupados += 1;
        cout << "Poltrona reservada com sucesso." << endl << endl;
    }
}

void MostrarFaturamento(int total_lugares_ocupados, int lugares_ocupados_por_fileira[num_fileiras], int &valor_bilheteria) {
    valor_bilheteria = 0; // Reinicia o valor do faturamento antes de calcular novamente

    for (int i = 0; i < num_fileiras; i++) {
        if (i < 5) {
            valor_bilheteria += lugares_ocupados_por_fileira[i] * 50;
        } else if (i < 10) {
            valor_bilheteria += lugares_ocupados_por_fileira[i] * 30;
        } else {
            valor_bilheteria += lugares_ocupados_por_fileira[i] * 15;
        }
    }

    cout << "Qtde de lugares ocupados: " << total_lugares_ocupados << endl;
    cout << "Valor da bilheteria: R$" << valor_bilheteria << endl;
    cout << "Valor das fileiras de 1 a 5:   R$ 50,00" << endl;
    cout << "Valor das fileiras de 6 a 10:  R$ 30,00" << endl;
    cout << "Valor das fileiras de 11 a 15: R$ 15,00" << endl << endl;
}



int main() {
    int escolha;
    int lugares_ocupados_por_fileira[num_fileiras] = {0};
    int total_lugares_ocupados = 0;
    int valor_bilheteria = 0;
    
    while (true) {
        cout << "Digite uma opcao: " << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupacao" << endl;
        cout << "3. Faturamento" << endl;

        cin >> escolha;

        switch (escolha) {
            case 0:
                return 0;
            case 1:
                reservarPoltrona(total_lugares_ocupados, lugares_ocupados_por_fileira, valor_bilheteria);
                break;
            case 2:
                mostrarMapaDeOcupacao();
                break;
            case 3:
                MostrarFaturamento(total_lugares_ocupados, lugares_ocupados_por_fileira, valor_bilheteria);
                break;
            default:
                cout << "Comando nao aceito" << endl << endl;
                break;
        }
    }

    return 0;
}
