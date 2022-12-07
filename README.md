# XINU + GDB Pratice

- Step 1: Building XINU

    To compile the XINU kernel, run `make` in the `compile` directory as follows:

    ```shell
    cd gdb_practice/compile
    make depend
    make
    ```
    This creates an OS image called `xinu.elf`.

    If you use the local QEMU environment, you may need to change two lines in the Makefile:

    ```
    LD      =       /usr/bin/ld
    ```
    to
    ```
    LD      =       /usr/bin/gcc
    ```
    and
    ```
        $(LD) -m elf_i386 -dn -Ttext 0x10000 -e start ${XOBJ} ${OBJ} ${LIB}/libxc.a \
    ```
    to
    ```
        $(LD) -m32 -dn -Ttext 0x10000 -e start ${XOBJ} ${OBJ} ${LIB}/libxc.a \
    ```

- Step 4: Running and debugging XINU

    The XINU image runs on the QEMU emulator machines. To boot up the image, type:
    ```shell
    make run
    ```
    XINU should start running and print a message "Hello World, Xinu lives."

    Typing "Ctrl-a" then "c" will always bring you to "(qemu)" prompt. From there, you can quit by typing `q`.

    To debug XINU, run the image in the debug mode by:
    ```shell
    make debug
    ```
    Then execute GDB in another ssh session:
    ```shell
    gdb xinu.elf
    ```
    In the (gdb) console, connect to the remote server by:
    ```
    target remote localhost:1234
    ```
    You can use many debugging features provided by GDB, e.g., adding a break point at the main function:
    ```
    b main
    ```
    To run to the next breakpoint, type:
    ```
    c
    ```
    The detailed document for GDB can be found [here](https://www.sourceware.org/gdb).

