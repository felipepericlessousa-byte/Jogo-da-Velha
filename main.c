#include <stdio.h>

int main(void) {
  char nome1[100];
  char nome2[100];
  int opcao;
  printf("Seja bem vindo ao jogo da velha do EducaHub.\n");
  printf("Aqui você aprende jogando!\n");
  printf("Vamos começar? Escolha uma opção do menu abaixo\n");
  printf("1 - Jogar\n");
  printf("2 - Intruções\n");
  printf("3 - Sair\n");
  printf("Digite sua opção: ");
  scanf ("%d", &opcao);
  switch (opcao) {
    case 1:
      printf("Excelente que você escolheui jogar. Antes de tudo vamos personalizar o jogo com os nomes dos jogadores!\n");
      printf("Digite o nome do jogador 1 (X):\n");
      fgets(nome1, 100, stdin); 
      printf("Digite o nome do jogador 2 (O):\n");
      fgets(nome2, 100, stdin);  
      printf ("Ahh que pena!! O jogo está indisponível, volte mais tarde!\n");
      break;
    case 2:
      printf ("Para começar, deve-se olhar para o tabuleiro, com as 9 casas.\n");
      printf ("Em seguida, deve-se escolher entre jogar o jogador um (X) e o jogador dois (O). \n");
      printf ("Jogando um de cada vez. O objetivo do jogo é fazer uma fila de três de seu símbolo escolhido, seja verticalmente, horizontalmente, ou diagonalmente. \n");
      printf ("Porém, a segunda pessoa com quem está jogando tem o mesmo objetivo, e os dois jogadores tem que tentar ser mais espertos do que o outro para fazer a linha de três símbolos.\n");
      printf ("Parece divertido né ? Então, vamos jogar?\n");
      break;
    case 3:
      printf ("Sentimos por ver você partir!!\n");
      printf ("Tente nos visitar sempre que possível! Esperaremos por você!! \n");
      break;
    default:
      printf ("Opção inválida! Tente digitar outro número!! \n");
      break;
  }
  return 0;
}