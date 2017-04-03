#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct students{
    char name[20];
    int rollno;
    int marks;

};


typedef struct students student;

int main(){

    char yname[10];
    FILE *fp,*fpp;
    student std[10],temp,e,test,edit;
    int n,i;
    fp = fopen("student.txt","w");
    printf("How many students you want to store information of?:");
    scanf("%d",&n);
    printf("Enter the info:");
    for(i=0; i<n; i++){
            fflush(stdin);
            printf("\nStudent %d\nName:",i+1);
            scanf("%s",&std[i].name);
            fflush(stdin);
            printf("Rollno:");
            scanf("%d",&std[i].rollno);
            fflush(stdin);
            printf("Marks:");
            scanf("%d",&std[i].marks);
            fflush(stdin);
            fwrite(&std[i],sizeof(std[i]),1,fp);

    }
    fclose(fp);
    printf("The recorded informations are:\n");
    fp = fopen("student.txt","r");
    if(fp==NULL){
        printf("The file is null");
    }
    while(fread(&temp,sizeof(temp),1,fp)>0){

        printf("Name: %s\nRollno:%d\nMarks:%d\n",temp.name,temp.rollno,temp.marks);
    }
    fclose(fp);
    printf("Enter the name of the person who you want to modify information of?:");
    scanf("%s",&yname);
    fp = fopen("student.txt","r+");
    if(fp==NULL){
        printf("Something's wrong");
    }
    /*fpp = fopen("student.txt","r+");
    if(fpp==NULL){
        printf("Something's wrong")
    } */
    while(fread(&test,sizeof(test),1,fp)>0){
        if(strcmp(test.name,yname)==0){
            fseek(fp,-sizeof(test),SEEK_CUR);
            printf("Enter the information to fill in here:\n Name:");
            scanf("%s",&edit.name);
            printf("Roll no:");
            scanf("%d",&edit.rollno);
            printf("Marks:");
            scanf("%d",&edit.marks);
            fwrite(&edit,sizeof(edit),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("Now the informations are:\n");
    fp = fopen("student.txt","r");
    while(fread(&temp,sizeof(temp),1,fp)>0){

        printf("Name: %s\nRollno:%d\nMarks:%d\n",temp.name,temp.rollno,temp.marks);
    }
    fclose(fp);

    return 0;

}

