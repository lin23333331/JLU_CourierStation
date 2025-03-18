#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include "structure.h"

// 文件操作功能声明
void saveCustomers(struct customer *head);
struct customer *loadCustomers();

#endif // FILEOPERATIONS_H