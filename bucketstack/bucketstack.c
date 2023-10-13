#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "bucketstack.h"

void initStack(int bucketSize, Stack **stack) {
    *stack = malloc(sizeof(Stack));
    (*stack)->firstBucket = NULL;
    (*stack)->topElt = -1;
    (*stack)->bucketSize = bucketSize;
}

bool isEmpty(const Stack *stack) {
    return (stack->firstBucket == NULL);
}

void push(char* val, Stack* stack) {
    char* str = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(str, val);

    if (stack->firstBucket == NULL || stack->topElt == stack->bucketSize - 1) {
        struct NodeBucket* new = malloc(sizeof(struct NodeBucket));
        if (new == NULL) {
            free(str);
            return;
        }
        new->next = stack->firstBucket;
        stack->firstBucket = new;
        stack->topElt = 0;
        new->val = malloc(sizeof(char*) * stack->bucketSize);
        if (new->val == NULL) {
            free(new);
            free(str);
            return;
        }
        new->val[0] = str;
    } 
    
    else {
        stack->topElt++;
        stack->firstBucket->val[stack->topElt] = str;
    }
}


void pop(Stack* stack) {
    assert(stack->firstBucket != NULL && stack->topElt >= 0); 

    free(stack->firstBucket->val[stack->topElt]);
    stack->firstBucket->val[stack->topElt] = NULL;
    stack->topElt--;

    if (stack->topElt < 0) {
        struct NodeBucket* old = stack->firstBucket;
        stack->firstBucket = old->next;

        if (old != NULL) {
            if (old->val != NULL) {
                for (int i = 0; i < stack->bucketSize; i++) {
                    if (old->val[i] != NULL) {
                        free(old->val[i]);
                        old->val[i] = NULL;
                    }
                }
                free(old->val);
                old->val = NULL;
            }
            free(old);
            old = NULL;
        }

        stack->topElt = (stack->firstBucket != NULL) ? (stack->bucketSize - 1) : -1;
    }
}



int size(const Stack* stack) {
    int count = 0;
    struct NodeBucket* bucket = stack->firstBucket;

    while (bucket != NULL) {
        count += (bucket == stack->firstBucket) ? (stack->topElt + 1) : stack->bucketSize;
        bucket = bucket->next;
    }

    return count;
}

char* top(const Stack* stack) {
    assert(!isEmpty(stack));
    char* tops = stack->firstBucket->val[stack->topElt];

    return tops;
}

void swap(Stack* stack) {
    assert(stack != NULL && stack->firstBucket != NULL && stack->topElt > 0);

    char** tops = &(stack->firstBucket->val[stack->topElt]);
    char** secondElement = &(stack->firstBucket->val[stack->topElt - 1]);

    char* temp = *tops;
    *tops = *secondElement;
    *secondElement = temp;
}


void print(const Stack *stack) {
    printf("stack is:\n");
    const struct NodeBucket *bucket = stack->firstBucket;
    int top = stack->topElt;
    while (bucket) {
        for (int i = top; i >= 0; i--) {
            if (bucket->val[i] != NULL) {
                printf("\t%s\n", bucket->val[i]);
            }
        }
        bucket = bucket->next;
        top = stack->bucketSize - 1;
    }
}


void clear(Stack *stack) {
    struct NodeBucket *current = stack->firstBucket;
    while (current != NULL) {
        struct NodeBucket *next = current->next;

        for (int i = 0; i < stack->bucketSize; i++) {
            if (current->val[i] != NULL) {
                free(current->val[i]);
                current->val[i] = NULL;
            }
        }
        if (current->val != NULL) {
            free(current->val);
            current->val = NULL;
        }
        free(current);
        current = next;
    }

    stack->firstBucket = NULL;
    stack->topElt = -1;
}


void destroyStack(Stack **stack) {
    if (*stack == NULL) {
        return;
    }
    clear(*stack);
    free(*stack);
    *stack = NULL;
}

