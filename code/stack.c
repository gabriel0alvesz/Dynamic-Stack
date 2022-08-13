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

void Stack_Push(Stack *s, int val){

    StNode *new = Stack_CreateNode(val);

    //A Pilha esta vazia?
    if(s->top == s->base || s->size == 0){

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

    puts("\tBase");
}

