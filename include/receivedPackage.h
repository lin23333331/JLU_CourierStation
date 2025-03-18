#ifndef PACKAGE_H
#define PACKAGE_H

#include "structure.h"

// 包裹相关功能声明
void freeReceivedPackages(struct package_r *head);
void freeSentPackages(struct package_s *head);

#endif // PACKAGE_H