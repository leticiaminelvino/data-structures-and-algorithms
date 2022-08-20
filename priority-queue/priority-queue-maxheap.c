#include <stdio.h>
#include <stdlib.h>
#define PAI(i) ((i-1)/2)
#define FILHO_ESQ(i) (2*i+1)
#define FILHO_DIR(i) (2*i+2)

typedef struct {
    /*char nome[30];*/
    int nome; /*mudar de volta para char qnd descobrir pq o scanf nao ta funcionando*/
    int chave;
} Paciente;

typedef struct {
    Paciente *vetor;
    int qtd_de_elem, tamanho;
} FilaPrioridade;

typedef FilaPrioridade *FilaPrioridade_ptr;

FilaPrioridade_ptr inicializa_fila_de_prioridade(int tam);
void insere(FilaPrioridade_ptr fila, Paciente paciente);
void heapify_up(FilaPrioridade_ptr fila, int position);
void swap(Paciente *xp, Paciente *yp);
Paciente remove_maximo(FilaPrioridade_ptr fila);
void heapify_down(FilaPrioridade_ptr fila, int position);
void muda_prioridade(FilaPrioridade_ptr fila, int position, int nova_chave);
void destroi_fila(FilaPrioridade_ptr fila);


void swap(Paciente *xp, Paciente *yp){
  Paciente aux = *xp;
  *xp = *yp;
  *yp = aux;
}

FilaPrioridade_ptr inicializa_fila_de_prioridade(int tam){
    FilaPrioridade_ptr fila = malloc(sizeof(FilaPrioridade));
    fila->vetor = malloc(tam * sizeof(Paciente));
    fila->qtd_de_elem = 0;
    fila->tamanho = tam;
    return fila;
}

void insere(FilaPrioridade_ptr fila, Paciente paciente){
    fila->vetor[fila->qtd_de_elem] = paciente;
    fila->qtd_de_elem++;
    heapify_up(fila, fila->qtd_de_elem-1);
}

void heapify_up(FilaPrioridade_ptr fila, int position){
    if(position > 0 && fila->vetor[PAI(position)].chave < fila->vetor[position].chave){
        swap(&fila->vetor[position], &fila->vetor[PAI(position)]);
        heapify_up(fila, PAI(position));
    }
}

Paciente remove_maximo(FilaPrioridade_ptr fila){
    Paciente paciente = fila->vetor[0];
    swap(&fila->vetor[0], &fila->vetor[fila->qtd_de_elem - 1]);
    fila->qtd_de_elem--;
    heapify_down(fila, 0);
    return paciente;
}

void heapify_down(FilaPrioridade_ptr fila, int position){
    int maior_filho;
    if (FILHO_ESQ(position) < fila->qtd_de_elem){ 
        maior_filho = FILHO_ESQ(position);
        if(FILHO_DIR(position)< fila->qtd_de_elem && fila->vetor[FILHO_ESQ(position)].chave < fila->vetor[FILHO_DIR(position)].chave)
            maior_filho = FILHO_DIR(position);
        if(fila->vetor[position].chave < fila->vetor[maior_filho].chave){
            swap(&fila->vetor[position], &fila->vetor[maior_filho]);
            heapify_down(fila, maior_filho);
        }
    }
}

void muda_prioridade(FilaPrioridade_ptr fila, int position, int nova_chave){
    if(fila->vetor[position].chave < nova_chave){
        fila->vetor[position].chave = nova_chave;
        heapify_up(fila, position);
    }
    else {
        fila->vetor[position].chave = nova_chave;
        heapify_down(fila, position);
    }
}

void imprime_fila(FilaPrioridade_ptr fila){  /*mudar o %d de volta para %s quando o o nome da struct paciente voltar a ser tipo char*/
    int i;
    for(i = 0; i < (fila->qtd_de_elem); i++){
        switch ( fila->vetor[i].chave ){
            case 1 :
            printf("Paciente: %d (Sem urgência)\n", fila->vetor[i].nome);
            break;
            
            case 2 :
            printf("Paciente: %d (Pouca urgência)\n", fila->vetor[i].nome);
            break;
            
            case 3 :
            printf("Paciente: %d (Média Urgência)\n", fila->vetor[i].nome);
            break;
            
            case 4 :
            printf("Paciente: %d (Alta Urgência)\n", fila->vetor[i].nome);
            break;

            case 5 :
            printf("Paciente: %d (Extrema Urgência)\n", fila->vetor[i].nome);
            break;

            default :
            printf ("Valor invalido!\n");
        }
    }
}

void destroi_fila(FilaPrioridade_ptr fila){
    free(fila);
}


int main(){
    Paciente paciente1, paciente2, paciente3, paciente4, paciente5, paciente6, paciente7;
    FilaPrioridade_ptr fila;

    fila = inicializa_fila_de_prioridade(100);

    /* testar o codigo*/
    paciente1.nome =  1;
    paciente1.chave =  1;
    insere(fila, paciente1);
    imprime_fila(fila);
    printf("\n\n");
    paciente2.nome =  2;
    paciente2.chave =  2;
    insere(fila, paciente2);
    imprime_fila(fila);
    printf("\n\n");
    paciente3.nome =  3;
    paciente3.chave =  4;
    insere(fila, paciente3);
    imprime_fila(fila);
    printf("\n\n");
    paciente4.nome =  4;
    paciente4.chave =  5;
    insere(fila, paciente4);
    imprime_fila(fila);
    printf("\n\n");
    paciente5.nome =  5;
    paciente5.chave =  3;
    insere(fila, paciente5);
    imprime_fila(fila);
    printf("\n\n");
    paciente6.nome =  6;
    paciente6.chave =  5;
    insere(fila, paciente6);
    imprime_fila(fila);
    printf("\n\n");
    paciente7.nome =  7;
    paciente7.chave =  4;
    insere(fila, paciente7);
    imprime_fila(fila);
    printf("\n\n");
    printf("//////////////\n");
    remove_maximo(fila);
    imprime_fila(fila);
    printf("\n\n");
    remove_maximo(fila);
    imprime_fila(fila);
    printf("\n\n");
    remove_maximo(fila);
    imprime_fila(fila);
    printf("\n\n");
    remove_maximo(fila);
    imprime_fila(fila);
    printf("\n\n");
    remove_maximo(fila);
    imprime_fila(fila);
    printf("\n\n");
    remove_maximo(fila);
    imprime_fila(fila);
    printf("\n\n");
    


    destroi_fila(fila);

    return 0;
}