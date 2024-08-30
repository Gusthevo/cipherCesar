#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para contar a frequência de caracteres em uma string
void contarCaracteres(const char *string) {
    int contagem[256] = {0};  // Inicializa o vetor de contagem com zeros
    int i;

    // Conta a frequência de cada caractere na string
    for (i = 0; string[i] != '\0'; i++) {
        contagem[(unsigned char)string[i]]++;
    }

    // Ordena os caracteres com base na frequência
    printf("Caractere | Frequencia\n");
    for (i = 0; i < 256; i++) {
        if (contagem[i] > 0) {
            printf("%c         | %d\n", i, contagem[i]);
        }
    }
}

int main() {
    char string[10000];

    printf("Insira uma string: ");
    fgets(string, sizeof(string), stdin);

    // Removendo o caractere de nova linha (\n) inserido pelo fgets
    string[strcspn(string, "\n")] = '\0';

    contarCaracteres(string);

    return 0;
}