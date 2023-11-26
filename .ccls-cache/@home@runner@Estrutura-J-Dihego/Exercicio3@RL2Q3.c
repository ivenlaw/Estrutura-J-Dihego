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
void destroiTree(No * Z);
void tree_gravar(FILE *arquivoSaida, No * x, int nivel);
int tamanhoNo(No * x);

int main(){

  int i=0, j, l=0;

  FILE *arquivoEntrada = fopen("L2Q3.in", "r");
  FILE *arquivoSaida = fopen("L2Q3.out", "w+");
  if(arquivoEntrada == NULL || arquivoSaida==NULL){
        printf("%s\n", "Falha na criação dos arquivos!");
        return EXIT_FAILURE;
  }
//  fclose(arquivoSaida);


  char linha[TAM_MAX_LINHA];

  while(fgets(linha, TAM_MAX_LINHA, arquivoEntrada) != NULL){
    Tree * arvore = malloc(sizeof(Tree));
    char *tok;
    printf("linha 44\n");
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
        if(no1 == 'a') {
          tree_inserir(arvore, novo);
          printf("linha 68\n");}
        else if(no1 == 'r'){
          printf("linha 70\n");
          if (tree_busca(arvore, no2)==NULL){
            tree_inserir(arvore, novo);
          }
          else {
            tree_apagar(arvore, tree_busca(arvore, no2));
            printf("linha 76\n");}
          }
        printf("linha 78\n");
        i=0;
      }
 //     i++;
      tok=strtok(NULL, " "); 
    }
  printf("linha 84 %d\n", l);
//  inorder_tree_walk(arvore->raiz);

  if (l>0){
 //   FILE *arquivoSaida = fopen("L2Q3.out", "w");
    printf("linha 86\n");
    fputs("\n", arquivoSaida);
    tree_gravar(arquivoSaida, arvore->raiz, 0);
//    destroiTree(arvore->raiz);
  } else {
    l++;
    tree_gravar(arquivoSaida, arvore->raiz, 0);
  }

//    destroiTree(arvore->raiz);
 // fclose(arquivoSaida);
 // tree_apagar(arvore, arvore->raiz);

  printf("linha 91\n");
//  fclose(arquivoSaida);
  }

fclose(arquivoSaida);
fclose(arquivoEntrada);
//tree_apagar(arvore, arvore->raiz);
}

No  * criar_no(char tok, int key){
   No * no = malloc(sizeof(No));
   no->key =  key;
   no->fazer = tok;
   return no;
}

void inorder_tree_walk(No * x){
    if(x!= NULL){
   //     FILE *arquivoSaida = fopen("L2Q3.out", "a");
        inorder_tree_walk(x->left);
//        printf("gravar insert %c %d\n", x->fazer, x->key);
      //  fprintf(arquivoSaida, "%d (%d)", x->key, nivel);
    //    printf(" %d ", x->key);
        inorder_tree_walk(x->right);
    }
}

void tree_inserir(Tree * T, No * z){
    No * y = NULL;
    No * x = T->raiz;
    while(x != NULL){
      printf("linha 116\n");
        y  = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->mae = y;
    if(y== NULL) {
      printf("linha 123\n");
      T->raiz = z;
    }
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
    if(y->mae == NULL) T->raiz = x;  //raiz
    else{
        if(y == y->mae->left) y->mae->left =  x;
        else y->mae->right = x;
    }
    if(y!=z) z->key = y->key;
    free(y);
}

void destroiTree(No * Z) {
    if (Z == NULL) {
        return;
    }

    // Apagar os filhos recursivamente (pós-ordem)
      destroiTree(Z->left);
      destroiTree(Z->right);

    // Liberar a memória do nó atual
    free(Z);
}

  void tree_gravar(FILE *arquivoSaida, No * x, int nivel){  

    if(x== NULL){
      printf("linha 189\n");
      return;
    }

    if(x != NULL){

      tree_gravar(arquivoSaida, x->left, nivel + 1);
 //     FILE *arquivoSaida = fopen("L2Q3.out", "a");
      fprintf(arquivoSaida, "%d (%d) ", x->key, nivel);
   //   fprintf(arquivoSaida, "%d (%d) ", x->key, nivel);
      tree_gravar(arquivoSaida, x->right, nivel + 1);


    }

  }

int tamanhoNo(No * x){
    if(x == NULL) return 0;
    else return 1 + tamanhoNo(x->left) + tamanhoNo(x->right);
}

