#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

// 添加用户
struct customer *addCustomer(struct customer *head, int user_id, const char *username, const char *phone_number, const char *password, int customer_type) {
    struct customer *newCustomer = (struct customer *)malloc(sizeof(struct customer));
    if (!newCustomer) {
        perror("Failed to allocate memory for new customer");
        return head;
    }

    newCustomer->user_id = user_id;
    strcpy(newCustomer->username, username);
    strcpy(newCustomer->phone_number, phone_number);
    strcpy(newCustomer->password, password);
    newCustomer->customer_type = customer_type;
    newCustomer->received_packages = NULL;
    newCustomer->send_packages = NULL;
    newCustomer->next = head;

    printf("用户添加成功！\n");
    return newCustomer;
}

// 查询用户信息
void queryCustomer(struct customer *head) {
    if (!head) {
        printf("当前没有用户数据。\n");
        return;
    }

    int user_id;
    printf("请输入要查询的用户ID: ");
    scanf("%d", &user_id);

    struct customer *current = head;
    while (current) {
        if (current->user_id == user_id) {
            printf("\n用户信息:\n");
            printf("用户ID: %d\n", current->user_id);
            printf("用户名: %s\n", current->username);
            printf("电话号码: %s\n", current->phone_number);
            printf("用户类型: %d\n", current->customer_type);
            return;
        }
        current = current->next;
    }

    printf("未找到用户ID为 %d 的用户。\n", user_id);
}

// 删除用户
struct customer *deleteCustomer(struct customer *head) {
    if (!head) {
        printf("当前没有用户数据。\n");
        return head;
    }

    int user_id;
    printf("请输入要删除的用户ID: ");
    scanf("%d", &user_id);

    struct customer *current = head, *prev = NULL;
    while (current) {
        if (current->user_id == user_id) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            freeCustomers(current);
            printf("用户ID为 %d 的用户已删除。\n", user_id);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("未找到用户ID为 %d 的用户。\n", user_id);
    return head;
}

// 释放用户链表
void freeCustomers(struct customer *head) {
    while (head) {
        struct customer *temp = head;
        head = head->next;
        free(temp);
    }
}