#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_LINHA 500

typedef struct No{
     int key;
     char fazer;
     struct No * left;
     struct No * right;
     struct No * mae;
}No;

typedef struct Tree{
    No * raiz;
}Tree;

No  * criar_no(char tok, int key);
void inorder_tree_walk(No * x);
void tree_inserir(Tree * T, No * z);
No * tree_busca(Tree * T, int k);
No * tree_minimo(No * x);
No * tree_successor(No * x);
void tree_apagar(Tree * T, No * z);
void tree_gravar(No * raiz);

int main(){

  int i=0, j, l=0;

  FILE *arquivoEntrada = fopen("L2Q3.in", "r");
  FILE *arquivoSaida = fopen("L2Q3.out", "w+");
  if(arquivoEntrada == NULL || arquivoSaida==NULL){
        printf("%s\n", "Falha na criação dos arquivos!");
        return EXIT_FAILURE;
  }
  fclose(arquivoSaida);

  char linha[TAM_MAX_LINHA];
  while(fgets(linha, TAM_MAX_LINHA, arquivoEntrada) != NULL){
    Tree * arvore = malloc(sizeof(Tree));
    char *tok;
    printf("linha 109\n");
    tok = strtok(linha, " ");
    while(tok != NULL){
      printf("linha 47\n");
      char no1;
      int no2;
      if(i==0){
 //       sscanf(tok, "%s", no1);
        printf("linha 52 -> %d\n", i);
   //     strcpy(n1, (*no1));
        no1 = (*tok);
        i++;
      }
      else if (i==1){
        printf("linha 58\n");
        no2 = atoi(tok);
//        i++;
        printf("linha 61 -> %d\n", i);
  //      printf("linha 62\n");
        No * novo = criar_no(no1, no2);
  //      printf("%d %d\n", novo->key, novo->mae->key);
        printf("%d %c\n", no2, no1);
        if(novo->fazer == 'a') {
          tree_inserir(arvore, novo);
          printf("linha 68\n");}
        else if(novo->fazer == 'r'){
          printf("linha 70\n");
          if (tree_busca(arvore, no2)==NULL){
            tree_inserir(arvore, novo);
          }
          else {
            tree_apagar(arvore, novo);
            printf("linha 76\n");}
          }
        printf("linha 78\n");
        i=0;
      }
 //     i++;
      tok=strtok(NULL, " "); 
    }
  printf("linha 84 %d\n", l);
  if (l>0){
    printf("linha 86\n");
    fputs("\n", arquivoSaida);
  }
  l++;
//  inorder_tree_walk(arvore->raiz);
  tree_gravar(arvore->raiz);
  printf("linha 91\n");
  }
  
}

No  * criar_no(char tok, int key){
   No * no = malloc(sizeof(No));
   no->key =  key;
   no->fazer = tok;
   return no;
}

void inorder_tree_walk(No * x){
    if(x!= NULL){
        inorder_tree_walk(x->left);
        printf(" %d ", x->key);
        inorder_tree_walk(x->right);
    }
}

void tree_inserir(Tree * T, No * z){
    No * y = NULL;
    No * x = T->raiz;
    while(x != NULL){
      printf("linha 115\n");
        y  = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->mae = y;
    if(y== NULL) T->raiz = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z; 
}

No * tree_busca(Tree * T, int k){
  No * x = T->raiz;
  while(x!=NULL && k!= x->key){
      if(k < x->key) x =  x->left;
      else x =  x->right;
  }
  return x;
}

No * tree_minimo(No * x){
    if(x->left == NULL) return x;
    else return tree_minimo(x->left);
}

No * tree_successor(No * x){
    if(x->right != NULL){
        return tree_minimo(x->right);
    }
    No * y = x->mae;
    while(y!= NULL  && x == y->right){
        x = y;
        y = y->mae;
    }
    return y;
}
void tree_apagar(Tree * T, No * z){
    No * y;
    No * x;
    if(z->left == NULL || z->right == NULL) y = z;
    else y = tree_successor(z);
    if(y->left != NULL) x = y->left;
    else x = y->right;
    if(x!=NULL) x->mae = y->mae;
    if(y->mae == NULL) T->raiz = x;
    else{
        if(y == y->mae->left) y->mae->left =  x;
        else y->mae->right = x;
    }
    if(y!=z) z->key = y->key;
    free(y);
}

  void tree_gravar(No * raiz){  

 /*   if (raiz == NULL) {
      printf("gravar raiz nula\n");
      return;
    }
    else { */
      FILE *arquivoSaida = fopen("L2Q3.out", "w+");
      printf("gravar arvore\n");
      tree_gravar(raiz->left);
      fprintf(arquivoSaida, "%d ", raiz->key);
      tree_gravar(raiz->right);
  //    } 
  }