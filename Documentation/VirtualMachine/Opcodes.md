# List of Opcodes

*   `add` **[$1: number, $2: number]** - Add two numbers and push them to the stack

*   `allocate` **[$mem_size: number]** - Allocate `$mem_size` bytes of memory from the heap

*   `free` **[$addr: liz_address]** - Unallocate memory blocks attached to `$liz_address`

*   `imut` **[$name: varname, $2: value (of type $1)]** - Create an immutable variable (const) with the name provided

*   `mov_number` **[$dest: [liz_address|register], $source: number]** - Move a value of type `number` into the `$dest` address space, e.g. `mov_number x 10`

*   `mut` **[$name: varname]** - Create a variable with the name provided, e.g. `mut x`

*   `put_character` **[$char_to_print: char]** - Put a single character to stdout

*   `return` - Pop `stack_top` and return its value

*   `set_type` **[$name: varname, $var_type: type]** - Set type of variable

