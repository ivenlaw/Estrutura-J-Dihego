/*Como ponteiros para ''void'' não apontam para nenhum tipo válido de dado, eles não podem ser desreferenciados; não é possível acessar diretamente os dados que eles apontam. Por isso, ponteiros para ''void'' precisam ser convertidos em ponteiros para algum tipo válido antes de serem desreferenciados.

O exemplo a seguir mostra como ponteiros ''void'' são convertidos em ''int'', dentro da função ''compara_int(a,b)'':*/

#include <stdio.h>
#include <stdlib.h>

int vetor[1000] ;
int vsize ;

// compara dois inteiros apontados por "a" e "b"
int compara_int (const void* a, const void* b)
{
   int *pa, *pb ;

   pa = (int*) a ;  // passa a ver a como int*
   pb = (int*) b ;  // idem, b

   if (*pa > *pb) return  1 ;
   if (*pa < *pb) return -1 ;
   return 0 ;
}

int main ()
{
   int i ;

   // preenche o vetor de inteiros com aleatórios
   vsize = 1000 ;
   for (i = 0; i < vsize; i++)
      vetor[i] = random() % 1000 ;

   // ordena o vetor (man qsort)
   qsort (vetor, vsize, sizeof(int), compara_int) ;

   // escreve o vetor
   for (i = 0; i < vsize; i++)
      printf ("%d ", vetor[i]) ;
   printf ("\n") ;
}