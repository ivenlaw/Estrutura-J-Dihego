#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define TAM_MAX_LINHA 500

typedef struct {

  char nome[TAM_MAX_LINHA];

} Dados;

void quebraLinha (int tamLinha, char linha[], int *iS, Dados vString[], int vInteiro [], float vFloat [], float vPontosx [], float vPontosy [], int *iP, int *iI, int *iF);
void gravaArquivo (char linha[], Dados sString[], char sInteiro[], char sFloat [], char sPontos []);
void trataPontos (float vPontosx [], float vPontosy [], int iP);
void trataInteiro(int vInteiro[], int iI);
void trataFloat(float vFloat[], int iF);
void trataString (int iS, Dados vString[]);
void impressaoInteiro (int vInteiro[], char sInteiro[], int *iI);
void impressaoFloat (float vFloat[], char sFloat[], int *iF);
void impressaoString (int *iS, Dados vString[], Dados sString[]);
void impressaoPontos (float vPontosx [], float vPontosy [], char sPontos [], int *iP);



int main () {

  int *vInteiro= malloc(TAM_MAX_LINHA * sizeof(int));
  float *vFloat= malloc(TAM_MAX_LINHA * sizeof(float));
  float *vPontosx= malloc(TAM_MAX_LINHA * sizeof(char));
  float *vPontosy= malloc(TAM_MAX_LINHA * sizeof(char));
 
  char sInteiro[TAM_MAX_LINHA], sFloat[TAM_MAX_LINHA],  sPontos[TAM_MAX_LINHA];
  Dados sString[TAM_MAX_LINHA], vString[TAM_MAX_LINHA];
  
  int iI=0, iP=0, iS=0, iF=0;
  int tamLinha=0;
  
  FILE *arquivoEntrada = fopen("L0Q2.in", "r");
  FILE *arquivoSaida = fopen("L0Q2.out", "w");
  if(arquivoEntrada == NULL || arquivoSaida==NULL){
          printf("%s\n", "Falha na criação dos arquivos!");
          return EXIT_FAILURE;
      }
  fclose(arquivoSaida);
  char *linha = malloc(TAM_MAX_LINHA * sizeof(char));

  while (fgets(linha, TAM_MAX_LINHA, arquivoEntrada)!=NULL) {
    quebraLinha (tamLinha, linha, &iS, vString,  vInteiro , vFloat, vPontosx, vPontosy, &iP, &iI, &iF); 
    impressaoString (&iS, vString, sString);
    impressaoInteiro (vInteiro, sInteiro, &iI);
    impressaoFloat (vFloat, sFloat, &iF);
    impressaoPontos (vPontosx, vPontosy, sPontos, &iP);
    gravaArquivo (linha, sString, sInteiro , sFloat, sPontos);
    tamLinha++;

  } 
 
  fclose(arquivoEntrada);
  free (linha);
  free (vFloat);
  free (vPontosx);
  free (vPontosy);
  free (vInteiro);

}

void gravaArquivo (char linha[], Dados sString[], char sInteiro[], char sFloat [], char sPontos []) {
  
  FILE *arquivoSaida = fopen("L0Q2.out", "a+");  
  
  fputs("str:", arquivoSaida);
  fputs(sString->nome, arquivoSaida);
  fputs(" int:", arquivoSaida);
  fputs(sInteiro, arquivoSaida);
  fputs(" float:", arquivoSaida);
  fputs(sFloat, arquivoSaida);
  fputs(" p:", arquivoSaida);
  fputs(sPontos, arquivoSaida);

  fclose(arquivoSaida);

}

/* funcao quebra linha antes de mexer*/
void quebraLinha (int tamLinha, char linha[], int *iS, Dados vString[], int vInteiro [], float vFloat [], float vPontosx [], float vPontosy [], int *iP, int *iI, int *iF) {
  (*iI)=0, (*iP)=0, (*iS)=0, (*iF)=0;
  char *tok;
  
  const char * separador = " ";
  tok = strtok(linha, separador);
  while (tok != NULL) {
    if(strchr(tok, '(')!= NULL){
      sscanf(tok, "(%f,%f)", &vPontosx[*iP], &vPontosy[*iP]);
      trataPontos(vPontosx, vPontosy,*iP);
      (*iP)++; 
    }        
    else if ((tok[0]>48 && tok[0]<=57) || tok[0]==45){
      if(strchr(tok,'.')!=NULL){
        sscanf(tok, "%f", &vFloat[*iF]);
        trataFloat(vFloat, *iF);
        (*iF)++;
      } 
      else {
        vInteiro[*iI]=atoi(tok);
        trataInteiro(vInteiro, *iI);
        (*iI)++;
      }
    }
    else if ((tok[0]>=65 && tok[0]<=90) || (tok[0]>=97 && tok[0]<=122)){
      sscanf(tok, "%s", vString[*iS].nome);
      trataString(*iS, vString);
      (*iS)++;
   }
    tok=strtok(NULL, separador); 
  }
  if (tamLinha>0) {
    FILE *arquivoSaida = fopen("L0Q2.out", "a+"); 
    fputs("\n", arquivoSaida);
    fclose(arquivoSaida);
  }
  }

