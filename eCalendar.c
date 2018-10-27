#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int DaySum[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *week[]= {};
char *Month[]={"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
char *ToDo[31][11]={""};

int sumt(int a){
	int year=0,i;
	year=(a-1900)*365;
	for(i=1900;i<a;i++){
		if(i%400==0){
			year++;
		}
		else if(i%100!=0&&i%4==0){
			year++;
		}
		else{
			year=year;
		}
	}
//	printf("\n%d\t\n", year);
	return year;
}

int sumb(int a){
	int month=0,i;
	for(i=0;i<a-1;i++){
		month=month+DaySum[i];
	}
//	printf("\n%d\t\n", month);
	return month;
}

int view(int a, int b, int c){
//	system("cls");
	int i,s;
	printf("\nMin\tSen\tSel\tRab\tKam\tJum\tSab\n\n");
	for(i=0;i<a;i++){
		printf("\t");
	}
	for(i=1;i<1+DaySum[b-1];i++){
		printf("%d\t",i);
		if((i+a)%7==0){
			printf("\n");
		}
	}
/*	FILE *f=fopen("todo.txt","r");
	while(fscanf(f,"%s",s)!=EOF){
		printf("Agenda: %s",s);
	}
	fclose(f);
*/	
	
}

int cek(){
	int hari, bulan, tahun, jml, year, month, day, awal, menu;
	printf("\nHari/Bulan/Tahun (dd/mm/yy): ");
	scanf("%d/%d/%d", &hari, &bulan , &tahun);
	printf("%d-%d-%d\n",hari, bulan, tahun);
	if(tahun%400==0||(tahun%4==0&&tahun%100!=0)&&bulan>2){
		DaySum[1]=29;
	}
	year=sumt(tahun);
	month=sumb(bulan);
	day=hari;
	jml=(year+month+day)%7;//Hari pada Tanggal input
	awal=(year+month+1)%7;//Awal Hari Tanggal Pertama
//	printf("\n%d\n", day);
//	printf("\n%d\n",jml);
//	printf("\n%d\n",awal);
	system("cls");
	printf("\n===================================================\n");
	printf("%s %d",Month[bulan-1],tahun);
	printf("\n===================================================\n");
	view(awal,bulan,tahun);
	
	printf("\n");
	system("pause");
}

int help(){
	system("cls");
	printf("Help\n\n");
	printf("\tProgram ini adalah program yang digunakan untuk menampilkan kalender\n");
	printf(" satu bulan penuh sesuai input yang dmasukkan.");
	printf(" Program ini juga digunakan untuk\n memasukkan agenda di suatu tanggal,");
	printf(" bulan,tahun tertentu sesuai input");
	printf(" Program\n ini dapat menampilkan tanggal pada hari ini dan waktu tertentu.\n\n");
	printf(" \tInput program memiliki format yaitu hari/bulan/tahun yang berupa integer\n");
	printf(" Kesalahan input dapat menyebabkan hasil yang tidak sesuai.");
	printf("\n\n");
	system("pause");
	
}

int now(){
	int year,month,day,awal;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	tm.tm_year =tm.tm_year + 1900;
	tm.tm_mon= tm.tm_mon +1;
	if(tm.tm_year%400==0||(tm.tm_year%4==0&&tm.tm_year%100!=0)&&tm.tm_mon>2){
		DaySum[1]=29;
	}
	year=sumt(tm.tm_year);
	month=sumb(tm.tm_mon);
	day=tm.tm_mday;
//	jml=year+month+day;//Hari pada Tanggal input
	awal=(year+month+1)%7;//Awal Hari Tanggal Pertama
//	printf("\n%d\n", day);
//	printf("\n%d\n",jml);
//	printf("\n%d\n",awal);
	system("cls");
	printf("\n===================================================\n");
	printf("%d-%d-%d %d:%d:%d", tm.tm_year, tm.tm_mon , tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("\n===================================================\n");
	view(awal,tm.tm_mon,tm.tm_year);
	printf("\n\n");
	system("pause");
	

	
}
int main(){
	int x,menu;
	printf("\teCalendar\n");
	while(0==0){
		printf("\n\tMenu:\n1. Cek Hari ini\n2. Cek Tanggal tertentu\n3. Help\n4. Keluar Program\nInput: ");
		scanf("%c",&menu);
		switch(menu){
			case '1': now(); system("cls"); break;
			case '2': cek(); system("cls"); break;
			case '3': help(); system("cls"); break;
			case '4': goto out; break;
			default: printf("\nInput Anda Salah. Coba Lagi.\n"); break;
		}
		fflush(stdin);
/*		if(menu=='1'){
			cek();
		}
		else if(menu=='2'){
			edit();
		}
		else if(menu=='3'){
			help();
		}
		else if(menu=='0'){
			break;
		}
		else{
			printf("\nInput anda kesalahan. Coba lagi.\n");
		}
		*/
	}	
	out: 
	return 0;	
}
