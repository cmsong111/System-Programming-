#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int *)malloc(sizeof(int)); // 메모리 동적 할당

    if (ptr == NULL) {
        printf("메모리 할당 오류\n");
        return 1;
    }

    // 메모리를 사용하지만, 해제하지 않음

    return 0;
}
