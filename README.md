# XINU + GDB Pratice

- Step 1: Building XINU

    To compile the XINU kernel, run `make` in the `compile` directory as follows:

    ```shell
    cd compile
    make depend
    make
    ```
    This creates an OS image called `xinu.elf`.    

- Step 2: Running and debugging XINU

    The XINU image runs on the QEMU emulator machines. To boot up the image, type:
    ```shell
    make run
    ```
    XINU should start running and print messages.

    Typing `Ctrl-a` then `c` (not `Ctrl-c`) will always bring you to "(qemu)" prompt. From there, you can quit by typing `q`.

    To debug XINU, run the image in the **debug mode** by:
    ```shell
    make debug
    ```
    Then execute GDB in **another ssh session**:
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
