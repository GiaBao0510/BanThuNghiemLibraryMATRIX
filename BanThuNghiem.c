	/* Ban thu nghiem */
#include<stdio.h>
#define column 50 //Cot
#define row 50 //hang
//Cau truc doi voi tung phan tu la so nguyen
typedef struct{
	int n,				//tong so hang trong ma tran
		m;				//tong so cot trong ma tran
	float A[row][column]; //Gia tri cua tung phan tu
}matrix;
//1.Nhap ma tran tu ban phim
	void enterMatrix(matrix *G){
		printf("\nNhap ma tran:\n");
		int i,j;
		printf("Nhap so luong hang: "); scanf("%d",&G->n);
		printf("Nhap so luong cot: "); scanf("%d",&G->m);
		for(i=1;i<=G->n;i++){
			for(j=1;j<=G->m;j++){
				printf("[%d][%d]: ",i,j); scanf("%f",&G->A[i][j]);
			}
		}
	}
//2.In ma tran
	void matrixPrint(matrix G){
		int i,j;
		printf("\tMa tran %dx%d: ",G.n,G.m);
		for(i=1;i<=G.n;i++){
			printf("\n");
			for(j=1;j<=G.m;j++){
				printf("%7.2f",G.A[i][j]);
			}
		}
	}
//3.Nhan gia tri tai tung vi tri
	void getValue(matrix *G,int u,int v,int w){
		G->A[u][v]=w;
	}
//4.Tong giua hai ma tran
	void Tong2Matran(matrix *A,matrix *B){
		printf("\n\tTong hai ma tran: ");
		if((A->n == B->n)&&(A->m == B->m)){
			matrix c;
			c.n = A->n;
			c.m = A->m;
			int i,j;
			for(i=1;i<=c.n;i++){
				for(j=1;j<=c.m;j++){
					c.A[i][j] = A->A[i][j]+B->A[i][j];
				}
			}
			matrixPrint(c);
		}else{
			printf("\nLoi! Vi hang va cot cua hai ma tren tren khong deu nhau");
		}
	}
//5.Nhan hai ma tran
	void Nhan2MaTran(matrix *A,matrix *B){
		printf("\n\tNhan hai ma tran:");
		if(A->m == B->n){//Kiem tra xem so cot cua ma tran A co bang voi so hang cua ma tran B khong
			matrix c;
			c.n = A->n;
			c.m = B->m;
			int i,j,k;
			for(i=1;i<=c.n;i++){
				for(j=1;j<=c.m;j++){
					c.A[i][j] = 0;
					for(k=1;k<=c.n;k++){
						c.A[i][j] +=(A->A[i][k] * B->A[k][j]) ; 
					}
					
				}
			}
			matrixPrint(c);
		}else{
			printf("\nLoi! vi so cot cua ma tran A khong bang so hang cua ma tran B");
		}
	}
//6.Ma tran chuyen vi tri.(Ham nay tra ve ma tran A da bi chuyen doi vi tri)
	void maTranChuyenViTri(matrix *X){
		printf("\n\tMa tran chuyen vi tri: ");
		//1 copy du lieu tu ma tran ban dau sang ma tran T
		matrix T;
		T.n=X->n;
		T.m=X->m;
		int i,j;
		for(i=1;i<=X->n;i++){
			for(j=1;j<=X->m;j++){
				T.A[i][j] = X->A[i][j];
			}
		}
		//2 chuyen doi hang cua ma tran ban dau thanh cot
		int temp = X->n;
		X->n = X->m;
		X->m = temp;
		//3 chuyen doi
		for(i=1;i<=X->n;i++){
			for(j=1;j<=X->m;j++){
				X->A[i][j] = T.A[j][i];
			}
		}

	}
