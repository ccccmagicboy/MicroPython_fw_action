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


