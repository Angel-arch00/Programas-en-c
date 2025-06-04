#include <stdio.h>
#include <string.h>

void mi_strlwr_corta(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char texto_variado[30] = "TeLeFoNo REPARADO";

    printf("Original: %s\n", texto_variado);
    mi_strlwr_corta(texto_variado); 
    printf("En minúsculas: %s\n", texto_variado);

    return 0;
}