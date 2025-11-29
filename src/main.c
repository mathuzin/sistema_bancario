#include <stdbool.h>
#include <stdio.h>

struct usuario {
  char nome[10];
  char cpf[14];
  char telefone[11];
  char email[100];
  char endereco[100];
};

struct conta {
  int id;
  struct usuario user;
  double saldo;
};

void mostrar_perfil(struct conta *c) {
  printf("=== Informações da conta === \n");
  printf("ID: %d\n", c->id);
  printf("Saldo: R$ %.2lf\n\n", c->saldo);
  printf("=== Informações do Usuário ===\n");
  printf("Nome: %s\n", c->user.nome);
  printf("CPF: %s\n", c->user.cpf);
  printf("Telefone %s\n", c->user.telefone);
  printf("Email: %s\n", c->user.email);
  printf("Endereço: %s\n", c->user.endereco);
};

void receber_transacao(struct conta *c, double valor) {
  c->saldo += valor;
  printf("A transferencia foi recebida com sucesso!\n");
};

void fazer_transcao(struct conta *c, double valor) {
  double novo_saldo;
  if (c->saldo >= valor) {
    novo_saldo = c->saldo - valor;
    c->saldo = novo_saldo;
    printf("A transação foi feita com sucesso!\n");
  } else {
    printf("Você não tem saldo suficiente!\n");
  }
};

int main() {

  struct usuario user = {"Arthur", "918.156.830-40", "8426506576",
                         "arthurzin@email.com",
                         "926, Rua dos Noobs - Nova, RedNau - DG"};
  struct conta c1 = {1, user, 500.00};
  bool acabar = false;
  while (!acabar) {
    int menu;
    printf("Menu de operações: \n 1-Mostrar perfil\n 2-Receber Transação\n "
           "3-Fazer Transação\n 4-Sair\n");

    double valor;
    scanf("%d", &menu);
    switch (menu) {
    case 1:
      mostrar_perfil(&c1);
      break;
    case 2:
      printf("Qual será o valor que você receberá? \n");
      scanf("%lf", &valor);
      receber_transacao(&c1, valor);
      break;
    case 3:
      printf("Quanto você irá transferir?  \n");
      scanf("%lf", &valor);
      fazer_transcao(&c1, valor);
      break;
    case 4:
      printf("Saindo do sistema...\n");
      acabar = true;
      break;
    default:
      printf("Essa operação não existe.\nSaindo do sistema... \n");
      acabar = true;
      break;
    }
  }
  return 0;
};
