#include<stdio.h>
int main (){
	
	//declaring amount variable 
	int amount;
	
	//getting value of amount from user
	printf("Enter amount to withdraw: ");
	scanf("%d",&amount);
	
	//applying condition as given
	if(amount >= 500 && amount <= 50000 && amount % 500 == 0){
	
	//for 5000 notes
	int notes_5000 =  amount/5000;
		
	printf("Notes of 5000: %d\n",notes_5000);	

	//for 1000 notes
	int remaining_amount=amount % 5000;
	int notes_1000 =  (remaining_amount/1000);

	printf("Notes of 1000: %d\n",notes_1000);
	
	//for 500 notes
	int  remaining_after_1000=(remaining_amount%1000);	
	int notes_500 =(remaining_after_1000/500);
		
	printf("notes of 500: %d\n",notes_500);	
	
	}
	
	//else block if user exceeds the limit
	else {
	
	printf("Invalid amount withdraw limit is 50000.");
	
	}
	
return 0;

}
