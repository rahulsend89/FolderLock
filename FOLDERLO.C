#include<stdio.h>
#include<conio.h>
#include<dir.h>
#include<io.h>
#include<dos.h>
#include<string.h>
#include<process.h>

void start(void);

#pragma startup start
char oldname[7]="locker", newname[7]="lock";
char pass1[20];
char encde[20];
char pass2[20];
char choice1;
char choice2;
void main();

int file_exists(char *filename)
{
  return (access(filename, 0) == 0);
}

folder_lock(){
int stat;
if(file_exists("lock")==1){
textcolor(10);
gotoxy(25,10);
cprintf("locker is already locked");
getch();
}
else{
stat = mkdir("locker");
if (!stat){
       textcolor(10);
       gotoxy(25,10);
       cprintf("Directory named locker is created\n");
       getch();
}
else{
gotoxy(25,10);
cprintf("R U Sure u Want to lock(Y/N)");
choice1=getch();
switch(choice1){
case 'y':
case 'Y':
if (rename(oldname,newname) == 0){
   system("attrib +r +a +s +h lock");
   system("cacls lock /e /d everyone");
   _setcursortype(_NOCURSOR);
   cprintf("Folder is lock");
   }
break;
default:
return 0;
}
}
}
return 0;
}
folder_unlock(){
if(file_exists("lock")==0 && file_exists("locker")==0){
textcolor(10);
gotoxy(20,10);
cprintf("Create a Directory By using LOCK FOLDER option");
gotoxy(20,12);
cprintf("     press any key to go to Main Menu...");
getch();
}
if(file_exists("locker")==1 && file_exists("lock")==0){
textcolor(10);
gotoxy(25,10);
cprintf("Folder is not lock");
gotoxy(20,12);
cprintf("press any key to go to Main Menu...");
getch();
}
if(file_exists("lock")==1){
 gotoxy(25,10);
 cprintf("R U sure u Want to Unlock(Y/N):");
 choice2=getch();
 switch(choice2){
 case 'y':
 case 'Y':
 system("cacls lock /e /g everyone:f");
 system("attrib -r -s -a -h lock");
 _setcursortype(_NOCURSOR);
 if(rename(newname,oldname)==0){
 printf("not Done");
 }
 break;
 default:
 return 0;
 }
}
return 0;
}
void soft()
{
	clrscr();
	textcolor(10);
	cprintf("                 ษออออออออออออออออออออออออออออออออออออออออออออป\r\n");
	cprintf("                 บ         -------FOLDER LOCK-------          บ\r\n");
	cprintf("                 บ        Copyright (C): Rahul Malik.         บ\r\n");
	cprintf("                 บ                    2008 :)                 บ\r\n");
	cprintf("                 ศออออออออออออออออออออออออออออออออออออออออออออผ\r\n");
	textcolor(WHITE);
}

size(ssl,esl)
int ssl,esl;
{
	union REGS i,o;
	i.h.ah=1;
	i.h.ch=ssl;
	i.h.cl=esl;
	i.h.bh=0;
	int86(16,&i,&o);
	return 0;
}

void setvidio(int k)
{
	if(k==0)
		return;
	textcolor(YELLOW);
	textbackground(20);
	return;
}
void resetvidio(int k)
{
	if(k==0)
		return;
	textcolor(WHITE);
	textbackground(BLACK);
	return;
}

