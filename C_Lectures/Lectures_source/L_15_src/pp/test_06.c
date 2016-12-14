#define BUILD_BUG_ON(condition) ((void) sizeof(char[1 - 2*!!(condition)]))

struct test
{
    int a;
    int b;
};

int main(void)
{
    BUILD_BUG_ON(sizeof(struct test) != 8);

    return 0;
}
