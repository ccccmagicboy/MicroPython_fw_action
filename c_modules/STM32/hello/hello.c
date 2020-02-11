#include "py/runtime.h"

STATIC mp_obj_t hello_world(
        mp_obj_t echo_obj) {
    const char* echo = mp_obj_str_get_str(echo_obj);
    bool result;

    // Your code here!
    printf("echo this: %s", echo);

    // Example exception
    if (some_val == 0) {
        mp_raise_ValueError("some_val can't be zero!");
    }

    return mp_obj_new_bool(result);
}
MP_DEFINE_CONST_FUN_OBJ_1(hello_world_obj, hello_world);

// Copy the uncommented line into your map table
// STATIC const mp_rom_map_elem_t my_module_globals_table[] = {
    // { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_builtins) },
    { MP_ROM_QSTR(MP_QSTR_hello_world), MP_ROM_PTR(&hello_world_obj) },
    // Example constant
    { MP_ROM_QSTR(MP_QSTR_EXAMPLE_CONST), MP_ROM_INT(123) },
// };