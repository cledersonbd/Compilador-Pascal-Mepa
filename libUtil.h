

#define VARIAVEL        (1)
#define FUNCAO          (2)
#define PROCEDIMENTO    (3)
#define LABELGOTO       (4)
#define VALOR           (5)
#define REFERENCIA      (6)

// Estrutura de pilha para os rotulos
typedef struct no_r { 
    int rotulo;
    struct no_r *prox;
} noRotulo;

// Estrutura de pilha para a tabela de simbolos

typedef struct no_ts {
    char nome[30];
    int n_lexico;
    int desloc;
    int tipo;
    int rotulo;
    int n_param;
    struct no_ts *prox; 
} noTS;

int empilhaRotulo(int , noRotulo **topo);
int desempilhaRotulo(noRotulo ** topo);

