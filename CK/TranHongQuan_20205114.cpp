#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char ten[10][7][5], test[7][5];
float mocua[10][7], dongcua[10][7];
float giatri[7] = {}, s[7] = {};
int u = -1;

void sosanh(){
	printf("Thong tin ma chung khoan theo thu tu tang dan la: \n");
	char k[5];
	float h;
	for(int i = 0; i < 7; i++){
		for(int j = i+1; j < 7; j++){
			if(strcmp(test[i], test[j]) >= 0){
				strcpy(k, test[i]);
				strcpy(test[i], test[j]);
				strcpy(test[j], k);
				h = s[i];
				s[i] = s[j];
				s[j] = h;
			}
		}
	}
	
	for(int i = 0; i < 7; i++){
		printf("%s   %6.3f\n", test[i], s[i]);
	}
	printf("\n\n");
}

void sapxep(){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 7; k++){
				if(strcmp(ten[0][i], ten[j][k]) == 0) giatri[i] = giatri[i] + dongcua[j][k] - mocua[j][k];
			}
		}
	}

	for(int t = 0; t < 7; t++){
		s[t] = giatri[t]/10;
		strcpy(test[t], ten[0][t]);
	}
	sosanh();
	
}

void docfile(){
	u = 0;
	FILE* f;
	int n;
	f = fopen("data.txt", "r");
	fscanf(f, "%d", &n);
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 7; j++){
			fscanf(f, "%s", &ten[i][j]);
			fscanf(f, "%f", &mocua[i][j]);
			fscanf(f, "%f", &dongcua[i][j]);
		}
	}

	sapxep();
	fclose(f);
}

void timkiem(){
	if(u == -1){
		printf("Ban chua thuc hien chuc nang 1 !!!\n\n");
		return;
	}
	float m = 100, n = 0;
	char nhap[5];
	printf("Nhap ma chung khoan can tim kiem: ");
	scanf("%s", &nhap);
	int a = -1;
	for(int i = 0; i < 7; i++){
		if(strcmp(nhap, test[i]) == 0)	a++;
	}
	if(a == -1) {
		printf("Khong co ma chung khoan nay !\n\n");
		return;
	}else{
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
				if(strcmp(nhap, ten[i][j]) == 0){
					if(dongcua[i][j] < m)	m = dongcua[i][j];
					if(dongcua[i][j] > n)	n = dongcua[i][j];
				}
			}
		}
	}
	
	printf("Gia dong cua thap nhat la: %.2f\n", m);
	printf("Gia dong cua cao nhat la: %.2f\n\n", n);
}

void xuhuong(){
	int a[7] = {};
	if(u == -1){
		printf("Ban chua thuc hien chuc nang 1 !!!\n\n");
		return;
	}		
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 7; k++){
				if(strcmp(test[i], ten[j][k]) == 0){
					if(dongcua[j][k] - mocua[j][k] > 0)	a[i]++;
				}
			}
		}
	}
	
	printf("Cac ma chung khoan co xu huong tang la: \n");
	
	for(int i = 0; i < 7; i++){
		if(a[i] == 2)	printf("%s\n", test[i]);
	}
	printf("\n\n");
}

void timngaytang(){
	int a[7] = {};
	if(u == -1){
		printf("Ban chua thuc hien chuc nang 1 !!!\n\n");
		return;
	}		
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 7; k++){
				if(strcmp(test[i], ten[j][k]) == 0){
					if(dongcua[j][k] - mocua[j][k] > 0)	a[i]++;
				}
			}
		}
	}
	
	int l = 0;
	
	for(int i = 0; i < 7; i++){
		if(l < a[i])	l = a[i];
	}
	printf("Cac ma co so ngay tang lon nhat la: ");
	for(int i = 0; i < 7; i++){
		if(a[i] == l)	printf("\n%s", test[i]);
	}
	printf("\nCac ma nay co so ngay tang la: %d\n\n", l);
}

int main(){	
	while(5){
		int x;
		printf("**********************************************\n");
		printf("====Ban hay nhap chuc nang can thuc hien====\n");
		printf("1) Doc File\n");
		printf("2) Tim kiem theo ma chung khoan\n");
		printf("3) Tim kiem nhung ma chung khoan co xu huong tang\n");
		printf("4) Tim ma co so ngay tang lon nhat\n");
		printf("5) Thoat chuong trinh\n");
		printf("**********************************************\n\n");	
		printf("Nhap lua chon: ");
		fflush(stdin);
		scanf("%d", &x);
				
		switch(x){
			case 1:
				docfile();
				break;
			case 2:
				timkiem();
				break;
			case 3:
				xuhuong();
				break;
			case 4:
				timngaytang();
				break;
			case 5:
				printf("Tac gia: Tran Hong Quan _ MSSV: 20205114\n");
				printf("Ban da thoat chuong trinh !\n");
				return 0;
			default:
				printf("Khong co chuc nang nay\n");
				printf("Vui long nhap lai chuc nang !!!\n\n");
				break;
		}
	}
}
