#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Arrays para armazenar l_i e r_i dos estudantes
    int l[1005], r[1005];

    // Ler os valores de l_i e r_i
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    // Array para armazenar os resultados
    int result[1005] = {0};

    // Variável para acompanhar o tempo atual
    int current_time = 0;

    // Processar cada estudante
    for (int i = 0; i < n; i++) {
        // Atualizar current_time para o máximo entre ele mesmo e l[i]
        if (current_time < l[i]) {
            current_time = l[i];
        }

        // Verificar se o estudante pode receber chá antes de r[i]
        if (current_time <= r[i]) {
            result[i] = current_time; // Estudante recebe chá no current_time
            current_time++; // Avança o tempo em 1 segundo
        } else {
            result[i] = 0; // Estudante não recebe chá
        }
    }

    // Imprimir os resultados
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) {
            cout << " "; // Adiciona espaço entre os números, exceto no último
        }
    }
    cout << endl; // Nova linha após cada caso de teste
}

int main() {
    int t;
    cin >> t;

    // Processar cada caso de teste
    while (t--) {
        solve();
    }

    return 0;
}