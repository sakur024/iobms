#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

typedef struct user{
    int ac;
    char name[100];
    char mob[100];
    float bal;
    char pass[100];
    char last_t[100];
}user;
    FILE *fp;
    char ac_name[100];
    int ac_n;
    int user_index=-1;

void admin(int a);
int a_login();
void p_all_ac();
void new_ac();
int u_login();
void user_in(int a);
void money();
void deposit();
void ac_det();
void change_p();
void withdraw();
void transfer();
void delete();
void p_all_tran();
void reset();
void project_members();

int main(){

    system("cls");
    printf("\n<--:Integrated Online Banking Management System:-->\n");
    printf("\n\nPress any key to continue...");
    getch();
    int choice;
    do{
    system("cls");

    printf("\n\t<--:BARISHAL BANK:-->\n\n");
    printf("1 : Administration\n");
    printf("2 : Create a new Account\n");
    printf("3 : Log in to your Account\n");
    printf("4 : Project Members\n");
    printf("5 : Exit\n\n");
    printf("Enter your Choice.....\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        admin(a_login());
        break;
    case 2:

        new_ac();
        break;
    case 3:
        user_in(u_login());
        break;
    case 4:
        project_members();
        break;
    case 5:
        break;
    default:
        printf("\nInvalid choice ! \n");
        printf("\nPress any key to continue...");
        getch();
        break;
    }

    }while(choice != 5);
    return 0;
}

void p_all_ac()
{
    system("cls");
    char s[100];
    int j=1;
    struct user us;
    fp=fopen("ac_info.txt","rb");
    printf("\n\t<--:ALL ACCOUNT:-->\n\n\n");
    for(int i=0;i<150;i++)printf("-");
    printf("%-10s%-22s%-15s%-20s%-20s%s\n","Sl No","Account Number","Name","Mobile Number","Balance","Last Transaction");
    for(int i=0;i<150;i++)printf("-");

    while(fread(&us,sizeof(user),1,fp)){
    
    sprintf(s,"%0.2f",us.bal);
    printf("\n  %-10d%-20d%-15s%-20s%-20s%s",j,us.ac,us.name,us.mob,s,us.last_t);
    for(int i=0;i<150;i++)printf("-");
    j++;

    }
    fclose(fp);

    printf("\n\nPress any key to continue...");
    getch();

}

int a_login()
{
    system("cls");

    char name[100];
    char pass[100];

    printf("\n\t<--:ADMINISTRATION:-->\n\n");
    printf("Enter Name : ");
    scanf("%s",&name);
    printf("\nEnter Password : ");
    scanf("%s",&pass);
    if(strcmp(name,"admin")==0 && strcmp(pass,"1234")==0){
        return 1;
    }
    else{
        return 0;
    }
}

void admin(int a){
    system("cls");

    if(a==1){
            int choice1;
        do{
            system("cls");
        printf("\n\t<--:ADMINISTRATION:-->\n\n");
        printf("1 : All Account\n");
        printf("2 : All Transaction\n");
        printf("3 : Delete Account\n");
        printf("4 : Reset the System\n");
        printf("5 : Exit\n\n");
        printf("Enter your Choice.....\t");
        scanf("%d",&choice1);

        switch (choice1)
        {
        case 1:
            p_all_ac();
            break;
        case 2:
            p_all_tran();
            break;
        case 3:
            delete();
            break;
        case 4:
            reset();
            break;       
        case 5:
            break;       
        default:
            printf("\nInvalid Choice !\n");
            printf("\nPress any key to continue...");
            getch();
            break;
        }

        }while(choice1 != 5);
    }
    else{
        printf("\nLog in Failed ! \n");
        printf("\nPress any key to go back...");
        getch();
    }
}


