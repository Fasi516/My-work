#include<stdio.h>
int main (){

	//declaring variable for total days worked 
	int num_days;
	
	//getting value from user
	printf("Enter number of days worked by employee: ");
	scanf("%d", &num_days);
	
	//declaring char variable to know type of employment
	char employee;
	
	//getting type of employee from user
	printf("Enter employee type (F-full time, P-part time & A-Adhoc): ");
	scanf(" %c", &employee);
	
	//declaring variable as per need
	double salary,tax,per_hour_rate,tax_deduct,net_payable;
	
	//if condition to check type & days for which employee worked
	if(employee =='F' && (num_days>=25 && num_days<=30)){
	
	//hourly rate for full time employee
	per_hour_rate=900;
	
	//tax for full time employee
	tax= 0.05;
		
	}
	//for partime employee
	else if(employee=='P' && (num_days>=15 && num_days<=24)){
	
	per_hour_rate=850;
	
	tax=0.07;
	
	}
	
	//for adhoc employee
	else if (employee=='A' && num_days>=15){
	
	per_hour_rate=600;
	
	tax =0.10;
	
	}
	
	//wrong type of employee entered
	else{
		
	printf("Invalid type of employee entered.");
		
	return 1;
		
	}
	
	//calculating salary 
	salary = num_days * 8 * per_hour_rate;
	printf("Salary of employee is:%.2f\n",salary);
	
	//calculating tax to be deduct from salary
	tax_deduct = salary * tax;
	printf("Tax deductions: %.2f\n",tax_deduct);
	
	//amount to be paid to employee after tax deduction
	net_payable = salary - tax_deduct;
	printf("Net payable amount is:%.2f\n",net_payable);

	
return 0;

}
