#include <stdio.h>

const char *aws_crt_init(void);
const char *aws_crt_clean_up(void);
const char *aws_crt_test_error(int);
const char *aws_crt_mem_acquire(size_t size);
const char *aws_crt_mem_release(void *mem);

const char *aws_crt_init() {
    return "calling aws_crt_init";
}

const char *aws_crt_clean_up() {
    return "calling aws_crt_clean_up";
}

const char *aws_crt_test_error(int a) {
    return "calling aws_crt_test_error";
}

const char *aws_crt_mem_acquire(size_t size) {
    return "calling aws_crt_mem_acquire";
}

const char *aws_crt_mem_release(void *mem) {
    return "calling aws_crt_mem_release";
}
