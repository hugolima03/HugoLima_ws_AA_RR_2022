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

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) largest = left;

  if (right < n && arr[right] > arr[largest]) largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
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
  heapSort(lista, count);
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
