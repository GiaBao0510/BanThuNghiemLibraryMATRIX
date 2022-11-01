#include<stdio.h>
#include<stdlib.h>
#define SIGN(X) (X%2? -1:1)
/*Vi tinh dinh thuc nen phai la ma tran vuong*/
//Tao ham cap phat bo nho cho mang hai chieu
int ** allowMatrix(int **Arr,int size){
	int i,j;
	Arr = (int**)malloc(size * sizeof(int*));	//Cap phat do dai cho tung hang
	for(i=0;i<size;i++){
		Arr[i] = (int*)malloc(size * sizeof(int));//Cap phat bo nho bo nho cho tung cot
	}
	return Arr;
}
//Giai phong bo nho
void freeMemory(int **Arr,int size){
	int i;
	for(i=0;i<size;i++){
		free(Arr[i]);
	}
	free(Arr);
}
//Tao ma tran
void createMatrix(int **Arr,int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("Nhap Array[%d][%d]: ",i,j); scanf("%d",&Arr[i][j]);
		}
	}
}
//Xuat ma tran 
void printMatrix(int **Arr,int size){
	int i,j;
	for(i=0;i<size;i++){
		printf("\n");
		for(j=0;j<size;j++){
			printf("%3d",Arr[i][j]);
		}
	}
}
//tinh Det
int DET(int **Arr,int size){
	if(size<2){
		return -1;
	}
	if(size==2){
		return Arr[1][1]*Arr[0][0] - Arr[1][0]*Arr[0][1];
	}
	else{
		int i,j,kt,
			hang,cot,
			det=0,
			**Cmatrix =allowMatrix(Arr,size-1);	//Cap pha bo nho cho ma tran con	
		for(kt = 0; kt <size ;kt++){//Day la vong lap ma ta chi khai trien tren dong dau tien
			hang = cot = 0;
			for(i = 1;i<size;i++){	//Luon cho i bat dau tai vi tri dong thu hai de luu gia tri tu ma tran goc sang ma tran con
				for(j=0;j<size;j++){
					if(j != kt){	//Neu cot j khac cot ma ta trien khai thi ta thuc hien cac phep toan sau
						Cmatrix[hang][cot] = Arr[i][j];
						cot++;
						if(cot == size-1){
							cot = 0;
							hang++;
						}
						
					}
				}
			}
			det += SIGN(kt) * Arr[0][kt]/*Luon trien khai theo dong 1 va cot thu i nao do*/ * DET(Cmatrix,size-1)/*De quy de lay ket qua tu ma tran con*/;
		}
		freeMemory(Cmatrix,size-1);//Giai phong bo nho cho ma tran con
		return det;	
	}
}
int main(){
	int **Arr,//Nhu mot mang hai chieu
		n;
	printf("Nhap ma tran cap: "); scanf("%d",&n);
	Arr = allowMatrix(Arr,n);
	createMatrix(Arr,n);
	printMatrix(Arr,n);
	printf("\nDet: %d",DET(Arr,n));
	
	freeMemory(Arr,n);
	
}
