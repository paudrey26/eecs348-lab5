# include <stdio.h>
float sales[12];
char *monthNames[]={
	"January", "February", "March", "April", "May", "June", "July", "August",
	"September", "October","November","December"
};

void read_print_file(char *filename, char *monthNames[], float sales[], int numMonths){
	int monthIndex =0;
	FILE *file=fopen(filename,"r");
	printf("Monthly sales report for 2022: \n");
	printf("Month        Sales\n");
	
	for(int i=0; i<12; i++){
		fscanf(file, "%f", &sales[monthIndex]);
		monthIndex++;
	}
	int second_counter=0;
	for (int i=0;i<12; i++){
		printf("%-9s $%.2f\n", monthNames[second_counter], sales[second_counter]);
		second_counter++;
	}
	fclose(file);
}

void find_minimum(){
	float min_sales = sales[0];
	int least_sale_month=0;
	for (int i=0; i<12; i++){
		if (sales[i]<min_sales){
			min_sales=sales[i];
			least_sale_month=i;
		}
	}
	printf("\nSales Summary:");
	printf("\nMinimum Sales: %.2f (%s)\n", min_sales, monthNames[least_sale_month]);
		
}

void find_maximum(){
	float max_sales=sales[0];
	int most_sale_month=0;
	for (int i=0; i<12; i++){
		if (sales[i]>max_sales){
			max_sales=sales[i];
			most_sale_month=i;
		}
	}
	printf("Maximum Sales: %.2f (%s)\n", max_sales, monthNames[most_sale_month]);
}

void calculate_average(){
	float total=0;
	for (int i=5; i<12; i++){
		total+=sales[i];
	}
	printf("Average Sales: $%.2f\n", total/12);
}

void moving_average(){
	printf("\nSix-Month Moving Average Report\n");
	int i;
	float total;
	for (int i=5; i<12; i++){
		float total=0;
		for (int j= i-5; j<=i; j++)
			total+=sales[j];
		printf("%-9s - %-9s: $%.2f\n", monthNames[i-5], monthNames[i], total/6);
	}
	
}

void high_to_low(){
	printf("\nSales Report (Highest to Lowest): \n");
	printf("Month\tSales\n");
	float sortedSales[12];
	char* sortedMonths[12];
	int j;
	int i;
	for (i=0; i<12; i++){
		sortedSales[i]=sales[i];
		sortedMonths[i]=monthNames[i];
	}
	char* tempMonth;
	for(i=0; i<12-1; i++){
		for (int j=i+1; j<12; j++){
			if (sortedSales[i]<sortedSales[j]){
				double temp=sortedSales[i];
				sortedSales[i]=sortedSales[j];
				sortedSales[j]=temp;
				tempMonth=sortedMonths[i];
				sortedMonths[i]=sortedMonths[j];
				sortedMonths[j]=tempMonth;
			}
		}
	}
	for(i=0;i<12;i++){
		printf("%-9s $%.2f\n", sortedMonths[i], sortedSales[i]);
	}
}

int main (){
	char user_file[256];
	printf("Enter the name of the input file: ");
	scanf("%255s",user_file);
	read_print_file(user_file, monthNames, sales, 12);
	find_minimum();
	find_maximum();
	calculate_average();
	moving_average();
	high_to_low();
}