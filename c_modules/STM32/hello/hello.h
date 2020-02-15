// 首先包含必要的定义
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"

// 定义hello模块里的常量   
enum { 
        CONSTANTS0, 
        CONSTANTS1,   
     };
////////////////////////////////////////////////////////////////////////////////////////
// 定义hello模块里的函数     
STATIC mp_obj_t hello_world(mp_obj_t echo_obj);
// 定义hello模块里函数的引用macro
MP_DEFINE_CONST_FUN_OBJ_1(hello_hello_world_obj, hello_world);
////////////////////////////////////////////////////////////////////////////////////////
//extern const mp_obj_type_t hello_math_obj;//引用外部定义
////////////////////////////////////////////////////////////////////////////////////////
// 定义模块的所有属性值对
STATIC const mp_rom_map_elem_t hello_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_hello) }, /*python暴露名hello与python暴露名__name__关联*/
    { MP_ROM_QSTR(MP_QSTR_hello_world), MP_ROM_PTR(&hello_hello_world_obj) }, /*python暴露名hello_world与函数引用关联*/
    { MP_ROM_QSTR(MP_QSTR_C0), MP_ROM_INT(CONSTANTS0)}, /*python暴露名C0与常量CONSTANTS0关联*/
    { MP_ROM_QSTR(MP_QSTR_C1), MP_ROM_INT(CONSTANTS1)}, /*python暴露名C1与常量CONSTANTS1关联*/
    //{ MP_ROM_QSTR(MP_QSTR_math), MP_ROM_PTR(&hello_math_obj)}, /*python暴露名math与math类（type）关联*/
};
// 定义模块的字典macro
STATIC MP_DEFINE_CONST_DICT(hello_module_globals, hello_module_globals_table);

// 定义模块的实体
const mp_obj_module_t hello_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&hello_module_globals,
};

// 注册模块实体到暴露名，并关联一个使能常量macro
/*python暴露名hello*/
/*模块实体*/
MP_REGISTER_MODULE(MP_QSTR_hello, hello_user_cmodule, MODULE_HELLO_ENABLED);


