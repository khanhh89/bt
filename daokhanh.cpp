#include<stdio.h>
int main(){
    int number[99][99];
    int choice;
    int a, b, tong = 0, size, find, found = 0, temp[99];

    do {
        printf("\n------MENU------\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu.\n");
        printf("2. In ra cac phan tu dang quan ly.\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich.\n");
        printf("4. In ra cac phan tu tren duong cheo chinh.\n");
        printf("5. In ra cac phan tu tren duong cheo phu.\n");
        printf("6. Sap xem phan tu tren duong cheo chinh tang dan.\n");
        printf("7. Tim kiem phan tu.\n");
        printf("8. Thoat.\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Nhap so hang: ");
                scanf("%d", &a);
                printf("Nhap so cot: ");
                scanf("%d",&b);
                for (int i = 0; i < a; i++) {
                    for (int j=0;j<b;j++) {
                        printf("Nhap phan tu [%d][%d]: ", i+1, j+1);
                        scanf("%d", &number[i][j]);
                    }
                }
                break;
            case 2:
                printf("Cac phan tu co trong mang:\n");
                for (int i =0;i<a;i++) {
                    for (int j=0;j<b;j++) {
                        printf("%d\t", number[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                tong = 0;
                printf("Cac phan tu nam tren duong bien: ");
                for (int i =0;i<a;i++) {
                    for (int j=0; j<b;j++) {
                        if (i == 0 ||i==a-1||j==0||j == b - 1) {
                            printf("%d\t", number[i][j]);
                            tong += number[i][j];
                        }
                    }
                }
                printf("\nTong cac phan tu tren duong bien: %d\n", tong);
                break;
            case 4:
                if (a!=b) {
                    printf("Khong co duong cheo chinh.\n");
                    break;
                }
                printf("Cac phan tu nam tren duong treo chinh: ");
                for (int i= 0;i<a;i++) {
                    printf("%d\t", number[i][i]);
                }
                printf("\n");
                break;
            case 5:
                if (a != b) {
                    printf("Khong co duong cheo phu\n");
                    break;
                }
                printf("Cac phan tu nam tren duong cheo phu: ");
                for (int i = 0;i<a;i++) {
                    printf("%d\t",number[i][a-i-1]);
                }
                printf("\n");
                break;
            case 6:
                if (a!= b) {
                    printf("Mnag khong co duong cheo chinh.\n");
                    break;
                }
                size=a;
                for (int i =0;i<a;i++) {
                    temp[i] =number[i][i];
                }
                for (int i =0;i <size-1;i++) {
                    for (int j = i +1;j<size;j++) {
                        if (temp[i]>temp[j]) {
                            int t = temp[i];
                            temp[i] = temp[j];
                            temp[j] = t;
                        }
                    }
                }
                printf("Duong cheo chinh sau khi xapxep: ");
                for (int i = 0; i < a; i++) {
                    printf("%d\t", temp[i]);
                }
                printf("\n");
                break;
            case 7:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &find);
                printf("Phan tu can tim nam o: ");
                found = 0;
                for (int i=0;i<a;i++) {
                    for (int j=0;j< b;j++) {
                        if (number[i][j]==find) {
                            printf("Hang %d,cot %d\n",i + 1,j + 1);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong ton tai\n", find);
                }
                break;
            case 8:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 8);
	return 0;
}
