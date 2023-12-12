#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memórias
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar do string

int registro() //função responsável por cadastrar os usuários
{
	//início da criação de variáveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado :"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a salvar a string
	
	strcpy (arquivo, cpf); //responsavel por copiar ps valores das strings
	
	FILE *file; //criar o arquivo.
	file = fopen(arquivo, "w"); //criar arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,","); //salvar variaável
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado :"); //coletando informações do usuário
	scanf("%s",nome); //%s refere-se a salvar a string
		
	file = fopen(arquivo, "a"); //criar arquivo 
	fprintf(file,nome); //salvar variável
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,","); //salvar variável
	fclose(file); //fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado :"); //coletar informações do usuário
	scanf("%s",sobrenome); //%s refere-se a salvar a string
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,sobrenome); //salvar variável
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,","); //salvar variável
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado :"); //coletar informações do usuário
	scanf("%s",cargo); //%s refere-se a salvar a string
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,cargo); //salvar variável
	fclose(file); //fechar o arquivo
	
	system("pause");			
	
} 

int consulta() //função responsável por consultar usuário
{
	
setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem

 //inicio da criação de variáveis string
char cpf[40];
char conteudo[200];
//fim da criação de variáveis string

printf("Digite o CPF a ser consultado :"); //coletar informções do usuário
scanf("%s",cpf); //%s refere-se a salvar a string

FILE *file;
file = fopen(cpf,"r"); //criar arquivo e "r" significar ler

   if(file == NULL) //se o arquivo for nulo
   {  
     printf("Não foi possível abrir, arquivo não localizado!.\n"); //informação ao usuário
   }
   
   while(fgets(conteudo, 200, file) != NULL) //enquanto o conteúdo de até 200 caracteres forem nulos
   {	
     printf("\nEssas são as informações do usuário :"); //informação na tela ao usuário
     printf("%s", conteudo);
     printf("\n\n"); //pular linhas
   }
  
   system("pause");
  
}

int deletar()
{
	//início criação de variáveis/string
    char cpf[40];
    // final criação de variável/string
    
    printf("Digitar o CPF do usuário à ser deletado:"); //coletar informação do usuário à ser deletado
    scanf("%s",cpf);
    
    remove(cpf); //remoção do CPF cadastrado
    
    FILE *file;
    file = fopen(cpf,"r"); //criar arquivo e "r" significa ler
    
    if(file == NULL)
    {
      printf("O ususário não se encontra no sistema!.\n"); //informação ao usuário
      system("pause");
	}
}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
	   system("cls"); //responsável por limpar a tela
	
	   setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	   printf ("### Cartório da EBAC ###\n\n");
       printf ("Escolha a opção desejada menu:\n\n");
	   printf ("\t1 - Registrar nomes\n");
	   printf ("\t2 - Consultar nomes\n");
	   printf ("\t3 - Deletar nomes\n\n");
	   printf ("opcao:"); //Fim menu
	
	   scanf("%d",&opcao); //armazenamento a escolha do usuário
	
	   system("cls"); //responsável por limpar a tela
	
	  switch (opcao) //início da seleção menu
	 {
	    case 1:
	    registro(); //chamada de funções
		break; 
		
		case 2:
		consulta(); //chamada de funções
		break; 
		
		case 3:
		deletar(); //chamada de funções
		break; 
		
		default:
		printf ("Essa opção não está disponível.\n");
		system ("pause");
		break;
	 } //Fim da seleção
    }
	
}
