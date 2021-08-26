#include<stdio.h>
#include<windows.h>//gotoxy()
#include<conio.h>//Use for delay(),getch()etc
#include<ctype.h>//Use for toupper(),tolower() etc
#include<string.h>//Use for strcmp(),strcpy(),Strlen() etc
#include<stdlib.h>
char ans=0;
int ok;
int b, valid=0;
//FUNCTION DECLARATION
void WelcomeScreen(void);//WelcomeScreen function declaration.
void Title(void);//Title function declaration.
void MainMenu(void);//MainMenu function declaration
void LoginScreen(void);//LoginScreen function declaration
void Add_rec(void);//Add_rec function declaration
void func_list();//function to list the patient details
void Search_rec(void);//Search_rec function declaration
void Edit_rec(void);//Edit_rec function declaration
void Dlt_rec(void);//Dlt_rec function declaration
void ex_it(void); //exit function declaration
void gotoxy(short x, short y)
{
	COORD pos ={x, y};//sets coordinates in (x,y)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//List of global variable
struct patient
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};
struct patient p, tmp_c;
main(void)
{
	WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
}
/* *********************************************************Welcome Screen********************************************************/
void WelcomeScreen(void)//function for welcome screen
{
	printf("\n\n\t\t\t\t########################################################");
	printf("\n\t\t\t\t\t\t      WELCOME TO\n  ");
	printf("\n\t\t\t\t\t  MAJUMDAR HOSPITAL MANAGEMENT SYSTEM     ");
	printf("\n\n\t\t\t\t########################################################");
	printf("\n\n\n\n\n\n\n\n Press any key to continue......\n");
	getch();
	system("cls");//Use to clear screen	
}
/* *********************************************************Title Screen********************************************************/
void Title(void)
{
	printf("\n\n\t\t---------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t          MAJUMDAR HOSPITAL        ");
	printf("\n\t\t---------------------------------------------------------------------------------------");
}
/* *********************************************************Main Menu********************************************************/
void MainMenu(void)
{
	system("cls");
	int choose;
	Title();//call title function
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i",&choose);
	switch(choose)//Arr_rec is called
	{
		case 1:
			Add_rec();
			break;
		case 2:
			func_list();
			break;
		case 3:
			Search_rec();//View_rec function is called
			break;
		case 4:
			Edit_rec();//Edit_rec function is called
			break;
		case 5:
			Dlt_rec();
			break;
		case 6:
			ex_it();
			break;
		default:
			printf("\t\t\tInvalid entry. Please enter right option :");
			getch();
	}
}
/********************************************************** Exit Screen ******************************************************************/
void ex_it(void)//function to exit
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :");
	getch();
}
/********************************************************** Login Screen ******************************************************************/
void LoginScreen(void)
{
	//List of variables
	int e=0;
	char Username[15];
	char Password[15];
	char original_Username[25]="Arijit";
	char original_Password[15]="1155";
	do
	{
		printf("\n\n\n\n\t\t\t\tEnter your Username and Password :");
		printf("\n\n\n\t\t\t\t\tUSERNAME:");
		scanf("%s",&Username);
		printf("\n\n\n\t\t\t\t\tPASSWORD:");
		scanf("%s",&Password);
		if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
		{
			printf("\n\n\n\t\t\t\t\t...Login Successful...");
			getch();
			MainMenu();//call MainMenu function
			break;
		}
		else
		{
			printf("\n\t\t\tPassword is incorrect:(Try Again :)");
			e++;
			getch();
		}
		
	}while(e<=2);
	if(e>2)
	{
		printf("You have crossed the limit. You cannot login :");
		getch();
		ex_it();
	}
	system("cls");
}
/********************************************************** ADD RECORD ******************************************************************/
void Add_rec(void)
{
	system("cls");
	Title();
	//list of variables
	char ans;
	FILE *ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!\n ");
	/********************************************************** FIRST NAME ******************************************************************/
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if(isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contains invalid character :( Enter Again: )");
			goto A;
		}
	}
	/********************************************************** LAST NAME ******************************************************************/
	B:
	printf("\n\t\t\tLast Name: ");
	scanf("%s",p.Last_Name);
	p.Last_Name[0]=toupper(p.Last_Name[0]);
	if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if(isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contains invalid character :( Enter Again: )");
			goto B;
		}
	}
	/********************************************************** Gender ******************************************************************/
	do
	{
		printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok=1;
		}
		else
		{
			ok=0;
		}
		if(!ok)
		{
			printf("\n\t\t Gender contain Invalid character :( Enter either F or M :)");
		}
	}while(!ok);
	/********************************************************** Age ******************************************************************/
	printf("\n\t\t\tAge:");
	scanf(" %i",&p.age);
	/********************************************************** Address ******************************************************************/
	do
	{
		C:
		printf("\n\t\t\tAddress: ");
		scanf("%s",p.Address);
		p.Address[0]=toupper(p.Address[0]);
		if(strlen(p.Address)>20||strlen(p.Address)<3)
		{
			printf("\n\t Invalid :(\t The max range for address is 20 and min range is 3)");
			goto C;
		}	
	}while(!valid);
	/********************************************************** Contact number ******************************************************************/
	do
	{
		D:
		printf("\n\t\t\tContact no: ");
		scanf("%s",p.Contact_no);
		if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
		{
			printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Error..)");
			goto D;
		}
		else
		{
			for (b=0;b<strlen(p.Contact_no);b++)
			{
				if(!isalpha(p.Contact_no[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Contact no. contains Invalid character :( Enter again :)");
				goto D;
			}
		}
	}while(!valid);
	/********************************************************** Email ******************************************************************/
	do
	{
		printf("\n\t\t\tEmail: ");
		scanf("%s",p.Email);
		if(strlen(p.Email)>30||strlen(p.Email)<8)
		{
			printf("\n\t Invalid :( \t The max range for Email is 30 and min range is 8 :)");
		}
	}while(strlen(p.Email)>30||strlen(p.Email)<8);
	/********************************************************** Problem ******************************************************************/
	E:
	printf("\n\t\t\tProblem: ");
	scanf("%s",p.Problem);
	p.Problem[0]=toupper(p.Problem[0]);
	if(strlen(p.Problem)>20||strlen(p.Problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for problem is 20 and min range is 3)");
			goto E;		
	}
	else
	{
		for(b=0;b<strlen(p.Problem);b++)
		{
			if (isalpha(p.Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contains Invalid character :( Enter again :)");
			goto E;
		}
	}
	/********************************************************** Prescribed Doctor ******************************************************************/
	F:
	printf("\n\t\t\tPrescribed Doctor: ");
	scanf("%s",p.Doctor);
	p.Doctor[0]=toupper(p.Doctor[0]);
	if(strlen(p.Doctor)>20||strlen(p.Doctor)<3)
	{
		printf("\n\t Invalid :( \t The max range for problem is 20 and min range is 3)");
			goto F;		
	}
		else
	{
		for(b=0;b<strlen(p.Doctor);b++)
		{
			if (isalpha(p.Doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contains Invalid character :( Enter again :)");
			goto F;
		}
	}
	fprintf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name,p.Last_Name,p.Gender,p.age,p.Address,p.Contact_no,p.Email,p.Doctor,p.Problem);
	printf("\n\n\t\t\t.... Information Record Successful....");
	fclose(ek);//ek file is closed
	sd:
	getch();
	printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
	scanf(" %c",&ans);
	if(toupper(ans)=='Y')
	{
		Add_rec();
	}
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
		getch();
		MainMenu();
	}
	else
	{
		printf("\n\t\tInvalid Input\n");
		goto sd;
	}		
}
/********************************************************** View Record ******************************************************************/
void func_list()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!! Patients Record List !!!!!!!!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Contact No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Problem");
		gotoxy(98,15);
		printf("Prescribed Doctor\n");
		printf("==============================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Doctor, p.Problem)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%i",p.age);
			gotoxy(37,row);
			printf("%s",p.Address);
			gotoxy(49,row);
			printf("%s",p.Contact_no);
			gotoxy(64,row);
			printf("%s",p.Email);
			gotoxy(88,row);
			printf("%s",p.Problem);
			gotoxy(98,row);
			printf("%s",p.Doctor);
			row++;
		}
	fclose(ek);
	getch();
	MainMenu();
}
/********************************************************** Search Record ******************************************************************/
void Search_rec(void)
{
	char name[20];
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!! Search Patients Record  !!!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Doctor, p.Problem)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Problem");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("==============================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(25,18);
			printf("%c",p.Gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.Address);
			gotoxy(52,18);
			printf("%s",p.Contact_no);
			gotoxy(64,18);
			printf("%s",p.Email);
			gotoxy(80,18);
			printf("%s",p.Problem);
			gotoxy(95,18);
			printf("%s",p.Doctor);
			printf("\n");
			break;
		}
	}
	if(strcmp(p.First_Name,name)!=0)
	{
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	}
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
	scanf("%c",&ans);
	if(toupper(ans)=='Y')
	{
		Search_rec();
	}
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
		getch();
		MainMenu();
	}
	else
	{
		printf("\n\tInvalid Input.\n");
		goto L;
	}	
}
/********************************************************** Edit Record ******************************************************************/
void Edit_rec(void)
{
	FILE *ek,*ft;
	int i,b, valid=0;
	char ch;
	char name[20];
	system("cls");
	Title();
	ft=fopen("temp2.dat","w+");
	ek=fopen("Record2.dat","r");
	if(ek==NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	}
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!! Edit Patients Record  !!!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,13);
	printf("Enter the First Name of the Patient : ");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL)
	{
		printf("\n Can not open file");
		getch();
		MainMenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Doctor, p.Problem)!=EOF);
	{
		if(strcmp(p.First_Name,name)==0)
		{
			valid=1;
			gotoxy(25,17);
			printf("*** Existing Record ***");
			gotoxy(10,19);
			printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n", p.First_Name,p.Last_Name,p.Gender,p.age,p.Address,p.Contact_no,p.Email,p.Doctor,p.Problem);
			gotoxy(12,22);
			printf("Enter New First Name: ");
			scanf("%s",p.First_Name);
			gotoxy(12,24);
			printf("Enter New Last Name: ");
			scanf("%s",p.Last_Name);
			gotoxy(12,26);
			printf("Enter Gender: ");
			scanf("%c",&p.Gender);
			p.Gender=toupper(p.Gender);
			gotoxy(12,28);
			printf("Enter Age: ");
			scanf("%i",&p.age);
			gotoxy(12,30);
			printf("Enter Address: ");
			scanf("%s",p.Address);
			p.Address[0]=toupper(p.Address[0]);
			gotoxy(12,32);
			printf("Enter Contact No: ");
			scanf("%s",p.Contact_no);
			gotoxy(12,34);
			printf("Enter Email: ");
			scanf("%s",p.Email);
			gotoxy(12,36);
			printf("Enter Problem: ");
			scanf("%s",p.Problem);
			p.Problem[0]=toupper(p.Problem[0]);
			gotoxy(12,38);
			printf("Enter Doctor Name: ");
			scanf("%s",p.Doctor);
			p.Doctor[0]=toupper(p.Doctor[0]);
			printf("\nPress U character for updating the operation : ");
			ch=getche();
			if(ch=='u'||ch=='U')
			{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name,p.Last_Name,p.Gender,p.age,p.Address,p.Contact_no,p.Email,p.Doctor,p.Problem);
				printf("\n\n\t\t\t.... Patient Record Updated Successfully....");
				
			}	
		}
		else
		{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name,p.Last_Name,p.Gender,p.age,p.Address,p.Contact_no,p.Email,p.Doctor,p.Problem);
		}
	}
	if(!valid)
	{
		printf("\n\t\tNO RECORD FOUND...");
	}
	fclose(ft);
	fclose(ek);
	remove("Record2.dat");
	rename("temp2.dat","Record2.dat");
	getch();
	MainMenu();
}
/********************************************************** Delete Record ******************************************************************/
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();
	FILE *ek,*ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!! Delete Patients Record  !!!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Doctor, p.Problem)!=EOF);
	{
		if(strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name,p.Last_Name,p.Gender,p.age,p.Address,p.Contact_no,p.Email,p.Doctor,p.Problem);
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name,p.Last_Name,p.Gender,p.age,p.Address,p.Contact_no,p.Email,p.Doctor,p.Problem);
			found=1;	
		}			
	}
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully :");
		getch();
		MainMenu();
	}	
}









