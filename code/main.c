#include "stack.h"

int main(){

    Stack s;

    Stack_CreateStack(&s);

    Stack_Push(&s,1);
    Stack_Push(&s,2);
    Stack_Push(&s,3);
    Stack_Push(&s,4);
    Stack_Push(&s,5);
    Stack_Push(&s,6);
    Stack_Push(&s,7);

    Stack_PrintStack(&s);

    Stack_Pop(&s);

    Stack_PrintStack(&s);

    Stack_DestroyStack(&s);
    
    return 0;
}