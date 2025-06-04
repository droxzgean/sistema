#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uma variável constante, com o número máximo de clientes que podem ser armazenado no array
#define MAX_CLIENTES 50

// Estrutura para armazenar os dados do cliente
typedef struct
{
    int codigo;
    char nome[100];
    char email[100];
    int idade;
} Cliente;

// Array global para armazenar os clientes e contador
Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

// Protótipos das funções
void exibirMenu();
void adicionarCliente();
void listarClientes();
void buscarCliente();

int main()
{
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao)
        {
        case 1:
            adicionarCliente();
            break;
        case 2:
            listarClientes();
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        printf("\nPressione Enter para voltar ao Menu Principal...");
        getchar();

    } while (opcao != 4);

    return 0;
}

void exibirMenu()
{
    system("clear || cls"); // Limpa a tela no Linux/Mac (clear) ou Windows (cls)
    printf("==================================\n");
    printf("      SISTEMA DE CADASTRO\n");
    printf("==================================\n");
    printf("1 - Adicionar Cliente\n");
    printf("2 - Listar Clientes\n");
    printf("0 - Sair\n");
    printf("==================================\n");
    printf("Escolha uma opcao: ");
}

void adicionarCliente()
{
    // Implementar a lógica de adição aqui...
    Cliente novoCliente;
     printf("Digite o nome do cliente: ");
    if (fgets(novoCliente.nome, MAX_CLIENTES, stdin) == NULL) {
        printf("Erro na leitura do nome.\n");
        return;
    }

    printf("Digite o email do cliente: ");
    if (fgets(novoCliente.email, MAX_CLIENTES, stdin) == NULL) {
        printf("Erro na leitura do email.\n");
        return;
    }
    

    printf("Digite a idade do cliente: ");
    if (scanf("%d", &novoCliente.idade) != 1) {
        printf("Entrada invalida para a idade.\n");
        while (getchar() != '\n'); 
        return;
    }
    while (getchar() != '\n'); 

    clientes[totalClientes] = novoCliente; // Armazena na próxima posição livre
    totalClientes++;                       // Incrementa o total de clientes

    printf("\n===============================");
    printf("\nCLIENTE CADASTRADO COM SUCESSO!");
    printf("\n===============================\n");
}

void listarClientes()
{
    // Implementar a lógica de listagem aqui...
    printf("\nLISTA DE CADASTRO");
    if (totalClientes == 0) 
    {
        printf ("\nNenhum Cliente Cadastrado!\n");
        return;
    }
    
    for (int i = 0; i < totalClientes; i++) {
        printf("\n----------------------------\n");
        printf("Nome: %s\n", clientes[i].nome);
        printf("Email: %s\n", clientes[i].email);
        printf("Idade: %d", clientes[i].idade);
        printf("\n----------------------------");
    }
}

void buscarCliente()
{
    // Implementar a lógica de busca aqui...
    // função não necessária
}