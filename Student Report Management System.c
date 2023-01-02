#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<windows.h>
struct student
{
   int rollno;
   char name[50];
   int p_marks,c_marks,m_marks,e_marks,cs_marks;
   float per;
   char grade;
}st;
FILE *fptr;

void write_student()
{
   //*fptr --> fuction pointer, capable of referring a function whose return type is void 
   //fopen() --> opens new or existing file
   // ab --> opens a binary file in append mode(add data to the existing data of file)
   fptr=fopen("student.dat","ab");
   printf("\nPlease Enter The New Details of student \n");
   printf("\nEnter The roll number of student : ");
   scanf("%d",&st.rollno);
   fflush(stdin);
   //fflush() is typically used for output stream only. Its purpose is to clear the output buffer and 
   //move the buffered data to console (in case of stdout) or disk (in case of file output stream).
   //While taking an input string with spaces, the buffer does not get cleared for the next input and 
   //considers the previous input for the same. To solve this problem fflush(stdin) is. used to clear the stream/buffer. 
   printf("\n\nEnter The Name of student : ");
   gets(st.name);
   printf("\nEnter The marks in physics out of 100 : ");
   scanf("%d",&st.p_marks);
   printf("\nEnter The marks in chemistry out of 100 : ");
   scanf("%d",&st.c_marks);
   printf("\nEnter The marks in maths out of 100 : ");
   scanf("%d",&st.m_marks);
   printf("\nEnter The marks in english out of 100 : ");
   scanf("%d",&st.e_marks);
   printf("\nEnter The marks in computer science out of 100 : ");
   scanf("%d",&st.cs_marks);
   //calculating percentage and grade:
   st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
   if(st.per>=60)
      st.grade='A';
   else if(st.per>=50 &&st.per<60)
      st.grade='B';
   else if(st.per>=33 &&st.per<50)
      st.grade='C';
   else
      st.grade='F';

   //syntax of fwrite() --> fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
   //writes data from the array pointed to, by ptr to the given stream.
   // PARAMETERS :
   //ptr − This is the pointer to the array of elements to be written.
   //size − This is the size in bytes of each element to be written.
   //nmemb − This is the number of elements, each one with a size of size bytes.
   //stream − This is the pointer to a FILE object that specifies an output stream.
   fwrite(&st,sizeof(st),1,fptr);
   //fclose() --> closes the stream. All buffers are flushed.
   fclose(fptr);
   printf("\n\nStudent Record Has Been Created ");
   // getch use --> hold the output screen for some time until the user passes a key from the keyboard to exit the console screen.
   getch();
}



void display_all()
{
   system("cls");
   printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
   // rb --> Open for reading in binary mode. If the file does not exist, fopen( ) returns NULL.
   // fread() --> used to read data from a file and store it in a buffer.
   fptr=fopen("student.dat","rb");
   while((fread(&st,sizeof(st),1,fptr))>0)
   {
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in Physics : %d",st.p_marks);
      printf("\nMarks in Chemistry : %d",st.c_marks);
      printf("\nMarks in Maths : %d",st.m_marks);
      printf("\nMarks in English : %d",st.e_marks);
      printf("\nMarks in Computer Science : %d",st.cs_marks);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nGrade of student is : %c",st.grade);
      printf("\n\n====================================\n");
      getch();
   }
   fclose(fptr);
   getch();
}



void display_sp(int n)
{
// flag variable --> A "flag" variable is simply a boolean variable whose contents is "true" or "false". 
//You can use either the bool type with true or false , or an integer variable with zero for "false" and non-zero for "true".
   int flag=0;
   fptr=fopen("student.dat","rb");
   while((fread(&st,sizeof(st),1,fptr))>0)
   {
      if(st.rollno==n)
      {
         system("cls");
         printf("\nRoll number of student : %d",st.rollno);
         printf("\nName of student : %s",st.name);
         printf("\nMarks in Physics : %d",st.p_marks);
         printf("\nMarks in Chemistry : %d",st.c_marks);
         printf("\nMarks in Maths : %d",st.m_marks);
         printf("\nMarks in English : %d",st.e_marks);
         printf("\nMarks in Computer Science : %d",st.cs_marks);
         printf("\nPercentage of student is  : %.2f",st.per);
         printf("\nGrade of student is : %c",st.grade);
         flag=1;
      }
   }
   fclose(fptr);

   if(flag==0)
      printf("\n\nrecord not exist");
      getch();
}



