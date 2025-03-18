#ifndef RECEIVEDPACKAGE_H
#define RECEIVEDPACKAGE_H

#include "structure.h"

// 包裹相关功能声明
void addReceivedPackage(struct customer *user);
void queryReceivedPackages(struct customer *user);
void freeReceivedPackages(struct package_r *head);
void receivedPackagesCreating();
void displayMenu_receivedPackage();

#endif // RECEIVEDPACKAGE_H