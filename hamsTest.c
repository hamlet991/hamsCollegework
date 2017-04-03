//Header files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//structure to store informations later
struct informations{
    char name[20];
    int id;
    int age;
};
typedef struct informations info;

//Function declarations
int palindrome(int arg1);
int armstrong(int arg1);
int reverse(int arg1);
int fibonacci(int arg1);
void record();
void matrixmult();
void sort(int arg1);
void temperature();

//The main function
int main(){
    int dec,n,i;
    //To repeat these statement over and over again
    while(9){
        printf("\nProgram options:\n1:Palindrome\n2:Armstrong\n3:Reverse\n4:Fibonacci\n5:Record\n6:Matrix multiplication\n7:Sort\n8:Leap year\n9:Convert temperature\n0:Exit\nSo what's up:");
        scanf("%d",&dec);
        switch(dec){
        case 1:
            printf("Enter the number:");
            scanf("%d",&n);
            if(n==palindrome(n))
                printf("It is a palindrome number\n");
            else
                printf("It is not a palindrome number\n");
            break;
        case 2:
            printf("Enter the number:");
            scanf("%d",&n);
            if(n==armstrong(n))
                printf("It is an armstrong number\n");
            else
                printf("It is not an armstrong number\n");
            break;
        case 3:
            printf("Enter the number:");
            scanf("%d",&n);
            printf("The reverse of the number is %d\n",palindrome(n)); //Since palindrome also reverse the number
            break;
        case 4:
            //Fibonacci using recursion
            printf("Enter how many terms:");
            scanf("%d",&n);
            for(i=0; i<n; i++){
                printf("%d ",fibonacci(i));
            }
            break;
        case 5:
            //Calls the void function record();
            record();
            break;
        case 6:
            //Function call
            matrixmult();
            break;
        case 7:
            printf("How many number you want to sort?:");
            scanf("%d",&n);
            sort(n);
            break;
        case 8:
            printf("Enter the year:");
            scanf("%d",&n);
            if((n%4==0 && n%100!=0) || n%400==0)
                printf("%d is a leap year\n",n);
            else
                printf("%d is not a leap year\n",n);
            break;
        case 9:
            temperature();
            break;
        case 0:
            //Exits from the program
            exit(0);
            break;
        default:
            printf("Something's wrong,try again");
            break;
        }
    }
    return 0;
}

//Function definition
int palindrome(int num){
    int rem,sum=0;
    while(num!=0){
        rem=num%10;
        sum=sum*10 + rem;
        num=num/10;
    }
    return sum;
}

int armstrong(int num){
    int rem,sum=0;
    while(num!=0){
        rem=num%10;
        sum=sum+rem*rem*rem;
        num=num/10;
    }
    return sum;
}

int fibonacci(int num){
    if(num<2){
        return num;
    }
    else{
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

void record(){
    FILE *fp;
    info *folks,read;
    int n,i;
    fp = fopen("theinfo.txt","w");
    if(fp==NULL){
        printf("Oops, Didn't work");
    }
    printf("How many people do you want to store the informations of?:");
    scanf("%d",&n);
    folks = (info*) calloc(n,sizeof(info)); //Dynamically allocates memory for structure
    if(folks==NULL){
        printf("Failed");
    }
    printf("Now enter the following informations:\n");
    for(i=0; i<n; i++){
        printf("Person %d\nName:", i+1);
        scanf("%s",&folks[i].name);
        fflush(stdin);
        printf("Id:");
        scanf("%d",&folks[i].id);
        fflush(stdin);
        printf("Age:");
        scanf("%d",&folks[i].age);
        fflush(stdin);
        fwrite(&folks[i],sizeof(folks[i]),1,fp);

    }
    fclose(fp);
    printf("alright check it out");
    fp = fopen("theinfo.txt","r");
    while(fread(&read,sizeof(read),1,fp)>0){
        printf("\nName: %s\nId: %d\nAge: %d",read.name,read.id,read.age);
    }
    fclose(fp);


}

void matrixmult(){
    int mat1[5][5],mat2[5][5],mat3[5][5];
    int r1,c1,r2,c2,n,i,j,k,sum=0;
    printf("Enter the number of row and column of the first matrix:");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of row and column of the second matrix:");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2){
        printf("The multiplication is unpossible duh, try again\n");
        matrixmult();
    }
    printf("Fill up the first matrix:");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Fill up the second matrix:");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    for(i=0; i<r1; i++){
        for(j=0; j<c2; j++){
            for(k=0; k<c1; k++){
                sum = sum+mat1[i][k]*mat2[k][j];
            }
            mat3[i][j]=sum;
            sum=0;
        }
    }
    printf("The multiplication of those matrix is:\n");
    for(i=0; i<r1; i++){
        for(j=0; j<c2; j++){
            printf("%d  ",mat3[i][j]);
        }
        printf("\n");
    }
}

void sort(int num){
    int i,j,temp;
    char dec;
    int nums[num];
    printf("Enter them:");
    for(i=0; i<num; i++){
        scanf("%d",nums+i);
    }
    for(i=0; i<num; i++){
        for(j=i+1; j<num; j++){
            if(*(nums+i)>*(nums+j)){
                temp = *(nums+i);
                *(nums+i) = *(nums+j);
                *(nums+j) = temp;
            }
        }
    }
    incase:            //Just in case the user presses wrong key
    printf("\nPress 'a' for Ascending order or 'd' for Descending order?:");
    scanf("%c",&dec);
    if(dec=='a'){
        for(i=0; i<num; i++){
            printf("%d  ",*(nums+i));
        }
    }
    else if(dec=='d'){
        for(i=num-1; i>=0; i--){
            printf("%d  ",*(nums+i));
        }
    }
    else{
        printf("Sorry, didn't catch that... try again");
        goto incase;    //Goes back to incase if the input is invalid
    }

}

void temperature(){
    int dec;
    float sum,temp;
    printf("\n1: Celsius to Fahrenheit \n2: Fahrenheit to Celsius:");
    scanf("%d",&dec);
    printf("Enter the temperature:");
    scanf("%f",&temp);
    if(dec==1){
        sum = (float) temp*1.8 + 32;                //Typecasting just to make sure it's a float
        printf("It's %.2f degree Fahrenheit\n",sum);
    }
    else if(dec==2){
        sum = (float) (temp-32) / 1.8;              //Same
        printf("It's %.2f degree Celsius\n",sum);
    }
    else{
        printf("You messed up, try again");
    }
}
