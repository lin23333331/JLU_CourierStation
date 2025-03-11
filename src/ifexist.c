#include <string.h>
#include "structure.h"
#include "ifexist.h"

int checkUserCredentials(struct customer* head, const char* username, const char* password) {
    struct customer* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            return 1; // 找到匹配的用户名和密码
        }
        current = current->next;
    }
    return 0; // 未找到匹配的用户名和密码
}