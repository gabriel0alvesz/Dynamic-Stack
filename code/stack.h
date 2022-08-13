#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode{

    int val;
    struct StackNode *prox, *Ant;

}StNode;

typedef struct TypeStack{

    size_t size;
    StNode *base, *top;

}Stack;


/**
 * @brief Cria a Pilha.
 * 
 * @param s Endereço da Pilha(&s)
 */
void Stack_CreateStack(Stack *s);

/**
 * @brief Cria um nó.
 * 
 * @param val Valor
 * @return Retorna o endereço do nó criado.
 */
StNode *Sstack_CreateNode(int val);


/**
 * @brief Empilha.
 * 
 * @param s Endereço da Pilha(&s)
 * @param val Valor.
 */
void Stack_Push(Stack *s, int val);

/**
 * @brief Desempilha.
 * 
 * @param s Endereço da Pilha(&s).
 */
void Stack_Pop(Stack *s);

/**
 * @brief Imprime a Pilha
 * 
 * @param s Endereço da Pilha(&s).
 */
void Stack_PrintStack(Stack *s);

/**
 * @brief Imprime o elemento no topo da pilha.
 * 
 * @param s Endereço da Pilha(&s).
 */
void Stack_LastNodeInStack(Stack *s);


#endif