//Function for getting key value
int getkey()
{
	union REGS i,o;
	while(!kbhit());
	i.h.ah=0;
	int86(22,&i,&o);

	return(o.h.ah);
}
int menu()
{

	int i=16,r=17,j=0,k=0,l=0,m=0,w=0,x=0,y=0,z=0,hit,ans=1;
	clrscr();
	_setcursortype(_NOCURSOR);
	       do{
	       clrscr();
	       soft();
	       gotoxy(38,9);
	       printf("Main Menu");
	       gotoxy(38,10);
	       printf("---------");
		gotoxy(32,12);
		 printf("ษอออออออออออออออออออป");
		 gotoxy(32,13);
		 printf("บ                   บ");
		 gotoxy(32,14);
		 printf("บ                   บ");
		 gotoxy(32,15);
		 printf("บ                   บ");
		 gotoxy(32,16);
		 printf("บ                   บ");
		 gotoxy(32,17);
		 printf("บ                   บ");
		 gotoxy(32,18);
		 printf("บ                   บ");
		 gotoxy(32,19);
		 printf("บ                   บ");
		 gotoxy(32,20);
		 printf("บ                   บ");
		 gotoxy(32,21);
		 printf("บ                   บ");
		 gotoxy(32,22);
		 printf("บ                   บ");
		 gotoxy(32,23);
		 printf("บ                   บ");
		 gotoxy(32,24);
		 printf("ศอออออออออออออออออออผ");

		gotoxy(34,14);
		printf("%c",i);
		gotoxy(36,14);
		setvidio(i);
		cprintf("SOFTWARE INFO");
		printf(" %c",r);
		resetvidio(1);

		size(32,1);
		gotoxy(34,16);
		printf("%c",j);
		gotoxy(36,16);
		setvidio(j);
		cprintf("PASSWORD CHNG");
		printf(" %c",w);
		resetvidio(1);

		size(32,2);
		gotoxy(34,18);
		printf("%c",k);
		gotoxy(36,18);
		setvidio(k);
		cprintf(" LOCK FOLDER ");
		printf(" %c",x);
		resetvidio(1);

		size(32,3);
		gotoxy(34,20);
		printf("%c",l);
		gotoxy(36,20);
		setvidio(l);
		cprintf("UNLOCK FOLDER");
		printf(" %c",y);
		resetvidio(1);

		size(32,4);
		gotoxy(34,22);
		printf("%c",m);
		gotoxy(36,22);
		setvidio(m);
		cprintf("    EXIT     ");
		printf(" %c",z);
		resetvidio(1);

		hit=getkey();
		if(hit==80){
			switch(ans){
				case 1:
					ans=2;
					j=16;
					w=17;
					i=k=l=m=r=x=y=z=0;
					break;
				case 2:
					ans=3;
					k=16;
					x=17;
					i=j=l=m=r=w=y=z=0;
					break;
				case 3:
					ans=4;
					l=16;
					y=17;
					i=j=k=m=w=x=z=r=0;
					break;
				case 4:
					ans=5;
					m=16;
					z=17;
					i=j=k=l=r=w=x=y=0;
					break;
				case 5:

					ans=1;
					i=16;
					r=17;
					j=k=l=m=w=x=y=z=0;

					break;

				}
			  }
		if(hit==72){
			switch(ans){
				case 1:
					ans=5;
					m=16;
					z=17;
					i=j=k=l=r=w=x=y=0;

					break;

				case 2:
					ans=1;
					i=16;
					r=17;
					j=k=l=m=w=x=y=z=0;
					break;
				case 3:
					ans=2;
					j=16;
					w=17;
					i=k=l=m=r=x=y=z=0;

					break;
			       case 4:
					ans=3;
					k=16;
					x=17;
					i=j=l=m=r=w=y=z=0;

					break;
			       case 5:
					ans=4;
					l=16;
					y=17;
					i=j=k=m=w=x=z=r=0;

					break;

			}

		}
			}while(hit!=28);

	return(ans);

}
void about()
{
	soft();
	printf("%c FOLDERLOCK:\n",3);
	printf("----------\n\n");
	printf("     This is a basically easy folder locking program used to hide\n");
	printf("     files from unauthorized access to that file.\n\n");
	printf("%c HOW TO USE:\n",3);
	printf("----------\n\n");
	printf("     First u just hav to go to %c LOCK FOLDER %c option\n",16,17);
	printf("     Then folder name locker will be created by this software\n");
	printf("     Then again u have to go to %c LOCK FOLDER %c option \n",16,17);
	printf("     Then it will lock that locker\n");
	printf("     Then to unlock u have to go to %c UNLOCK FOLDER %c option \n",16,17);
	printf("\n%c Program:\n",3);
	printf("-----------\n\n");
	printf("     This program is implimented in TURBO C++ v3.0 enviroment. It cannot be run\n");
	printf("     in LINUX . I realy Dont get time to check it out\n");
	printf("\n%c Contact:\n",3);
	printf("----------\n\n");
	printf("     E Mail: rahul.send89@gmail.com\n");
	printf("\n\n\n\nPress ENTER to return.....");
	getch();
}
void border(int color)
    {
      union REGS i,o;

      clrscr();
      i.h.ah=0x0B;
      i.x.bx=color;
      int86(0x10,&i,&o);
      }
void invalid(){
	_setcursortype(_NOCURSOR);
	border(3);
	soft();
	textcolor(RED);
	gotoxy(22,20);
	cprintf("ษออออออออออออออออออออออออออออออออป\r\n");
	gotoxy(22,21);
	cprintf("บ       Invalid Password.        บ\r\n");
	gotoxy(22,22);
	cprintf("ศออออออออออออออออออออออออออออออออผ\r\n");
	getch();
	_setcursortype(_SOLIDCURSOR);
	printf("\n\n                     EXIT? <y/n>: ");
	if(getch()=='y')
		exit(1);
}
void match(){
	_setcursortype(_NOCURSOR);
	border(3);
	soft();
	textcolor(BLUE);
	textbackground(10);
	gotoxy(22,20);
	cprintf("ษออออออออออออออออออออออออออออออออป\r\n");
	gotoxy(22,21);
	cprintf("บ         Password Match         บ\r\n");
	gotoxy(22,22);
	cprintf("ศออออออออออออออออออออออออออออออออผ\r\n");
	getch();
	textcolor(YELLOW);
	textbackground(BLACK);
}
void first(){
	_setcursortype(_NOCURSOR);
	border(3);
	soft();
	textcolor(GREEN);
	gotoxy(22,20);
	cprintf("ษออออออออออออออออออออออออออออออออป\r\n");
	gotoxy(22,21);
	cprintf("บ  This is your first Password   บ\r\n");
	gotoxy(22,22);
	cprintf("ศออออออออออออออออออออออออออออออออผ\r\n");
	getch();
}

