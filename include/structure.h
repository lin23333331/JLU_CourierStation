#ifndef STRUCTURE_H
#define STRUCTURE_H

#define RECEIVED_FILE "received_packages.txt"
#define SENT_FILE "sent_packages.txt"
#define CUSTOMER_FILE "customers.txt"

#define MAX_LEN 100

// 收件包裹结构体
struct package_r {
    char package_id[MAX_LEN];
    double volume;
    int package_type;
    int ifCollection;
    double shipping_fee;
    int package_status;
    struct package_r *next;
};

// 寄件包裹结构体
struct package_s {
    char package_id[MAX_LEN];
    char sender_name[MAX_LEN];
    char receiver_name[MAX_LEN];
    char sender_address[MAX_LEN];
    char receiver_address[MAX_LEN];
    double weight;
    double volume;
    int package_type;
    char order_time[MAX_LEN];
    double shipping_fee;
    int package_status;
    char description[MAX_LEN];
    struct package_s *next;
};

// 用户结构体
struct customer {
    int user_id;
    char username[MAX_LEN];
    char phone_number[MAX_LEN];
    char password[MAX_LEN];
    int customer_type;
    struct package_r *received_packages;
    struct package_s *send_packages;
    struct customer *next;
};

#endif // STRUCTURE_H