

#define VARIAVEL        (1)
#define FUNCAO          (2)
#define PROCEDIMENTO    (3)
#define LABELGOTO       (4)
#define VALOR           (5)
#define REFERENCIA      (6)

#define MAX_STR_NOME    (30)
#define MAX_N_PARAMS    (32)

// Estrutura de pilha para os rotulos
typedef struct no_r { 
    int rotulo;
    struct no_r *prox;
} noRotulo;

// Estrutura de pilha para a tabela de simbolos

typedef struct no_param {
    char nome[MAX_STR_NOME][MAX_N_PARAMS];
    int desloc[MAX_N_PARAMS];
    int tipoPass[MAX_N_PARAMS];
} noParam;

typedef struct no_ts {
    char nome[MAX_STR_NOME];
    int n_lexico;
    int desloc;
    int tipo;
    int rotulo;
    int n_param;
    struct no_param *parametros;
    struct no_ts *prox; 
} noTS;

int empilhaRotulo(int , noRotulo **topo);
int desempilhaRotulo(noRotulo ** topo);

