#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coEfficient;
    int exponent;
    node *prev;
    node *next;
}node;




void Input(int polyCount){
    int polyTerms;
    int nodeCount = 1;
    printf("\nPlease enter the the polynomial, following guidlines\n"
    "1. Polynomial equation should be in decreasing order of power of X.\n"
    "2. The coefficient of X should be entered with signs(+/-).\n");
    printf("How many terms are there in Polynomial %d.", polyCount);
    scanf("%d", &polyTerms);
    while(polyTerms--){
        node *nodeCount;
        printf("Enter all the terms of Polynomial %d.\n", polyCount);
        printf("Enter term %d.\n");
        printf("Enter the coefficient of X: ");
        scanf("%d", &nodeCount->coEfficient);
        printf("Enter the exponent of X: ");
        scanf("%d", &nodeCount->exponent);
        nodeCount++;
    }
    polyCount++;
}



void PolyAddition(node *){

}

int main(){
    node *p;
    int numOfeqn;
    int polyCount = 1;
    printf("\t\nWelcome to the Polynomial Addition, implemented with DOUBLY LINKED LIST\n\n\n");
    printf("How many Equations to add: ");
    scanf("%d", &numOfeqn);
    while(numOfeqn--){
        Input(polyCount);
        polyCount++;
    }
}
