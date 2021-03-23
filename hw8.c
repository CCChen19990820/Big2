#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int arr[13][4];
int temp,h=0;
char asc;
int open=0;
int number;
char suit;
int a=0,b=0,c=0,d=0,e=0;
void tonumber(char *word);
void out(int temp);
void in(int number);
int main(void){
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			arr[j][i]=0;
		}
	}
	struct ya{
		char f;
		char n;
		char ten;
		int face;
		int num;
	}card[13];
	for(int i=0;i<13;i++){
		scanf("%c%c%c",&card[i].f,&card[i].n,&card[i].ten);
		if(card[i].ten=='0'){
			scanf(" ");
		}
		switch(card[i].n){
			case 'A':
				card[i].num=1;
				break;
			case '2':
				card[i].num=2;
				break;
			case '3':
				card[i].num=3;
				break;
			case '4':
				card[i].num=4;	
				break;
			case '5':
				card[i].num=5;
				break;
			case '6':
				card[i].num=6;
				break;
			case '7':
				card[i].num=7;
				break;
			case '8':
				card[i].num=8;
				break;
			case '9':
				card[i].num=9;
				break;
			case '1':
				card[i].num=10;
				break;
			case 'J':
				card[i].num=11;
				break;
			case 'Q':
				card[i].num=12;
				break;
			case 'K':
				card[i].num=13;
				break;
		}
	}
	for(int i=0;i<13;i++){
		tonumber(&card[i].f);
		//		printf("%d\n",card[i].f);
		if(card[i].f==0){
			arr[card[i].num-1][0]=1;
		}
		if(card[i].f==1){
			arr[card[i].num-1][1]=1;
		}
		if(card[i].f==2){
			arr[card[i].num-1][2]=1;
		}
		if(card[i].f==3){
			arr[card[i].num-1][3]=1;
		}
	}
	/*	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
		printf("%d ",arr[j][i]); 
		}
		printf("\n");
		}*/

	//¦Pªá¶¶
	for(int i=0;i<4;i++){
		if(arr[1][i]==1&&arr[2][i]==1&&arr[3][i]==1&&arr[4][i]==1&&arr[5][i]==1){
			temp=i;
			out(temp);
			printf("%c2 %c3 %c4 %c5 %c6\n",asc,asc,asc,asc,asc);
			for(int j=1;j<6;j++){
				arr[j][i]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		if(arr[9][i]==1&&arr[10][i]==1&&arr[11][i]==1&&arr[12][i]==1&&arr[0][i]==1){
			temp=i;
			out(temp);
			printf("%c10 %cJ %cQ %cK %cA\n",asc,asc,asc,asc,asc);
			for(int j=9;j<13;j++){
				arr[j][i]=0;
			}
			arr[0][i]=0;
		}
	}
	for(int i=8;i>1;i--){
		if(arr[i][0]==1&&arr[i+1][0]==1&&arr[i+2][0]==1&&arr[i+3][0]==1&&arr[i+4][0]==1){
			number=i;
			for(int j=0;j<5;j++){
				if(number<=10){
					printf("S%d",number+j);
				}
				if(number>9){
					in(number+j);
					printf("S%c",suit);
				}
				if(j!=4){
					printf(" ");
				}
				if(j==4){
					printf("\n");
				}
				for(int j=i;j<i+5;j++){
					arr[j][0]=0;
				}
			}
		}
		if(arr[i][1]==1&&arr[i+1][1]==1&&arr[i+2][1]==1&&arr[i+3][1]==1&&arr[i+4][1]==1){
			number=i;
			for(int j=0;j<5;j++){
				if(number<=10){
					printf("H%d",number+j);
				}
				if(number>9){
					in(number+j);
					printf("H%c",suit);
				}
				if(j!=4){
					printf(" ");
				}
				if(j==4){
					printf("\n");
				}
			}
			for(int j=i;j<i+5;j++){
				arr[j][1]=0;
			}
		}
		if(arr[i][2]==1&&arr[i+1][2]==2&&arr[i+2][2]==1&&arr[i+3][2]==1&&arr[i+4][2]==1){
			number=i;
			for(int j=0;j<5;j++){
				if(number<=10){
					printf("D%d",number+j);
				}
				if(number>9){
					in(number+j);
					printf("D%c",suit);
				}
				if(j!=4){
					printf(" ");
				}
				if(j==4){
					printf("\n");
				}
			}
			for(int j=i;j<i+5;j++){
				arr[j][2]=0;
			}
		}
		if(arr[i][3]==1&&arr[i+1][3]==1&&arr[i+2][3]==1&&arr[i+3][3]==1&&arr[i+4][3]==1){
			number=i;
			for(int j=0;j<5;j++){
				if(number<=10){
					printf("C%d",number+j);
				}
				if(number>9){
					in(number+j);
					printf("C%c",suit);
				}
				if(j!=4){
					printf(" ");
				}
				if(j==4){
					printf("\n");
				}
			}
			for(int j=i;j<i+5;j++){
				arr[j][3]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		if(arr[0][i]==1&&arr[1][i]==1&&arr[2][i]==1&&arr[3][i]==1&&arr[4][i]==1){
			temp=i;
			out(temp);
			printf("%cA %c2 %c3 %c4 %c5\n",asc,asc,asc,asc,asc);
			for(int j=0;j<5;j++){
				arr[j][i]=0;
			}
		}
	}
	//ÅK¤ä
	if(arr[1][0]==1&&arr[1][1]==1&&arr[1][2]==1&&arr[1][3]==1){
		printf("S2 H2 D2 C2 ");
		open=1;
		for(int i=0;i<4;i++){
			arr[1][i]=0;
		}
		while(open==1){
			for(int i=2;i<13;i++){
				for(int j=3;j>=0;j--){
					if(arr[i][j]==1&&open==1){
						temp=j;
						out(temp);
						//	printf("open=%d\n",open);
						if(i<10){
							printf("%c%d\n",asc,i+1);	
						}
						if(i>9){
							number=i+1;
							in(number);
							printf("%c%c\n",asc,suit);	
						}
						open=0;
						arr[i][j]=0;
						//	printf("open1=%d\n",open);
						continue;
					}
				}
			}
			for(int i=3;i>=0;i--){
				if(arr[0][i]==1&&open==1){
					temp=i;
					out(temp);
					printf("%cA\n",asc);
					arr[0][i]=0;
					open=0;
					continue;
				}
			}
		}
	}
	if(arr[0][0]==1&&arr[0][1]==1&&arr[0][2]==1&&arr[0][3]==1){
		printf("SA HA DA CA ");
		open=1;
		for(int i=0;i<4;i++){
			arr[0][i]=0;
		}
		while(open==1){
			for(int i=2;i<13;i++){
				for(int j=3;j>=0;j--){
					if(arr[i][j]==1&&open==1){
						temp=j;
						out(temp);
						if(i<10){
							printf("%c%d\n",asc,i+1);	
						}
						if(i>9){
							number=i+1;
							in(number);
							printf("%c%c\n",asc,suit);	
						}
						arr[i][j]=0;
						open=0;
						continue;;
					}
				}
			}
			for(int i=3;i>=0;i--){
				if(arr[1][i]==1&&open==1){
					temp=i;
					out(temp);
					printf("%c2\n",asc);
					arr[1][i]=0;
					open=0;
					continue;
				}
			}
		}
	}
	for(int i=12;i>1;i--){
		if(arr[i][0]==1&&arr[i][1]==1&&arr[i][2]==1&&arr[i][3]==1){
			if(i>9){
				number=i;
				in(number);
				printf("S%d H%d D%d C%d ",suit,suit,suit,suit);
			}
			else{
				printf("S%d H%d D%d C%d ",i+1,i+1,i+1,i+1);
			}
			open++;
			for(int j=0;j<4;j++){
				arr[i][j]=0;
			}
			while(open!=0){
				for(int j=2;j<13;j++){
					for(int k=3;k>=0;k--){
						if(arr[j][k]==1&&open==1){
							temp=k;
							out(temp);
							if(j<10){
								printf("%c%d\n",asc,j+1);	
							}
							if(j>9){
								number=j+1;
								in(number);
								printf("%c%c\n",asc,suit);	
							}
							arr[j][k]=0;
							open=0;
						}
					}
				}
				continue;
				for(int k=0;k<2;k++){
					for(int j=3;j>=0;j--){
						if(arr[k][j]==1&&open==1){
							temp=j;
							out(temp);
							printf("%c%d\n",asc,k);
							arr[k][j]=0;
							open=0;
						}
					}
				}
			}
		}
	}
	/*	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
		printf("%d ",arr[j][i]); 
		}
		printf("\n");
		}*/
	//¸¬Äª
	if(arr[1][0]+arr[1][1]+arr[1][2]+arr[1][3]==3){
		for(int i=2;i<13;i++){
			open=0;
			if(arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]>=2&&arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]<=5){
				for(int j=0;j<4;j++){
					if(arr[1][j]==1){
						temp=j;
						out(temp);
						printf("%c2 ",asc);
					}
					arr[1][j]=0;
				}
				for(int j=3;j>=0;j--){
					if(arr[i][j]==1&open<2){
						arr[i][j]=2;
						open++;
					}
				}
				for(int j=0;j<4;j++){
					if(arr[i][j]==2){
						temp=j;
						out(temp);
						if(i<10){
							printf("%c%d",asc,i+1);
						}
						if(i>9){
							number=i+1;
							in(number);
							printf("%c%c",asc,suit);
						}
						h++;
						if(h!=2){
							printf(" ");
						}
						if(h==2){
							printf("\n");
						}
						arr[i][j]=0;
					}
				}
				break;;
			}
			else if(arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]<2&&i==12){
				if(arr[0][0]+arr[0][1]+arr[0][2]+arr[0][3]>=2){
					for(int j=0;j<4;j++){
						if(arr[1][j]==1){
							temp=j;
							out(temp);
							printf("%c2 ",asc);
							arr[1][j]=0;
						}
					}
					open=0;
					for(int k=3;k>=0;k--){
						if(arr[0][k]==1&&open<2){
							arr[0][k]=2;
							open++;
						}
					}
					h=0;
					for(int k=0;k<4;k++){
						if(arr[0][k]==2){
							temp=k;
							out(temp);	
							printf("%cA",asc);
							h++;
							if(h!=2){
								printf(" ");
							}
							if(h==2){
								printf("\n");
							}
							arr[0][k]=0;
						}
					}
					break;
				}
			}
		}
	}
	if(arr[0][0]+arr[0][1]+arr[0][2]+arr[0][3]==3){
		for(int i=2;i<13;i++){
			open=0;
			if(arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]>=2&&arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]<=5){
				for(int j=0;j<4;j++){
					if(arr[0][j]==1){
						temp=j;
						out(temp);
						printf("%cA ",asc);
					}
					arr[0][j]=0;
				}
				for(int j=3;j>=0;j--){
					if(arr[i][j]==1&open<2){
						arr[i][j]=2;
						open++;
					}
				}
				h=0;
				for(int j=0;j<4;j++){
					if(arr[i][j]==2){
						temp=j;
						out(temp);
						if(i<10){
							printf("%c%d",asc,i+1);
						}
						if(i>9){
							number=i+1;
							in(number);
							printf("%c%c",asc,suit);
						}
						h++;
						if(h!=2){
							printf(" ");
						}
						if(h==2){
							printf("\n");
						}
						arr[i][j]=0;
					}
				}
				break;
			}
			if(arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]<2&&i==12){
				if(arr[1][0]+arr[1][1]+arr[1][2]+arr[1][3]>=2){
					for(int j=0;j<4;j++){
						if(arr[0][j]==1){
							temp=j;
							out(temp);
							printf("%cA ",asc);
							arr[0][j]=0;
						}
					}
					open=0;
					for(int k=3;k>=0;k--){
						if(arr[1][k]==1&&open<2){
							arr[1][k]=2;
							open++;
						}
					}
					h=0;
					for(int k=0;k<4;k++){
						if(arr[1][k]==2){
							temp=k;
							out(temp);	
							printf("%c2",asc);
							h++;
							if(h!=2){
								printf(" ");
							}
							if(h==2){
								printf("\n");
							}
							arr[1][k]=0;
						}
					}
					break;
				}
			}
		}
	}
	for(int g=12;g>1;g--){
		if(arr[g][0]+arr[g][1]+arr[g][2]+arr[g][3]==3){
			for(int i=2;i<13;i++){
				open=0;
				if(i!=g&&arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]>=2&&arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]<=5){
					//		printf("haha\n");
					for(int j=0;j<4;j++){
						if(arr[g][j]==1){
							//				printf("haha\n");
							temp=j;
							out(temp);
							if(g<10){
								printf("%c%d ",asc,g+1);
							}
							if(g>9){
								number=g+1;
								in(number);
								printf("%c%c ",asc,suit);
							}
							arr[g][j]=0;
						}
					}
					for(int j=3;j>=0;j--){
						if(open<2&&arr[i][j]==1){
							arr[i][j]=2;
							open++;
						}
					}
					h=0;
					for(int j=0;j<4;j++){
						if(arr[i][j]==2){
							temp=j;
							out(temp);
							if(i<10){
								printf("%c%d",asc,i+1);
							}
							else{
								number=i;
								in(number);
								printf("%c%c",asc,suit);
							}
							h++;
							if(h!=2){
								printf(" ");
							}
							if(h==2){
								printf("\n");
							}
							arr[i][j]=0;
						}
					}
					break;
				}
				else if(i==12&&i!=g){
					for(int l=0;l<2;l++){
						if(arr[l][0]+arr[l][1]+arr[l][2]+arr[l][3]>=2&&arr[l][0]+arr[l][1]+arr[l][2]+arr[l][3]<=5){
							for(int j=0;j<4;j++){
								if(arr[l][j]==1){
									temp=j;
									number=l;
									in(number);
									out(temp);
									printf("%c%c ",asc,suit);
									arr[l][j]=0;
								}
							}
							open=0;
							for(int k=3;k>=0;k--){
								if(arr[l][k]==1&&open<2){
									arr[l][k]=2;
									open++;
								}
							}
							for(int k=0;k<4;k++){
								if(arr[l][k]==2){
									temp=k;
									out(temp);
									if(l==0){
										number=l+1;
										in(number);
										printf("%c%c",asc,suit);
									}
									if(l==1){
										printf("%c%d",asc,i+1);
									}
									h++;
									if(h!=2){
										printf(" ");
									}
									if(h==2){
										printf("\n");
									}
									arr[l][k]=0;
								}
							}
						}
					}
				}
			}
		}
	}
	//¶¶¤l
	for(int i=0;i<4;i++){
		a+=arr[1][i];
	}
	for(int i=0;i<4;i++){
		b+=arr[2][i];
	}
	for(int i=0;i<4;i++){
		c+=arr[3][i];
	}
	for(int i=0;i<4;i++){
		d+=arr[4][i];
	}
	for(int i=0;i<4;i++){
		e+=arr[5][i];
	}
	if(a>0&&b>0&&c>0&&d>0&&e>0){
		for(int i=0;i<4;i++){
			if(arr[1][i]==1){
				temp=i;
				out(temp);
				printf("%c2 ",asc);
				arr[1][i]=0;
				break;
			}
		}
		for(int j=2;j<6;j++){
			for(int i=0;i<4;i++){
				if(arr[j][i]==1){
					temp=i;
					out(temp);
					if(j!=5){
						printf("%c%d ",asc,j+1);
					}
					if(j==5){
						printf("%c%d\n",asc,j+1);
					}
					arr[j][i]=0;
					break;
				}
			}
		}
	}
	a=0;
	b=0;
	c=0;
	d=0;
	e=0;
	for(int i=0;i<4;i++){
		a+=arr[9][i];
	}
	for(int i=0;i<4;i++){
		b+=arr[10][i];
	}
	for(int i=0;i<4;i++){
		c+=arr[11][i];
	}
	for(int i=0;i<4;i++){
		d+=arr[12][i];
	}
	for(int i=0;i<4;i++){
		e+=arr[0][i];
	}
	if(a>0&&b>0&&c>0&&d>0&&e>0){
		for(int j=9;j<13;j++){
			for(int i=0;i<4;i++){
				if(arr[j][i]==1){
					temp=i;
					out(temp);
					if(j<10){
						printf("%c%d ",asc,j+1);
					}
					if(j>9){
						number=j+1;
						in(number);
						printf("%c%c ",asc,suit);
					}
					arr[j][i]=0;
					break;
				}
			}
		}
		for(int i=0;i<4;i++){
			if(arr[0][i]==1){
				temp=i;
				out(temp);
				printf("%cA\n",asc);
				arr[1][i]=0;
				break;
			}
		}
	}
	for(int k=8;k>1;k--){
		a=0;
		b=0;
		c=0;
		d=0;
		e=0;
		for(int i=0;i<4;i++){
			a+=arr[k][i];
		}
		for(int i=0;i<4;i++){
			b+=arr[k+1][i];
		}
		for(int i=0;i<4;i++){
			c+=arr[k+2][i];
		}
		for(int i=0;i<4;i++){
			d+=arr[k+3][i];
		}
		for(int i=0;i<4;i++){
			e+=arr[k+4][i];
		}
		if(a>0&&b>0&&c>0&&d>0&&e>0){
			for(int j=k;j<k+4;j++){
				for(int i=0;i<4;i++){
					if(arr[j][i]==1){
						temp=i;
						out(temp);
						if(j<10){
							printf("%c%d ",asc,j+1);
						}
						else{
							number=j+1;
							in(number);
							printf("%c%c ",asc,suit);
						}
						arr[j][i]=0;
						break;
					}
				}
			}
			for(int i=0;i<4;i++){
				if(arr[k+4][i]==1){
					temp=i;
					out(temp);
					if(k+4<10){
						printf("%c%d\n",asc,k+5);
					}
					else{
						number=k+5;
						in(number);
						printf("%c%c\n",asc,suit);
						arr[k+4][i]=0;
						break;
					}
				}
			}
		}
	}
	a=0;
	b=0;
	c=0;
	d=0;
	e=0;
	for(int i=0;i<4;i++){
		a+=arr[0][i];
	}
	for(int i=0;i<4;i++){
		b+=arr[1][i];
	}
	for(int i=0;i<4;i++){
		c+=arr[2][i];
	}
	for(int i=0;i<4;i++){
		d+=arr[3][i];
	}
	for(int i=0;i<4;i++){
		e+=arr[4][i];
	}
	if(a>0&&b>0&&c>0&&d>0&&e>0){
		for(int j=0;j<4;j++){
			for(int i=0;i<4;i++){
				if(arr[j][i]==1){
					temp=i;
					out(temp);
					if(i<1){
						number=j+1;
						in(number);
						printf("%c%c ",asc,suit);
					}
					if(i>0){
						printf("%c%d ",asc,j+1);
					}
					arr[j][i]=0;
					break;
				}
			}
		}
		for(int i=0;i<4;i++){
			if(arr[4][i]==1){
				temp=i;
				out(temp);
				printf("%c5\n",asc);
				arr[4][i]=0;
				break;
			}
		}
	}

	//pairs
	for(int i=1;i>=0;i--){
		a=0,open=0;
		for(int j=0;j<4;j++){
			a+=arr[i][j];
		}
		if(a>1){
			for(int k=0;k<4;k++){
				if(arr[i][k]==1&&open<1){
					temp=k;
					out(temp);
					if(i==0){
						printf("%cA ",asc);
					}
					if(i==1){
						printf("%c2 ",asc);
					}
					open++;
					arr[i][k]=0;
				}
			}
			for(int k=3;k>=0;k--){
				if(arr[i][k]==1&&open<2){
					temp=k;
					out(temp);
					if(i==0){
						printf("%cA\n",asc);
					}
					if(i==1){
						printf("%c2\n",asc);
					}
					open++;
					arr[i][k]=0;
				}
			}
		}
	}
	for(int i=12;i>1;i--){
		a=0,open=0;
		for(int j=0;j<4;j++){
			a+=arr[i][j];
		}
		if(a>1){
			for(int k=0;k<4;k++){
				if(arr[i][k]==1&&open<1){
					temp=k;
					out(temp);
					if(i<10){
						printf("%c%d ",asc,i+1);
					}
					if(i>9){
						number=i+1;
						in(number);
						printf("%c%c ",asc,suit);
					}
					open++;
					arr[i][k]=0;
				}
			}
			for(int k=3;k>=0;k--){
				if(arr[i][k]==1&&open<2){
					temp=k;
					out(temp);
					if(i<10){
						printf("%c%d\n",asc,i+1);
					}
					if(i>9){
						number=i+1;
						in(number);
						printf("%c%c\n",asc,suit);
					}
					open++;
					arr[i][k]=0;
				}
			}
			open=0;
		}
	}
	//³æ±i
	for(int i=1;i>=0;i--){
		for(int j=0;j<4;j++){
			if(arr[i][j]==1){
				temp=j;
				out(temp);
				if(i==0){
					printf("%cA\n",asc);
				}
				else{
					printf("%c2\n",asc);
				}
				arr[i][j]=0;
			}
		}
	}
	for(int i=12;i>1;i--){
		for(int j=0;j<4;j++){
			if(arr[i][j]==1){
				temp=j;
				out(temp);
				if(i<10){
					printf("%c%d\n",asc,i+1);
				}
				else{
					number=i+1;
					in(number);
					printf("%c%c\n",asc,suit);
				}
				arr[i][j]=0;
			}
		}
	}
	/*	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
		printf("%d ",arr[j][i]); 
		}
		printf("\n");
		}*/
	return 0;
}

void tonumber(char *word){
	if(*word==83){
		*word-=83;
	}
	if(*word==72){
		*word-=71;
	}
	if(*word==68){
		*word-=66;
	}
	if(*word==67){
		*word-=64;
	}
}
void out(int temp){
	if(temp==0){
		asc='S';
	}
	if(temp==1){
		asc='H';
	}
	if(temp==2){
		asc='D';
	}
	if(temp==3){
		asc='C';
	}
}
void in(int number){
	switch(number){
		case 1:
			suit='A';
			break;
		case 11:
			suit='J';
			break;
		case 12:
			suit='Q';
			break;
		case 13:
			suit='K';
			break;
	}
}
