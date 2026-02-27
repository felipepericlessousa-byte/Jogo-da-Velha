#include <stdio.h>

char matriz[3][3];
int opcao;
int linha, coluna;
char jogador = 'X';  

void inicializar_tabuleiro () {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matriz[i][j] = ' ';
    }
  }
}

void exibir_tabuleiro () {
  printf("    0    1    2 \n");
  for (int i = 0; i < 3; i++) {
    printf("%d   ", i);
    for (int j = 0; j < 3; j++) {
      if (j < 2) {
        printf(" %c |", matriz[i][j]);
      } else {
        printf(" %c ", matriz[i][j]);
      }
    }
    if (i < 2) {
      printf("\n ----------------\n");
    }
  }
  printf("\n");
}

int verificar_vencedor() {
  for (int i = 0; i < 3; i++) {
    if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ')
      return 1;
  }
  for (int j = 0; j < 3; j++) {
    if (matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j] && matriz[0][j] != ' ')
      return 1;
  }
  if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' ')
    return 1;
  if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != ' ')
    return 1;
  return 0;
}

void AlternarJogador (){
  if (jogador == 'X') {
    jogador = 'O';
  } else {
    jogador = 'X';
  }
}

void FucaoJogada(){
  printf("\nVez do jogador %c\n", jogador);

  do {
    printf("Digite a linha (0-2): ");
    scanf("%d", &linha);
    printf("Digite a coluna (0-2): ");
    scanf("%d", &coluna);

    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
      printf("Coordenadas inválidas! Tente novamente.\n");
      continue;
    }

    if (matriz[linha][coluna] != ' ') {
      printf("Essa posição já está ocupada! Escolha outra.\n");
    }

  } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || matriz[linha][coluna] != ' ');

  matriz[linha][coluna] = jogador;
}

int Empate() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (matriz[i][j] == ' ') {
        return 0;
      }
    }
  }

  if (!verificar_vencedor()) {
    return 1; 
  }
  return 0; 
}

int main(void) {

  printf("Seja bem-vindo ao jogo da velha do EducaHub.\n");
  printf("Aqui você aprende jogando!\n");
  printf("Vamos começar? Escolha uma opção do menu abaixo\n");
  printf("1 - Jogar\n");
  printf("2 - Instruções\n");
  printf("3 - Sair\n");
  printf("Digite sua opção: ");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      printf("Excelente que você escolheu jogar.\n");
      printf("Jogador 1 será o X.\n");
      printf("Jogador 2 será o O.\n");
      printf("Observe o tabuleiro!!\n");

      inicializar_tabuleiro ();
      exibir_tabuleiro ();

      for (int jogada = 0; jogada < 9; jogada++) {
        FucaoJogada ();
        exibir_tabuleiro ();

        if (verificar_vencedor()) {
          printf("Jogador %c venceu! Parabéns!\n", jogador);
          break;
        }

        if (Empate()) {
          printf("Empate! Ninguém venceu.\n");
          printf("Recomendo jogar novamente!.\n");
          break;
        }

        AlternarJogador ();
      }

      break;

    case 2:
      printf("Para começar, deve-se olhar para o tabuleiro, com as 9 casas.\n");
      printf("Em seguida, deve-se escolher entre o jogador um (X) e o jogador dois (O).\n");
      printf("Jogando um de cada vez. O objetivo é fazer uma fila de três símbolos iguais — horizontal, vertical ou diagonal.\n");
      printf("Divirta-se!\n");
      break;

    case 3:
      printf("Sentimos por ver você partir!!\n");
      printf("Tente nos visitar sempre que possível! Esperaremos por você!\n");
      break;

    default:
      printf("Opção inválida! Tente digitar outro número!\n");
      break;
  }

  return 0;
  }