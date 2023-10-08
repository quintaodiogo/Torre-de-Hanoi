#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(int matriz[][3], int discos)
{
  for (int i = 0; i < discos; i++)
  {
    for (int j = 0; j < discos; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  int origem, destino, aux, resposta;
  int discos = 3;
  int matriz[3][3] = {0};

  srand(time(NULL));
  printf("==================\n");
  printf("==TORRE DE HANOI==\n");
  printf("==================\n");
  printf("JOGAR (1)\n");
  printf("MODO AUTOMÁTICO(2)\n");
  if (scanf("%d", &resposta) != 1 || (resposta != 1 && resposta != 2))
  {
    printf("Erro: Você deve digitar 1 ou 2.\n");
    return 1; // Retorna um código de erro
  }
  if (resposta == 1)
  {
    printf("Digite a origem: ");
    scanf("%d", &origem);
    printf("\nDigite o destino: ");
    scanf("%d", &destino);
  }
  else
  {
    origem = 1 + (rand() % 3);
    do
    {
      destino = 1 + (rand() % 3);
    } while (destino == origem);
  }
  printf("%d %d\n", origem, destino);

  aux = 6 - (origem + destino);

  matriz[discos - 1][origem - 1] = discos;
  imprimirMatriz(matriz, discos);
  matriz[discos - 2][origem - 1] = discos - 1;
  imprimirMatriz(matriz, discos);
  matriz[discos - 3][origem - 1] = discos - 2;
  imprimirMatriz(matriz, discos);
  matriz[discos - 3][origem - 1] = 0;
  matriz[discos - 1][destino - 1] = discos - 2;
  imprimirMatriz(matriz, discos);
  matriz[discos - 2][origem - 1] = 0;
  matriz[discos - 1][aux - 1] = discos - 1;
  imprimirMatriz(matriz, discos);
  matriz[discos - 1][destino - 1] = 0;
  matriz[discos - 2][aux - 1] = discos - 2;
  imprimirMatriz(matriz, discos);
  matriz[discos - 1][origem - 1] = 0;
  matriz[discos - 1][destino - 1] = discos;
  imprimirMatriz(matriz, discos);
  matriz[discos - 2][aux - 1] = 0;
  matriz[discos - 1][origem - 1] = discos - 2;
  imprimirMatriz(matriz, discos);
  matriz[discos - 1][aux - 1] = 0;
  matriz[discos - 2][destino - 1] = discos - 1;
  imprimirMatriz(matriz, discos);
  matriz[discos - 1][origem - 1] = 0;
  matriz[discos - 3][destino - 1] = discos - 2;
  imprimirMatriz(matriz, discos);

  return 0;
}