void modify_student()
{
   int no,found=0;
   system("cls");
   printf("\n\n\tTo Modify ");
   printf("\n\n\tPlease Enter The roll number of student : ");
   scanf("%d",&no);
   // rb+ --> Open for both reading and writing in binary mode. If the file does not exist, fopen( ) returns NULL.
   fptr=fopen("student.dat","rb+");
   while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
   {
      if(st.rollno==no)
      {
         printf("\nRoll number of student : %d",st.rollno);
         printf("\nName of student : %s",st.name);
         printf("\nMarks in Physics : %d",st.p_marks);
         printf("\nMarks in Chemistry : %d",st.c_marks);
         printf("\nMarks in Maths : %d",st.m_marks);
         printf("\nMarks in English : %d",st.e_marks);
         printf("\nMarks in Computer Science : %d",st.cs_marks);
         printf("\nPercentage of student is  : %.2f",st.per);
         printf("\nGrade of student is : %c",st.grade);


         printf("\nPlease Enter The New Details of student \n");
         printf("\nEnter The roll number of student : ");
         scanf("%d",&st.rollno);
         fflush(stdin);
         printf("\n\nEnter The Name of student : ");
         gets(st.name);
         printf("\nEnter The marks in physics out of 100 : ");
         scanf("%d",&st.p_marks);
         printf("\nEnter The marks in chemistry out of 100 : ");
         scanf("%d",&st.c_marks);
         printf("\nEnter The marks in maths out of 100 : ");
         scanf("%d",&st.m_marks);
         printf("\nEnter The marks in english out of 100 : ");
         scanf("%d",&st.e_marks);
         printf("\nEnter The marks in computer science out of 100 : ");
         scanf("%d",&st.cs_marks);
         st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
         if(st.per>=60)
            st.grade='A';
         else if(st.per>=50 && st.per<60)
            st.grade='B';
         else if(st.per>=33 && st.per<50)
            st.grade='C';
         else
            st.grade='F';

         // fseek --> Moving to a specific location in a file
         //int fseek(FILE *pointer, long int offset, int position)
         //pointer: pointer to a FILE object that identifies the stream.
         //offset: number of bytes to offset from position
         //position: position from where offset is added.
         //returns: zero if successful, or else it returns a non-zero value
         fseek(fptr,-(long)sizeof(st),1);

         fwrite(&st,sizeof(st),1,fptr);
         printf("\n\n\t Record Updated");
         found=1;
      }
   }
   fclose(fptr);

   if(found==0)
      printf("\n\n Record Not Found ");
      getch();
}



void delete_student()
{
   int no;
   FILE *fptr2;
   system("cls");
   printf("\n\n\n\tDelete Record");
   printf("\n\nPlease Enter The roll number of student You Want To Delete : ");
   scanf("%d",&no);
   fptr=fopen("student.dat","rb");
   // wb --> Open for writing in binary mode. If the file exists, its contents are overwritten. If the file does not exist, it will be created.
   fptr2=fopen("Temp.dat","wb");
   // rewind --> Moving to a specific location in a file
   rewind(fptr);
   while((fread(&st,sizeof(st),1,fptr))>0)
   {
      if(st.rollno!=no)
      {
         fwrite(&st,sizeof(st),1,fptr2);
      }
   }
   fclose(fptr2);
   fclose(fptr);
   remove("student.dat");
   rename("Temp.dat","student.dat");
   printf("\n\n\tRecord Deleted ..");
   getch();
}



