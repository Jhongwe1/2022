#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct date{
	int year;
	int month;
	int day;
};

struct info{
	int id;
	char name[20];
	int age;
	char address[50];
	char citizenid[10];
	int phone;
	int balance;
	struct date opendate;
	struct date birthday;
}add,check,ed;

void menu(void);
void closethis(void){
	printf("---wei produce---");
}
void backtomenu(void){
	printf("\nenter 0 to exit , 1 back to menu : ");
	int qt;
	scanf("%d",&qt);
	if(qt==1){
		printf("\n");
		menu();
	}else if(qt==0){
		closethis();
	}else{
		printf("\nerror\n");
		backtomenu();
	}
}
void opennewaccount(void){
	system("cls");
	FILE *ptr;
	ptr=fopen("k.dat","a+");
	newid:
	printf("new id : ");
	scanf("%d",&check.id);
	while(fscanf(ptr,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",&add.id,add.name,&add.opendate.year,&add.opendate.month,&add.opendate.day,&add.age,add.address,add.citizenid,&add.phone,&add.balance)!=EOF){
		if(check.id==add.id){
			printf("id used . \n");
			goto newid;
		}
	}
	add.id=check.id;
	printf("opendate(**/**/**) : ");
	scanf("%d/%d/%d",&add.opendate.year,&add.opendate.month,&add.opendate.day);
	printf("name : ");
	scanf("%s",add.name);
	printf("age : ");
	scanf("%d",&add.age);
	printf("address : ");
	scanf("%s",add.address);
	printf("citizenid : ");
	scanf("%s",add.citizenid);
	printf("phone : ");
	scanf("%d",&add.phone);
	printf("balance : ");
	scanf("%d",&add.balance);
	fprintf(ptr,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);
	fclose(ptr);
	printf("saved success . ");
	backtomenu();
}
void checkallaccount(void){
	system("cls");
	FILE *chac;
	chac=fopen("k.dat","r");
	while(fscanf(chac,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",&add.id,add.name,&add.opendate.year,&add.opendate.month,&add.opendate.day,&add.age,add.address,add.citizenid,&add.phone,&add.balance)!=EOF){
		printf("%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);
	}
	fclose(chac);
	backtomenu();
}
void editaccount(void){
	system("cls");
	FILE *edi;
	FILE *neww;
	edi=fopen("k.dat","r");
	neww=fopen("new.dat","w");
	printf("edit account id : ");
	scanf("%d",&ed.id);
	int find=0;
	while(fscanf(edi,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",&add.id,add.name,&add.opendate.year,&add.opendate.month,&add.opendate.day,&add.age,add.address,add.citizenid,&add.phone,&add.balance)!=EOF){
		if(ed.id==add.id){
			find=1;
			int chose;
			printf("1.name\n2.address\n3.age\n4.phone\n");
			printf("option (1~4) : ");
			scanf("%d",&chose);
			switch(chose){
			case 1:
				printf(" : ");
				scanf("%s",ed.name);
				fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,ed.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);

				break;
			case 2:
				printf(" : ");
				scanf("%s",ed.address);
				fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,ed.address,add.citizenid,add.phone,add.balance);

				break;
			case 3:
				printf(" : ");
				scanf("%d",&ed.age);
				fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,ed.age,add.address,add.citizenid,add.phone,add.balance);

				break;
			case 4:
				printf(" : ");
				scanf("%d",&ed.phone);
				fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,ed.phone,add.balance);

				break;
			}
		}else{
			fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);

		}
		
	}
	
	fclose(edi);
    fclose(neww);
    
    remove("k.dat");
    rename("new.dat","k.dat");
    if(find==0){
		printf("not found");
	}else{
		printf("save success");
	}
	backtomenu();
}
void deleteaccount(void){
	system("cls");
	FILE *edi;
	FILE *neww;
	edi=fopen("k.dat","r");
	neww=fopen("new.dat","w");
	printf("delete account id : ");
	scanf("%d",&ed.id);
	int find=0;
	while(fscanf(edi,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",&add.id,add.name,&add.opendate.year,&add.opendate.month,&add.opendate.day,&add.age,add.address,add.citizenid,&add.phone,&add.balance)!=EOF){
		if(ed.id==add.id){
			find=1;
		}else{
			fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);
		}
	}
	
	fclose(edi);
    fclose(neww);
    
    remove("k.dat");
    rename("new.dat","k.dat");
    if(find==0){
		printf("not found");
	}else{
		printf("save success");
	}
	backtomenu();
}
void deposite(void){
	system("cls");
	FILE *edi;
	FILE *neww;
	edi=fopen("k.dat","r");
	neww=fopen("new.dat","w");
	printf("deposite account id : ");
	scanf("%d",&ed.id);
	int find=0;
	while(fscanf(edi,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",&add.id,add.name,&add.opendate.year,&add.opendate.month,&add.opendate.day,&add.age,add.address,add.citizenid,&add.phone,&add.balance)!=EOF){
		if(ed.id==add.id){
			find=1;
			int mny;
			printf(" : ");
			scanf("%d",&mny);
			mny+=add.balance;
			int chose;
			fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,mny);

		}else{
			fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);

		}
		
	}
	
	fclose(edi);
    fclose(neww);
    
    remove("k.dat");
    rename("new.dat","k.dat");
    if(find==0){
		printf("not found");
	}else{
		printf("save success");
	}
	backtomenu();
}
void withdraw(void){
	system("cls");
	FILE *edi;
	FILE *neww;
	edi=fopen("k.dat","r");
	neww=fopen("new.dat","w");
	printf("withdraw account id : ");
	scanf("%d",&ed.id);
	int find=0;
	while(fscanf(edi,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",&add.id,add.name,&add.opendate.year,&add.opendate.month,&add.opendate.day,&add.age,add.address,add.citizenid,&add.phone,&add.balance)!=EOF){
		if(ed.id==add.id){
			find=1;
			int mny;
			printf(" : ");
			scanf("%d",&mny);
			mny=add.balance-mny;
			int chose;
			fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,mny);

		}else{
			fprintf(neww,"%d\t%s\t%d/%d/%d\t%d\t%s\t%s\t%d\t%d\n",add.id,add.name,add.opendate.year,add.opendate.month,add.opendate.day,add.age,add.address,add.citizenid,add.phone,add.balance);

		}
		
	}
	
	fclose(edi);
    fclose(neww);
    
    remove("k.dat");
    rename("new.dat","k.dat");
    if(find==0){
		printf("not found");
	}else{
		printf("save success");
	}
	backtomenu();
}
void fordelay(int o){
	int g;
	for(int i=0;i<o;i++)
		g=i;
}
void menu(void){
	int chose;
	system("cls");
	system("color 9");
	printf("1.open new account\n");
	printf("2.check all account\n");
	printf("3.edit account\n");
	printf("4.delete account\n");
	printf("5.deposite\n");
	printf("6.withdraw\n");
	printf("7.exit\n");
	printf("option (1~7) : ");
	scanf("%d",&chose);
	switch(chose){
		case 1:
			opennewaccount();
			break;
		case 2:
			checkallaccount();
			break;
		case 3:
			editaccount();
			break;
		case 4:
			deleteaccount();
			break;
		case 5:
			deposite();
			break;
		case 6:
			withdraw();
			break;
		case 7:
			closethis();
			break;
	}
}

int main(void){
	char passward[10];
	char passwardd[10]="12345678";
	retry:
	printf("enter passward: ");
	scanf("%s",passward);
	if(strcmp(passward,passwardd)==0){
		printf("\nlogin success");
		for(int i=0;i<6;i++){
			fordelay(100000000);
			printf(" .");
		}
		system("cls");
		menu();
	}else{
		printf("\nlogin fail\n");
		rety:
		printf("\nenter 0 to exit , 1 to  retry : ");
		int qt;
		scanf("%d",&qt);
		if(qt==1){
			printf("\n");
			main();
		}else if(qt==0){
			closethis();
		}else{
			printf("\nerror\n");
			goto rety;
		}
	}
	
	return 0;
}
