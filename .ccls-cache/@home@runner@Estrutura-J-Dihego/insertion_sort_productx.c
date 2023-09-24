#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// converter "30-08-2020" (texto) em X segundos

time_t text_2_time(char * text) {
  struct tm tmp = {0};
  strptime(text,"%d-%m-%Y",&tmp);
  return mktime(&tmp);  
}

void time_2_text(time_t * time, char * output, int size) {
  struct tm * tmp = localtime (time);
  strftime(output,size,"%d=%m-%Y", tmp);
  }

// x segundos em "30-08-2020" (texto)

typedef struct Product {
  char * name;
  float price;
  time_t due_date;
} Product;

typedef struct Supermarket {
  char * name;
  Product ** products;
} Supermarket;

void print_product (Product * product) {
  char *date = malloc(11 *sizeof(char));
  time_2_text (&product->due_date, date, 11);
  printf("Nome: %s \t Preco: %.2f \t Data Validade: %s\n", product->name, product->price,
  date);
}
/*
int main() {
  
  char * date_text = "30-08-2020";
  time_t time_mili = text_2_time(date_text);
  printf("antes: %s\n", date_text);
//  printf("%lld\n", (long long)time);

  char * date_text2 = malloc(12 * sizeof(char));
  time_2_text(&time_mili, date_text2, 12);
  printf("depois: %s\n", date_text2);
  return EXIT_SUCCESS;
}
*/


int main () {

  Product * farinha = malloc(sizeof(Product)); // aloca o endereco de um ponteiro de um produto na variavel farinha, que é um ponteiro

  // vá dentro do endereco farinha, em name e coloque "Farinha Boa Sorte", etc
  farinha->name = "Farinha Boa Sorte";
  farinha->price = 7.00;
  farinha->due_date=text_2_time("30-12-2013");

  print_product(farinha);
  
}