void class_result()
{
   system("cls");
   fptr=fopen("student.dat","rb");
   if(fptr==NULL)
   {
      printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
      printf("\n\n\n Program is closing ....");
      getch();
      exit(0);
   }

   printf("\n\n\t\tALL STUDENTS RESULT \n\n");
   printf("=====================================================\n");
   printf("R.No.  Name       P   C   M   E   CS  %%age   Grade \n");
   printf("=====================================================\n");

   while((fread(&st,sizeof(st),1,fptr))>0)
   {
      printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",st.rollno   ,st.name,st.p_marks,st.c_marks,st.m_marks,st.e_marks,st.cs_marks,st.per,st.grade);
   }

   fclose(fptr);
   getch();
}



void result()
{
   int ans,rno;
   char ch;
   system("cls");
   printf("\n\n\nRESULT MENU");
   printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
   printf("\n\n\nEnter Choice (1/2)? ");
   scanf("%d",&ans);
   switch(ans)
   {
      case 1 : 
         class_result();
         break;

      case 2 : 
      {
         do{
         char ans;
         system("cls");
         printf("\n\nEnter Roll Number Of Student : ");
         scanf("%d",&rno);
         display_sp(rno);
         printf("\n\nDo you want to See More Result (y/n)?");
         scanf("%c",&ans);
         }while(ans=='y'||ans=='Y');
         break;
      }

      case 3: break;

      default:
         printf("\a");
   }
}



//Gotoxy function --> used to print the statement at appropriate position on the screen. 
//The parameters passed to gotoxy() are column number and row number.
void gotoxy(int x, int y);
void intro()
{
   system("cls");
   COORD pos1 = {35,11};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos1);
   printf("STUDENT ");
   COORD pos2 = {33,14};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
   printf("REPORT CARD ");
   COORD pos3 = {35,17};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos3);
   printf("PROJECT");
   printf("\n\n\n\n\n\nMADE BY : TANYA SINGH");
   printf("\n\nCOLLEGE : TECHNO INTERNATIONAL NEW TOWN");
   getch();
}



void entry_menu()
{
   char ch2;
   system("cls");
   printf("\n\n\n\tENTRY MENU");
   printf("\n\n\t1.CREATE STUDENT RECORD");
   printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
   printf("\n\n\t3.SEARCH STUDENT RECORD ");
   printf("\n\n\t4.MODIFY STUDENT RECORD");
   printf("\n\n\t5.DELETE STUDENT RECORD");
   printf("\n\n\t6.BACK TO MAIN MENU");
   printf("\n\n\tPlease Enter Your Choice (1-6) ");

   //getche is a C function to read a single character from the keyboard which displays immediately on screen without waiting for the enter key. 
   //getch does not display the character entered by the user. getche displays the character entered by the user.
   ch2=getche();

   switch(ch2)
   {
      case '1':
         system("cls");
         write_student();
         break;

      case '2': 
         display_all();
         break;

      case '3':  {
         int num;
         system("cls");
         printf("\n\n\tPlease Enter The roll number : ");
         scanf("%d",&num);
         display_sp(num);
         }
         break;

      case '4': 
         modify_student();
         break;

      case '5': 
         delete_student();
         break;

      case '6': 
         break;

      default:
         printf("\a");entry_menu();
   }
}



void main()
{
   char ch;
   intro();
   do
    {
       system("cls");
       printf("\n\n\n\tMAIN MENU");
       printf("\n\n\t01. RESULT MENU");
       printf("\n\n\t02. ENTRY/EDIT MENU");
       printf("\n\n\t03. EXIT");
       printf("\n\n\tPlease Select Your Option (1-3) ");
       ch=getche();
       switch(ch)
       {

          case '1': 
            system("cls");
            result();
            break;

          case '2': 
            entry_menu();
            break;

          case '3':
            exit(0);

          default :
            printf("\a");
       }
    }while(ch!='3');
}