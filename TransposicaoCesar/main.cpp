#include <stdio.h>
#include <cstring>

// Função para decifrar a string usando a cifra de César com deslocamento 13
void deslocarLetras(char *string) {
    int i;

    for (i = 0; string[i] != '\0'; i++) {
        char charAtual = string[i];

        if (charAtual >= 'a' && charAtual <= 'z') {
            // Se o caractere é minúsculo
            charAtual = 'a' + (charAtual - 'a' + 13) % 26;
        } else if (charAtual >= 'A' && charAtual <= 'Z') {
            // Se o caractere é maiúsculo
            charAtual = 'A' + (charAtual - 'A' + 13) % 26;
        }
        string[i] = charAtual;
    }
}

int main() {
    char string[1000];

    printf("Insira uma string: ");
    fgets(string, sizeof(string), stdin);

    // Remover o caractere de nova linha (\n) inserido pelo fgets
    string[strcspn(string, "\n")] = '\0';

    deslocarLetras(string);

    printf("String decifrada: %s\n", string);

    return 0;
}

