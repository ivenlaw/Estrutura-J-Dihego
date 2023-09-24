#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define TAM_MAX_LINHA 500

void quebraLinha (char linha[], char vString[], int vInteiro [], float vFloat [], float vPontosx [], float vPontosy [], int iP, int iI, int iS, int iF);
void gravaArquivo (char linha[], char sString[], char sInteiro[], char sFloat [], char sPontos []);
void trataPontos (float vPontosx [], float vPontosy [], int iP);
void trataInteiro(int vInteiro[], int iI);
void trataFloat(float vFloat[], int iF);
void trataString (char vString[], int iS);
void impressaoInteiro (int vInteiro[], char sInteiro[], int iI);
void impressaoFloat (float vFloat[], char sFloat[], int iF);
void impressaoString (char vString[], char sString[], int iS);
void impressaoPontos (float vPontosx [], float vPontosy [], char sPontos [], int iP);

int main () {

  char *vString= malloc(TAM_MAX_LINHA * sizeof(char)); 
  int *vInteiro= malloc(TAM_MAX_LINHA * sizeof(int));
  float *vFloat= malloc(TAM_MAX_LINHA * sizeof(float));
  float *vPontosx= malloc(TAM_MAX_LINHA * sizeof(char));
  float *vPontosy= malloc(TAM_MAX_LINHA * sizeof(char));
 
  char sInteiro[TAM_MAX_LINHA], sFloat[TAM_MAX_LINHA], sString[TAM_MAX_LINHA], sPontos[TAM_MAX_LINHA];
  int iI=0, iP=0, iS=0, iF=0;
  
  FILE *arquivoEntrada = fopen("L0Q2.in", "r");
  FILE *arquivoSaida = fopen("L0Q2.out", "w");
  if(arquivoEntrada == NULL || arquivoSaida==NULL){
          printf("%s\n", "Falha na criação dos arquivos!");
          return EXIT_FAILURE;
      }
  fclose(arquivoSaida);
  char *linha = malloc(TAM_MAX_LINHA * sizeof(char));

  while (fgets(linha, TAM_MAX_LINHA, arquivoEntrada)!=NULL) {
    quebraLinha (linha, vString, vInteiro , vFloat, vPontosx, vPontosy, iF, iP, iI, iS);  
    impressaoString (vString, sString, iS);
    impressaoInteiro (vInteiro, sInteiro, iI);
    impressaoFloat (vFloat, sFloat, iF);
    impressaoPontos (vPontosx, vPontosy, sPontos, iP);
    gravaArquivo (linha, sString, sInteiro , sFloat, sPontos);
   
  } 

  
  fclose(arquivoEntrada);
//  fclose(arquivoSaida);
  free (linha);
  free (vString);
  free (vFloat);
  free (vPontosx);
  free (vPontosy);
  free (vInteiro);

}

void gravaArquivo (char linha[], char sString[], char sInteiro[], char sFloat [], char sPontos []) {
  
  FILE *arquivoSaida = fopen("L0Q2.out", "a+");
    
  fputs("str:", arquivoSaida);
  fputs(sString, arquivoSaida);
  fputs(" int:", arquivoSaida);
  fputs(sInteiro, arquivoSaida);
  fputs(" float:", arquivoSaida);
  fputs(sFloat, arquivoSaida);
  fputs(" p:", arquivoSaida);
  fputs(sPontos, arquivoSaida);
  fputs("\n", arquivoSaida);

  fclose(arquivoSaida);

}
  
  

