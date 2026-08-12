#include<stdio.h>
#include<string.h>
char data[20][20];
int n;
int main(){
	int i , j , ch;
	char temp[20][20];
	printf("enter the number of frames:");
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		printf("frame %d :",i);
		fgets(data[i],sizeof(data[i]),stdin);
		data[i][strcspn(data[i],"\n")] = '\0';
	}
	for(i=1;i<=n;i++){
		int len = strlen(data[i]);
		temp[i][0] = len+'0';
		temp[i][1] = '\0';
		strcat(temp[i] , data[i]);
	}
	printf("\n\t\t At rhe sender : \n");
	printf("data as frames :\n");
	for(i=1;i<=n;i++){
		printf("frame %d :",i);
		puts(temp[i]);
	}
	printf("data transmitted :");
	for(i=1;i<=n;i++){	
		printf("%s",temp[i]);
	}
	printf("\n\n\t at the receiver : \n");
	printf("the data received :");
	for(i=1;i<=n;i++){
		ch = temp[i][0]-'0';
		for(j=0;j<ch;j++){
			data[i][j] =temp[i][j+1];
		}
		data[i][j] = '\0';
	}
	printf("\n data after removing count count characters :\n");
	for(i=1;i<=n;i++){
		printf("frame %d:",i);
		puts(data[i]);
	}
	return 0 ;
}
