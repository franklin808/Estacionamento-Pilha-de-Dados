#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_PILHA 5

typedef struct Carro {
  char placa[7];
} Carro;

Carro pilhaPrincipal[TAM_PILHA];
int topoPrincipal = 0;

Carro pilhaAuxiliar[TAM_PILHA];
int topoAuxiliar = 0;

void empilharPrincipal(Carro carro) {
  if (topoPrincipal < TAM_PILHA) {
    pilhaPrincipal[topoPrincipal] = carro;
    topoPrincipal++;
  } else {
    printf("Estacionamento lotado!\n");
  }
}

Carro desempilharPrincipal() {
  if (topoPrincipal > 0) {
    topoPrincipal--;
    return pilhaPrincipal[topoPrincipal];
  } else {
    Carro carroVazio = {""};
    return carroVazio;
  }
}

void empilharAuxiliar(Carro carro) {
  if (topoAuxiliar < TAM_PILHA) {
    pilhaAuxiliar[topoAuxiliar] = carro;
    topoAuxiliar++;
  } else {
    printf("ERRO: Pilha auxiliar cheia!\n");
  }
}

Carro desempilharAuxiliar() {
  if (topoAuxiliar > 0) {
    topoAuxiliar--;
    return pilhaAuxiliar[topoAuxiliar];
  } else {
    Carro carroVazio = {""};
    return carroVazio;
  }
}

void exibirCarros() {
  if (topoPrincipal == 0) {
    printf("\nEstacionamento vazio!\n");
  } else {
    printf("\nCarros estacionados:\n\n");
    int i;
    for (i = topoPrincipal - 1; i >= 0; i--) {
      printf("%d. %s \n", i + 1, pilhaPrincipal[i].placa);
    }
  }
}

void saidaCarro(char placaSaida[]) {
  int carrosMovimentados = 0;
  Carro carroSaindo = {""};
 int i;
  for (i = topoPrincipal - 1; i >= 0; i--) {
    if (strcmp(pilhaPrincipal[i].placa, placaSaida) == 0) {
      if (i == topoPrincipal - 1) {
        carroSaindo = desempilharPrincipal();
      } else {
        while (i < topoPrincipal - 1) {
          empilharAuxiliar(desempilharPrincipal());
          carrosMovimentados++;
        }
        carroSaindo = desempilharPrincipal();
        while (topoAuxiliar > 0) {
          empilharPrincipal(desempilharAuxiliar());
        }
      }
      break;
    }
  }
  
  

  if (strcmp(carroSaindo.placa, "") != 0) {
    printf("Veículo %s deseja sair.\n", carroSaindo.placa);
    printf("Carros manobrados: %d\n", carrosMovimentados);
  } else {
    printf("Veículo %s não encontrado!\n", placaSaida);
  }
}

void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
  char opcao;
  Carro carro;

  while (1) {
    printf("Estacionamento de Veículos\n\n",setlocale(LC_ALL,""));
    printf("E + Placa do Veículo para entrada do veículo Exemplo : (E ABC1234)\n");
    printf("S + Placa do Veículo para saída do veículo Exemplo : (S ABC1234)\n");
    printf("Digite M para mostrar os veículos estacionados\n");
    printf("Digite Q para Sair\n");
    printf("Escolha uma opção: ");
    scanf("%c", &opcao);

    switch (opcao) {
      case 'e':
      case 'E':
        scanf("%s", carro.placa);
        limparBufferEntrada();
        empilharPrincipal(carro);
        exibirCarros();        
        break;
      case 's':
      case 'S':
        scanf("%s", carro.placa);
        limparBufferEntrada();
        saidaCarro(carro.placa);
        exibirCarros();
        break;
      case 'm':
      case 'M':
      limparBufferEntrada();
      exibirCarros();
      break;
      case 'q':
      case 'Q':
        printf("Saindo do sistema...\n");
        exit(0);
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}