void trataPontos (float vPontosx [], float vPontosy [], int iP){
  int i=0;
  double k1, k2, EuK1, EuK2;
  if(iP>0 && vPontosx!= NULL && vPontosy!=NULL){
    while(iP>0) {
      double pontoProvisorioX1=vPontosx[iP];
      double pontoProvisorioY1=vPontosy[iP];
      double pontoProvisorioX2=vPontosx[iP-1];
      double pontoProvisorioY2=vPontosy[iP-1];
      k1=(pow((pontoProvisorioX1),2)+pow((pontoProvisorioY1),2));
      EuK1=sqrt(k1);
      k2=(pow((pontoProvisorioX2),2)+pow((pontoProvisorioY2),2));
      EuK2=sqrt(k2);
      if(EuK1<EuK2){
        vPontosx[iP-1]=vPontosx[iP];
        vPontosy[iP-1]=vPontosy[iP];
        vPontosx[iP]=pontoProvisorioX2;
        vPontosy[iP]=pontoProvisorioY2;
        iP--;
      }
      else{
        iP--;
         
      }
    }
    
  }
  
}
void trataFloat(float vFloat[], int iF){

  int contF=0;
  int y = sizeof(vFloat[iF]);
  for(int i=0; i<y;i++){
    if(vFloat[i]== '.'){
      contF=y-i;
    }
  }
    if(iF>0){
    while(iF>0) {
      float provisorio= vFloat[iF-1];
      if(vFloat[iF]<provisorio){
        vFloat[iF-1]=vFloat[iF];
        vFloat[iF]=provisorio;
        iF--;
      }
      else{
        iF--;
         
      }
    }
    
  }
  
}

void trataInteiro(int vInteiro[], int iI){

  if(iI>0){
    while(iI>0) {
      int provisorio= vInteiro[iI-1];
      if(vInteiro[iI]<provisorio){
        vInteiro[iI-1]=vInteiro[iI];
        vInteiro[iI]=provisorio;
        iI--;
      }
      else{
        iI--; 
      }
    }
    
  }
}

void trataString (int iS, Dados vString[]){
  char provisorio[20];
  int y=sizeof(vString[iS]);
  if(iS>0){
    while(iS>0) {
      for(int i=iS-1; i<iS; i++){
         strcpy(provisorio, vString[i].nome);
      }
      if((strcmp(vString[iS].nome, provisorio)<0)){
        for(int i=iS-1; i<iS; i++){
             strcpy(vString[i].nome, vString[iS].nome);
        }
        sscanf(provisorio, "%s", vString[iS].nome);
        iS--;
      }
      else{
        iS--;
       }
    }
      iS--;
    }
  
}

void impressaoPontos (float vPontosx [], float vPontosy [], char sPontos [], int *iP){

  int i=1;
  int z=(*iP);
  char x[20];
  sprintf(x, "(%.2f,%.2f)",  vPontosx[0], vPontosy[0]);
  strcpy(sPontos, x);
  while (i<=z && vPontosx[i]!=0 && vPontosy[i]!=0){
    if(i<z){
      strcat(sPontos, " "); 
    }
    sprintf(x, "(%.2f,%.2f)",  vPontosx[i], vPontosy[i]);
    strcat(sPontos, x);  
    i++;
    }
 
}


void impressaoFloat (float vFloat[], char sFloat[], int *iF){

  int i=1;
  int y=(*iF);
  char x[20];
  sprintf(x, "%.2f",  vFloat[0]);
  strcpy(sFloat, x);
  while (i<=y && vFloat[i]!=0){
    if (i<y){
      strcat(sFloat, " "); 
      }
    sprintf(x, "%.2f",  vFloat[i]);
    strcat(sFloat, x);  
    i++;
    }
 
}

void impressaoInteiro (int vInteiro[], char sInteiro[], int *iI){

  int i=1;
  int y=(*iI);
  char x[20];
  sprintf(x, "%d",  vInteiro[0]);
  strcpy(sInteiro, x);
  while (i<y && vInteiro[i]!=0){
    strcat(sInteiro, " "); 
    sprintf(x, "%d",  vInteiro[i]);
    strcat(sInteiro, x);  
 //   printf("sInteiro é %s\n", sInteiro);
    i++;
    }
 
}

  void impressaoString (int *iS, Dados vString[], Dados sString[]){

  int i=1;
  int y=(*iS);
  strcpy(sString[0].nome, vString[0].nome);

  while (i<y){
    strcat(sString[0].nome, " "); 
    strcat(sString[0].nome, vString[i].nome);  
    i++;
    }
 
}

