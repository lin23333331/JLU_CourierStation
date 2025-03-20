#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "structure.h"

// 文件操作功能声明
void saveCustomers(struct customer *head); // 保存用户数据到文件
struct customer *loadCustomers(); // 从文件加载用户数据

// 收件包裹文件操作
void saveReceivedPackages(struct customer *customerList);
void loadReceivedPackages(struct customer *customerList);

#endif // FILEOPERATIONS_H