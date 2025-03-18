#include <stdio.h>
#include <stdlib.h>
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