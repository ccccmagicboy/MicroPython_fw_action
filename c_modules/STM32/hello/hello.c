// 首先包含必要的定义
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"
// 包含标准库
#include <stdio.h>
// 包含这个模块用的头文件
#include "hello.h"

// 自定义一个函数
// https://mpy-c-gen.oliverrobson.tech/
// 以上网址可生成函数接口模板

mp_obj_t hello_world(mp_obj_t echo_obj) 
{
    const char* echo = mp_obj_str_get_str(echo_obj);
    bool result;

    // Your code here!
    printf("the input is: %s\n", echo);

    result = 1;

    return mp_obj_new_bool(result);
}

mp_obj_t math_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args)
{
    mp_arg_check_num(n_args, n_kw, 0, 0, true); //检查参数的个数
    math_obj_t *self = m_new_obj(math_obj_t);   //分配内存空间
    self->base.type = &hello_math_obj;          //结构体实体化与类实体关联
    return MP_OBJ_FROM_PTR(self);               //返回分配的指针
}

mp_obj_t math_add(mp_obj_t self_in, mp_obj_t data)
{
    math_obj_t *self = MP_OBJ_TO_PTR(self_in);  //从第一参数里取出类self
    self->value1 = 100;
    self->value2 = 200;
    self->value3 = mp_obj_get_int(data);    //从第二个参数里取出一个整形
    printf("100 + 200 + %d =\n", self->value3);
    return mp_obj_new_int(self->value1 + self->value2 + self->value3);//返回计算结果
}



