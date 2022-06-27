#include <stdio.h>
#include <stdlib.h>
#define rep(y,x) for(int i=y;i<x;i++)

int c_size=0;

typedef struct Node ll;
struct Node{
    int data;
    struct Node *next;
};

ll*head=NULL;


//Creating initial LinkedList

void createNode(){
    ll *temp,*ptr;

    temp = (ll *)malloc(sizeof(ll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{   ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
        ptr->next=temp;
    }
}

//Displaying the LinkedList

void display(){
    ll *ptr;
    int node_no=1;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        ptr = head;
        printf("\n");
        rep(0,30) printf("-");
        printf("\nDISPLAYING THE LINKED LIST\n");
        rep(0,30) printf("-");
        printf("\n[  ");
        while(ptr!=NULL){
        printf("(Data:%d||Node:%d)-->",ptr->data,node_no++);
        ptr = ptr->next;
        }
        printf("NULL ]\n");
    }

}

/*
Insertion functions starts
*/

//Insertion at the beginning of the linked list
void insertAtBegin(){
    ll *temp;
    temp = (ll *)malloc(sizeof(ll));
    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }
    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

//Insertion at the end of the linked list
void insertAtEnd(){
    ll *temp,*ptr;
    temp = (ll *)malloc(sizeof(ll));
    ptr=head;

    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    }

}

//Insertion at a given position of the linked list
void insertAtPosition(){
    ll *temp,*ptr;
    temp = (ll *)malloc(sizeof(ll));
    ptr=head;

    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }
    int pos;
    printf("\nENTER POSITION FOR NODE INSERTION: ");
    scanf("%d",&pos);

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(pos==1){
        temp->next=head;
        head=temp;
    }
    else{
        int i=1;
        while(i!=pos-1){
            if(ptr==NULL){
              printf("\nPOSITION NOT FOUND!!\n");
              return;
            }
            ptr=ptr->next;
            i++;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }

}

//Insertion after a node of the linked list
void insertAfterNode(){
    ll *temp,*ptr;
    temp = (ll *)malloc(sizeof(ll));
    ptr=head;

    if(temp==NULL){
        printf("\nOUT OF MEMORY SPACE");
        exit(0);
    }
    int nd;
    printf("\nENTER NODE VALUE FOR NODE INSERTION: ");
    scanf("%d",&nd);

    printf("\nENTER NODE DATA: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        while(ptr->data!=nd){
            if(ptr->next==NULL){
              printf("\nNODE NOT FOUND!!\n");
              return;
            }
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

/*
Insertion functions ends
*/


/*
Deletion functions starts
*/

void deleteAtFirst(){
    ll *ptr;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else{
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("DELETION COMPLETE");
    }
}

void deleteAtLast(){
    ll *prev,*ptr;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }
    else if(head->next==NULL){
        ptr=head;
        head=NULL;
        printf("DELETION COMPLETE");
        free(ptr);

    }

    else{
        ptr=head;
        while(ptr->next!=NULL){
            prev=ptr;
            ptr=ptr->next;

        }
        prev->next=NULL;
        free(ptr);
        printf("DELETION COMPLETE");
    }
}

void deleteAtPosition(){
    ll *prev,*ptr;
    if(head==NULL){
        printf(" \nLINKED LIST IS EMPTY");
        return;
    }


    else{
            int pos;
            printf("\nENTER POSITION FOR NODE TO DELETE : ");
            scanf("%d",&pos);

            if(pos==1){
            ptr=head;
            head=head->next;
            free(ptr);
            printf("DELETION COMPLTETE");
            }

            else{
            ptr=head;
            int i=1;
            while(i<pos){

                if(ptr->next==NULL){
                  printf("\nPOSITION NOT FOUND!!\n");
                  return;
                }
                prev=ptr;
                ptr=ptr->next;
                i++;
            }
            prev->next=ptr->next;
            free(ptr);
            printf("DELETION COMPLTETE");
        }
    }


}

void deleteSpecifiedNode(){

    ll *prev,*ptr;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }

    else{
        ptr=head;
        int nd;
        printf("\nENTER NODE VALUE FOR NODE DELETION: ");
        scanf("%d",&nd);
        if(ptr->data==nd){\
            ptr=head;
            head=head->next;
            free(ptr);
            printf("DELETION COMPLTETE");
        }
            else{
                while(ptr->data!=nd){
                if(ptr->next==NULL){
                  printf("\nNODE NOT FOUND!!\n");
                  return;
                }
                prev=ptr;
                ptr=ptr->next;
            }
            prev->next=ptr->next;
            free(ptr);
            printf("DELETION COMPLTETE");
            }

    }
}

/*
Deletion functions ends
*/



int main()
{
    int choice;
    rep(0,10) printf("*");
            printf("WELCOME TO LINKED LIST");
            rep(0,10) printf("*");
            printf("\n");
    while(1){

            rep(0,30) printf("=");
            printf("\n<-<-<-MAIN MENU->->->\n(1)CREATE\n(2)INSERT\n(3)DELETE\n(4)DISPLAY\n(5)EXIT\n");
            rep(0,30) printf("-");
            printf("\nENTER YOUR CHOICE: ");
            scanf("%d",&choice);
            printf("\n");
            rep(0,30) printf("-");
            printf("\n");

            switch(choice){
                case 1: {   int num;
                            printf("\nENTER NUMBER OF NODES IN THE STARTING LINKED LIST: ");
                            scanf("%d",&num);
                            while(num!=0){
                                createNode();
                                num--;
                            }
                            break;
                        }

                case 2: {
                            int ch1;
                            rep(0,30) printf(">");
                            printf("\n<-<-<-INSERTION MENU->->->\n(1)INSERT AT THE BEGINNING\n(2)INSERT AT THE END\n(3)INSERT NODE AT POSITION\n(4)INSERT AFTER A SPECIFIED NODE\n");
                            rep(0,30) printf(">");
                            printf("\nENTER YOUR CHOICE: ");
                            scanf("%d",&ch1);
                            switch(ch1){
                                case 1: insertAtBegin();
                                        break;

                                case 2: insertAtEnd();
                                        break;

                                case 3: insertAtPosition();
                                        break;

                                case 4: insertAfterNode();
                                        break;

                                default: exit(0);
                            }
                            break;

                        }


                case 3: {
                            int ch2;
                            printf("\n");
                            rep(0,30) printf("<");
                            printf("\n<-<-<-DELETION MENU->->->\n(1)DELETE THE FIRST NODE\n(2)DELETE THE LAST NODE\n(3)DELETE NODE AT POSITION\n(4)DELETE A NODE OF SPECIFIED VALUE\n");
                            rep(0,30) printf("<");
                            printf("\nENTER YOUR CHOICE: ");
                            scanf("%d",&ch2);
                            switch(ch2){
                                case 1: deleteAtFirst();
                                        break;

                                case 2: deleteAtLast();
                                        break;

                                case 3: deleteAtPosition();
                                        break;

                                case 4: deleteSpecifiedNode();
                                        break;

                                default: exit(0);
                            }
                            break;

                        }

                case 4: display();
                        break;

                case 5: exit(0);
                        break;
                default: printf("WRONG OPTION SELCTED!!TRY AGAIN\n");

            }
            printf("\n");
            rep(0,30) printf("=");
            printf("\n\n\n");

    }
    getch();
    return 0;

}
