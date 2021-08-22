#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define SIZE 100 //constante SIZE com valor de 3
#define MAXIMO 50
#define MAXS 11

typedef struct {
    int cod;
    int vazio;
    char nome_paciente[MAXIMO];
    int cpf_paciente[MAXS];
    int numero_carteirinha[MAXS];
    char nome_medico[MAXIMO];
    char especialidade_medico[MAXIMO];
    char data_consulta[MAXS];
    char data_revisao[MAXS];
    int codigo_medicamento[MAXS];
    int codigo_fornecedor[MAXS];
    float valor_medicamento[MAXS];
} Cadastro;

int opcao = 0, opt;

int main() //inicio do int main
{
    Cadastro cadastro[SIZE];
    setlocale(LC_ALL,"Portuguese");
    system("color 09");

    int posicao,retorno;
    int codin;

    do //do com while para realizar o codigo enquanto estiver dentro dos parametros
    {
        if(opcao==0) //if para a exibicao do menu
        {
            printf("\n\n=======================================================\n");

            printf("\n1 - cadastro");
            printf("\n2 - pesquisa");
            printf("\n3 - listar");
            printf("\n4 - excluir");
            printf("\n5 - limpar tela");
            printf("\n6 - sair\n"); //menu com as opcoes

            printf("\n\n=======================================================\n");

            printf("\nEscolha sua opcao:\n");
            fflush(stdin); //limpando buffer
            scanf("%d", &opcao); //pegando a escolha do usuario

            printf("\n\n=======================================================\n");
        }

        if(opcao==1) //if para entrar na area de cadastro
        {
            novoCadastro(cadastro[SIZE]);
            opcao = 0;
        }

        if(opcao==2)
        {
            pesquisar(cadastro[SIZE]);
            opcao = 0;
        }

        if(opcao==3)
        {
            listarDados(cadastro[SIZE]);
            opcao = 0;
        }

        if(opcao==4)
        {
            excluir(cadastro[SIZE]);
            opcao = 0;
        }

        if(opcao==5)
        {
            system("cls");
        }

        if(opcao==6)
        {
            return 0;
        }

        if(opcao<0 && opcao>6)
        {
            printf("\nOpcao inexistente\n");
            opcao=0;
        }
    }while(opcao>=0 && opcao<6);
}
//Fim do main
//Começo das funções

void listarDados(Cadastro cadastro[SIZE])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(cadastro[i].nome_paciente != NULL)
        {
            printf("\n\nNome do paciente:", cadastro[i].nome_paciente);
            printf("\nCPF do paciente:", cadastro[i].cpf_paciente);
            printf("\nNumero da carteirinha:", cadastro[i].numero_carteirinha);
            printf("\nNome do medico: ", cadastro[i].nome_medico);
            printf("\nEspecialidade do medico: ", cadastro[i].especialidade_medico);
            printf("\nData da consulta: ", cadastro[i].data_consulta);
            printf("\nData da revisao: ", cadastro[i].data_revisao);
            printf("\nCodigo do medicamento: ", cadastro[i].codigo_medicamento);
            printf("\nCodigo do fornecedor: ", cadastro[i].codigo_fornecedor);
            printf("\nValor do medicamento: ", cadastro[i].valor_medicamento);
        }
    }
}

