#include<stdio.h>
#include< stdlib.h>
#include<string.h>
struct bank* search(struct bank *head,char name[],int password) ;
struct bank* searchNew(struct bank *head,int account);
void Inquiry(struct bank *pointer);
void Save(struct bank *pointer);
void Withdraw(struct bank *pointer);
void Transfer(struct bank *pointer,struct bank *head);
void Quit(struct bank *head);
void deleteList(struct bank *head);
 struct bank{
	int account;
	char name[50];
	int password;
	float money;
	char rank;
	struct bank *next;
};
int main(){
	FILE *fp;
	int a,b,d,password,n=0;
	char c[50],f,name[50];
	float e;
    struct bank *pnode1,*pnode2,*head,*pointer;
	while(1){                                                      //Define a big loop, which is continue a display the login menu
	pnode1=(struct bank*)malloc(sizeof(struct bank));              //Create a list
	fp=fopen("bank.txt","r");
	fscanf(fp,"%d %s %d %f %c",&pnode1->account,pnode1->name,&pnode1->password,&pnode1->money,&pnode1->rank);
	head=pnode1;
	while(fscanf(fp,"%d %s %d %f %c",&b,c,&d,&e,&f)!=EOF){
		pnode2=(struct bank*)malloc(sizeof(struct bank));
		pnode2->account=b;
		strcpy(pnode2->name,c);
		pnode2->password=d;
		pnode2->money=e;
		pnode2->rank=f;
		pnode1->next=pnode2;
		pnode1=pnode2;
	}
	pnode2->next=NULL;
	
	
	printf("please input your name and password\n");          //Get information for the login name and password
	scanf("%s %d",name,&password);                            
while(n<2){                                                  //To limit the biggest values for login false
		pointer=search(head, name, password);
		if(pointer!=NULL)
			break;
		
		printf("please input your name and password\n");
		scanf("%s %d",name,&password);
		n++;
}

if(n==2)
		printf("warning");
	else{
		while(1){                                           //create a small loop to display the main menu continuely
		printf("\t\t|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|       Welcome to Use ATM System %s        |\n",pointer->name);
		printf("\t\t|                                               |\n");
		printf("\t\t|    Please Select The Following Functions:     |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|   $$-Inquery	 -- Press 1                     |\n");
		printf("\t\t|   $$-Save      -- Press 2                     |\n");
		printf("\t\t|   $$-Withdraw	 -- Press 3                     |\n");
		printf("\t\t|   $$-Transfer	 -- Press 4                     |\n");
		printf("\t\t|   $$-Quit      -- Press 5                     |\n");
		printf("\t\t|                                               |\n");
		printf("\t\t|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");

		printf("\n\n\n\n");
	
		printf("Please Input Number:");
		scanf("%d",&a);
		switch (a) {                                          //Call the function depands by the a's value

			case 1: Inquiry(pointer); break;
			case 2: Save(pointer); break;
			case 3: Withdraw(pointer); break;
			case 4: Transfer(pointer,head); break;
			case 5: Quit(head); break;
			default: printf("Number should between 1 -- 5!\n");
		}
		if(a==5)
			break;
		}
		
}
	void deleteList(struct bank *head);                                  //Free the memory
	
	}


}
struct bank* search(struct bank *head,char name[],int password){    //Compare the name and password between the ones you input and ones in the document 
	struct bank *current;
	int a,b=5;
	for(current=head;current!=NULL;current=current->next){
		a=strcmp(current->name,name);
		if(a==0)
			b=current->password-password;
		if(b==0)
			break;
	}
    return current;
	
}
void Inquiry(struct bank *pointer){                           //print out the account informations
	printf("%d %s %f\n",pointer->account,pointer->name,pointer->money);
}
void Save(struct bank *pointer){                             
	int m;
	printf("please input the value of the money that you want to save\n");
	scanf("%d",&m);
	pointer->money=pointer->money+m;
	printf("%d %s %f\n",pointer->account,pointer->name,pointer->money);
}
void Withdraw(struct bank *pointer){
	float m;
	if(pointer->rank=='N'){
		printf("you can only get 2000 yuan at most\n");
		scanf("%f",&m);
		if(m<=2000){
			pointer->money=pointer->money-m;
			printf("%d %s %f\n",pointer->account,pointer->name,pointer->money);
		}
		else
			printf("you can not get so much money\n");
	}
	if(pointer->rank=='V'){
		printf("you can only get 3000 yuan at most\n");
		scanf("%f",&m);
		if(m<=3000){
			pointer->money=pointer->money-m;
			printf("%d %s %f\n",pointer->account,pointer->name,pointer->money);
		}
		else
			printf("you can not get so much money\n");
	}
}
	void Transfer(struct bank *pointer,struct bank *head){
		int a=0;
		float m=0;
		struct bank *pointer2;
		printf("please give the account number\n");
		scanf("%d",&a);
		pointer2= searchNew(head,a);                 //find the people who you want to tranfer the money
		if(pointer2!=NULL){
			if(pointer->rank=='N'){
				printf("you can at most transfer 10000\n");
				scanf("%f",&m);
				if((m<=10000)&&(pointer->money-m>0)){
					pointer->money=pointer->money-m;
				    pointer2->money=pointer2->money+m*0.99;
	}
				else
					printf("warning\n");
			}
			if(pointer->rank=='V'){
				printf("you can at most transfer 20000\n");
				scanf("%f",&m);
				if((m<=20000)&&(pointer->money-m>0)){
					pointer->money=pointer->money-m;
				    pointer2->money=pointer2->money+m*0.995;
					printf("%f\n",pointer->money);
	}
				else
					printf("warning\n");
			}
		}
		else
			printf("warning, can not find the account\n");
	}
			
	struct bank* searchNew(struct bank *head,int account){                //search by the account number
		struct bank *current;
	int a,b=5;
	for(current=head;current!=NULL;current=current->next){
		a=current->account-account;
		if(a==0)
			break;
		
	}
    return current;
	}
	void Quit(struct bank *head){
			FILE *str;
			struct bank *current;    
			current = head;  
			str=fopen("bank.txt","w");
			while (current != NULL) {                                  //update the informations to the TXT document
				fprintf(str,"%d %s %d %f %c\n",current->account,current->name,current->password,current->money,current->rank);  
				current=current->next;
			}
			fclose(str);
	}
			    
	void deleteList(struct bank *head){                             //delete the list
		struct bank *next, *current;
		current=head;
		while(current!=NULL){
			next=current->next;
			free(current);
			current=next;
		}
	}

