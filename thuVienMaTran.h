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
	void PrintMatrix(matrix G){
		int i,j;
		printf("\nKet qua: ");
		for(i=1;i<=G.n;i++){
			printf("\n");
			for(j=1;j<=G.m;j++){
				printf("%7.2f",G.A[i][j]);
			}
		}
	}
//3.Tong giua hai ma tran
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
//4.Nhan hai ma tran
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
//5.Ma tran chuyen vi tri.(Ham nay tra ve ma tran A da bi chuyen doi vi tri)
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
//6.Nhan ma tran voi mot so nguyen nhap tu ban phim
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
//7.Kiem tra ma tran vuong
	int KiemTraMaTranVuong(matrix X){
		if(X.m == X.n){
			return 1;
		}
		return 0;
	}
//8.Kiem tra ma tran tam giac tren
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
//9.Kiem tra ma tran tam giac tren
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
//10.Hieu giua hai ma tran
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
//11.Xoa 1 hang trong ma tran
	void removeRow(matrix *X){
		int vitri;
		printf("\n\tXoa mot hang trong ma tran:\n");
		printf("Nhap vi tri hang can phai xoa: ");scanf("%d",&vitri);
		if(vitri > X->n || vitri < 1 || X->n < 1 || X->m < 1){		//Kiem tra dieu kien neu vi tri can xoa ma lon hon so luong hang co trong mot ma tran hoac vi tri can xoa nho hon 1 thi Dung lai bao loi
			printf("\nLoi!Vi tri can xoa khong hop le hoac khong con hang hoac cot de xoa.");
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
//12.Xoa 1 cot trong ma tran
	void removeColumn(matrix *X){
		int vitri;
		printf("\n\tXoa mot cot trong ma tran:\n");
		printf("Nhap vi tri cot can phai xoa: ");scanf("%d",&vitri);
		if(vitri > X->m || vitri < 1|| X->n < 1 || X->m < 1){		//Kiem tra dieu kien neu vi tri can xoa ma lon hon so luong cot co trong mot ma tran hoac vi tri can xoa nho hon 1 thi Dung lai bao loi
			printf("\nLoi!Vi tri can xoa khong hop le hoac khong con hang hoac cot de xoa.");
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
//13. Tich duong cheo chinh tren ma tran
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
//14.Tinh dinh thuc
	//15.1 Ham cycle
	int cycle(int x,int N){
		return (x>N)? 1:x;
	}
	//15.2 Ham tinh dinh thuc tinh duoc ma tran vuong cap 2 va 3
	void tinhDet(matrix G){
		if(KiemTraMaTranVuong(G)==1){
			int i,j;
			float tong1=0,//Luu tru ket qua cac duong cheo ben phai
				  tong2=0;//Luu tru ket qua cac duong cheo ben trai
			//Neu la ma tran vuong cap 3
			if(G.n==3){
				printf("\n\tTinh dinh thuc cua ma tran vuong cap %d",G.n);
				for(i=1;i<=G.n;i++){
					int k=i,
						m=i;
					float temp1=1,temp2=1;//Khoi tao ban dau cho 2 bien tam la 1
					//tong1
					for(j=1;j<=G.n;j++){
						temp1*=G.A[j][cycle(k,G.n)];
						k=cycle(k,G.n);//Kiem tra lai neu K vuot qua So luong cho phep thi ta quay ve 1
						k++;
					}
					tong1+=temp1;
					//tong2
					for(j=1;j<=G.n;j++){
						temp2*=G.A[G.n-j+1][cycle(m,G.n)];
						m=cycle(m,G.n);//Kiem tra lai neu K vuot qua So luong cho phep thi ta quay ve 1
						m++;
					}
					tong2+=temp2;
				}
			}
			//Neu la ma tran vuong cap 2
			else if(G.n==2){
				printf("\n\tTinh dinh thuc cua ma tran vuong cap %d",G.n);
				tong1 =G.A[1][1]*G.A[2][2];
				tong2 =G.A[1][2]*G.A[2][1];
			}
			//Ket qua
			printf("\n%.2f - %.2f = %.2f",tong1,tong2,tong1-tong2);
		}else{
			printf("\nLoi!Vi khong phai la ma tran vuong nen khong the ap dung dinh thuc.\n");
		}
	}