void new_ac()
{
    system("cls");

    user us;
    printf("\n\t<--:CREATE NEW ACCOUNT:-->\n\n");
    printf("Enter your Name : ");
    fflush(stdin);
    gets(us.name);
    printf("\nEnter your mobile no : ");
    fflush(stdin);
    gets(us.mob);
    printf("\nSet password : ");
    fflush(stdin);
    gets(us.pass);
    us.bal=0;
    strcpy(us.last_t,"None\n");

    int tem=0;
    fp=fopen("ac.txt","r+b");
    fread(&tem,sizeof(int),1,fp);

    us.ac=tem;
    tem=tem+1;

    rewind(fp);

    fwrite(&tem,sizeof(int),1,fp);
    fclose(fp);
    
    fp=fopen("ac_info.txt","a+b");
    fwrite(&us,sizeof(user),1,fp);
    fclose(fp);

    printf("\nAccount Successfully Created \n");
    printf("\nYour account number is %d\n",us.ac);
    printf("\nPress any key to continue...");
    getch();
}

int u_login()
{
    system("cls");

    struct user us;
    char p[100];
    printf("\n\t<--:LOG IN:-->\n\n");
    printf("Enter Account No : ");
    scanf("%d",&ac_n);
    printf("\nEnter Password : ");
    fflush(stdin);
    gets(p);
    fp=fopen("ac_info.txt","rb");
    int index=0;
    while(fread(&us,sizeof(user),1,fp) != 0){
    if(strcmp(us.pass,p)==0 && (us.ac==ac_n)){
        fclose(fp);
        return index;
    }
    index++;
    }
    fclose(fp);
    return -1;
    
}

void user_in(int a)
{
    system("cls");

    if(a!=-1){
        user_index=a;
        money();
    }
    else{
        printf("Login Failed !\n");
        printf("\nPress any key to continue...");
        getch();
    }
}

void money()
{
    system("cls");

    int ch;
    do{
    system("cls");
    printf("\n\t<--:SERVICES:-->\n\n");
    printf("\n1 : Deposit Money\n");
    printf("2 : Withdraw Money\n");
    printf("3 : Transfer Money\n");
    printf("4 : Account Details\n");
    printf("5 : Change Password\n");
    printf("6 : EXIT\n");
    printf("\nEnter your Choice...");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        deposit();
        break;
    case 2:
        withdraw();
        break;
    case 3:
        transfer();
        break;
    case 4:
        ac_det();
        break;
    case 5:
        change_p();
        break;
    case 6:
        break;
    default:
            printf("\nInvalid Choice !\n");
            printf("\nPress any key to continue...");
            getch();
            break;
        }
    }while(ch!=6);
    user_index=-1;
}

void deposit()
{
    system("cls");

    FILE *fp1;
    time_t tm;
    time(&tm);
    float dep;
    char d[100];
    user us;
    printf("\n\t<--:DEPOSIT:-->\n\n");
    printf("Enter The amount to be Deposited : ");
    scanf("%f",&dep);
    fp=fopen("ac_info.txt","r+b");
    int in=-1;
    do{
        fread(&us,sizeof(struct user),1,fp);
        in++;
    }while(in!=user_index);

    rewind(fp);

    us.bal+=dep;
    printf("\n%0.2f Taka is Deposited\n",dep);
    printf("\nYour New Balance is %0.2f Taka\n",us.bal);

    fseek(fp,user_index*sizeof(user),SEEK_SET);

    fp1=fopen("all_tran.txt","a");
    char t[100];
    strcpy(t,ctime(&tm));
    fprintf(fp1,"Account Number : %d  Name : %s Deposited %0.2f Taka \n[d/t] %s\n",us.ac,us.name,dep,t);
    fclose(fp1);

    sprintf(d,"%0.2f",dep);
    strcpy(us.last_t,"Deposited ");
    strcat(us.last_t,d);
    strcat(us.last_t," [d/t] ");
    strcat(us.last_t,t);

    fwrite(&us,sizeof( user),1,fp);

    fclose(fp);

    printf("\nPress any key to continue...");
    getch();
}

