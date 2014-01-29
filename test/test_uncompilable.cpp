#include <gtest\gtest.h>
#include "container.hpp"
#include "consumer_types.h"

//////////////////////////////////////////////////////////////////////////
// Tests invalid input parameters. Uncomment to drive the compiler 
// some nuts.

typedef consumer_types<ioc::transient_t> types;

TEST(Test_Uncompilable, TooManyDependencies)
{
    /*
    typedef ioc::descriptor_t<
        Svc9,
        ioc::transient_t,
        ioc::dependency_t<types::_SubSvc1>, 
        ioc::dependency_t<types::_SubSvc2>, 
        ioc::dependency_t<types::_SubSvc3>, 
        ioc::dependency_t<types::_SubSvc4>, 
        ioc::dependency_t<types::_SubSvc5>, 
        ioc::dependency_t<types::_SubSvc6>, 
        ioc::dependency_t<types::_SubSvc7>, 
        ioc::dependency_t<types::_SubSvc8>, 
        ioc::dependency_t<types::_SubSvc9>
    > _Svc9;
    */
}

TEST(Test_Uncompilable, WrongDependencyDescriptor)
{
    /*
    typedef ioc::descriptor_t<
        Svc1,
        ioc::transient_t, 
        ioc::dependency_t<types::_SubSvc2>
    > _Svc1;

    ioc::container container;
    container.registerType<_Svc1>();
    */
}

TEST(Test_Uncompilable, ExcessiveDescriptor)
{
    /*
    typedef ioc::descriptor_t<
        Svc1,
        ioc::transient_t, 
        ioc::dependency_t<types::_SubSvc1>, 
        ioc::dependency_t<types::_SubSvc2>
    > _Svc1;

    ioc::container container;
    container.registerType<_Svc1>();
    */
}

TEST(Test_Uncompilable, InsufficientDescriptor)
{
    /*
    typedef ioc::descriptor_t<
        Svc3,
        ioc::transient_t, 
        ioc::dependency_t<types::_SubSvc1>,
        ioc::dependency_t<types::_SubSvc2>
    > _Svc3;

    ioc::container container;
    container.registerType<_Svc3>();
    */
}
