#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int baralho_carta[52];
int jogador_a_carta[52];
int jogador_b_carta[52];
int num_carta;
int i;
int contador;
int naipe;
char opcao_jogador_a;
char opcao_jogador_b;
int validar_carta;
int carta_jogada;
int carta_mesa;
int naipe_mesa;
int naipe_jogado;
int numero_mesa;
int numero_jogado;
int validar_naipe;
int validar_numero;
int carta_temporaria;
int passa_jogada;

void imprime_carta(int numero)
{
	char carta[15];
	if(numero != 0)
		{
			num_carta = numero % 13;
			naipe = numero / 14;
			switch (num_carta)
			{
			case 1:
				strcpy(carta, "A");
				break;
			case 2:
				strcpy(carta, "2");
				break;
			case 3:
				strcpy(carta, "3");
				break;
			case 4:
				strcpy(carta, "4");
				break;
			case 5:
				strcpy(carta, "5");
				break;
			case 6:
				strcpy(carta, "6");
				break;
			case 7:
				strcpy(carta, "7");
				break;
			case 8:
				strcpy(carta, "8");
				break;
			case 9:
				strcpy(carta, "9");
				break;
			case 10:
				strcpy(carta, "10");
				break;
			case 11:
				strcpy(carta, "Q");
				break;
			case 12:
				strcpy(carta, "J");
				break;
			case 0:
				strcpy(carta, "K");
				break;
			}
			switch (naipe)
			{
			case 0:
				strcat(carta, " Paus");
				break;
			case 1:
				strcat(carta, " Espadas");
				break;
			case 2:
				strcat(carta, " Copas");
				break;
			case 3:
				strcat(carta, " Ouros");
				break;
			}
			printf("\n%d-%s",numero,carta);
		}
}
void imprime_baralho()
{
	printf("Baralho:");
	for (i = 0; i < 52; i++)
	{
		imprime_carta(baralho_carta[i]);
	}
}	
void imprime_cartas_a()
{
	printf("\n\nBaralho jogador A:");
	for (i = 0; i < 52; i++)
	{
		imprime_carta(jogador_a_carta[i]);
	}	
}
void imprime_cartas_b()
{
	printf("\n\nBaralho jogador B:");
	for (i = 0; i < 52; i++)
	{
		imprime_carta(jogador_b_carta[i]);
	}	
}
void menu_jogador_a()
{
	do
	{
		system("cls");
		printf("\nCarta na mesa:");
		imprime_carta(carta_mesa);
		imprime_cartas_a();
		printf("\n\nJogador A\n");
		printf("1-Jogar uma carta\n");
		printf("2-Buscar ao baralho\n");
		printf("3-Passar jogada\n");
		printf("Opção:");
		scanf("\n%c",&opcao_jogador_a);
		passa_jogada=0;
		switch(opcao_jogador_a)
		{
			case '1':
			//ler carta do jogador
				printf("Carta:");
				scanf("%d",&carta_jogada);
				//validar se a carta existe nas cartas do jogador
				validar_carta = 0;
				for(i = 0;i < 52;i++)
				{
					if(jogador_a_carta[i] == carta_jogada)
						validar_carta = 1;
				}
				if(validar_carta)
					printf("Carta válida");
				else
					printf("Carta inválida");
				//validar se a jogada é valida
				//verficar se é do mesmo naipe
				validar_naipe = 0;
				naipe = jogador_a_carta[i] / 14;
				naipe_mesa = carta_mesa / 14;
				naipe_jogado = carta_jogada / 14;
				if(naipe_mesa == naipe_jogado)
					validar_naipe = 1;
				if(validar_naipe)
					printf("\nNaipe válido");
				else
					printf("\nNaipe inválido");
				//verificar se é do mesmo numero
				validar_numero = 0;
				num_carta = jogador_a_carta[i] % 13;
				numero_mesa = carta_mesa % 13;
				numero_jogado = carta_jogada % 13;
				if(numero_mesa == numero_jogado)
					validar_numero = 1;
				if(validar_numero)
					printf("\nNumero válido");
				else
					printf("\nNumero inválido");
				//jogar a carta valida
				if(validar_carta && (validar_naipe || validar_numero))
				{
					passa_jogada=1;
					//meter carta na mesa
					carta_mesa=carta_jogada;
					//tirar carta do jogador
					for(i = 0;i < 52;i++)
					{
						if(jogador_a_carta[i] == carta_jogada)
							jogador_a_carta[i]= 0;
					}		
				}
				else 
				{
					printf("\nJogada inválida");
				}
				break;
			case '2':
				//verificar se o baralho tem cartas
				if(baralho_carta[0] != 0)
				{
					//ir buscar a ultima carta ao baralho
					for(i = 0;i < 52;i++)
					{
						if(baralho_carta[i] == 0)
						{
							carta_temporaria = baralho_carta[i-1];
							baralho_carta[i-1]=0;
							break;
						}
					}
					//inserir carta na mao do jogador
					for(i = 0;i < 52;i++)
					{
						if(jogador_a_carta[i] == 0)
						{
							jogador_a_carta[i]=carta_temporaria;
							break;
						}
					}
					//escreve carta retirada
					printf("\nCarta do baralho:");
					imprime_carta(carta_temporaria);
				}
				else
				printf("Baralho vazio!");
				break;
		}
		getch();
	}while(opcao_jogador_a != '3' && passa_jogada == 0);
}
void menu_jogador_b()
{
	do
	{
		system("cls");
		printf("\nCarta na mesa:");
		imprime_carta(carta_mesa);
		imprime_cartas_b();
		printf("\n\nJogador B\n");
		printf("1-Jogar uma carta\n");
		printf("2-Buscar ao baralho\n");
		printf("3-Passar jogada\n");
		printf("Opção:");
		scanf("\n%c",&opcao_jogador_b);
		passa_jogada=0;
		switch(opcao_jogador_b)
		{
			case '1':
			//ler carta do jogador
				printf("Carta:");
				scanf("%d",&carta_jogada);
				//validar se a carta existe nas cartas do jogador
				validar_carta = 0;
				for(i = 0;i < 52;i++)
				{
					if(jogador_b_carta[i] == carta_jogada)
						validar_carta = 1;
				}
				if(validar_carta)
					printf("Carta válida");
				else
					printf("Carta inválida");
				//validar se a jogada é valida
				//verficar se é do mesmo naipe
				validar_naipe = 0;
				naipe = jogador_b_carta[i] / 14;
				naipe_mesa = carta_mesa / 14;
				naipe_jogado = carta_jogada / 14;
				if(naipe_mesa == naipe_jogado)
					validar_naipe = 1;
				if(validar_naipe)
					printf("\nNaipe válido");
				else
					printf("\nNaipe inválido");
				//verificar se é do mesmo numero
				validar_numero = 0;
				num_carta = jogador_b_carta[i] % 13;
				numero_mesa = carta_mesa % 13;
				numero_jogado = carta_jogada % 13;
				if(numero_mesa == numero_jogado)
					validar_numero = 1;
				if(validar_numero)
					printf("\nNumero válido");
				else
					printf("\nNumero inválido");
				//jogar a carta valida
				if(validar_carta && (validar_naipe || validar_numero))
				{
					passa_jogada=1;
					//meter carta na mesa
					carta_mesa=carta_jogada;
					//tirar carta do jogador
					for(i = 0;i < 52;i++)
					{
						if(jogador_b_carta[i] == carta_jogada)
							jogador_b_carta[i]= 0;
					}		
				}
				else 
				{
					printf("\nJogada inválida");
				}
				break;
			case '2':
				//verificar se o baralho tem cartas
				if(baralho_carta[0] != 0)
				{
					//ir buscar a ultima carta ao baralho
					for(i = 0;i < 52;i++)
					{
						if(baralho_carta[i] == 0)
						{
							carta_temporaria = baralho_carta[i-1];
							baralho_carta[i-1]=0;
							break;
						}
					}
					//inserir carta na mao do jogador
					for(i = 0;i < 52;i++)
					{
						if(jogador_b_carta[i] == 0)
						{
							jogador_b_carta[i]=carta_temporaria;
							break;
						}
					}
					//escreve carta retirada
					printf("\nCarta do baralho:");
					imprime_carta(carta_temporaria);
				}
				else
				printf("Baralho vazio!");
				break;
		}
		getch();
	}while(opcao_jogador_b != '3' && passa_jogada == 0);
}
void main()
{
	setlocale(LC_ALL, "Portuguese");

	int vitoria_jogador_b=1;
	int vitoria_jogador_a=1;
	time_t t;
	
	for(contador = 0; contador < 52; contador++)
	{
		baralho_carta[contador]  = 0;
		jogador_a_carta[contador]  = 0;
		jogador_b_carta[contador]  = 0;
	}
	srand((unsigned)time(&t));
	/*for (i = 0; i < 52; i++)
	{
		baralho_carta[i] = rand() % 52 + 1;
	}*/
	//baralhar baralho
	for(i = 0; i < 52; i++)
	{
		baralho_carta[i]=i + 1;
		
	}
	//shuffle array
	for (i = 0; i < 52; i++) 
	{
    int temp = baralho_carta[i];
    int randomIndex = rand() % 13;
	baralho_carta[i] = baralho_carta[randomIndex];
    baralho_carta[randomIndex] = temp;
	}
	for(i = 0;i < 7; i++)
	{
		jogador_a_carta[i] = baralho_carta[51-i];
		jogador_b_carta[i] = baralho_carta[44-i];
		baralho_carta[51-i] = 0;
		baralho_carta[44-i] = 0;
	}
	printf("\n\n");
	imprime_cartas_a();
	imprime_cartas_b();
	printf("\n\n");
	imprime_baralho();
	//tirar carta do baralho e por na mesa 
	carta_mesa = baralho_carta[37];
	baralho_carta[37] = 0;
	printf("\n\n");
	imprime_carta(carta_mesa);
	printf("\n");
	//ciclo de jogo
	do
	{
		menu_jogador_a();
		//condição de vitoria
		vitoria_jogador_a=0;
		for(i = 0;i < 52;i++)
		{
			if(jogador_a_carta[i] != 0)
			vitoria_jogador_a = 1;
		}
		if(vitoria_jogador_a == 1)
		{
			menu_jogador_b();
			//condição de vitoria
			vitoria_jogador_b=0;
			for(i = 0;i < 52;i++)
			{
				if(jogador_b_carta[i] != 0)
				vitoria_jogador_b = 1;
			}
		}
	}while(vitoria_jogador_a && vitoria_jogador_b);
	if(vitoria_jogador_a == 0)
	printf("\nVitoria do jogador A!");
	else
	printf("\nVitoria do jogador B!");
}
