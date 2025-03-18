#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "structure.h"

// 文件操作功能声明
void saveCustomers(struct customer *head); // 保存用户数据到文件
struct customer *loadCustomers(); // 从文件加载用户数据

#endif // FILEOPERATIONS_H