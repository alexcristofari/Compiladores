#include <stdio.h>

void removeComments(FILE *inputFile, FILE *outputFile) {
    char currentChar, nextChar;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == '/') {
            nextChar = fgetc(inputFile);

            if (nextChar == '/')
                while ((currentChar = fgetc(inputFile)) != '\n' && currentChar != EOF);

            else if (nextChar == '*')
                while ((currentChar = fgetc(inputFile)) != '*' && (nextChar = fgetc(inputFile)) != '/' && currentChar != EOF && nextChar != EOF);

            else {
                fputc(currentChar, outputFile);
                fputc(nextChar, outputFile);
            }
        } else {
            fputc(currentChar, outputFile);
        }
    }
}

int main() {
    FILE *inputFile = fopen("codigo_fonte.c", "r");
    FILE *outputFile = fopen("codigo_fonte.sco", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Erro ao abrir os arquivos");
        return 1;
    }

    removeComments(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Comentários removidos com sucesso.\n");

    return 0;
}
