#include <gtest\gtest.h>
#include <boost\shared_ptr.hpp>
#include <boost\make_shared.hpp>
#include "container.hpp"
#include "consumer_types.h"

//////////////////////////////////////////////////////////////////////////
// Tests object lifetimes using various lifestyle approaches.

typedef consumer_types<ioc::transient_t> transient_types;
typedef consumer_types<ioc::singleton_t> singleton_types;
typedef consumer_types<ioc::singleton_t, ioc::singleton_t, ioc::transient_t> mixed_types;

class Test_Lifetime : public testing::Test
{
public:

    virtual void SetUp()
    {
        ConsumerTypesResetCounters();
    }
};

TEST_F(Test_Lifetime, TransientConstructors)
{
    ioc::container container;
    container.registerType<transient_types::_Consumer3>();
    boost::shared_ptr<Consumer3> obj = container.resolve<Consumer3>();

    EXPECT_TRUE(obj->Svc1->SubSvc1 != obj->Svc2->SubSvc1);
    EXPECT_TRUE(obj->Svc2->SubSvc1 != obj->Svc3->SubSvc1);
    EXPECT_TRUE(obj->Svc3->SubSvc1 != obj->Svc1->SubSvc1);

    EXPECT_EQ(1, Consumer3::CtorCount);
    EXPECT_EQ(1, Svc1::CtorCount);
    EXPECT_EQ(1, Svc2::CtorCount);
    EXPECT_EQ(1, Svc3::CtorCount);
    EXPECT_EQ(3, SubSvc1::CtorCount);
    EXPECT_EQ(2, SubSvc2::CtorCount);
    EXPECT_EQ(1, SubSvc3::CtorCount);
}

TEST_F(Test_Lifetime, TransientDestructors)
{
    ioc::container container;
    container.registerType<transient_types::_Consumer1>();
    boost::shared_ptr<Consumer1> obj = container.resolve<Consumer1>();

    EXPECT_EQ(0, Consumer1::DtorCount);
    EXPECT_EQ(0, Svc1::DtorCount);

    obj.reset();

    EXPECT_EQ(1, Consumer1::DtorCount);
    EXPECT_EQ(1, Svc1::DtorCount);
}

TEST_F(Test_Lifetime, SingletonConstructors)
{
    ioc::container container;
    container.registerType<singleton_types::_Consumer3>();
    boost::shared_ptr<Consumer3> obj = container.resolve<Consumer3>();

    EXPECT_TRUE(obj->Svc1->SubSvc1 == obj->Svc2->SubSvc1);
    EXPECT_TRUE(obj->Svc2->SubSvc1 == obj->Svc3->SubSvc1);
    EXPECT_TRUE(obj->Svc3->SubSvc1 == obj->Svc1->SubSvc1);

    EXPECT_EQ(1, Consumer3::CtorCount);
    EXPECT_EQ(1, Svc1::CtorCount);
    EXPECT_EQ(1, Svc2::CtorCount);
    EXPECT_EQ(1, Svc3::CtorCount);
    EXPECT_EQ(1, SubSvc1::CtorCount);
    EXPECT_EQ(1, SubSvc2::CtorCount);
    EXPECT_EQ(1, SubSvc3::CtorCount);
}

TEST_F(Test_Lifetime, SingletonDestructors)
{
    boost::shared_ptr<ioc::container> container = boost::make_shared<ioc::container>();
    container->registerType<singleton_types::_Consumer1>();
    boost::shared_ptr<Consumer1> obj = container->resolve<Consumer1>();

    obj.reset();

    EXPECT_EQ(0, Consumer1::DtorCount);
    EXPECT_EQ(0, Svc1::DtorCount);

    container.reset();

    EXPECT_EQ(1, Consumer1::DtorCount);
    EXPECT_EQ(1, Svc1::DtorCount);
}

TEST_F(Test_Lifetime, SingletonConsumerAndTransientService)
{
    ioc::container container;
    container.registerType<mixed_types::_Svc1>();
    
    boost::shared_ptr<Svc1> firstSvc1 = container.resolve<Svc1>();
    boost::shared_ptr<Svc1> secondSvc1 = container.resolve<Svc1>();
    EXPECT_EQ(1, SubSvc1::CtorCount);
}
