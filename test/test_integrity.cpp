#include <gtest\gtest.h>
#include <boost\shared_ptr.hpp>
#include "container.hpp"
#include "consumer_types.h"

//////////////////////////////////////////////////////////////////////////
// Verify integrity of generators and constructors by resolving 
// an extensive Consumer - Service - SubService hierarchy. 
// Consumer and Service layers have types with 0 to 8 dependencies. Thus 
// each specification of generator and constructor is tested in root and 
// nested position.

typedef consumer_types<ioc::transient_t> types;

class Test_Integrity : public testing::Test
{
public:

    void AssertSvcNotNull(const boost::shared_ptr<Svc1>& svc1)
    {
        ASSERT_TRUE(svc1 != 0);
        EXPECT_TRUE(svc1->SubSvc1 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc2>& svc2)
    {
        ASSERT_TRUE(svc2 != 0);
        EXPECT_TRUE(svc2->SubSvc1 != 0);
        EXPECT_TRUE(svc2->SubSvc2 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc3>& svc3)
    {
        ASSERT_TRUE(svc3 != 0);
        EXPECT_TRUE(svc3->SubSvc1 != 0);
        EXPECT_TRUE(svc3->SubSvc2 != 0);
        EXPECT_TRUE(svc3->SubSvc3 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc4>& svc4)
    {
        ASSERT_TRUE(svc4 != 0);
        EXPECT_TRUE(svc4->SubSvc1 != 0);
        EXPECT_TRUE(svc4->SubSvc2 != 0);
        EXPECT_TRUE(svc4->SubSvc3 != 0);
        EXPECT_TRUE(svc4->SubSvc4 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc5>& svc5)
    {
        ASSERT_TRUE(svc5 != 0);
        EXPECT_TRUE(svc5->SubSvc1 != 0);
        EXPECT_TRUE(svc5->SubSvc2 != 0);
        EXPECT_TRUE(svc5->SubSvc3 != 0);
        EXPECT_TRUE(svc5->SubSvc4 != 0);
        EXPECT_TRUE(svc5->SubSvc5 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc6>& svc6)
    {
        ASSERT_TRUE(svc6 != 0);
        EXPECT_TRUE(svc6->SubSvc1 != 0);
        EXPECT_TRUE(svc6->SubSvc2 != 0);
        EXPECT_TRUE(svc6->SubSvc3 != 0);
        EXPECT_TRUE(svc6->SubSvc4 != 0);
        EXPECT_TRUE(svc6->SubSvc5 != 0);
        EXPECT_TRUE(svc6->SubSvc6 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc7>& svc7)
    {
        ASSERT_TRUE(svc7 != 0);
        EXPECT_TRUE(svc7->SubSvc1 != 0);
        EXPECT_TRUE(svc7->SubSvc2 != 0);
        EXPECT_TRUE(svc7->SubSvc3 != 0);
        EXPECT_TRUE(svc7->SubSvc4 != 0);
        EXPECT_TRUE(svc7->SubSvc5 != 0);
        EXPECT_TRUE(svc7->SubSvc6 != 0);
        EXPECT_TRUE(svc7->SubSvc7 != 0);
    }

    void AssertSvcNotNull(const boost::shared_ptr<Svc8>& svc8)
    {
        ASSERT_TRUE(svc8 != 0);
        EXPECT_TRUE(svc8->SubSvc1 != 0);
        EXPECT_TRUE(svc8->SubSvc2 != 0);
        EXPECT_TRUE(svc8->SubSvc3 != 0);
        EXPECT_TRUE(svc8->SubSvc4 != 0);
        EXPECT_TRUE(svc8->SubSvc5 != 0);
        EXPECT_TRUE(svc8->SubSvc6 != 0);
        EXPECT_TRUE(svc8->SubSvc7 != 0);
        EXPECT_TRUE(svc8->SubSvc8 != 0);
    }
};

TEST_F(Test_Integrity, DependencyCount0)
{
    ioc::container container;
    container.registerType<types::_Consumer0>();
    boost::shared_ptr<Consumer0> obj = container.resolve<Consumer0>();

    ASSERT_TRUE(obj != 0);
}

TEST_F(Test_Integrity, DependencyCount1)
{
    ioc::container container;
    container.registerType<types::_Consumer1>();
    boost::shared_ptr<Consumer1> obj = container.resolve<Consumer1>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
}

TEST_F(Test_Integrity, DependencyCount2)
{
    ioc::container container;
    container.registerType<types::_Consumer2>();
    boost::shared_ptr<Consumer2> obj = container.resolve<Consumer2>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
}

TEST_F(Test_Integrity, DependencyCount3)
{
    ioc::container container;
    container.registerType<types::_Consumer3>();
    boost::shared_ptr<Consumer3> obj = container.resolve<Consumer3>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
    AssertSvcNotNull(obj->Svc3);
}

TEST_F(Test_Integrity, DependencyCount4)
{
    ioc::container container;
    container.registerType<types::_Consumer4>();
    boost::shared_ptr<Consumer4> obj = container.resolve<Consumer4>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
    AssertSvcNotNull(obj->Svc3);
    AssertSvcNotNull(obj->Svc4);
}

TEST_F(Test_Integrity, DependencyCount5)
{
    ioc::container container;
    container.registerType<types::_Consumer5>();
    boost::shared_ptr<Consumer5> obj = container.resolve<Consumer5>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
    AssertSvcNotNull(obj->Svc3);
    AssertSvcNotNull(obj->Svc4);
    AssertSvcNotNull(obj->Svc5);
}

TEST_F(Test_Integrity, DependencyCount6)
{
    ioc::container container;
    container.registerType<types::_Consumer6>();
    boost::shared_ptr<Consumer6> obj = container.resolve<Consumer6>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
    AssertSvcNotNull(obj->Svc3);
    AssertSvcNotNull(obj->Svc4);
    AssertSvcNotNull(obj->Svc5);
    AssertSvcNotNull(obj->Svc6);
}

TEST_F(Test_Integrity, DependencyCount7)
{
    ioc::container container;
    container.registerType<types::_Consumer7>();
    boost::shared_ptr<Consumer7> obj = container.resolve<Consumer7>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
    AssertSvcNotNull(obj->Svc3);
    AssertSvcNotNull(obj->Svc4);
    AssertSvcNotNull(obj->Svc5);
    AssertSvcNotNull(obj->Svc6);
    AssertSvcNotNull(obj->Svc7);
}

TEST_F(Test_Integrity, DependencyCount8)
{
    ioc::container container;
    container.registerType<types::_Consumer8>();
    boost::shared_ptr<Consumer8> obj = container.resolve<Consumer8>();

    ASSERT_TRUE(obj != 0);
    AssertSvcNotNull(obj->Svc1);
    AssertSvcNotNull(obj->Svc2);
    AssertSvcNotNull(obj->Svc3);
    AssertSvcNotNull(obj->Svc4);
    AssertSvcNotNull(obj->Svc5);
    AssertSvcNotNull(obj->Svc6);
    AssertSvcNotNull(obj->Svc7);
    AssertSvcNotNull(obj->Svc8);
}
