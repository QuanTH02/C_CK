// Tran Hong Quan - 20205114
// Thi Giua ky mon Lap trinh C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, test = -1;
char b[20][20];

void ds(){
	printf("Danh sach file Input.txt\n\n");
	FILE* f;
	f = fopen("Input.txt", "r");
	char a[20];
	while(fgets(a, 20, f) != NULL){	
		puts(a);		
	}
	fclose(f);
	printf("\n\n");
}

void xacdinh(){
	test = 0;
	int k;
	char a[20];
	int  m = 0, l = 0, c = 0;
	FILE* f;
	f = fopen("Input.txt", "r");	
	fscanf(f, "%d", &n);	
		
	printf("Nhap vao cua hang can xac dinh cac mon hang: ");
	fflush(stdin);
	scanf("%d", &k);
	
	if(k <= 0 || k > n){
		printf("Ban da nhap sai ten cua hang, chuong trinh da thoat\n\n");
		return;
	}
		
	while(fgets(a, 20, f) != NULL){
		l++;
		if(l == k+1){
			a[strlen(a)-1] = '\0';
			char* s = strtok(a, "	,");
			s = strtok(NULL, "	,");
			printf("Cac mon hang cua cua hang %d la: ", k);
			while(s != NULL){
				strcpy(b[c], s);
				c++;
				s = strtok(NULL, "	,");						
			}
		}
	}

	for(int i = 0; i < c; i++){
		for(int j = i; j < c; j++){
			if(strcmp(b[i], b[j]) > 0){
				char tmp[20];
				strcpy(tmp, b[i]);
				strcpy(b[i], b[j]);
				strcpy(b[j], tmp);
			}
		}
	}
	
	for(int i = 0; i < c; i++){
		printf("%s ", b[i]);
	}
	
	printf("\n\n");
	
	fclose(f);
}

void Xoa(){
	int p;
	char q[20], a[20];
	int  m = 0, l = 0, c = 0;
	FILE* f;
	f = fopen("Input.txt", "r");	
	fscanf(f, "%d", &n);
	Nhap:
		printf("Nhap vao ten cua hang muon xoa: ");
		fflush(stdin);
		scanf("%d", &p);
	if(p <= 0 || p > n){
		printf("Ban da nhap sai, vui long nhap lai ten cua hang !\n");
		goto Nhap;
	}
	
	while(fgets(a, 20, f) != NULL){
		l++;
		if(l == p+1){
			a[strlen(a)-1] = '\0';
			char* s = strtok(a, "	,");
			s = strtok(NULL, "	,");
			printf("Cac mon hang cua cua hang %d la: ", p);
			while(s != NULL){
				strcpy(b[c], s);
				c++;
				s = strtok(NULL, "	,");						
			}
		}
	}
	
	for(int i = 0; i < c; i++){
		for(int j = i; j < c; j++){
			if(strcmp(b[i], b[j]) > 0){
				char tmp[20];
				strcpy(tmp, b[i]);
				strcpy(b[i], b[j]);
				strcpy(b[j], tmp);
			}
		}
	}
	
	for(int i = 0; i < c; i++){
		printf("%s ", b[i]);
	}
	
	printf("\n");
	
	int u = 0, y;
	
	Nhap1:
		printf("Nhap ten mon hang ban muon xoa: ");
		fflush(stdin);
		scanf("%c", &q);
	for(int i = 0; i < c; i++){
		if(strcmp(q, b[i]) == 0){
			u++;
			y = i;
		}
	}
	
	if(u == 0){
		printf("Mon hang ban nhap khong co, vui long nhap lai !\n");
		goto Nhap1;
	}
	
	printf("Cac mon hang cua cua hang %d sau khi xoa la: ", p);
	
	for(int i = 0; i < c; i++){
		if(i == y)	{
			strcmp(b[i], "");
			continue;
		}
		printf("%s ", b[i]);
	}
	printf("\n\n");
	printf("Ban co muon tiep tuc chuong trinh ?\nNeu co thi bam phim bat ky, neu khong thi bam Q de thoat chuong trinh: ");
	fflush(stdin);
	char t[10];
	scanf("%s", &t);
	if(strcmp(t, "Q") == 0){
		printf("Ban da thoat chuong trinh !");
		return;
	}
	else(Xoa());
	printf("\n\n");
	fclose(f);
}

void Them(){
	int p, k, w, r = 0;
	char a[20], t[20];
	int  m = 0, c = 0;
	
	Nhap:
		printf("Nhap vao ten cua hang muon them vao: ");
		fflush(stdin);
		scanf("%d", &p);
	if(p <= n){
		printf("Nhap khong hop le, vui long nhap lai !\n");
		goto Nhap;
	}
	
	char x[20][20];
	FILE* f;
	f = fopen("Input.txt", "r");	
	fscanf(f, "%d", &n);
	
	while(fgets(a, 20, f) != NULL){		
		a[strlen(a)-1] = '\0';
		char* s = strtok(a, "	,");
		s = strtok(NULL, "	,");
		while(s != NULL){
			strcpy(x[c], s);
			c++;
			s = strtok(NULL, "	,");						
		}
	}
	
	printf("Nhap danh sach cac mon hang: ");
	fflush(stdin);
	gets(t);
	
	char* u = strtok(t, ",");
	while(u != NULL){
		r++;
		for(int i = 0; i < c; i++){
			if(strcmp(x[i], u) == 0){
				w++;
			}
		}
		u = strtok(NULL, ",");
	}
	printf("\n");
	return;
	
	
}

void Tinhtoan(){
	char N[20];	
	printf("Nhap danh sach muon di kiem tra: ");
	fflush(stdin);
	gets(N);
	
	int x[10];
	char y[10][10];
	
	printf("Chi phi la: ");
	printf("\n\n");
	return;
}


int main(){	
	ds();
	while(5){
		int x;
		printf("**********************************************\n");
		printf("====Ban hay nhap chuc nang can thuc hien====\n");
		printf("1) Xac dinh cac mon hang trong cua hang\n");
		printf("2) Xoa di cac mon hang cua mot cua hang\n");
		printf("3) Them mot cua hang va cac mon hang trong do\n");
		printf("4) Tinh toan chi phi di lai\n");
		printf("5) Thoat\n");
		printf("**********************************************\n\n");	
		printf("Nhap lua chon: ");
		fflush(stdin);
		scanf("%d", &x);
				
		switch(x){
			case 1:
				xacdinh();
				break;
			case 2:
				Xoa();
				break;
			case 3:
				Them();
				break;
			case 4:
				Tinhtoan();
				break;
			case 5:
				printf("Ban da thoat chuong trinh !\n");
				return 0;
			default:
				printf("Khong co chuc nang nay\n");
				printf("Vui long nhap lai chuc nang !!!\n\n");
				break;
		}
	}
}
