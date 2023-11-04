#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_LINHA 500
#define TAM 50

typedef struct reg {
    int conteudo;
    int soma;
    int linha;
    struct reg *prox;
} No;
/*
typedef struct {
  int *inicioLista;
  int num;
}Linha;
*/
typedef struct {
  int nrLinha;
  No *aux;
  int nrLista;
  int qtd;
} Linhas;

int main(){

  No *inicio;
  
  No *atual, *anterior, *novo;
  Linhas *vetorPrincipal = malloc (TAM_MAX_LINHA*sizeof(Linhas));
    
  FILE *arquivoEntrada = fopen("L1Q1.in", "r");
  FILE *arquivoSaida = fopen("L1Q1.out", "w+");
  if(arquivoEntrada == NULL || arquivoSaida==NULL){
        printf("%s\n", "Falha na criação dos arquivos!");
        return EXIT_FAILURE;
    }


  char *linha = malloc(TAM_MAX_LINHA * sizeof(char));
  int j=0;
  int i=-1;
  int z=0;
  int start=0;

  vetorPrincipal[z].nrLista=0;
  
  while (fgets(linha, TAM_MAX_LINHA, arquivoEntrada)!=NULL) {

    char *tok;
    const char * separador = " ";
    
    
    tok = strtok(linha, separador);
    while(tok != NULL) {
      if (strchr(tok,'s')!=NULL){
        // inicio de lista com cabecote
 //       printf("strchr(tok,'s')!=NULL resultado tok %s\n", tok);
      
        if (vetorPrincipal[j].qtd>0)  {
          No* tmp = inicio->prox;
          char *imprimir=malloc(TAM_MAX_LINHA*sizeof(char));
          fputs("start ", arquivoSaida);
          for (int t=0;tmp != NULL;t++) {
  //          printf(" %d ", tmp->conteudo);
            imprimir[t]=tmp->conteudo;
            fprintf(arquivoSaida, " %d ", imprimir[t]);
            tmp = tmp->prox;
          }
        free(imprimir);
        }
        
        i=i+1;
        inicio = (No *)malloc(sizeof(No));
          inicio->prox=NULL;
        vetorPrincipal[j].aux=malloc(TAM_MAX_LINHA*sizeof(Linhas));
        vetorPrincipal[j].aux[i]=*inicio;
        vetorPrincipal[j].qtd=0;
        vetorPrincipal[z].nrLista++;
        z++;
        start++;
//        printf(" vetorPrincipal[j].aux[i] %d\n", vetorPrincipal[j].nrLinha);
      }
      else if (strchr(tok,'s')==NULL) {
        // primeiro nó da lista
        
        if ((inicio->prox)==NULL){
//          printf("strchr(tok,'s')==NULL resultado tok %s\n", tok);
          novo = (No *)malloc(sizeof(No));
          novo->conteudo=atoi(tok);
          novo->prox=NULL;
          inicio->prox = novo;
          novo->linha=j;
          vetorPrincipal[j].qtd++;
 //         novo->soma = novo->conteudo;
 //         printf("primeiro novo->conteudo %d\n", novo->conteudo);
 //         printf("primeiro novo->soma %d\n", novo->soma);
        }
        else if (vetorPrincipal[j].qtd==1) {
          // inserir 2 elemento em ordem
//          printf("inserir 2 elemento em ordem\n");
          atual=inicio->prox;
          novo = (No *)malloc(sizeof(No));
          novo->conteudo = atoi(tok);
          if(atual->conteudo <= novo->conteudo){
 //           soma1=novo->soma;
   //         soma2=novo->conteudo;
     //       soma=soma1+soma2;
       //     novo->soma = soma;
            novo->prox=NULL;
            atual->prox=novo;
            vetorPrincipal[j].qtd++;
 //           printf("soma %d e 2 novo->soma %d\n", soma, novo->soma);
          }
          else{
//            soma1=novo->soma;
  //          soma2=novo->conteudo;
    //        soma=soma1+soma2;
      //      novo->soma = soma;
            inicio->prox = novo;
            novo->prox= atual;
            atual->prox=NULL;
            vetorPrincipal[j].qtd++;
            }
 //         printf("segundo novo->conteudo %d\n", novo->conteudo);
//          printf("2 novo->soma %d\n", novo->soma);
        }
        else if (vetorPrincipal[j].qtd>1){
          // inserir demais elementos em ordem

 //         printf("inserir demais elementos em ordem\n");
          atual = inicio;
          anterior=inicio;
          novo = (No *)malloc(sizeof(No));
          novo->conteudo = atoi(tok);
  //        novo->prox=NULL;
          if(anterior->conteudo > novo->conteudo){
            novo->prox= anterior;
            inicio->prox = novo;
            vetorPrincipal[j].qtd++;
 //           novo->soma = ((novo->soma) + (novo->conteudo));
 //           printf("demais if novo->conteudo %d\n", novo->conteudo);
          }
          else{
            while(atual!=NULL && atual->conteudo <= (atoi(tok))){
              anterior=atual;
              atual=atual->prox;
            }
            anterior->prox=novo;
            novo->prox=atual;
            vetorPrincipal[j].qtd++;
 //           novo->soma = ((novo->soma) + (novo->conteudo));
//            printf("demais else novo->conteudo %d\n", novo->conteudo);
 //           printf(" demais novo->soma %d\n", novo->soma);
          }
          }
 //       printf("#########################\n");
        }

//      printf("tok nullllllllll\n");
      tok=strtok(NULL, separador); 
//      printf("XXXXXXXXXXXXXXXXXXXXXXXXX\n");
      
       
    }
    int q=j;    
//    printf("ZZZZZZZZ   fora do while tok   outra linha ZZZZZZZZZZZZ\n");
    vetorPrincipal->nrLinha=j;
 //   printf("vetorPrincipal->nrLinha %d\n", vetorPrincipal->nrLinha);
    j++;
    start=0;
    
    if(q < j){
      No* tmp = inicio->prox;
      char imprimir[TAM_MAX_LINHA];
      int k=0;
      fputs("start ", arquivoSaida);
      while(imprimir[k] != '\0'){
//        printf(" %d ", tmp->conteudo);
        imprimir[k]=tmp->conteudo;
        fprintf(arquivoSaida, " %d ", imprimir[k]);
        tmp = tmp->prox;
        k++;
      } 
    }
    
 //   if (j>1) {
      fputs("\n", arquivoSaida);
 //   }

    
  }
/*


  
 /*
  No* tmp = inicio->prox;
  char imprimir[TAM_MAX_LINHA];
  int k=0;
  fputs("start ", arquivoSaida);
	while(tmp != NULL){
		printf(" %d ", tmp->linha);
    imprimir[k]=tmp->linha;
    fprintf(arquivoSaida, " %d ", imprimir[k]);
		tmp = tmp->prox;
    k++;
	}
/*

  for(int i=1; i<vetorPrincipal->nrLinha; i++) {
    printf("primeiro for\n");
    for(int a=0; a<vetorPrincipal->nrLista; a++){
      printf("segundo for\n");
      No *p;
      No *imprime = inicio->prox;
      //No *imprime = &vetorPrincipal[i].aux[a];
      fputs("start ", arquivoSaida);
      for (p = imprime; p->prox!= NULL; p = p->prox){
        printf("terceiro for\n");
        fprintf(arquivoSaida, "%d", imprime->conteudo);
        fputs(" 3 for", arquivoSaida);
      }
    }
  }
*/

  free(linha);
  free(novo);
  for (int i = 0; i < TAM_MAX_LINHA; i++) {
    free(vetorPrincipal[i].aux);    
    vetorPrincipal[i].aux = NULL;
    vetorPrincipal[i].nrLinha = 0;
    vetorPrincipal[i].qtd = 0;  
  }
  free(vetorPrincipal);
  fclose(arquivoSaida);
  fclose(arquivoEntrada);
    
} 