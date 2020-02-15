// 首先包含必要的定义
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"

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

// 定义math类的构造函数
STATIC mp_obj_t math_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
// 定义math类里的函数     
STATIC mp_obj_t math_add(mp_obj_t self_in, mp_obj_t data);
STATIC void math_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind);
// 定义math类里函数的引用macro
MP_DEFINE_CONST_FUN_OBJ_2(math_add_obj, math_add);
// 定义math类里的所有属性值对
STATIC const mp_rom_map_elem_t math_type_locals_table[] = {
    { MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&math_add_obj) },/*python暴露名add与函数引用关联*/
    { MP_ROM_QSTR(MP_QSTR_C0), MP_ROM_INT(CONSTANTS0)}, /*python暴露名C0与常量CONSTANTS0关联*/
    { MP_ROM_QSTR(MP_QSTR_C1), MP_ROM_INT(CONSTANTS1)}, /*python暴露名C1与常量CONSTANTS1关联*/
};
// 定义math类的字典macro
STATIC MP_DEFINE_CONST_DICT(math_type_locals, math_type_locals_table);
// 定义math类的实体
const mp_obj_type_t hello_math_obj = {
    .base = { &mp_type_type },  /*这里与module不同*/
    .name = MP_QSTR_math,       /*python暴露名在这里定义*/
    .print = math_print,        //print()时调用的函数
    .make_new = math_new,       //构造函数
    .locals_dict = (mp_obj_dict_t*)&math_type_locals,
};


