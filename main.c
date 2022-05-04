#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.h"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, menu, resultado;
	int pontos1 = 0;
	int pontos2 = 0;
	char jogador1[16], jogador2[16];
	
	printf("Menu - Jankenpon\n");
	printf("1 - Jogar 1v1\n");
	printf("2 - Jogar vs máquina\n");
	printf("3 - Extras\n");
	
	menu = getch() - '0';
	
	switch(menu){
		case 1:
			system("cls");				
			printf("\nJogador 1, digite seu nome: ");
			scanf("%s", &jogador1);			
			printf("\nJogador 2, digite seu nome: ");
			scanf("%s", &jogador2);
			
			for(;;){
				int a = validar(jogador1);
				int b = validar(jogador2);
				resultado = comparar(a, b);
				
				printf("%s escolheu: ", jogador1);
				sleep(1);
				printf("%s", mostrar(a));
				
				printf("\n");
				
				printf("%s escolheu: ", jogador2);
				sleep(1);
				printf("%s", mostrar(b));
				
				if(resultado == a)
					pontos1++;
				if(resultado == b)
					pontos2++;
					
				vencedor(resultado);
				
				printf("\n\n* %s: %d pontos\n* %s: %d pontos", jogador1, pontos1, jogador2, pontos2);
				printf("\nDeseja jogar novamente?");
				printf(" S para sim, N para não: ");
				
				char j = getch();
				if(j == 'S' || j == 's') continue;
				else break;
			}
			break;
		case 2:
			system("cls");				
			printf("\nJogador 1, digite seu nome: ");
			scanf("%s", &jogador1);	
			
			for(;;){
				int a = validar(jogador1);
				int b = computador();
				
				printf("%s escolheu: ", jogador1);
				sleep(1);
				printf("%s", mostrar(a));
				
				printf("\n");
				
				printf("Computador escolheu: ");
				sleep(1);
				printf("%s", mostrar(b));
				
				resultado = comparar(a, b);
				if(resultado == a)
					pontos1++;
				if(resultado == b)
					pontos2++;
					
				vencedor(resultado);
				
				sleep(1);
				printf("\n\n* %s: %d pontos\n* Computador: %d pontos", jogador1, pontos1, pontos2);
				printf("\nDeseja jogar novamente?");
				printf(" S para sim, N para não: ");
				
				char j = getch();
				if(j == 'S' || j == 's') continue;
				else break;
			}
			break;
		case 3:
			system("cls");
			printf("\n1 - Ajuda");
			printf("\n2 - Créditos");
			
			opcao = getch() - '0';
		
			if(opcao == 1){				
				system("cls");
				printf("\nVocê não precisa de ajuda.");
				sleep(2);
				system("exit");
			}
			if(opcao == 2){
				system("cls");
				printf("Turma de ADS/Engenharia de Software da FESP\n1 periodo\n2022\n\nAlexandre Lohn Sell\nEduardo Henrique Alberti\nMelryan Ellise Koppper\n");
				sleep(2);
				system("exit");
			}
			else break;
			break;
		default:
			printf("Opção inválida!");
	}
}
