#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

int comparar(int a, int b){
	
	/*
	1 - Pedra
	2 - Papel
	3 - Tesoura
	4 - Empate
	*/
	
	if(a == b)
		return 4; 
	
	else if(a == 1 && b == 2)
		return 2;
		
	else if(a == 1 && b == 3)
		return 1;
		
	else if(a == 2 && b == 1)			
		return 2;
		
	else if(a == 2 && b == 3)
		return 3;
		
	else if(a == 3 && b == 1)
		return 1;
	
	else if(a == 3 && b == 2)
		return 3;
		
	else return 0;
}

int validar(char nome[]){
	for(;;){
		system("cls");
		printf("%s, escolha \n 1- Pedra \n 2- Papel \n 3- Tesoura \n", nome);
		int b = getch() - '0';
		
		if(b == 1 || b == 2 || b == 3)
			return b;
			
		else{
			system("cls");
			printf("Opcao invalida!");
		}
	}
}

void vencedor(int resultado){
	if(resultado == 1)
		printf("\n\n - Pedra vence");
	if(resultado == 2)
		printf("\n\n - Papel vence");
	if(resultado == 3)
		printf("\n\n - Tesoura vence");
	if(resultado == 4)
		printf("\n\n - Empate");
}

int computador(){
	return (rand() %2) + 1;
}

const char* mostrar(int a){
	if(a == 1)
		return "Pedra";
	if(a == 2)
		return "Papel";
	if(a == 3)
		return "Tesoura";
}
