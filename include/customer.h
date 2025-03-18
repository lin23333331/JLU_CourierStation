#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "structure.h"

// 用户相关功能声明
struct customer *addCustomer(struct customer *head, int user_id, const char *username, const char *phone_number, const char *password, int customer_type);
void queryCustomer(struct customer *head);
struct customer *deleteCustomer(struct customer *head);
void freeCustomers(struct customer *head);

#endif // CUSTOMER_H