#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�rias
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar do string

int registro() //fun��o respons�vel por cadastrar os usu�rios
{
	//in�cio da cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado :"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a salvar a string
	
	strcpy (arquivo, cpf); //responsavel por copiar ps valores das strings
	
	FILE *file; //criar o arquivo.
	file = fopen(arquivo, "w"); //criar arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,","); //salvar varia�vel
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado :"); //coletando informa��es do usu�rio
	scanf("%s",nome); //%s refere-se a salvar a string
		
	file = fopen(arquivo, "a"); //criar arquivo 
	fprintf(file,nome); //salvar vari�vel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,","); //salvar vari�vel
	fclose(file); //fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado :"); //coletar informa��es do usu�rio
	scanf("%s",sobrenome); //%s refere-se a salvar a string
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,sobrenome); //salvar vari�vel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,","); //salvar vari�vel
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado :"); //coletar informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a salvar a string
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,cargo); //salvar vari�vel
	fclose(file); //fechar o arquivo
	
	system("pause");			
	
} 

int consulta() //fun��o respons�vel por consultar usu�rio
{
	
setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem

 //inicio da cria��o de vari�veis string
char cpf[40];
char conteudo[200];
//fim da cria��o de vari�veis string

printf("Digite o CPF a ser consultado :"); //coletar inform��es do usu�rio
scanf("%s",cpf); //%s refere-se a salvar a string

FILE *file;
file = fopen(cpf,"r"); //criar arquivo e "r" significar ler

   if(file == NULL) //se o arquivo for nulo
   {  
     printf("N�o foi poss�vel abrir, arquivo n�o localizado!.\n"); //informa��o ao usu�rio
   }
   
   while(fgets(conteudo, 200, file) != NULL) //enquanto o conte�do de at� 200 caracteres forem nulos
   {	
     printf("\nEssas s�o as informa��es do usu�rio :"); //informa��o na tela ao usu�rio
     printf("%s", conteudo);
     printf("\n\n"); //pular linhas
   }
  
   system("pause");
  
}

int deletar()
{
	//in�cio cria��o de vari�veis/string
    char cpf[40];
    // final cria��o de vari�vel/string
    
    printf("Digitar o CPF do usu�rio � ser deletado:"); //coletar informa��o do usu�rio � ser deletado
    scanf("%s",cpf);
    
    remove(cpf); //remo��o do CPF cadastrado
    
    FILE *file;
    file = fopen(cpf,"r"); //criar arquivo e "r" significa ler
    
    if(file == NULL)
    {
      printf("O usus�rio n�o se encontra no sistema!.\n"); //informa��o ao usu�rio
      system("pause");
	}
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
	   system("cls"); //respons�vel por limpar a tela
	
	   setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	   printf ("### Cart�rio da EBAC ###\n\n");
       printf ("Escolha a op��o desejada menu:\n\n");
	   printf ("\t1 - Registrar nomes\n");
	   printf ("\t2 - Consultar nomes\n");
	   printf ("\t3 - Deletar nomes\n\n");
	   printf ("opcao:"); //Fim menu
	
	   scanf("%d",&opcao); //armazenamento a escolha do usu�rio
	
	   system("cls"); //respons�vel por limpar a tela
	
	  switch (opcao) //in�cio da sele��o menu
	 {
	    case 1:
	    registro(); //chamada de fun��es
		break; 
		
		case 2:
		consulta(); //chamada de fun��es
		break; 
		
		case 3:
		deletar(); //chamada de fun��es
		break; 
		
		default:
		printf ("Essa op��o n�o est� dispon�vel.\n");
		system ("pause");
		break;
	 } //Fim da sele��o
    }
	
}
