#include<stdio.h>
int main (){
	
	//declaring 2 number variables 
	int  num_1,num_2;
	
	//user-defined value of variable
	printf("Enter two numbers from the grid: ");
	scanf("%d %d",&num_1,&num_2);
	
	//conditions to check if color of squares are same
	if((num_1 + num_2) % 2 == 0 ){
	
	printf("Both squares in grid have same color.\n");
		
	}
	
	//else block so that colors of squares doesn't match
	else{
	
	printf("Both squares are different in color.\n");
	
	}	
	
return 0;
}
