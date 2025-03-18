#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "fileOperations.h"
#include "package.h"
#include "structure.h"

void displayMenu() {
    printf("\n========== 包裹管理系统 ==========\n");
    printf("1. 添加用户\n");
    printf("2. 查询用户信息\n");
    printf("3. 删除用户\n");
    printf("4. 保存数据到文件\n");
    printf("5. 从文件加载数据\n");
    printf("0. 退出系统\n");
    printf("=================================\n");
}

int main() {
    struct customer *customerList = NULL;

    int choice;
    do {
        displayMenu();
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int user_id, customer_type;
                char username[100], phone_number[100], password[100];
                printf("请输入用户ID: ");
                scanf("%d", &user_id);
                printf("请输入用户名: ");
                scanf("%s", username);
                printf("请输入电话号码: ");
                scanf("%s", phone_number);
                printf("请输入密码: ");
                scanf("%s", password);
                printf("请输入用户类型 (1-普通用户, 2-VIP用户): ");
                scanf("%d", &customer_type);
                customerList = addCustomer(customerList, user_id, username, phone_number, password, customer_type);
                break;
            }
            case 2:
                queryCustomer(customerList);
                break;
            case 3:
                customerList = deleteCustomer(customerList);
                break;
            case 4:
                saveCustomers(customerList);
                break;
            case 5:
                customerList = loadCustomers();
                break;
            case 0:
                printf("退出系统...\n");
                break;
            default:
                printf("无效的选择，请重试。\n");
        }
    } while (choice != 0);

    freeCustomers(customerList);
    return 0;
}