#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define TAM_MAX_LINHA 500
#define SEPARADOR " "

int main () {

  FILE*  arquivoEntrada = fopen("L0Q2.in", "r");
  FILE*  arquivoSaida = fopen("L0Q2.out", "w");
  if(arquivoEntrada == NULL || arquivoSaida==NULL){
          printf("%s\n", "Falha na criação dos arquivos!");
          return EXIT_FAILURE;
      }
  char* linha = malloc(TAM_MAX_LINHA * sizeof(char));
  
  do {
    fgets(linha, TAM_MAX_LINHA, arquivoEntrada);
    printf("%s", linha);
    
  } while (!feof(arquivoEntrada));

  
  fclose(arquivoEntrada);
  fclose(arquivoSaida);
  
}