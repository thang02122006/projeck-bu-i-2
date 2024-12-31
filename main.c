#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int check,checks;
int length = 0;

int main(int argc, char *argv[]) {
    Store store[100]; 
    menu();
	printf("Nhap lua chon cua ban :");
    scanf("%d", &checks); 
    if(checks==1){
    if (length == 0) {
        store[0] = (Store){1, "Sach ngoai ngu", 150, "100"};  
        store[1] = (Store){2, "Sach tieu thuyet", 220, "120"};  
        store[2] = (Store){3, "Sach thieu nhi",  120, "145"};  
        store[3] = (Store){4, "Sach khoa hoc gia tuong",  200, "130"};  
        store[4] = (Store){5, "Sach van hoc", 100, "70"}; 
	    store[5] = (Store){6, "Sach lich su",  170, "90"}; 
		store[6] = (Store){7, "Sach van hoc",  145, "90"}; 
		store[7] = (Store){8, "Sach hoc thuat",  300, "110"}; 
        length = 8;
    }

    do {
        displayMenu();
        printf("Nhap lua chon cua ban :");
        scanf("%d", &check);
        switch(check) {
            case 1: {
                printStore(store, length);  
                break;
            }
            case 2: {
                addStore(store, &length); 
                saveStoresToFile(store, length); 
                break;
            }
            case 3: {
                updateStore(store, length); 
                saveStoresToFile(store, length); 
                break;
            }
            case 4: {
                deleteStore(store, &length);  
                saveStoresToFile(store, length);  
                break;
            }
            case 5: {
                searchStoreByName(store, length);  
                break;
            }
            case 6: {
                int sortOrder;
                printf("Chon kieu sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Nhap lua chon: ");
                scanf("%d", &sortOrder);

                sortStoresByPrice(store, length, sortOrder == 1);  
                printf("Danh sach sau khi sap xep:\n");
                printStore(store, length);  
                saveStoresToFile(store, length);  
                break;
            }
            case 7: {
                printf("Thoat chuong trinh...!\n");
                break;
            }
            default:
                printf("Lua chon cua ban khong hop le.Yeu cau ban nhap lai !!!\n");
        }
    } while (check != 7);
}
    return 0;
}

