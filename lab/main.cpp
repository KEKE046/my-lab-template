#include<log.h>
#include<iostream>

void bar() {
    logd("123", 456);
    logi("123", 456);
    logn("123", 456);
    logp("123", 456);
    logw("123", 456);
    loge("123", 456);
}

void foo() {
    bar();
}

int main() {
    foo();
    return 0;
}