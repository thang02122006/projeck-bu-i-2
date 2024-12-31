#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include"function.h"

//logic ham
void menu() {
    printf("+----------------+----------------+----------------+----------------+\n");
    printf("|        ________  Store Management System Using C   _________        |\n");
    printf("+----------------+                                  +----------------+\n");
    printf("|                  ========== Menu ==========                         |\n");
    printf("+----------------+----------------+----------------+----------------+\n");
    printf("|                [1] Category management                              |\n");
    printf("|                [2] Product management                               |\n");
    printf("|                [3] Exit...!                                         |\n");
    printf("+----------------+----------------+----------------+----------------+\n");
}
void displayMenu() {
    printf("+----------------+----------------+----------------+----------------+\n");
    printf("|        ________  Store Management System Using C   _________        |\n");
    printf("+----------------+                                  +----------------+\n");
    printf("|                  ==========Store Menu ==========                    |\n");
    printf("+----------------+----------------+----------------+----------------+\n");
    printf("|                [1] Show category list                               |\n");
    printf("|                [2] Add categories                                   |\n");
    printf("|                [3] Edit category (not edit id)                      |\n");
    printf("|                [4] Delete category                                  |\n");
    printf("|                [5] Search categories by name                        |\n");
    printf("|                [6] Sort the category list by name                   |\n");
    printf("|                [7] Exit...!                                         |\n");
    printf("+----------------+----------------+----------------+----------------+\n");
}

void printStore(Store store[], int length) {  
    int i;
    printf("\n========================   Menu    =======================\n");
    printf("%-5s %-28s %-10s %-15s\n", "ID", "Ten loai sach", "Gia tien", "so luong");
    printf("----------------------------------------------------------\n");
    for (i = 0; i < length; i++) {
        printf("%-5d %-28s %-10.3f %-15s\n",
               store[i].id,
               store[i].name,
               store[i].price,
               store[i].number);
    }
    printf("========================================================================\n");
}

void addStore(Store store[], int *length) {  
    printf("\nNhap thong tin loai sach moi:\n");
    store[*length].id = *length + 1;
    printf("Ten thuc pham: ");
    fflush(stdin); 
    fgets(store[*length].name, 50, stdin);
    store[*length].name[strcspn(store[*length].name, "\n")] = '\0';

    printf("Gia tien: ");
    scanf("%f", &store[*length].price);

    printf("So luong: ");
    fflush(stdin);
    fgets(store[*length].number, 30, stdin);
    store[*length].number[strcspn(store[*length].number, "\n")] = '\0';

    (*length)++;
    printf("\nDa them thanh cong!\n");
}

void updateStore(Store store[], int length) { 
    system("cls"); 
    int id, found = 0;
    int i;
    printf("Nhap ID koai sach can sua: ");
    scanf("%d", &id);

    for (i = 0; i < length; i++) {
        if (store[i].id == id) {
            found = 1;
            printf("Thong tin loai sach hien tai:\n");
            printf("ID: %d, Ten loai sach: %s, Gia tien: %.2f, so luong: %s\n",
                   store[i].id, store[i].name, store[i].price, store[i].number);

            printf("\nNhap ten loai sach moi: ");
            getchar(); 
            fgets(store[i].name, sizeof(store[i].name), stdin);
            store[i].name[strcspn(store[i].name, "\n")] = '\0'; 
            printf("Nhap gia tien moi: ");
            scanf("%f", &store[i].price);

            printf("Nhap so luong moi: ");
            getchar(); 
            fgets(store[i].number, sizeof(store[i].number), stdin);
            store[i].number[strcspn(store[i].number, "\n")] = '\0'; 

            printf("�� cap nhat thong tin loai sach co ID %d\n", id);
            break;
        }
    }
    if (found == 0) {
        printf("Khong tim thay loai sach co ID %d\n", id);
    }
}

void deleteStore(Store store[], int *length) {  
    int id, found = 0;
    int i, j;
    char confirm;
    printf("Nhap ID loai sach muon xoa: ");
    scanf("%d", &id);

    for (i = 0; i < *length; i++) {
        if (store[i].id == id) {
            found = 1;
            printf("Ban co muon xoa loai sach nay khong?\n");
            printf("Nhap 'a' hoac 'A' de xoa , muon huy thi ban bam phim bat ki : ");
            getchar(); 
            scanf("%c", &confirm);
            if (confirm == 'a' || confirm == 'A') {
                for (j = i; j < *length - 1; j++) {
                    store[j] = store[j + 1];
                }
                (*length)--; 
                printf("Da xoa loai sach co ID %d\n", id);
            } else {
                printf("Huy xoa loai sach\n");
            }
            break;
        }
    }
    if (found == 0) {
        printf("Khong tim thay loai sach co ID %d\n", id);
    }
}

void searchStoreByName(Store store[], int length) {  
    char name[100];
    int found = 0;
    int i;

    printf("Nhap ten loai sach can tim: ");
    getchar(); 
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 
    toLowerCase(name);

    for (i = 0; i < length; i++) {
        char storeName[100];
        strcpy(storeName, store[i].name);
        toLowerCase(storeName);

        if (strstr(storeName, name) != NULL) {
            found = 1;
            printf("\n============================     Menu     ============================\n");
            printf("%-5s %-28s %-10s %-15s\n", "ID", "Ten loai sach",  "Gia tien", "So luong");
            printf("%-5d %-28s %-10.3f %-15s\n",
               store[i].id,
               store[i].name,
               store[i].price,
               store[i].number);
        }
    }

    if (found == 0) {
        printf("Khong tim thay loai sach '%s'\n", name);
    }
}

void toLowerCase(char str[]) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void sortStoresByPrice(Store stores[], int length, int ascending) {  
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if ((ascending && stores[j].price > stores[j + 1].price) || 
                (!ascending && stores[j].price < stores[j + 1].price)) {
                Store temp = stores[j];
                stores[j] = stores[j + 1];
                stores[j + 1] = temp;
            }
        }
    }
}

void saveStoresToFile(Store store[], int length) {  
    FILE *ptr = fopen("stores.dat", "wb");

    if (ptr == NULL) {
        printf("Khong mo duoc file");
    }
    fwrite(store, sizeof(Store), length, ptr);
    printf("Luu thong tin thanh cong\n");

    fclose(ptr);
}

void loadStoresFromFile(Store store[], int *length) {  
    int i;
    FILE *ptr = fopen("stores.dat", "rb");

    if (ptr == NULL) {
        printf("Khong mo duoc file");
    }
    *length = fread(store, sizeof(Store), 50, ptr);
    for (i = 0; i < *length; i++) {
        printf("%-5d %-18s %-10.2f %-15s\n",
               store[i].id,
               store[i].name,
               store[i].price,
               store[i].number);
    }   
    printf("Lay Du Lieu Thanh Cong\n");
    fclose(ptr);
}

