#include <stdio.h>
#include <assert.h>

// Dummy functions to test, replace these with actual functions in your kernel
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void test_add() {
    int result = add(2, 3);
    printf("Testing add function...\n");
    assert(result == 5);  // Should pass if add(2, 3) == 5
    printf("Add test passed!\n");
}

void test_subtract() {
    int result = subtract(5, 3);
    printf("Testing subtract function...\n");
    assert(result == 2);  // Should pass if subtract(5, 3) == 2
    printf("Subtract test passed!\n");
}

int main() {
    printf("Starting Kernel Tests...\n");
    
    // Run individual tests
    test_add();
    test_subtract();
    
    printf("All tests passed!\n");
    
    return 0;
}
