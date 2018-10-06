#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define ZERO 0  //variavel nunca ira mudar o valor

int main () {

  typedef struct _empresa_ {
  
    char nome_empresa[100];
    char lugar_empresa[100];
    int  cod_empresa;
  
  } Empresa;

  Empresa empresas[5];
  int i, escolha, tamanho;
  int cod_empresa = 1001;
  int cont = 0;       //Variável que contará a qntd de empresas cadastradas 

  setlocale(LC_ALL, "Portuguese");
  printf("             SE FOR SUA PRIMEIRA VEZ NO PROGRAMA, ENTAO CADASTRE UM HOTEL\n\n"); // partida de escolha, essa primeira fase irei del.

  while(escolha != ZERO) {//Enquanto não digitar zero, repete isso tudo

    printf("Digite uma das escolhas abaixo: \n\n1- Verificar todos Hoteis Cadastrados. \n2- Buscar por posicao de cadastro \n3- Cadastrar Hotel, no caso serao 5 hoteis ha ser cadastrados.\n0- Digite para sair.");
    printf("\n\nEscolha ha opcao: ");
    scanf("%d", &escolha);
    system("cls");
    
    switch (escolha) {

      case 0:
      
        printf("\n\n|:::::::::::::: SAIR ::::::::::::::| \n\n"); // apos digitar 0 ele sai do programa
        break;
      
      case 1:
      
        printf("\n\n|******* Empresas que foram cadastradas *******| \n\n"); // mostra as empresas que foram cadastradas
      
        for(i = ZERO; i < cont; i++) {
          printf("Posicao de cadastro para pesquisa é: %i\n", i+1);
          printf("Nome da Empresa: %s\n", empresas[i].nome_empresa);
          printf("Local da Empresa: %s\n", empresas[i].lugar_empresa);
          printf("Codigo da Empresa %i\n\n", empresas[i].cod_empresa);
        }
        break;
      
      case 2:
      
        printf("**** Buscar Hotel pelo Numero de Inscrição ****\n");  //busca hoteis cadastrados pela posição de cadastro
        printf("\nDigite Numero de Cadastro do Hotel: ");
        scanf("%d", &i);
        printf("Posicao de cadastro para pesquisa é: %i \n", i);
        i--;
        printf("Codigo da Empresa: %i\n\n", empresas[i].cod_empresa); 
        printf("Nome do Hotel: %s\n",empresas[i].nome_empresa);
        printf("Local do Hotel: %s\n",empresas[i].lugar_empresa);
        break;
      
      case 3:

        printf("Quantos cadastros voce ira fazer? ");
        scanf("%d", &tamanho);

      	for(i=ZERO; i<tamanho; i++) {
          printf("                    Cadastro de Hoteis                    \n\n");
          empresas[cont].cod_empresa = cod_empresa += cont;
          printf("Codigo do Hotel %i\n\n", empresas[cont].cod_empresa);  //soma valor de i+ o cod_empresa 1001+1 ..
          printf("Digite Nome do %i Hotel: \n",i+1);
          fflush(stdin);
          gets(empresas[cont].nome_empresa);	//armazena em cada posição do vetor
          printf("Digite Local do Hotel: \n");
          fflush(stdin);
          gets(empresas[cont].lugar_empresa); //armazena em cada posição do vetor
          system("cls");
          cont++;
  	    }
        break;
      
      default :
      
        printf ("Valor Inserido invalido!\n");
    
    } //fim switch
  } //fim while

  return ZERO;
}
