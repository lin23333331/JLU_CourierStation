#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOperations.h"

// 保存用户到文件
void saveCustomers(struct customer *head) {
    FILE *file = fopen(CUSTOMER_FILE, "w");
    if (!file) {
        perror("Failed to open file for saving customers");
        return;
    }

    struct customer *current = head;
    while (current) {
        fprintf(file, "%d %s %s %s %d\n",
                current->user_id, current->username, current->phone_number,
                current->password, current->customer_type);
        current = current->next;
    }

    fclose(file);
    printf("Customers saved successfully.\n");
}

// 从文件加载用户
struct customer *loadCustomers() {
    FILE *file = fopen(CUSTOMER_FILE, "r");
    if (!file) {
        perror("No customers file found");
        return NULL;
    }

    struct customer *head = NULL, *tail = NULL;
    while (!feof(file)) {
        struct customer *cust = (struct customer *)malloc(sizeof(struct customer));
        if (!cust) {
            perror("Memory allocation failed");
            break;
        }
        if (fscanf(file, "%d %s %s %s %d",
                   &cust->user_id, cust->username, cust->phone_number,
                   cust->password, &cust->customer_type) == 5) {
            cust->next = NULL;
            if (!head) {
                head = tail = cust;
            } else {
                tail->next = cust;
                tail = cust;
            }
        } else {
            free(cust);
            break;
        }
    }

    fclose(file);
    return head;
}

void saveReceivedPackages(struct customer *customerList) {
    FILE *file = fopen(RECEIVED_FILE, "w");
    if (!file) {
        perror("无法打开文件保存收件包裹");
        return;
    }

    struct customer *currentCustomer = customerList;
    while (currentCustomer) {
        struct package_r *currentPackage = currentCustomer->received_packages;
        while (currentPackage) {
            fprintf(file, "%d %s %.2f %d %d %.2f %d\n",
                    currentCustomer->user_id,
                    currentPackage->package_id,
                    currentPackage->volume,
                    currentPackage->package_type,
                    currentPackage->ifCollection,
                    currentPackage->shipping_fee,
                    currentPackage->package_status);
            currentPackage = currentPackage->next;
        }
        currentCustomer = currentCustomer->next;
    }

    fclose(file);
    printf("收件包裹保存成功！\n");
}

// 从文件加载收件包裹
void loadReceivedPackages(struct customer *customerList) {
    FILE *file = fopen(RECEIVED_FILE, "r");
    if (!file) {
        perror("无法打开文件加载收件包裹");
        return;
    }

    int user_id;
    char package_id[MAX_LEN];
    double volume;
    int package_type, ifCollection, package_status;
    double shipping_fee;

    while (fscanf(file, "%d %s %lf %d %d %lf %d",
                  &user_id, package_id, &volume, &package_type,
                  &ifCollection, &shipping_fee, &package_status) == 7) {
        struct customer *currentCustomer = customerList;
        while (currentCustomer && currentCustomer->user_id != user_id) {
            currentCustomer = currentCustomer->next;
        }

        if (currentCustomer) {
            struct package_r *newPackage = (struct package_r *)malloc(sizeof(struct package_r));
            if (!newPackage) {
                perror("Failed to allocate memory for new received package");
                fclose(file);
                return;
            }

            strcpy(newPackage->package_id, package_id);
            newPackage->volume = volume;
            newPackage->package_type = package_type;
            newPackage->ifCollection = ifCollection;
            newPackage->shipping_fee = shipping_fee;
            newPackage->package_status = package_status;

            newPackage->next = currentCustomer->received_packages;
            currentCustomer->received_packages = newPackage;
        }
    }

    fclose(file);
    printf("收件包裹加载成功！\n");
}