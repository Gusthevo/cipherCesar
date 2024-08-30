#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Função para cifrar o texto usando a Cifra de César
void cifraDeCesar(char *text, char key) {
    int textLength = strlen(text);  // Obtém o comprimento do texto
    int i, j;

    // Converte a chave para um valor numérico entre 1 e 26
    char keyChar = isupper(key) ? key - 'A' + 1 : key - 'a' + 1;

    // Percorre cada caractere do texto
    for (i = 0; i < textLength; ++i) {
        // Verifica se o caractere é uma letra
        if (isalpha(text[i])) {
            // Determina a base (A ou a) com base no caractere atual
            char base = isupper(text[i]) ? 'A' : 'a';

            // Aplicação da Cifra de César para cifrar o caractere
            // Usa a fórmula (caractere - base + chave) % 26 para calcular o novo caractere
            text[i] = tolower(base + ((text[i] - base + keyChar) % 26));
        }
    }
}

int main() {
    char textSimple[10000];  // Vetor para armazenar o texto simples
    char key;  // Variável para armazenar a chave da Cifra de César

    // Solicita ao usuário para inserir o texto a ser cifrado
    printf("Insira o Texto a ser cifrado:\n");
    fgets(textSimple, sizeof(textSimple), stdin); //Lê a string passada no texto simples

    // Remove o caractere de nova linha adicionado pelo fgets
    textSimple[strcspn(textSimple, "\n")] = '\0';

    // Solicita ao usuário para inserir a chave
    printf("Insira a chave:\n");
    key = getchar();

    // Mostra o texto original inserido pelo usuário
    printf("Texto original: %s\n", textSimple);

    // Chama a função para cifrar o texto
    cifraDeCesar(textSimple, key);

    // Mostra o texto cifrado
    printf("Texto cifrado: %s\n", textSimple);

    return 0;
}
