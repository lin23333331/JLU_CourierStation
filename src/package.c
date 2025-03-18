#include <stdio.h>
#include <stdlib.h>
#include "package.h"

// 释放收件包裹链表
void freeReceivedPackages(struct package_r *head) {
    while (head) {
        struct package_r *temp = head;
        head = head->next;
        free(temp);
    }
}

// 释放寄件包裹链表
void freeSentPackages(struct package_s *head) {
    while (head) {
        struct package_s *temp = head;
        head = head->next;
        free(temp);
    }
}