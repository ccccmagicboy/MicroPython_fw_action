// 首先包含必要的定义
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"
// 包含标准库
#include <stdio.h>
// 自定义一个函数
STATIC mp_obj_t hello_world(mp_obj_t echo_obj) 
{
    const char* echo = mp_obj_str_get_str(echo_obj);
    bool result;

    // Your code here!
    printf("the input is: %s\n", echo);

    result = 1;

    return mp_obj_new_bool(result);
}
// 定义一个对以上函数的引用
MP_DEFINE_CONST_FUN_OBJ_1(hello_world_obj, hello_world);
// 这个定义module的所有属性值
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t hello_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_hello) },
    { MP_ROM_QSTR(MP_QSTR_hello_world), MP_ROM_PTR(&hello_world_obj) },
};
STATIC MP_DEFINE_CONST_DICT(hello_module_globals, hello_module_globals_table);
// 定义这个module实体对象
const mp_obj_module_t hello_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&hello_module_globals,
};
// 注册这个module，并留一个活口开关
MP_REGISTER_MODULE(MP_QSTR_hello, hello_user_cmodule, MODULE_HELLO_ENABLED);



