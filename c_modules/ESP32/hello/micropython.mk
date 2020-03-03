HELLO_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(HELLO_MOD_DIR)/hello.c
SRC_USERMOD += $(HELLO_MOD_DIR)/hello_math.c

# We can add our module folder to include paths if needed
# This is not actually needed in this example.
CFLAGS_USERMOD += -I$(HELLO_MOD_DIR) -DMODULE_HELLO_ENABLED=1


