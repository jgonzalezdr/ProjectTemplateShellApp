/*
 * This file has been auto-generated by CppUTestMock v0.3.1.
 *
 * Contents will NOT be preserved if it is regenerated!!!
 */

#include "ExamplePrivateClass.hpp"

#include <CppUTestExt/MockSupport.h>

int ExamplePrivateClass::f2(int a, int b)
{
    return mock().actualCall("ExamplePrivateClass::f2")./*onObject(this).*/withIntParameter("a", a).withIntParameter("b", b).returnIntValue();
}

