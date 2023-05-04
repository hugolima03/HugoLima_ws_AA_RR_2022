#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval t1, t2;
double elapsedTime;
/*para o calculo do tempo*/
unsigned long time_diff(struct timeval a, struct timeval b) {
  struct timeval res;
  timersub(&a, &b, &res);
  return res.tv_sec * 1000000 + res.tv_usec;
}

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

int main(int argc, char **argv) {
  FILE *fp;
  int num, count = 0;
  int *lista = NULL;

  if (argc != 2) {
    printf("Uso: %s <arquivo>\n", argv[0]);
    exit(0);
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    exit(1);
  }

  while (fscanf(fp, "%d", &num) == 1) {
    count++;
    lista = realloc(lista, count * sizeof(int));
    lista[count - 1] = num;
  }

  fclose(fp);
  int size = sizeof(&lista) / sizeof(lista[0]);
  gettimeofday(&t1, NULL);
  // EXECUCAO - apenas o algoritmo de ordenacao deve executar aqui
  selectionSort(lista, count);
  gettimeofday(&t2, NULL);
  // OUTPUT
  // for (int i = 0; i < count; i++) {
  //   printf("%d\n", lista[i]);
  // }
  // imprimi o tempo em milisegundos
  printf("\n Tempo de Execucao: ---> %lf \n", time_diff(t2, t1) / 100000.0);

  free(lista);
  return 0;
}