void ac_det()
{
    system("cls");

    user us;
    fp=fopen("ac_info.txt","rb");

    fseek(fp,user_index*sizeof(user),SEEK_SET);

    fread(&us,sizeof(user),1,fp);

    fclose(fp);
    printf("\n\t<--:ACCOUNT DETAILS:-->\n\n");
    printf("Account Number : %d\n",us.ac);
    printf("\nName : %s\n",us.name);
    printf("\nMobile Number : %s\n",us.mob);
    printf("\nBalance : %0.2f\n",us.bal);
    printf("\nLast Transaction : %s\n",us.last_t);
    printf("\nEnter any key to continue...");
    getch();

}

void change_p()
{
    system("cls");

    char old[100];
    user us;
    fp=fopen("ac_info.txt","r+b");

    int index=0;

    while(fread(&us,sizeof(user),1,fp)){
       
        if(index==user_index){
             printf("\n\t<--:CHANGE PASSWORD:-->\n\n");
            printf("Enter Old Password : ");
            fflush(stdin);
            gets(old);
            if(strcmp(old,us.pass)==0){
        printf("\nEnter new Password : ");
            fflush(stdin);
        gets(us.pass);

        fseek(fp,user_index*sizeof(user),SEEK_SET);

        fwrite(&us,sizeof(user),1,fp);
        fclose(fp);
        printf("\nPassword Changed Successfully.\n");
        printf("\nYour new password is %s\n",us.pass);
        }
        else{
            printf("WRONG Password !\n");
        }
        break;
        }
        index++;
    }
    printf("\nPress any key to continue...");
    getch();
}

void withdraw()
{
    system("cls");

    FILE *fp1;
    time_t tm;
    time(&tm);
    float w;
    user us;
    fp=fopen("ac_info.txt","r+b");
    int in=-1;
    do{
       fread(&us,sizeof(struct user),1,fp);
       in++;
    }while(in!=user_index);

    printf("\n\t<--:WITHDRAW:-->\n\n");
    printf("Enter The Amount to be Withdrawed : ");
    scanf("%f",&w);
    if(us.bal>=w){
    us.bal-=w;

    fseek(fp,user_index*sizeof(user),SEEK_SET);

    fp1=fopen("all_tran.txt","a");
    char t[100],we[100];
    strcpy(t,ctime(&tm));
    fprintf(fp1,"Account Number : %d  Name : %s Withdrawed %0.2f Taka \n[d/t] %s\n",us.ac,us.name,w,t);
    fclose(fp1);

    sprintf(we,"%0.2f",w);
    strcpy(us.last_t,"Withdrawed ");
    strcat(us.last_t,we);
    strcat(us.last_t," [d/t] ");
    strcat(us.last_t,t);

    fwrite(&us,sizeof( user),1,fp);
    printf("\nWithdraw Successful\n");
    printf("\nYour new balance is %0.2f\n",us.bal);
    fclose(fp);
    }
    else{
        printf("\nNot Sufficient Balance ! \n");
    }
    printf("\nPress any key to continue...");
    getch();
}

void transfer()
{
    system("cls");

    FILE *fp1;
    time_t tm;
    int bl=0;
    time(&tm);
    float mon;
    user us,us1;
    fp=fopen("ac_info.txt","rb");

    int in=-1;
    do{
        fread(&us,sizeof(user),1,fp);
        in++;
    }while(in!=user_index);

    fclose(fp);

    fp1=fopen("ac_info.txt","r+b");
    int st;
    printf("\n\t<--:TRANSFER:-->\n\n");
    printf("Enter the account number of the Recipant : ");
    scanf("%d",&st);
    int ind=0;
    while(fread(&us1,sizeof(user),1,fp1)){
        if(us1.ac==st){
            if(us.ac==us1.ac){
                bl=0;
                break;
            }
            printf("\nEnter The Amount to be Transfered : ");
            scanf("%f",&mon);
                if(us.bal>=mon){
                        fseek(fp1,ind*sizeof(user),SEEK_SET);
            us1.bal+=mon;
            us.bal-=mon;
            fwrite(&us1,sizeof(user),1,fp1);
            fclose(fp1);

            fp=fopen("ac_info.txt","r+b");

            fp1=fopen("all_tran.txt","a");
            char t[100];
            strcpy(t,ctime(&tm));
            fprintf(fp1,"Account Number : %d  Name : %s Transfered %0.2f Taka \nto Account Number : %d Name : %s \n[d/t] %s\n",us.ac,us.name,mon,us1.ac,us1.name, t);
            fclose(fp1);           

            printf("\n%0.2f Taka is Transferred to Account no: %d Name : %s\n",mon,us1.ac,us1.name);
            printf("\nYour New Balance is %0.2f Taka\n",us.bal);

            char str[100];
            sprintf(str,"%0.2f",mon);
            strcpy(us.last_t,"Transferred ");
            strcat(us.last_t,str);
            strcat(us.last_t," [d/t] ");
            strcat(us.last_t,t);

            fseek(fp,user_index*sizeof(user),SEEK_SET);

            fwrite(&us,sizeof(user),1,fp);
            fclose(fp);
    }
    else{
        printf("\nInsufficient Balance !\n");
    }
        bl=1;
        }
        ind++;
    }
    if(!bl){
        printf("\nRecipant's account is not valid !\n");
    }

    printf("\nEnter any key to continue...");
    getch();
}

