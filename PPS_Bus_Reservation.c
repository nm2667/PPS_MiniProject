#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void display1(int a[6][5],int n);
void display2(int a1[6][5],int n);
void display3(int a2[6][5],int n);
void read();
int main(){
    int a[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int a1[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int a2[6][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int flag=1;
    while(flag==1){
    printf("\n\nWelcome to Yatra Travels!\n\nPress 1 to book your ticket\nPress 2 to view Passenger Database\nPress 3 to exit\n");
    int ch,c,n,n1,n2,i;
    scanf("%d",&ch);
    if(ch==1){
        printf("Book your tickets ASAP!\n\nAvailable Buses:\n1.Chennai to Bangalore\n2.Chennai to Kochi\n3.Chennai to Mumbai\nEnter your choice:");
        scanf("%d",&c);
        if(c==1){
            printf("Enter number of tickets:");
            scanf("%d",&n);
            display1(a,n);
        }
        else if(c==2){
            printf("Enter number of tickets:");
            scanf("%d",&n1);
            display2(a1,n1);
        }
        else if(c==3){
            printf("Enter number of tickets:");
            scanf("%d",&n2);
            display3(a2,n2);
        }
        else{
            printf("Invalid Input");
        }
    }
    else if (ch==2){
        read();
     }
    else if (ch==3){
        flag=0;
        break;
    }
    else{
            printf("Invalid Input");
        }
    }
    return 0;
}
void display1(int a[6][5],int n){
    printf("Chennai to Bangalore\n");
    int count=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]==0){
                count++;
            }
        }
    }
    printf("\n* ==> Occupied\no ==> Empty\n");
    if(count>=n){
        for(int i=0;i<6;i++){
            if(i==0){
                printf("\t1\t2\t3\t4\t5\n");
            }
            for(int j=0;j<5;j++){
                if(j==0){
                    printf("%c\t",(65+i));
                }
                if(a[i][j]==0){
                    printf("o\t");
            }
                else if(a[i][j]==1){
                     printf("*\t");
                }
            }
            printf("\n");
            }
            int amount=0;
            for(int i=0;i<n;i++){
                printf("Enter your choice of seats:\n");
                char seat[3];
                scanf("%s",&seat);
                char alpha;
                int num1,num2;
                alpha=seat[0];
                num2= ((int)(alpha))-65;
                num1=(int)seat[1]-48;
                a[num2][num1-1]=1;
                amount=3600;
                struct Details{
                    char name[100];
                    int busno;
                    char seat[3];
                    int amount;
                };
                struct Details s[n];
                printf("Enter First Name:");
                scanf("%s",&s[i].name);
                s[i].busno=9801;
                strcpy(s[i].seat,seat);
                s[i].amount=amount;
                FILE *bus;
                bus=fopen("YatraTravels.txt","a+");
                /*if(bus==NULL){
                    printf("Error");
                    exit();
                }*/
                fprintf(bus,"Name:%s\tBus Number:%d\tSeat Number:%s\tAmount to be paid:%d\tStatus:%s\n",s[i].name,s[i].busno,s[i].seat,s[i].amount,"Confirmed");
                fclose(bus);
            }
            if(n*amount==n*3600){
                printf("Your %d tickets have been booked succesfully. Please pay the total amount at the counter before boarding\nTotal amount to be paid: %d\nBus Number:9801\nHave a nice jouney! Thank you for choosing Yatra Travels!",n,n*amount);
            }
            else{
                printf("Sorry your seats couldn't be booked. Please try again later. Feel free to contact our customer care toll free number.");
            }
    }
    else{
        printf("Sorry seats are not available right now. Please try agian later.");
    }
}
void display2(int a1[6][5],int n){
    printf("Chennai to Kochi");
    int count=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            if(a1[i][j]==0){
                count++;
            }
        }
    }
    printf("\n* ==> Occupied\no ==> Empty\n");
    if(count>=n){
        for(int i=0;i<6;i++){
            if(i==0){
                printf("\t1\t2\t3\t4\t5\n");
            }
            for(int j=0;j<5;j++){
                if(j==0){
                    printf("%c\t",65+i);
                }
                if(a1[i][j]==0){
                    printf("o\t");
            }
                else if(a1[i][j]==1){
                     printf("*\t");
                }
            }
            printf("\n");
            }
            int amount=0;
            for(int i=0;i<n;i++){
                printf("Enter your choice of seats:");
                char seat[3];
                scanf("%s",&seat);
                char alpha;
                int num1,num2;
                alpha=seat[0];
                num2= ((int)(alpha))-65;
                num1=(int)seat[1]-48;
                a1[num2][num1-1]=1;
                amount=3600;
                struct Details{
                    char name[100];
                    int busno;
                    char seat[3];
                    int amount;
                }s[n];
                printf("Enter First Name:");
                scanf("%s",&s[i].name);
                s[i].busno=9802;
                strcpy(s[i].seat,seat);
                s[i].amount=amount;
                FILE *bus;
                bus=fopen("YatraTravels.txt","a+");
                /*if(bus==NULL){
                    printf("Error");
                    exit();
                }*/
                fprintf(bus,"Name:%s\tBus Number:%d\tSeat Number:%s\tAmount to be paid:%d\tStatus:%s\n",s[i].name,s[i].busno,s[i].seat,s[i].amount,"Confirmed");
                fclose(bus);
            }
            if(n*amount==n*3600){
                printf("Your %d have been booked succesfully. Please pay the total amount at the counter before boarding\nTotal amount to be paid: %d\nBus Number:9802\nTo cancel your tickets please contact our customer service\nHave a nice jouney! Thank you for using Yatra Travels!",n,n*amount);
            }
            else{
                printf("Sorry your seats couldn't be booked. Please try again later. Feel free to contact our customer care toll free number.");
            }
    }
    else{
        printf("Sorry seats are not available right now. Please try agian later.");
    }
}
void display3(int a2[6][5],int n){
    printf("Chennai to Mumbai\n");
    int count=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            if(a2[i][j]==0){
                count++;
            }
        }
    }
    printf("\n* ==> Occupied\no ==> Empty\n");
    if(count>=n){
        for(int i=0;i<6;i++){
            if(i==0){
                printf("\t1\t2\t3\t4\t5\n");
            }
            for(int j=0;j<5;j++){
                if(j==0){
                    printf("%c\t",65+i);
                }
                if(a2[i][j]==0){
                    printf("o\t");
            }
                else if(a2[i][j]==1){
                     printf("*\t");
                }
            }
            printf("\n");
            }
            int amount=0;
            for(int i=0;i<n;i++){
                printf("Enter your choice of seats:");
                char seat[3];
                scanf("%s",&seat);
                char alpha;
                int num1,num2;
                alpha=seat[0];
                num2= ((int)(alpha))-65;
                num1=(int)seat[1]-48;
                a2[num2][num1-1]=1;
                amount=3600;
                struct Details{
                    char name[100];
                    int busno;
                    char seat[3];
                    int amount;
                }s[n];
                printf("Enter First Name:");
                scanf("%s",&s[i].name);
                s[i].busno=9803;
                strcpy(s[i].seat,seat);
                s[i].amount=amount;
                FILE *bus;
                bus=fopen("YatraTravels.txt","a+");
                /*if(bus==NULL){
                    printf("Error");
                    exit();
                }*/
                fprintf(bus,"Name:%s\tBus Number:%d\tSeat Number:%s\tAmount to be paid:%d\tStatus:%s\n",s[i].name,s[i].busno,s[i].seat,s[i].amount,"Confirmed");
                fclose(bus);
            }
            if(n*amount==n*3600){
                printf("Your %d have been booked succesfully. Please pay the total amount at the counter before boarding\nTotal amount to be paid: %d\nBus number: 9803\nTo cancel your tickets please contact our customer service\nHave a nice jouney! Thank you for using Yatra Travels!",n,n*amount);
            }
            else{
                printf("Sorry your seats couldn't be booked. Please try again later. Feel free to contact our customer care toll free number.");
            }
    }
    else{
        printf("Sorry seats are not available right now. Please try again later.");
    }
}
void read(){
    FILE *bus;
    bus=fopen("YatraTravels.txt","r");
    /*if(bus==NULL){
        printf("Error");
        exit();
    }*/
    printf("Yatra Travels Database\n");
    char ch;
    do {
        ch = fgetc(bus);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(bus);
}