/* funcao quebra linha antes de mexer*/
void quebraLinha (char linha[], char vString[], int vInteiro [], float vFloat [], float vPontosx [], float vPontosy [], int iP, int iI, int iS, int iF) {
  char *tok;
  const char * separador = " ";
  tok = strtok(linha, separador);
  while (tok != NULL) {
    if(strchr(tok, '(')!= NULL){
      sscanf(tok, "(%f,%f)", &vPontosx[iP], &vPontosy[iP]);
      trataPontos(vPontosx, vPontosy, iP);
      iP++; 
    }        
    else if ((tok[0]>48 && tok[0]<=57) || tok[0]==45){
      if(strchr(tok,'.')!=NULL){
        sscanf(tok, "%f", &vFloat[iF]);
//        vFloat[iF]=atof(tok);
        trataFloat(vFloat, iF);
        printf("iF quebra %d\n", iF);
        iF++;
      } 
      else {
        vInteiro[iI]=atoi(tok);
        trataInteiro(vInteiro, iI);
        printf("iI quebra %d\n", iI);
        iI++;
      }
    }
    else if ((tok[0]>=65 && tok[0]<=90) || (tok[0]>=97 && tok[0]<=122)){
      strcpy(&vString[iS], tok);
      trataString(&vString[iS], iS);
      iS++;
   }
    tok=strtok(NULL, separador); 
  }
  printf("fim do funcao quebraLinha\n\n");
  }

void trataPontos (float vPontosx [], float vPontosy [], int iP){
  printf("Inicio trataPontos = %.2f,%.2f e iP - 1= %d\n", vPontosx[iP], vPontosy[iP], iP);
  printf("Inicio trataPontos -1 = %.2f,%.2f e iP - 1= %d\n", vPontosx[iP-1], vPontosy[iP-1], iP-1);
  int i=0;
  float k1, k2, EuK1, EuK2;
  float x=0;
  float y=0;
  float pontoProvisorioX1=vPontosx[iP];
  float pontoProvisorioY1=vPontosy[iP];
  float pontoProvisorioX2=vPontosx[iP-1];
  float pontoProvisorioY2=vPontosy[iP-1];
  printf("%f %f %f %f", pontoProvisorioX1, pontoProvisorioY1,  pontoProvisorioX2, pontoProvisorioY2);


  if(iP>0){
    k1=(pow((pontoProvisorioX1),2)+pow((pontoProvisorioY1),2));
    float rounded_down = floorf(k1 * 100) / 100;
    //    EuK1=sqrtf(k1);
    k2=(pow((pontoProvisorioX2),2)+pow((pontoProvisorioY2),2));
//    EuK2=sqrtf(k2);
    printf("k1 %f EuK1 %f k2 %f EuK2 %f\n", k1, k2, EuK1, EuK2);
  }
  

  printf("fim do funcao trataPontos\n\n");
}
void trataFloat(float vFloat[], int iF){

  int contF=0;
  printf("inicio float = %.2f e iF= %d\n", vFloat[iF], iF);
  int y = sizeof(vFloat[iF]);
  printf("float y %d\n",y);
  for(int i=0; i<y;i++){
    if(vFloat[i]== '.'){
      contF=y-i;
      printf("contF %d\n", contF);
    }
  }
    if(iF>0){
    while(iF>0) {
      float provisorio= vFloat[iF-1];
      printf("%f\n", provisorio);
      if(vFloat[iF]<provisorio){
        vFloat[iF-1]=vFloat[iF];
        vFloat[iF]=provisorio;
        printf("float if final = %.2f e i= %d\n", vFloat[iF], iF);
        iF--;
      }
      else{
         printf("float else final = %.2f e i= %d\n", vFloat[iF], iF);
        iF--;
         
      }
    }
    
  }
     printf("fim do funcao trataFloat\n\n");

  
}

void trataInteiro(int vInteiro[], int iI){

  printf("inicio inteiro = %d e iI= %d\n", vInteiro[iI], iI);
  if(iI>0){
    while(iI>0) {
      int provisorio= vInteiro[iI-1];
      printf("%d\n", provisorio);
      if(vInteiro[iI]<provisorio){
        vInteiro[iI-1]=vInteiro[iI];
        vInteiro[iI]=provisorio;
        printf("inteiro if final = %d e i= %d\n", vInteiro[iI], iI);
        iI--;
      }
      else{
         printf("inteiro else final = %d e i= %d\n", vInteiro[iI], iI);
        iI--;
         
      }
    }
    
  }
     printf("fim do funcao trataInteiro\n\n");
}

