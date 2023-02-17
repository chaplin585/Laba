#include "../src/libComputer/mySimpleComputer.h"
#include <cstdio>
#include "../thirdparty/ctest.h"

using namespace std;

// test checkfile
CTEST(check_data, True_address_sc_memorySet)
{
    sc_memoryInit();
    int check = sc_memorySet(1, 1);

    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_address_sc_memorySet)
{
    sc_memoryInit();
    int check = sc_memorySet(101, 1);

    ASSERT_EQUAL(-1, check);
}
CTEST(check_data, True_address_sc_memoryGet)
{
    sc_memoryInit();
    sc_memorySet(1, 1);
    int value = 0;
    int check = sc_memoryGet(1, &value);
    ASSERT_EQUAL(0, check);
}
