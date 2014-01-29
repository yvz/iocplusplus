#include <gtest\gtest.h>
#include <boost\mpl\vector.hpp>
#include "container.hpp"
#include "consumer_types.h"

//////////////////////////////////////////////////////////////////////////
// Tests registration interface.

typedef consumer_types<ioc::transient_t> types;

TEST(Test_Registration, RegisterOne)
{
    ioc::container container;
    container.registerType<types::_SubSvc1>();
    EXPECT_TRUE(container.isRegistered<SubSvc1>());
}

TEST(Test_Registration, RegisterMany)
{
    ioc::container container;
    container.registerTypes< boost::mpl::vector<types::_SubSvc1, types::_SubSvc2> >();
    EXPECT_TRUE(container.isRegistered<SubSvc1>());
    EXPECT_TRUE(container.isRegistered<SubSvc2>());
}

TEST(Test_Registration, NestedTypeIsNotRegistered)
{
    ioc::container container;
    container.registerType<types::_Svc1>();
    EXPECT_FALSE(container.isRegistered<SubSvc1>());
}

TEST(Test_Registration, UnregisteredTypeDoesNotResolve)
{
    ioc::container container;
    container.registerType<types::_Svc1>();
    EXPECT_THROW(container.resolve<SubSvc1>(), ioc::unregistred_type);
}
