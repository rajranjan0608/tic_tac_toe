#include<stdio.h>
#include <term.h>

char p1[100], p2[100];


void toUpper(char s[]){
	
	int i;

	for (i = 0; s[i]!='\0'; i++) {
		if(s[i] >= 'a' && s[i]<='z') {
         	s[i] = s[i] - 32;
      		}
	}
}


void print(char a[][3]){
	
	int i,j;
		
	printf("  %d %d %d\n",1,2,3);

	for(i=0;i<3;i++){
		printf("%d",i+1);
		for(j=0;j<3;j++){
			printf("|%c",a[i][j]);
			if((j+1)%3==0){
				printf("|\n");
			}
		}
	}
}


void player1(char a[][3]){
	
	int x,y,r,c;	printf("\n%s (O) ENTER CORDINATES: ",p1);	scanf("%d %d",&r,&c);

	x=r-1;	y=c-1;

	if(a[x][y]==' '){
		a[x][y]='O';
		printf("\n");
	}
	else{
		printf("SORRY, THAT PLACE IS ALREADY FILLED, ENTER AGAIN\n\n");
		player1(a);
	}
}

void player2(char a[][3]){
	
	int x,y,r,c;	printf("\n%s (X) ENTER CORDINATES: ",p2);	scanf("%d %d",&r,&c);

	x=r-1;	y=c-1;

	if(a[x][y]==' '){
		a[x][y]='X';
		printf("\n");
	}
	else{
		printf("SORRY, THAT PLACE IS ALREADY FILLED, ENTER AGAIN\n\n");
		player2(a);
	}

	
	
}

int horizontal(char a[][3]){
	
	int i;

	for(i=0;i<3;i++){
		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]){

			if(a[i][0]=='O'){
				printf("\n%s (O)  WINS\n\n",p1);
				return 1;
			}
			else if(a[i][0]=='X'){
				printf("\n%s (X)  WINS\n\n",p2);
				return 1;
			}
		}
	}
	return 0;
}

int vertical(char a[][3]){
	
	int i;

	for(i=0;i<3;i++){
		if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]){

			if(a[0][i]=='O'){
				printf("\n%s (O)  WINS\n\n",p1);
				return 1;
			}
			else if(a[0][i]=='X'){
				printf("\n%s (X)  WINS\n\n",p2);
				return 1;
			}
		}
	}
	return 0;
}

int diagonal(char a[][3]){

	if(  ((a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]=='O')||(a[0][2]==a[1][1]&&a[1][1]==a[2][0])&&a[0][2]=='O')  ||  (a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]=='X')||(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[0][2]=='X')   ){

		if(a[0][0]=='O'||a[0][2]=='O'){
			printf("\n%s (0) WINS\n\n",p1);
			return 1;
		}
		else if(a[0][0]=='X'||a[0][2]=='X'){
			printf("\n%s (X) WINS\n\n",p2);
			return 1;
		}
	}

	else{
		return 0;
	}
}
	
int main(){
	
	char a[3][3];
	int i,j;

	printf("\nENTER PLAYER 1 NAME: ");	scanf("%s",p1);		
	printf("\nENTER PLAYER 2 NAME: ");	scanf("%s",p2);
	printf("\n\n");

	toUpper(p1);	toUpper(p2);	

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			a[i][j]=' ';
		}
	}

	print(a);

	int chance;

	for(chance=0;chance<9;chance++){

		if(chance%2==0){
			player1(a);
			print(a);
		}
		else{
			player2(a);
			print(a);
		}
		
		if(horizontal(a)==1||vertical(a)==1||diagonal(a)==1){
			break;
		}
		
	}
}
