//Tic Tac Toe
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int i, j, z=0, d=0,e=1,f=2, m=0,n=1,win=0,player,replay;
char a[5], b[5], c[5], p[5], name1[50], name2[50], dname[50]="Computer";
void wingame(){
	for(i=0;i<3;i++){
		if(a[i]=='X' && b[i]=='X' && c[i]=='X'){
			win=1;
		}else if(a[i]=='O' && b[i]=='O' && c[i]=='O'){
			win=2;
		}
	   }
	   if(a[0]=='X' && a[1]=='X' && a[2]=='X'){
		win=1;
	   }else if(a[0]=='O' && a[1]=='O' && a[2]=='O'){
		win=2;
	   }
	   if(b[0]=='X' && b[1]=='X' && b[2]=='X'){
		win=1;
	   }else if(b[0]=='O' && b[1]=='O' && b[2]=='O'){
		win=2;
	   }
	   if(c[0]=='X' && c[1]=='X' && c[2]=='X'){
		win=1;
	   }else if(c[0]=='O' && c[1]=='O' && c[2]=='O'){
		win=2;
	   }
	   if(a[0]=='X' && b[1]=='X' && c[2]=='X'){
		win=1;
	   }else if(a[0]=='O' && b[1]=='O' && c[2]=='O'){
		win=2;
	   }
	   if(a[2]=='X' && b[1]=='X' && c[0]=='X'){
		win=1;
	   }else if(a[2]=='O' && b[1]=='O' && c[0]=='O'){
		win=2;
	   }
}

void structure(){
	printf("\tTic Tac Toe\n\n");
	printf("\tPlayer1:%s\tPlayer2:%s",name1,name2);
	printf("\n\n\n    |   1   |   2   |   3   |");
	printf("\n_____________________________");
	printf("\n    |       |       |       |");
	printf("\n 1  |   %c   |   %c   |   %c   |",a[d],a[e],a[f]);
	printf("\n    |       |       |       |");
	printf("\n_____________________________");
	printf("\n    |       |       |       |");
	printf("\n 2  |   %c   |   %c   |   %c   |",b[d],b[e],b[f]);
	printf("\n    |       |       |       |");
	printf("\n_____________________________");
	printf("\n    |       |       |       |");
	printf("\n 3  |   %c   |   %c   |   %c   |",c[d],c[e],c[f]);
	printf("\n    |       |       |       |");
	printf("\n_____________________________");
}
void invalid(){
	if(z%2==0 && player==1){
		printf("\nInvalid Input");
		getch();
	}
	if(player==2){
		printf("\nInvalid Input");
		getch();
	}
}

inline void clr(){
	system("cls");
}

int main()
{
	start:
	clr();
	printf("\tTic Tac Toe\n\n");
	printf("Select the type of game:\n1 Single Player \n2 Two Player\n3 End Game");
	printf("\nPlease enter your choice:");
	scanf("%d",&player);
	if(player==3){
		goto end;
	}else if(player!=1 || player!=2) {
		printf("\n\tInvalid Opti");
		Sleep(2000);
		goto start;
	}
	clr();
	printf("\tTic Tac Toe");
	printf("\nEnter the name of player1:");
	scanf("%s",&name1);
	if(player==1){
		strcpy(name2,dname);
	}else{
		printf("Enter the name of player2:");
		scanf("%s",&name2);
	}
	clr();
	do{
	input:
	clr();
	structure();
	if(z%2==0)
	{
		p[1]='X';
		printf("\n\tTurn of Player1");
	}else{
		p[1]='O';
		printf("\n\tTurn of Player2");
	}
	if(z%2!=0 && player==1){
		i=rand()%3+1;
		j=rand()%3+1;
	}else{
	printf("\n\nEnter the number of row:");
	scanf("%d",&i);
	printf("\nEnter the number of column:");
	scanf("%d",&j);
	}
	switch (i)
	{
		case 1:
		switch (j)
		{
			case 1:
			if(a[0]!=NULL){
				invalid();
				goto input;
				}
			a[0]=p[1];
			break;
			case 2:
			if(a[1]!=NULL){
				invalid();
				goto input;
				}
			a[1]=p[1];
			break;
			case 3:
			if(a[2]!=NULL){
				invalid();
				goto input;
				}
			a[2]=p[1];
			break;
			default:
			printf("\n Invalid");
			goto input;
		}
		break;

		case 2:
		switch (j)
		{
			case 1:
			if(b[0]!=NULL){
				invalid();
				goto input;
				}
			b[0]=p[1];
			break;
			case 2:
			if(b[1]!=NULL){
				invalid();
				goto input;
				}
			b[1]=p[1];
			break;
			case 3:
			if(b[2]!=NULL){
				invalid();
				goto input;
				}
			b[2]=p[1];
			break;
			default:
			printf("\n Invalid");
			goto input;
		}
		break;

		case 3:
		switch (j)
		{
			case 1:
			if(c[0]!=NULL){
				invalid();
				goto input;
				}
			c[0]=p[1];
			break;
			case 2:
			if(c[1]!=NULL){
				invalid();
				goto input;
				}
			c[1]=p[1];
			break;
			case 3:
			if(c[2]!=NULL){
				invalid();
				goto input;
				}
			c[2]=p[1];
			break;
			default:
			printf("\n Invalid");
			goto input;
		}
		break;

		default:
		printf("\n Invalid");
		goto input;
	}
	z++;
	wingame();
	if(win==1 || win==2){
		goto out;
	}
	}while(z<9);
	out:
	clr();
	structure();
	if(win==1){
		printf("\n\n\t%s wins",name1);
	}else if(win==2){
		printf("\n\n\t%s wins",name2);
	}
	else{
		printf("\n\n\tDraw");
	}
	if(player==3)
	{
		end:
		printf("\nGame Ended");
	}
	return 0;
}