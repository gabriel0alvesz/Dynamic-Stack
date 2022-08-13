#include "stack.h"

void Stack_CreateStack(Stack *s){
    
    s->base = (StNode*)malloc(sizeof(StNode));
    s->base->prox = NULL;
    s->top = s->base;
    s->size = 0;
    //Pilha vazia criada!
}

StNode *Stack_CreateNode(int val){

    StNode *new = (StNode*)malloc(sizeof(StNode));
    new->ant = NULL;
    new->prox = NULL;
    new->val = val;
    //Nó criado!
    return new;
}

bool Stack_isEmpty(Stack *s){

    return s->top == s->base || s->size == 0;
}

void Stack_Push(Stack *s, int val){

    StNode *new = Stack_CreateNode(val);

    //A Pilha esta vazia?
    if(Stack_isEmpty(s)){

        s->base->prox = new;
        s->top = new;
        s->top->prox = NULL;
    
    }else{  

        new->ant = s->top; // o antigo ultimo elemento passa a ser o elemento anterior do novo nó
        s->top->prox = new; // O penultimo elemento agora tera seu ponteiro prox apontando para o ultimo nó
        s->top = new; // o ponteiro de ultimo agora aponta para o novo nó inserido
        s->top->prox = NULL;

    }

    s->size++;
}

void Stack_Pop(Stack *s){

    StNode *aux = s->top;

    if(!Stack_isEmpty(s)){

        s->top = s->top->ant;
        free(aux);
        s->top->prox = NULL;

    }else{

        puts("---> Pilha vazia!");
    }

}

void Stack_PrintStack(Stack *s){

    StNode *aux = s->top;

    while(aux != NULL){

        if(aux == s->top){
            printf("\t %d (Top)\n",aux->val);
        }else{
            printf("\t %d\n",aux->val);
        }
        
        aux = aux->ant;
    
    }

    puts("\tBase\n");
}

int Stack_LastNodeInStack(Stack *s){

    return s->top->val;
}

void Stack_DestroyStack(Stack *s){

    //Verifica se ao menos a Pilha foi criada.
    if(!(s->base == NULL)){

        StNode *p = s->base;
        StNode *aux = NULL;

        while(p != NULL){
            
            aux = p;
            p = p->prox;
            free(aux);
        
        }

        free(p);
        s = NULL;
        
        puts("\n---> Pilha Desalocada!\n");

    }else{

        puts("---> Pilha não existe!\n");
    
    }
}



