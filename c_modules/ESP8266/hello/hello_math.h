////////////////////////////////////////////////////////////////////////////////////////
// 定义math类里的常量   
enum { 
        CONSTANTS0, 
        CONSTANTS1,   
     };

typedef struct _math_obj_t
{
    mp_obj_base_t base;/*这个类成员是必须的*/
    uint16_t value1;//成员变量value1
    uint16_t value2;//成员变量value2
    uint16_t value3;//成员变量value3
}math_obj_t;/*定义math类的结构体*/

const mp_obj_type_t hello_math_obj;