//7.Nhan ma tran voi mot so nguyen nhap tu ban phim
	void nhanMaTranVoi1SoNguyen(matrix *X){
		int n,i,j;
		printf("\n\tNhan ma tran voi mot so nguyen:");
		printf("\nNhap vao mot so nguyen: "); scanf("%d",&n);
		for(i=1;i<=X->n;i++){
			for(j=1;j<=X->m;j++){
				X->A[i][j]*=n;
			}
		}
	}
//8.Kiem tra ma tran vuong
	int KiemTraMaTranVuong(matrix X){
		if(X.m == X.n){
			return 1;
		}
		return 0;
	}
//9.Kiem tra ma tran tam giac tren
	int kiemTraMaTranTamGiacTren(matrix X){
		if(KiemTraMaTranVuong(X)==1){	//kiem tra xem ma tran nay co phai la ma tran vuong khong.Neu khong phai thi khong duoc xem la ma tran tam giac tren
			int i,j;
			for(i=2;i<=X.n;i++){
				for(j=1;j<i;j++){
					if(X.A[i][j]!=0){
						return 0;
					}
				}
			}
		}else{
			return 0;
		}
		return 1;
	}
//10.Kiem tra ma tran tam giac duoi
	int kiemTraMaTranTamGiacDuoi(matrix X){
		if(KiemTraMaTranVuong(X)==1){	//kiem tra xem ma tran nay co phai la ma tran vuong khong.Neu khong phai thi khong duoc xem la ma tran tam giac duoi
			int i,j;
			for(i=1;i<=X.n;i++){
				for(j=X.n;j>i;j--){
					if(X.A[i][j]!=0){
						return 0;
					}
				}
			}
		}else {
			return 0;
		}
		return 1;
	}
//11.Hieu giua hai ma tran
	void Hieu2Matran(matrix *A,matrix *B){
		printf("\n\tHieu giua hai ma tran: ");
		if((A->n == B->n)&&(A->m == B->m)){
			matrix c;
			c.n = A->n;
			c.m = A->m;
			int i,j;
			for(i=1;i<=c.n;i++){
				for(j=1;j<=c.m;j++){
					c.A[i][j] = A->A[i][j]-B->A[i][j];
				}
			}
			matrixPrint(c);
		}else{
			printf("\nLoi! Vi hang va cot cua hai ma tren tren khong deu nhau");
		}
	}
//12.Xoa 1 hang trong ma tran
	void Xoa1Hang(matrix *X){
		int vitri;
		printf("\n\tXoa mot hang trong ma tran:\n");
		printf("Nhap vi tri hang can phai xoa: ");scanf("%d",&vitri);
		if(vitri > X->n || vitri < 1){		//Kiem tra dieu kien neu vi tri can xoa ma lon hon so luong hang co trong mot ma tran hoac vi tri can xoa nho hon 1 thi Dung lai bao loi
			printf("\nLoi!Vi tri can xoa khong hop le.");
		}else{
			int i,j;
			for(i=vitri;i<=X->n;i++){
				for(j=1;j<=X->m;j++){
					X->A[i][j]=X->A[i+1][j];
				}
			}
			X->n--;//Giam so luong hang di 1 don vi
		}
	}
//13.Xoa 1 cot trong ma tran
	void Xoa1Cot(matrix *X){
		int vitri;
		printf("\n\tXoa mot cot trong ma tran:\n");
		printf("Nhap vi tri cot can phai xoa: ");scanf("%d",&vitri);
		if(vitri > X->m || vitri < 1){		//Kiem tra dieu kien neu vi tri can xoa ma lon hon so luong cot co trong mot ma tran hoac vi tri can xoa nho hon 1 thi Dung lai bao loi
			printf("\nLoi!Vi tri can xoa khong hop le.");
		}else{
			int i,j;
			for(i=1;i<=X->n;i++){
				for(j=vitri;j<=X->m;j++){
					X->A[i][j]=X->A[i][j+1];
				}
			}
			X->m--;//Giam so luong cot di 1 don vi
		}
	}
