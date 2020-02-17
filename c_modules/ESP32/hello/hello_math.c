// 首先包含必要的定义
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"
// 包含标准库
#include <stdio.h>
// 包含这个模块用的头文件
#include "hello_math.h"

// 自定义一个函数
// https://mpy-c-gen.oliverrobson.tech/
// 以上网址可生成函数接口模板

// 定义math类的构造函数
STATIC mp_obj_t math_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args)
{
    mp_arg_check_num(n_args, n_kw, 0, 0, true); //检查参数的个数
    math_obj_t *self = m_new_obj(math_obj_t);   //分配内存空间
    self->base.type = &hello_math_obj;          //结构体实体化与类实体关联
    return MP_OBJ_FROM_PTR(self);               //返回分配的指针
}
// 定义math类里的函数     
STATIC mp_obj_t math_add(mp_obj_t self_in, mp_obj_t data)
{
    math_obj_t *self = MP_OBJ_TO_PTR(self_in);  //从第一参数里取出类self
    self->value1 = 100;
    self->value2 = 200;
    self->value3 = mp_obj_get_int(data);    //从第二个参数里取出一个整形
    printf("100 + 200 + %d =\n", self->value3);
    return mp_obj_new_int(self->value1 + self->value2 + self->value3);//返回计算结果
}
//print()时调用的函数
STATIC void math_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind)
{
    math_obj_t *self = MP_OBJ_TO_PTR(self_in);
    mp_printf(print, "value3 is %d", self->value3);
}

// 定义math类里引出public函数的引用macro
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



