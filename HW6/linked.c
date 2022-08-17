#include<stdio.h>
#include<stdlib.h>

struct ACCOUNT {
         int accountNumber;
         float balance;
         struct ACCOUNT *next;
};

struct ACCOUNT *head = NULL;

//  Add a node or update the linkedlist
void findUpdate(int account, float amount){
        struct ACCOUNT *anAccount;
        int i = 0;

        anAccount = head;

        while(anAccount != NULL){

                if(anAccount->accountNumber==account){
                        anAccount->balance+=amount;
                        i++;
                }
        anAccount = anAccount->next;
        }
        if(i==0){
                struct ACCOUNT *newAccount = (struct ACCOUNT *)malloc(sizeof(struct ACCOUNT));
                newAccount->accountNumber = account;
                newAccount->balance = amount;

                newAccount->next=head;
                head=newAccount;
        }

}
//Pretty print method
void prettyPrint(){
        struct ACCOUNT *current;

        if(head != NULL){
                current = head;
        }else{
                printf("Your list is empty");
                return;
        }
        while(current != NULL){
                printf("ACCOUNT ID: %5d BALANCE: $ %9.2f\n", current->accountNumber, current->balance);
                current=current->next;
        }
}