//14. Tich duong cheo chinh tren ma tran
	int tichDuongCheoChinh(matrix X){
		printf("\nTinh tich duong cheo chinh:");
		int i,j;
		float ketQua=1;
		for(i=1;i<=X.n;i++){
			for(j=1;j<=X.m;j++){
				if(i == j){		//Neu phan tu nam tren duong cheo chinh thi tich no
					ketQua*=X.A[i][j];
				}
			}
		}
		return ketQua;
	}
//17.Ham swap(ap dung cho 1 so ham khac,So thuc)
void Swap(float *A,float *B){
	float temp =*A;
	*A = *B;
	*B = temp;
}	
//16.Doi cho 2 hang bat ky	
void doiCho2Hang(matrix *X){
	printf("\n\tDoi cho 2 hang bat ky.\n");
	int hangX, //Luu tru vi tri hang dau
		hangY; //Luu tru vi tri hang cuoi	
	printf("Chon vi tri hang can muon doi: ");scanf("%d",&hangX);
	printf("Chon vi tri hang can doi: ");scanf("%d",&hangY);
	if(hangX > X->n || hangY > X->n || hangX < 1 || hangY <1){
		printf("Loi! Vi tri Chon khong phu hop.");
	}else{
		int j;
		for(j=1;j<=X->m;j++){
			Swap(&X->A[hangX][j],&X->A[hangY][j]);
		}
	}
}
//17.Doi cho 2 cot bat ky	
void doiCho2Cot(matrix *X){
	printf("\n\tDoi cho 2 cot bat ky.\n");
	int cotX, //Luu tru vi tri cot dau
		cotY; //Luu tru vi tri cot cuoi	
	printf("Chon vi tri cot can muon doi: ");scanf("%d",&cotX);
	printf("Chon vi tri cot can doi: ");scanf("%d",&cotY);
	if(cotX > X->m || cotY > X->m || cotX < 1 || cotY <1){
		printf("Loi! Vi tri Chon khong phu hop.");
	}else{
		int i;
		for(i=1;i<=X->n;i++){
			Swap(&X->A[i][cotX],&X->A[i][cotY]);
		}
	}
}
//18.Doc ma tran tu tep tin
void readMatrixFromFile(matrix *G){
	FILE *F = fopen("dataMatrix.txt","r");
	if(F!=NULL){
		fscanf(F,"%d %d",&G->n,&G->m);
		int i,j;
		for(i = 1;i<=G->n;i++){
			for(j=1;j<=G->m;j++){
				fscanf(F,"%f",&G->A[i][j]);
			}
		}
	}else{
		printf("!Loi mo tep.");
	}
	fclose(F);
}
//19.Tinh dinh thuc cach 2
#define SIGN(x) (x%2==0? -1:1)
float tinhdet(int size,float Arr[size][size]){
	if(size<2){
		return -1;
	}
	if(size==2){
		return Arr[1][1]*Arr[2][2] - Arr[1][2]*Arr[2][1];
	}
	else{
		int i,j,kt,
			hang,cot;
		int kichCo;
		kichCo=size-1; 
		float det=0,
			Cmatrix[kichCo][kichCo];	//Cap pha bo nho cho ma tran con	
		for(kt = 1; kt <=size ;kt++){//Day la vong lap ma ta chi khai trien tren dong dau tien
			hang = cot = 1;
			for(i = 2;i<=size;i++){	//Luon cho i bat dau tai vi tri dong thu hai de luu gia tri tu ma tran goc sang ma tran con
				for(j=1;j<=size;j++){
					if(j != kt){	//Neu cot j khac cot ma ta trien khai thi ta thuc hien cac phep toan sau
						Cmatrix[hang][cot] = Arr[i][j];
						cot++;
						if(cot == size){
							cot = 1;
							hang++;
						}
						
					}
				}
			}
			det += SIGN(kt) * Arr[1][kt]/*Luon trien khai theo dong 1 va cot thu i nao do*/ * tinhdet(size-1,Cmatrix)/*De quy de lay ket qua tu ma tran con*/;
		}
		return det;	
	}
}
void Det(matrix X){
	//Kiem tra xem co phai ma tran vuong khong
	if(KiemTraMaTranVuong(X) == 0){	//Neu khong phai la ma tran vuong
		printf("\n\tVi khong phai la ma tran vuong nen khong the tinh duoc dinh thuc.\n");
		return;
	}
	float Matrix[X.n][X.n];
	int size = X.n;
	int i,j;
	//Sao chep qua mang 2 chieu khac
	for(i=1;i<=X.n;i++){
		for(j=1;j<=X.n;j++){
			Matrix[i][j] = X.A[i][j];
		}
	}
	printf("\nDet: %.2f",tinhdet(size,Matrix));
}
//20 Kiem tra ma tran 0
int kiemTraMaTranKhong(matrix X){
	printf("\n\tKiem tra ma tran khong: ");
	if(X.n<=0 || X.m<=0){
		return 1; //La ma tran khong 
	}
	int i,j,dem=0;
	for(i=1;i<=X.n;i++){
		for(j=1;j<=X.m;j++){
			if(X.A[i][j]!=0){
				dem++;
			}
		}
	}
	if(dem==0){
		return 1;
	}
	return 0;/*Khong phai la ma tran khong*/
}
//21 tim gia tri lon nhat tren ma tran
float maxValue(matrix X){
	if(kiemTraMaTranKhong(X)==1){
		printf("\n\tVi la ma tran khong nen khong the thuc thi.");
		return -1;
	}
	int i,j;
	int max = X.A[1][1];
	for(i=1;i<=X.n;i++){
		for(j=1;j<=X.m;j++){
			if(max < X.A[i][j]){
				max = X.A[i][j];
			}
		}
	}
	return max;
}
//22 tim gia tri nho nhat tren ma tran
float minValue(matrix X){
	if(kiemTraMaTranKhong(X)==1){
		printf("\n\tVi la ma tran khong nen khong the thuc thi.");
		return -1;
	}
	int i,j;
	int min = X.A[1][1];
	for(i=1;i<=X.n;i++){
		for(j=1;j<=X.m;j++){
			if(min > X.A[i][j]){
				min = X.A[i][j];
			}
		}
	}
	return min;
}
//23. Kiem tra ma tran don vi
int kiemTraMaTranDonVi(matrix G){
	if(KiemTraMaTranVuong(G) == 1){
		if(kiemTraMaTranTamGiacDuoi(G) == 0){
			return 0;
		}
		if(kiemTraMaTranTamGiacTren(G) == 0){
			return 0;
		}
		int i,j;
		for(i=1;i<=G.n;i++){
			if(G.A[i][i]!=1){
				return 0;
			}
		}
		return 1;
	}else{
		return 0;
	}
}
//24. Tim hang cua ma tran
int rankMatrix(matrix G){
	int i,dem1 =0;
	//24.1 ban dau ta kiem tra xem tat ca cac cot dau tien trong ma tran.Neu tat ca cac cot dau tien dieu khac 0 thi hang cua ma tran la = 0
	for(i=1;i<=G.n;i++){
		if(G.A[i][1]!=0){
			dem1++;
		}
	}
	if(dem1 == G.n){
		return 0;
	}else{//Nguoc lai
		int hang0,//Bien nay dung de kiem tra xem co hang nao la hang 0 hay khong
		rank=0,j;
		for(i=1;i<=G.n;i++){
			hang0=0;
			for(j=1;j<=G.m;j++){
				if(G.A[i][j] == 0){
					hang0++;
				}
			}
			if(hang0 != G.m){//neu mot hang khong phai la hang 0 thi rank tang len 1 don vi
				rank++;
			}
		}
		return rank;
	}
}
int main(){
	matrix B;
	readMatrixFromFile(&B);
//	printf("\nGia tri lon nhat :%.2f\nGia tri nho nhat: %.2f",maxValue(B),minValue(B));
//	Det(B);
	printf("Rank: %d",rankMatrix(B));
}