void disp(){
	border(3);
	soft();
	textcolor(51);
	gotoxy(22,20);
	cprintf("ษออออออออออออออออออออออออออออออออป\r\n");
	gotoxy(22,21);
	cprintf("บ Enter Password:                บ\r\n");
	gotoxy(22,22);
	cprintf("ศออออออออออออออออออออออออออออออออผ\r\n");
	textcolor(WHITE);
	gotoxy(40,21);
	//getch();
}

void pas()
{
      int i=0,a,l=40;
      char j;
      _setcursortype(_SOLIDCURSOR);
      disp();
	while((j=getch())!=13){
	      a=j;
	      if(a==8&&l>40){
		l--;
		gotoxy(l,21);
		printf(" ");
		gotoxy(l,21);
		i--;
		}
		else if(a!=8 && l<48){
		gotoxy(l,21);
		printf("*");
	      l++;
		pass1[i]=j;
		i++;
		       }

      }
      pass1[i]=NULL;
}
void encode(){
	FILE *fp;
	char ch;
	int i=0,a,j=1,b;
	fp=fopen("C:\\windows\\system32\\system.sys","r+");
	if(fp==NULL)
	     fp=fopen("C:\\windows\\system32\\system.sys","w");
	a=pass1[0];
	ch=a;
	fputc(ch*2,fp);
	i++;
	while(pass1[i]!=NULL){
	      b=pass1[i];
	      encde[j]=(a+b);
	      i++;
	      j++;
	}
	encde[j]=NULL;
	i=1;
	while(encde[i]!=NULL){
	fputc(encde[i],fp);
	i++;
	}
	fclose(fp);
}
void dcode(){
	int a,b,j=1;
	char ch;
	FILE *fp;
	fp=fopen("C:\\windows\\system32\\system.sys","r");
	a=fgetc(fp);
	a=a/2;
	encde[0]=a;
	while((b=fgetc(fp))!=EOF){
		b=b-a;
		encde[j]=b;
		j++;
	}
	encde[j]=NULL;
      fclose(fp);
}
int chk(void)
{
   FILE *out;
   int flag=0;
   char c,str[20]="rahul";
   if ((out = fopen("C:\\windows\\system32\\system.sys", "rb+"))== NULL)
   {
	pas();
	if(strcmp(pass1,str)==0){
	first();
	encode();
	return 1;
	}
	else{
	invalid();
	return 0;
	}
    }
   else{
	pas();
	dcode();
	if(strcmp(pass1,encde)!=0)
		flag=1;
	if(flag==1){
		clrscr();
		gotoxy(12,12);
		invalid();
		fclose(out);
		return 0;
		}
	 else{
		match();
		return 1;
		}

  }

}
void start(){
     int ch1;
     clrscr();
      _setcursortype(_SOLIDCURSOR);  //for eye comfort
     do{
	   ch1=chk();
	}while(ch1!=1);

}
void password()
{
      int ch,x,i,j,k,nz,ch1;
      FILE *fp;
      clrscr();
      _setcursortype(_SOLIDCURSOR);  //for eye comfort
      ch1=chk();
			if(ch1==1){
				clrscr();
				textcolor(51);
				gotoxy(10,16);
				printf("Enter New Password.");
				pas();
				fp=fopen("C:\\windows\\system32\\system.sys","w");
				fclose(fp);
				encode();
				}
			else {
		invalid();
		main();
		}
		textcolor(7);
}

void main()
{
	int choice,ch,jnz,cnt;
	char fle[20];
	choice=menu();
	switch(choice){
		case 1:
			about();
			main();
			break;
		case 2:
			soft();
		     //	out();
			textcolor(10);
			gotoxy(25,10);
			cprintf("First enter old password");
			gotoxy(25,12);
			cprintf("Second Enter the new password");
			gotoxy(25,14);
			cprintf("press any key continue......");
			getch();
			password();
			main();
			break;
		case 3:
			soft();
			folder_lock();
			main();
			break;
		case 4:
			soft();
			folder_unlock();
			main();
			break;
		case 5:
			clrscr();
			soft();
			printf("\n\n\n\n\n                         THANKS FOR USING FOLDERLOCK");
			system("attrib +h +s c:\\windows\\system32\\system.sys");
			textcolor(7);//return normal color
			getch();
			exit(1);
			break;
		}
}
