#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
struct resources{
    int water = 100;
    int milk = 200;
    int coffee = 50;
}rs;


struct chai{
    int coffee=5;
    int milk=100;
    int water=10;
    int cost=5;
}ch;


struct cappaccino{
    int coffee=7;
    int milk=150;
    int water=15;
    int cost=15;
}ca;


struct latte{
    int coffee=8;
    int milk=125;
    int water=20;
    int cost=11;
}lt;


struct espresso{
    int coffee=7;
    int milk=0;
    int water=10;
    int cost=12;
}es;



int collect_money(int purchased_itm, int cost5, int cost2, int cost1, int half){
    int total_cost = cost5*5 + cost2*2 + cost1*1 + half*0.5 ;
    switch(purchased_itm)
    {
        case 1:
            if( total_cost >= ch.cost )
            {
                if ( rs.water >= 0 && rs.coffee>=0 && rs.milk>=0 )
                {
                    printf("\nTake your Chai...");
                    total_cost-=ch.cost;
                    break;
                }
                  
                else
                    printf("Not Enough Resources...");
                    
            }
            else
                printf("Not Enough Money...");
            break;
        case 2:
            if( total_cost >= lt.cost )
            {
                if ( rs.water >= 0 && rs.coffee>=0 && rs.milk>=0 )
                {
                    printf("\nTake your Latte...");
                    total_cost-=lt.cost;
                    break;
                }
                else
                    printf("Not Enough Resources...");
            }
            else
                printf("Not Enough Money...");
            break;
        case 3:
            if( total_cost >= ca.cost )
            {
                if ( rs.water >= 0 && rs.coffee>=0 && rs.milk>=0 )
                {
                    printf("\nTake your Cappaccino...");
                    total_cost-=ca.cost;
                    break;
                }
                else
                    printf("Not Enough Resources...");
            }
            else
                printf("Not Enough Money...");
            break;
        case 4:
            if( total_cost >= es.cost)
            {
                if ( rs.water >= 0 && rs.coffee>=0 && rs.milk>=0 )
                {
                    printf("\nTake your espresso...");
                    total_cost-=es.cost;
                    break;
                }
                else
                    printf("Not Enough Resources...");
            }
            else
                printf("Not Enough Money...");
            break;
    }
    return total_cost;

}

int update_resource(int purchased_itm){
    switch(purchased_itm){
        case 1:
            if(rs.water >= 0 && rs.coffee>=0 && rs.milk>=0)
            {
                rs.water -= ch.water ;
                rs.coffee -= ch.coffee;
                rs.milk -= ch.milk;
            }
            break;

        case 2:
            if(rs.water >= 0 && rs.coffee>=0 && rs.milk>=0)
            {
                rs.water -= lt.water ;
                rs.coffee -= lt.coffee;
                rs.milk -= lt.milk;
            }
            break;
        case 3:
            if(rs.water >= 0 && rs.coffee>=0 && rs.milk>=0)
            {
                rs.water -= ca.water ;
                rs.coffee -= ca.coffee;
                rs.milk -= ca.milk;
            }
            break;
        case 4:
            if(rs.water >= 0 && rs.coffee>=0 && rs.milk>=0)
            {
                rs.water -= es.water ;
                rs.coffee -= es.coffee;
                rs.milk -= es.milk;
            } 
            
    }
    

}


int main(){


    int choice, coin5, coin2, coin1, half, total;
    int remain;
    
    printf("Welcome to Virtual Coffee Machine....\n\n");
    while(1){
        printf("\nWhat you want to drink? (Chai(1), Latte(2), Cappaccino(3), Espresso(4): ");
        scanf("%d", &choice);
        printf("Enter ₹5 coin: ");
        scanf("%d",&coin5);
        printf("Enter ₹2 coin: ");
        scanf("%d",&coin2);
        printf("Enter ₹1 coin: ");
        scanf("%d",&coin1);
        printf("Enter ₹0.5 coin: ");
        scanf("%d",&half);
        total= coin5*5 + coin2*2 + coin1*1 + half*0.5 ;
        printf("Total Money: %d", total);

        switch(choice){
            case 1:
                update_resource(1);
                remain=collect_money(choice, coin5, coin2, coin1, half);
                printf("\nTake your balance: ");
                printf("%d", remain);
                break;
            case 2:
                update_resource(2);
                remain=collect_money(choice, coin5, coin2, coin1, half);
                printf("\nTake your balance: ");
                printf("%d", remain);
                break;
            case 3:
                update_resource(3);
                remain=collect_money(choice, coin5, coin2, coin1, half);
                printf("\nTake your balance: ");
                printf("%d", remain);
                break;
            case 4:
                update_resource(4);
                remain=collect_money(choice, coin5, coin2, coin1, half);
                printf("\nTake your balance: ");
                printf("%d", remain);
                break;
            case 5:
                break;
            case 6:
                printf("Turning off..");
                exit(0);
        }
        
    }
    
}