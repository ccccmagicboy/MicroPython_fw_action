#include "py/nlr.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/binary.h"
#include "portmodules.h"
#include <string.h>
#include <stdio.h>

STATIC mp_obj_t c_sample_set_callback(mp_obj_t callback_obj) {
    MP_STATE_PORT(c_sample_callback_obj) = callback_obj;
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(c_sample_set_callback_obj, c_sample_set_callback);

STATIC mp_obj_t c_sample_call_callback(void) {
#if 1
    vstr_t vstr;
    vstr_init_len(&vstr, strlen("some_string"));
    strcpy(vstr.buf, "some_string");
    mp_obj_t obj = mp_obj_new_str_from_vstr(&mp_type_bytes, &vstr);
#else
    mp_obj_t obj = mp_obj_new_str("some_string", strlen("some_string"), false);
#endif
    return mp_call_function_1(MP_STATE_PORT(c_sample_callback_obj), obj);
    //return mp_call_function_0(MP_STATE_PORT(c_sample_callback_obj));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(c_sample_call_callback_obj, c_sample_call_callback);

STATIC mp_obj_t c_sample_func_0(void) {
    printf("c_sample_func_0\n");
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(c_sample_func_0_obj, c_sample_func_0);

STATIC mp_obj_t c_sample_func_1(mp_obj_t arg1) {
    printf("c_sample_func_1: arg1 = ");
    mp_obj_print(arg1, PRINT_STR);
    printf("\n");
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(c_sample_func_1_obj, c_sample_func_1);

STATIC mp_obj_t c_sample_func_2(mp_obj_t arg1, mp_obj_t arg2) {
    printf("c_sample_func_2: arg1 = ");
    mp_obj_print(arg1, PRINT_STR);
    printf(", arg2 = ");
    mp_obj_print(arg2, PRINT_STR);
    printf("\n");
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(c_sample_func_2_obj, c_sample_func_2);

STATIC mp_obj_t c_sample_func_3(mp_obj_t arg1, mp_obj_t arg2, mp_obj_t arg3) {
    printf("c_sample_func_3: arg1 = ");
    mp_obj_print(arg1, PRINT_STR);
    printf(", arg2 = ");
    mp_obj_print(arg2, PRINT_STR);
    printf(", arg3 = ");
    mp_obj_print(arg3, PRINT_STR);
    printf("\n");
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(c_sample_func_3_obj, c_sample_func_3);

STATIC mp_obj_t c_sample_func_var(mp_uint_t n_args, const mp_obj_t *args) {
    printf("c_sample_func_var: num_args = %d\n", n_args);
    for (int i = 0; i < n_args; i++) {
        printf("  arg[%d] = ", i);
        mp_obj_print(args[i], PRINT_STR);
        printf("\n");
    }
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR(c_sample_func_var_obj, 0, c_sample_func_var);

STATIC mp_obj_t c_sample_func_int(mp_obj_t num) {
    printf("c_sample_func_int: num = %d\n", mp_obj_get_int(num));
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(c_sample_func_int_obj, c_sample_func_int);

STATIC mp_obj_t c_sample_func_str(mp_obj_t str) {
    printf("c_sample_func_str: str = '%s'\n", mp_obj_str_get_str(str));
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(c_sample_func_str_obj, c_sample_func_str);

STATIC const mp_rom_map_elem_t c_sample_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_c_sample) },
    { MP_ROM_QSTR(MP_QSTR_set_callback), MP_ROM_PTR(&c_sample_set_callback_obj) },
    { MP_ROM_QSTR(MP_QSTR_call_callback), MP_ROM_PTR(&c_sample_call_callback_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_0), MP_ROM_PTR(&c_sample_func_0_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_1), MP_ROM_PTR(&c_sample_func_1_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_2), MP_ROM_PTR(&c_sample_func_2_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_3), MP_ROM_PTR(&c_sample_func_3_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_var), MP_ROM_PTR(&c_sample_func_var_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_int), MP_ROM_PTR(&c_sample_func_int_obj) },
    { MP_ROM_QSTR(MP_QSTR_func_str), MP_ROM_PTR(&c_sample_func_str_obj) },
};

STATIC MP_DEFINE_CONST_DICT(mp_module_c_sample_globals, c_sample_globals_table);

const mp_obj_module_t mp_module_c_sample = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_c_sample_globals,
};

