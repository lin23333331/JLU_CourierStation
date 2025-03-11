#ifndef USER_H
#define USER_H
#define len 100

int count = 0;                          // 包裹数量计数器

// 收件包裹结构体定义
struct package_r {
    char package_id[len];           // 包裹唯一标识符
    double volume;                  // 包裹体积，单位如立方厘米
    int package_type;               // 包裹类型（1-文件 2-生鲜 3-易碎品 4-家电 5-危险品）
    int ifCollection;               // 是否需要到付(0-不需要 1-需要)
    double shipping_fee;            // 运输费用
    int package_status;             // 包裹状态（1-损坏 2-违禁品 3-逾期）
    struct package_r *next;         // 指向下一个包裹节点（链表结构）
};

// 寄件包裹结构体定义
struct package_s {
    char package_id[len];           // 包裹快递单号 
    char sender_name[50];           // 寄件人姓名
    char receiver_name[50];         // 收件人姓名
    char sender_address[200];       // 寄件地址：街道、城市、邮编等
    char receiver_address[200];     // 收货地址：街道、城市、邮编等
    double weight;                  // 包裹重量，单位如公斤
    double volume;                  // 包裹体积，单位如立方厘米
    int package_type;               // 包裹类型（1-文件 2-生鲜 3-易碎品 4-家电 5-危险品）
    char order_time[20];            // 下单时间，格式如"YYYY-MM-DD HH:MM:SS"
    double shipping_fee;            // 运输费用
    int package_status;             // 包裹状态（可枚举：1-已提交，2-运输中，3-已签收，4-延迟）
    char description[200];          // 包裹描述，可选项
    struct package_s *next;         // 指向下一个包裹节点（链表结构）
};

// 用户结构体定义
struct customer {
    int user_id;                    // 用户唯一标识符
    char username[50];              // 用户名，用于登录
    char phone_number[20];          // 用户联系电话
    char password[50];              // 用户密码
    int customer_type;              // 用户类型（1-普通用户 2-vip用户 3-企业用户 4-学生用户 5-老年用户）
    struct package_r *received_packages;    // 用户收件包裹链表
    struct package_s *send_packages;        // 用户寄件包裹链表
    struct customer *next;          // 指向下一个用户节点（链表结构）
};

#endif // USER_H
