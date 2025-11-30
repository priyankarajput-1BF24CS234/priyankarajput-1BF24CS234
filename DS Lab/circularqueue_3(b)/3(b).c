#include<stdio.h>
#define MAX 3
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int e){
    if (rear==MAX-1){
        printf("queue overflow");
    }
    else if (front==-1 && rear==-1){
            front=0;
            rear=0;
            queue[rear]=e;
    }
    else{
        rear++;
        queue[rear]=e;
        printf("element %d inserted in queue.",e);
    }

}
void dequeue(){
    if (front==-1 && rear==-1){
        printf("queue underflow!");
    }
    else if (front==rear){
        printf("element %d deleted from queue.",queue[front]);
        front=rear=-1;
    }
    else{
        printf("element %d deleted from queue.",queue[front]);
        front++;
    }
}
void display(){
    if (front==-1 && rear==-1){
        printf("queue is empty");
    }
    else{
            printf("queue elements are:");
        for (int i=front;i<rear+1;i++){
            printf("%d ",queue[i]);
        }
    }

}

int main(){
    int ch;
    int ele;
    printf("\n queue menu: \n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit");
    while (1){
    printf("\n enter choice:");
    scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter element to be inserted:");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting program");
                return 0;
            default:
                printf("invalid choice! try again.");


        }

    }
    return 0;
}


#include <stdio.h>
#define MAX 5
int front=-1;
int rear =-1;
int queue[MAX];

void enqueue(int e){
    if (front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=e;
        printf("element inserted:%d",e);
    }
    else if ((rear+1)% MAX == front){
        printf("queue is full");
    }
    else{
        rear=(rear+1)%MAX;
        queue[rear]=e;
    }

}

void dequeue(){
    if (front==-1 && rear==-1){
        printf("queue underflow!");
    }
    else if (front==rear){
        printf("deleted element:%d",queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("deleted element:%d",queue[front]);
        front=(front+1)%MAX;
    }

}
void display(){
    int i=front;
    if (front==-1 && rear==-1){
        printf("queue is empty");
    }
    else{
            printf("queue elements are:\n");
            while(i!=rear){
                printf("%d ",queue[i]);
                i=(i+1)%MAX;
            }
            printf("%d", queue[i]);
        }
}

int main(){
    int ch;
    int ele;
    printf("\n queue menu: \n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit");
    while (1){
    printf("\n enter choice:");
    scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter element to be inserted:");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting program");
                return 0;
            default:
                printf("invalid choice! try again.");


        }

    }
return 0;
}
