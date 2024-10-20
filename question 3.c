#include<stdio.h>
int main (){

	//declaring varible for eggs
	int total_eggs;
	
	//getting value of eggs from user
	printf("Enter number of total eggs: ");
	scanf("%d",&total_eggs);
	
	//to check if eggs are negative value
	if(total_eggs < 0){
	
	//incorrect input , as if value of  eggs is negative
	printf("Invalid input.");

	return 1;
				
	}
	//declaring var according to size of packing
	int packing_size_30,packing_size_24,packing_size_18,packing_size_12,packing_size_6;
	
	//for 30 eggs packing
	packing_size_30 =total_eggs/30;
	int left_eggs_30=total_eggs-(packing_size_30*30);
	
	printf("Number of 30 eggs packing:%d\n",packing_size_30);
	printf("Number of leftover eggs:%d\n",left_eggs_30);
	
	//for 24 egggs packing
	packing_size_24 =total_eggs/24 ;
	int left_eggs_24=total_eggs-(packing_size_24*24);
	
	printf("Number of 24 eggs packing:%d\n",packing_size_24);
	printf("Number of leftover eggs:%d\n",left_eggs_24);
	
	//for 18 eggs packing
	packing_size_18 =total_eggs/18;
	int left_eggs_18=total_eggs-(packing_size_18*18);
	

	printf("Number of 18 eggs packing:%d\n",packing_size_18);
	printf("Number of leftover eggs:%d\n",left_eggs_18);
	
	//for 12 eggs packing	
	packing_size_12 =total_eggs/12;
	int left_eggs_12=total_eggs-(packing_size_12*12);
	
	printf("Number of 12 eggs packing:%d\n",packing_size_12);
	printf("Number of leftover egg:%d\n",left_eggs_12);
	
	//for 6 eggs packing
	packing_size_6  =total_eggs/6;
	int left_eggs_6=total_eggs-(packing_size_6*6);

	printf("Number of 6 eggs packing:%d\n",packing_size_6);
	printf("Number of lefover eggs:%d\n",left_eggs_6);	

	//checking which of the packing is more precise

	if(packing_size_30 <= packing_size_24 && packing_size_30 <= packing_size_18 && packing_size_30<=packing_size_12 && packing_size_30 <=packing_size_6){

	printf("30 eggs packing is more appropriate.");

	}
	
	else if(packing_size_24 <= packing_size_18 && packing_size_24 <= packing_size_12 && packing_size_24<=packing_size_6 ){
	
	printf("24 eggs packing is more appropriate.");
	
	}
	
	else if(packing_size_18 <= packing_size_12 && packing_size_18 <= packing_size_6 ){
	
		printf("18 eggs packing is more appropriate.");
	
	}
	
	else if(packing_size_12 <= packing_size_6 ){
	
	printf("12 eggs packing is more appropriate.");
	
	}
	
	else{
	
	printf("6 eggs packing is more appropriate.");
	
	}

return 0;

}