void trataString (char vString[], int iS){

  printf("string = %s e i= %d\n", &vString[iS], iS);
  printf("string anterior= %s e i= %d\n", &vString[iS-4], iS-1);
  int y = strlen(&vString[iS-1]);
  char provisorio[y];
  printf("y %d\n",y);
  if(iS>0){
    while(iS>0) {
      strcpy(provisorio, &vString[iS - 1]);
      printf("provisorio %s\n", provisorio);
      for(int i=0; i<y-1; i++){
        if(provisorio[i]<vString[i]){
          strcpy(&vString[iS-1], vString);
          strcpy(vString, provisorio);
          printf("string if final = %s e i= %d\n", &vString[iS], iS);
          iS--;
        }
        else{
           printf("string else final = %s e i= %d\n", &vString[iS], iS);
          iS--;
         }
      }
    }
    
  }
     printf("fim do funcao trataString\n\n");  

  
}

void impressaoPontos (float vPontosx [], float vPontosy [], char sPontos [], int iP){

  int i=1;
  int z=sizeof(iP);
  char x[20], y[20];
  sprintf(x, "(%.2f,%.2f)",  vPontosx[0], vPontosy[0]);
  printf("%d %s %s\n", z, x, y);
  for(int b=0; b<z; b++){
    printf("Vetor float, posição %d: %f %f\n", b, vPontosx[b], vPontosy[b]);
  }
  strcpy(sPontos, x);
  printf("%s\n", sPontos);
//  char itoa(vInteiro[0], x);
  while (i<z-1){
    strcat(sPontos, " "); 
    sprintf(x, "(%.2f,%.2f)",  vPontosx[i], vPontosy[i]);
    strcat(sPontos, x);  
    printf("%s\n", sPontos);
    i++;
    }
 
}


void impressaoFloat (float vFloat[], char sFloat[], int iF){

  int i=1;
  int y=sizeof(iF);
  char x[20];
  sprintf(x, "%.2f",  vFloat[0]);
  printf("%d %s\n", y, x);
  for(int b=0; b<y; b++){
    printf("Vetor float, posição %d: %f\n", b, vFloat[b]);
  }
  strcpy(sFloat, x);
  printf("%s\n", sFloat);
//  char itoa(vInteiro[0], x);
  while (i<y-1){
    strcat(sFloat, " "); 
    sprintf(x, "%.2f",  vFloat[i]);
    strcat(sFloat, x);  
    printf("%s\n", sFloat);
    i++;
    }
 
}

void impressaoInteiro (int vInteiro[], char sInteiro[], int iI){

  int i=1;
  int y=sizeof(iI);
  char x[20];
  sprintf(x, "%d",  vInteiro[0]);
  printf("%d %s\n", y, x);
  for(int b=0; b<y; b++){
    printf("Vetor inteiro, posição %d: %d\n", b, vInteiro[b]);
  }
  strcpy(sInteiro, x);
  printf("%s\n", sInteiro);
//  char itoa(vInteiro[0], x);
  while (i<y-1){
    strcat(sInteiro, " "); 
    sprintf(x, "%d",  vInteiro[i]);
    strcat(sInteiro, x);  
    printf("%s\n", sInteiro);
    i++;
    }
 
}

void impressaoString (char vString[], char sString[], int iS){

  int i=1;
  int y=sizeof(iS);
  for(int b=0; b<y; b++){
    printf("Vetor string, posição %d: %s\n", b, &vString[b]);
  }
  strcpy(sString, &vString[0]);

  while (i<y-1){
    strcat(sString, " "); 
    strcat(sString, &vString[i]);  
    printf("%s\n", sString);
    i++;
    }
 
}

