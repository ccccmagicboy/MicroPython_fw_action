#include "py/runtime.h"
#include <stdio.h>

STATIC mp_obj_t hello_world(
        mp_obj_t echo_obj) {
    const char* echo = mp_obj_str_get_str(echo_obj);
    bool result;

    // Your code here!
    printf("the input is: %s\n", echo);

    result = 1;
    
    

    

    return mp_obj_new_bool(result);
}
MP_DEFINE_CONST_FUN_OBJ_1(hello_world_obj, hello_world);

// Copy the uncommented line into your map table
STATIC const mp_rom_map_elem_t hello_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_hello) },
    { MP_ROM_QSTR(MP_QSTR_hello_world), MP_ROM_PTR(&hello_world_obj) },
};