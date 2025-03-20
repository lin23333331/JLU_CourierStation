#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "fileOperations.h"
#include "receivedPackage.h"
#include "structure.h"
#include "menu.h"

int main() {
    struct customer *customerList = NULL;

    int choice;
    do {
        displayMainMenu();
        printf("请输入您的选择: ");

        // 验证输入是否为有效整数
        if (scanf("%d", &choice) != 1) {
            printf("输入无效，请输入数字。\n");
            // 清理输入缓冲区
            while (getchar() != '\n');
            continue;
        }


        switch (choice) {
            case 1:
                customerList = customersCreating(customerList);
                break;
            case 2:
                receivedPackagesCreating(customerList);
                break;
            case 3:
                saveReceivedPackages(customerList);
                break;
            case 4:
                loadReceivedPackages(customerList);
                break;
            case 0:
                printf("退出系统...\n");
                break;
            default:
                printf("无效的选择，请重试。\n");
        }
        system("pause");
        system("cls");
    } while (choice != 0);

    freeCustomers(customerList);
    return 0;
}