void delete()
{
    system("cls");

    FILE *fp1;
    user us;
    int del;

    fp1=fopen("temp.txt","a");
    fp=fopen("ac_info.txt","rb");
    printf("\n\t<--:DELETE ACCOUNT:-->\n\n");
    printf("Enter the account number to delete : ");
    scanf("%d",&del);
    int bl=0;
    while(fread(&us,sizeof(user),1,fp)){
        if(del!=us.ac){
            fwrite(&us,sizeof(user),1,fp1);
        }
        else{
            bl=1;
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("ac_info.txt");
    rename("temp.txt","ac_info.txt");
    if(bl){
    printf("\nThe Account is Deleted\n");}
    else{
        printf("\nInvalid Account Number\n");
    }
    printf("\nPress any key to continue...");
    getch();
}

void p_all_tran()
{
    system("cls");
    fp=fopen("all_tran.txt","r");
    printf("\n\t<--:ALL TRANSACTION:-->\n\n");
    char c=fgetc(fp);
    if(c==EOF){
        printf("None\n");
    }
    else{
        while(c!=EOF){
            printf("%c",c);
            c=fgetc(fp);
        }
    }
    printf("\nPress any key to continue...");
    getch();
}

void reset()
{
    system("cls");
    remove("ac_info.txt");
    remove("all_tran.txt");
    remove("ac.txt");
    int a=111050;
    fp=fopen("ac.txt","wb");
    fwrite(&a,sizeof(int),1,fp);
    fclose(fp);

    printf("\nSystem Reset Successful.\n");
    printf("\nPress any key to continue...");
    getch();
}

void project_members(){
    system("cls");
    printf("\n\n");
   printf("Name      : Abdus Sakur  \n");
   printf("Roll No   : 22CSE024\t\t\t      Seassion: 2021-2022\n");
   printf("Semester  : Second\t\t\t      Year    : First\n");
   printf("Email     : sakur.cse9.bu@gmail.com\n");
   printf("Department: Computer Science and Engineering,\n");
   printf("University Of Barishal.\n");
   printf("\n_______________#####_______________\n");
   printf("\nName      : Md Rayhanul Islam Rony\n");
   printf("Roll No   : 22CSE011\t\t              Seassion: 2021-2022\n");
   printf("Semester  : Second\t\t              Year    : First\n");
   printf("Email     : mdrayhanul.cse9.bu@gmail.com\n");
   printf("Department: Computer Science and Engineering\n");
   printf("University Of Barishal\n");
   printf("\n_______________#####_______________\n");
   printf("\nName      : Md Abdullah Al Noman\n");
   printf("Roll No   : 22CSE038\t\t\t      Seassion: 2021-2022\n");
   printf("Semester  : Second\t\t\t      Year    : First\n");
   printf("Email     : alnoman.cse9.bu@gmail.com\n");
   printf("Department: Computer Science and Engineering\n");
   printf("University Of Barishal\n");
   printf("\n_______________#####_______________\n");
   printf("\nPress any key to continue...");
   getch();
}