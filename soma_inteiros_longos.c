#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    struct node *next;
    long int info;
};

typedef struct node *NODEPTR;

NODEPTR getnode()
{
    NODEPTR new_node = malloc(sizeof(struct node));
    if (!new_node)
        return NULL;

    new_node->next = NULL;
    return new_node;
}

NODEPTR firstin()
{
    NODEPTR v = getnode();
    v->info = -1;
    v->next = v;
    return v;
}

void insafter(NODEPTR s, long int info)
{
    if (s)
    {
        NODEPTR new_node = getnode();
        new_node->next = s->next;
        s->next = new_node;
        new_node->info = info;
    }
}

NODEPTR addint(NODEPTR p, NODEPTR q)
{
    long int hunthou = 100000L;
    long int carry, number, total;
    NODEPTR s;

    p = p->next;
    q = q->next;

    s = getnode();
    s->info = -1;
    s->next = s;

    carry = 0;

    while (p->info != -1 && q->info != -1)
    {
        total = p->info + q->info + carry;
        number = total % hunthou;
        insafter(s, number);
        p = p->next;
        q = q->next;
        carry = total / hunthou;
    }

    while (p->info != -1)
    {
        total = p->info + carry;
        number = total % hunthou;
        insafter(s, number);
        carry = total / hunthou;
        p = p->next;
    }

    while (q->info != -1)
    {
        total = q->info + carry;
        number = total % hunthou;
        insafter(s, number);
        carry = total / hunthou;
        q = q->next;
    }

    if (carry == 1)
    {
        insafter(s, carry);
    }

    return s;
}

char *input()
{
    static char n1[251];
    printf("INSIRA O VALOR INTEIRO: ");
    scanf("%250s", n1);
    return n1;
}

NODEPTR convert()
{
    NODEPTR nu = firstin();
    NODEPTR tail = nu;
    char *n1 = input();
    char block[6];

    int len = strlen(n1);
    int index = 0;
    long int blockint;

    for (int i = len - 1; i >= 0; i--)
    {
        block[index] = n1[i];
        index++;

        if (index == 5)
        {
            block[5] = '\0';
            char temp;
                for (int j = 0; j < 2; j++)
                {
                    temp = block[j];
                    block[j] = block[4 - j];
                    block[4 - j] = temp;
                }
            blockint = atoi(block);
            insafter(tail, blockint); 
            tail = tail->next;        
            index = 0;
        }
    }

    if (index > 0)
    {
        block[index] = '\0';
        char temp;
        for (int j = 0; j < index / 2; j++)
        {
            temp = block[j];
            block[j] = block[index - 1 - j];
            block[index - 1 - j] = temp;
        }
        blockint = atoi(block);
        insafter(tail, blockint);
    }

    return nu;
}

void imprimir_resultado(NODEPTR lista)
{
    NODEPTR atual = lista->next;
    printf("\nRESULTADO DA SOMA: ");

    if (atual->info == -1)
    {
        printf("0\n");
        return;
    }

    bool primeiro_bloco = true;
    while (atual->info != -1)
    {
        if (primeiro_bloco)
        {
            printf("%ld", atual->info);
            primeiro_bloco = false;
        }
        else
        {
            printf("%05ld", atual->info);
        }
        atual = atual->next;
    }
    printf("\n");
}

void liberar_lista(NODEPTR lista)
{
    NODEPTR atual = lista->next;
    NODEPTR proximo;

    while (atual->info != -1)
    {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    free(atual);
}

int main()
{
    int opcao = 1;

    while (opcao == 1)
    {
        printf("\n=======================================================\n");
        printf("            SOMA DE INTEIROS LONGOS POSITIVOS          \n");
        printf("=======================================================\n");

        printf("\n--- PRIMEIRO NUMERO ---\n");
        NODEPTR num1 = convert();

        printf("\n--- SEGUNDO NUMERO ---\n");
        NODEPTR num2 = convert();

        NODEPTR resultado = addint(num1, num2);

        imprimir_resultado(resultado);

        liberar_lista(num1);
        liberar_lista(num2);
        liberar_lista(resultado);

        printf("\n-------------------------------------------------------\n");
        printf("Deseja realizar outra soma?\n");
        printf("[1] Sim\n");
        printf("[0] Nao, encerrar programa\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1)
        {
            opcao = 0;
        }
    }

    printf("\nPrograma encerrado com sucesso.\n");
    return 0;
}