void novoCadastro(Cadastro cadastro[SIZE])
{
    int i,sair, codigoNovo = 0;
    for(i = 0;i < SIZE;i++)
    {
        printf("\n\nNome do paciente:");
        fflush(stdin);
        scanf("%s", &cadastro[i].nome_paciente);

        printf("\nCPF do paciente:");
        fflush(stdin);
        scanf("%d", &cadastro[i].cpf_paciente);

        printf("\nNumero da carteirinha:");
        fflush(stdin);
        scanf("%d", &cadastro[i].numero_carteirinha);

        printf("\nNome do medico: ");
        fflush(stdin);
        scanf("%s", &cadastro[i].nome_medico);

        printf("\nEspecialidade do medico: ");
        fflush(stdin);
        scanf("%s", &cadastro[i].especialidade_medico);

        printf("\nData da consulta: ");
        fflush(stdin);
        scanf("%s", &cadastro[i].data_consulta);

        printf("\nData da revisao: ");
        fflush(stdin);
        scanf("%s", &cadastro[i].data_revisao);

        printf("\nCodigo do medicamento: ");
        fflush(stdin);
        scanf("%d", &cadastro[i].codigo_medicamento);

        printf("\nCodigo do fornecedor: ");
        fflush(stdin);
        scanf("%d", &cadastro[i].codigo_fornecedor);

        printf("\nValor do medicamento: ");
        fflush(stdin);
        scanf("%f", &cadastro[i].valor_medicamento);

        printf("\n\n=======================================================\n");

        printf("\nQuer cadastrar mais um dado?");
        printf("\nDigite 1 para continuar e 0 para sair\n");
        fflush(stdin);
        scanf("%d", &sair);

        printf("\n\n=======================================================\n");

        cadastro[i].cod = codigoNovo;
        codigoNovo++;

        cadastro[i].vazio = 1;

        if(sair == 0)
        {
            break;
        }
    }
}

void pesquisar(Cadastro cadastro[SIZE])
{
    int codigoPesquisado, i;
    printf("\nEntre com o código\n");
    fflush(stdin);
    scanf("%d",&codigoPesquisado);

    for(i = 0;i < SIZE;i++)
    {
        if (cadastro[i].cod == codigoPesquisado)
        {
            if (cadastro[i].vazio == 1)
            {
                printf("\n\nNome do paciente:", cadastro[i].nome_paciente);
                printf("\nCPF do paciente:", cadastro[i].cpf_paciente);
                printf("\nNumero da carteirinha:", cadastro[i].numero_carteirinha);
                printf("\nNome do medico: ", cadastro[i].nome_medico);
                printf("\nEspecialidade do medico: ", cadastro[i].especialidade_medico);
                printf("\nData da consulta: ", cadastro[i].data_consulta);
                printf("\nData da revisao: ", cadastro[i].data_revisao);
                printf("\nCodigo do medicamento: ", cadastro[i].codigo_medicamento);
                printf("\nCodigo do fornecedor: ", cadastro[i].codigo_fornecedor);
                printf("\nValor do medicamento: ", cadastro[i].valor_medicamento);
            }
            break;
        }
    }
}

void excluir(Cadastro cadastro[SIZE])
{
    int codigoExcluir, i;
    char resposta;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    fflush(stdin);
    scanf("%d", &codigoExcluir );

    for(i = 0;i < SIZE;i++)
    {
        if (cadastro[i].cod == codigoExcluir )
        {
            if (cadastro[i].vazio == 1)
            {
                printf("\n\nNome do paciente:", cadastro[i].nome_paciente);
                printf("\nCPF do paciente:", cadastro[i].cpf_paciente);
                printf("\nNumero da carteirinha:", cadastro[i].numero_carteirinha);
                printf("\nNome do medico: ", cadastro[i].nome_medico);
                printf("\nEspecialidade do medico: ", cadastro[i].especialidade_medico);
                printf("\nData da consulta: ", cadastro[i].data_consulta);
                printf("\nData da revisao: ", cadastro[i].data_revisao);
                printf("\nCodigo do medicamento: ", cadastro[i].codigo_medicamento);
                printf("\nCodigo do fornecedor: ", cadastro[i].codigo_fornecedor);
                printf("\nValor do medicamento: ", cadastro[i].valor_medicamento);

                printf("\n\n=======================================================\n");
                printf("\nDeseja realmente excluir? s/n: ");
                fflush(stdin);
                printf("\n\n=======================================================\n");

                scanf("%s",&resposta);
                if ( ( resposta == 'S' ) || ( resposta == 's' ) )
                {
                    cadastro[i].vazio=0;
                    cadastro[i].cod = NULL;

                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resposta == 'N' ) || ( resposta == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }
            }
        }
    }
}
