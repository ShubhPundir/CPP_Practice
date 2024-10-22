
void unoptimized(void) f{
    static int i;
    i = 0;
    while (i != 100);
}
// This is an innite loop! Hence the compiler should optimize as:
void optimized(void) f{
    i = 0;
    while (1); // compiler optimizes
}

void volatileFun(){
    static volatile int i;
    i = 0;
    while (i != 100); // Compiler does not optimize
    // Being volatile, i can be changed by hardware anytime. It waits till the value becomes 100
    // (possibly some hardware writes to a port).
}