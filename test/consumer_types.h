#ifndef CONSUMER_TYPES_H
#define CONSUMER_TYPES_H

#include <boost/shared_ptr.hpp>
#include "dependency.hpp"

//////////////////////////////////////////////////////////////////////////
// Hierarchy outline
//
// Consumer8
//   Svc1
//     SubSvc1
//   Svc2
//     SubSvc1
//     SubSvc2
//   Svc3
//     SubSvc1
//     SubSvc2
//     SubSvc3
//   ... 
//   Svc8
//     SubSvc1
//     SubSvc2
//     SubSvc3
//     SubSvc4
//     SubSvc5
//     SubSvc6
//     SubSvc7
//     SubSvc8

//////////////////////////////////////////////////////////////////////////
// Consumer

class Svc0;
class Svc1;
class Svc2;
class Svc3;
class Svc4;
class Svc5;
class Svc6;
class Svc7;
class Svc8;
class Svc9;

class Consumer0
{
public:
    Consumer0() { CtorCount++; }
    virtual ~Consumer0() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class Consumer1
{
public:
    Consumer1(const boost::shared_ptr<Svc1>& svc1) : Svc1(svc1) { CtorCount++; }
    virtual ~Consumer1() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
};

class Consumer2
{
public:
    Consumer2(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2) 
            : Svc1(svc1), Svc2(svc2) { CtorCount++; }

    virtual ~Consumer2() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
};

class Consumer3
{
public:
    Consumer3(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2,
        const boost::shared_ptr<Svc3>& svc3) 
            : Svc1(svc1), Svc2(svc2), Svc3(svc3) { CtorCount++; }

    virtual ~Consumer3() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
    boost::shared_ptr<Svc3> Svc3;
};

class Consumer4
{
public:
    Consumer4(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2,
        const boost::shared_ptr<Svc3>& svc3,
        const boost::shared_ptr<Svc4>& svc4) 
            : Svc1(svc1), Svc2(svc2), Svc3(svc3), Svc4(svc4) { CtorCount++; }

    virtual ~Consumer4() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
    boost::shared_ptr<Svc3> Svc3;
    boost::shared_ptr<Svc4> Svc4;
};

class Consumer5
{
public:
    Consumer5(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2,
        const boost::shared_ptr<Svc3>& svc3,
        const boost::shared_ptr<Svc4>& svc4,
        const boost::shared_ptr<Svc5>& svc5) 
            : Svc1(svc1), Svc2(svc2), Svc3(svc3), Svc4(svc4), Svc5(svc5) { CtorCount++; }

    virtual ~Consumer5() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
    boost::shared_ptr<Svc3> Svc3;
    boost::shared_ptr<Svc4> Svc4;
    boost::shared_ptr<Svc5> Svc5;
};

class Consumer6
{
public:
    Consumer6(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2,
        const boost::shared_ptr<Svc3>& svc3,
        const boost::shared_ptr<Svc4>& svc4,
        const boost::shared_ptr<Svc5>& svc5,
        const boost::shared_ptr<Svc6>& svc6) 
            : Svc1(svc1), Svc2(svc2), Svc3(svc3), Svc4(svc4), Svc5(svc5), Svc6(svc6) { CtorCount++; }

    virtual ~Consumer6() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
    boost::shared_ptr<Svc3> Svc3;
    boost::shared_ptr<Svc4> Svc4;
    boost::shared_ptr<Svc5> Svc5;
    boost::shared_ptr<Svc6> Svc6;
};

class Consumer7
{
public:
    Consumer7(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2,
        const boost::shared_ptr<Svc3>& svc3,
        const boost::shared_ptr<Svc4>& svc4,
        const boost::shared_ptr<Svc5>& svc5,
        const boost::shared_ptr<Svc6>& svc6,
        const boost::shared_ptr<Svc7>& svc7) 
            : Svc1(svc1), Svc2(svc2), Svc3(svc3), Svc4(svc4), Svc5(svc5), Svc6(svc6), Svc7(svc7) { CtorCount++; }
    
    virtual ~Consumer7() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
    boost::shared_ptr<Svc3> Svc3;
    boost::shared_ptr<Svc4> Svc4;
    boost::shared_ptr<Svc5> Svc5;
    boost::shared_ptr<Svc6> Svc6;
    boost::shared_ptr<Svc7> Svc7;
};

class Consumer8
{
public:
    Consumer8(
        const boost::shared_ptr<Svc1>& svc1,
        const boost::shared_ptr<Svc2>& svc2,
        const boost::shared_ptr<Svc3>& svc3,
        const boost::shared_ptr<Svc4>& svc4,
        const boost::shared_ptr<Svc5>& svc5,
        const boost::shared_ptr<Svc6>& svc6,
        const boost::shared_ptr<Svc7>& svc7,
        const boost::shared_ptr<Svc8>& svc8) 
            : Svc1(svc1), Svc2(svc2), Svc3(svc3), Svc4(svc4), Svc5(svc5), Svc6(svc6), Svc7(svc7), Svc8(svc8) { CtorCount++; }

    virtual ~Consumer8() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<Svc1> Svc1;
    boost::shared_ptr<Svc2> Svc2;
    boost::shared_ptr<Svc3> Svc3;
    boost::shared_ptr<Svc4> Svc4;
    boost::shared_ptr<Svc5> Svc5;
    boost::shared_ptr<Svc6> Svc6;
    boost::shared_ptr<Svc7> Svc7;
    boost::shared_ptr<Svc8> Svc8;
};

//////////////////////////////////////////////////////////////////////////
// Service

class SubSvc1;
class SubSvc2;
class SubSvc3;
class SubSvc4;
class SubSvc5;
class SubSvc6;
class SubSvc7;
class SubSvc8;
class SubSvc9;

class Svc1
{
public:
    Svc1(const boost::shared_ptr<SubSvc1>& subSvc1) : SubSvc1(subSvc1) { CtorCount++; }
    virtual ~Svc1() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
};

class Svc2
{
public:
    Svc2(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2) { CtorCount++; }

    virtual ~Svc2() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
};

class Svc3
{
public:
    Svc3(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3) { CtorCount++; }

    virtual ~Svc3() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
};

class Svc4
{
public:
    Svc4(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3,
         const boost::shared_ptr<SubSvc4>& subSvc4) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3), SubSvc4(subSvc4) { CtorCount++; }

    virtual ~Svc4() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
    boost::shared_ptr<SubSvc4> SubSvc4;
};

class Svc5
{
public:
    Svc5(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3,
         const boost::shared_ptr<SubSvc4>& subSvc4, 
         const boost::shared_ptr<SubSvc5>& subSvc5) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3), SubSvc4(subSvc4)
            , SubSvc5(subSvc5)
                    { CtorCount++; }

    virtual ~Svc5() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
    boost::shared_ptr<SubSvc4> SubSvc4;
    boost::shared_ptr<SubSvc5> SubSvc5;
};

class Svc6
{
public:
    Svc6(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3,
         const boost::shared_ptr<SubSvc4>& subSvc4, 
         const boost::shared_ptr<SubSvc5>& subSvc5, 
         const boost::shared_ptr<SubSvc6>& subSvc6) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3), SubSvc4(subSvc4)
            , SubSvc5(subSvc5), SubSvc6(subSvc6)
                    { CtorCount++; }

    virtual ~Svc6() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
    boost::shared_ptr<SubSvc4> SubSvc4;
    boost::shared_ptr<SubSvc5> SubSvc5;
    boost::shared_ptr<SubSvc6> SubSvc6;
};

class Svc7
{
public:
    Svc7(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3,
         const boost::shared_ptr<SubSvc4>& subSvc4, 
         const boost::shared_ptr<SubSvc5>& subSvc5, 
         const boost::shared_ptr<SubSvc6>& subSvc6, 
         const boost::shared_ptr<SubSvc7>& subSvc7) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3), SubSvc4(subSvc4)
            , SubSvc5(subSvc5), SubSvc6(subSvc6), SubSvc7(subSvc7) 
                    { CtorCount++; }

    virtual ~Svc7() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
    boost::shared_ptr<SubSvc4> SubSvc4;
    boost::shared_ptr<SubSvc5> SubSvc5;
    boost::shared_ptr<SubSvc6> SubSvc6;
    boost::shared_ptr<SubSvc7> SubSvc7;
};

class Svc8
{
public:
    Svc8(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3,
         const boost::shared_ptr<SubSvc4>& subSvc4, 
         const boost::shared_ptr<SubSvc5>& subSvc5, 
         const boost::shared_ptr<SubSvc6>& subSvc6, 
         const boost::shared_ptr<SubSvc7>& subSvc7, 
         const boost::shared_ptr<SubSvc8>& subSvc8) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3), SubSvc4(subSvc4)
            , SubSvc5(subSvc5), SubSvc6(subSvc6), SubSvc7(subSvc7), SubSvc8(subSvc8) 
                    { CtorCount++; }

    virtual ~Svc8() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
    boost::shared_ptr<SubSvc4> SubSvc4;
    boost::shared_ptr<SubSvc5> SubSvc5;
    boost::shared_ptr<SubSvc6> SubSvc6;
    boost::shared_ptr<SubSvc7> SubSvc7;
    boost::shared_ptr<SubSvc8> SubSvc8;
};

class Svc9
{
public:
    Svc9(const boost::shared_ptr<SubSvc1>& subSvc1, 
         const boost::shared_ptr<SubSvc2>& subSvc2,
         const boost::shared_ptr<SubSvc3>& subSvc3,
         const boost::shared_ptr<SubSvc4>& subSvc4, 
         const boost::shared_ptr<SubSvc5>& subSvc5, 
         const boost::shared_ptr<SubSvc6>& subSvc6, 
         const boost::shared_ptr<SubSvc7>& subSvc7, 
         const boost::shared_ptr<SubSvc8>& subSvc8, 
         const boost::shared_ptr<SubSvc9>& subSvc9) 
            : SubSvc1(subSvc1), SubSvc2(subSvc2), SubSvc3(subSvc3), SubSvc4(subSvc4)
            , SubSvc5(subSvc5), SubSvc6(subSvc6), SubSvc7(subSvc7), SubSvc8(subSvc8), SubSvc9(subSvc9)
                    { CtorCount++; }

    virtual ~Svc9() { DtorCount++; }

    static int CtorCount, DtorCount;

    boost::shared_ptr<SubSvc1> SubSvc1; 
    boost::shared_ptr<SubSvc2> SubSvc2;
    boost::shared_ptr<SubSvc3> SubSvc3;
    boost::shared_ptr<SubSvc4> SubSvc4;
    boost::shared_ptr<SubSvc5> SubSvc5;
    boost::shared_ptr<SubSvc6> SubSvc6;
    boost::shared_ptr<SubSvc7> SubSvc7;
    boost::shared_ptr<SubSvc8> SubSvc8;
    boost::shared_ptr<SubSvc9> SubSvc9;
};

//////////////////////////////////////////////////////////////////////////
// Subservice

class SubSvc1
{
public:
    SubSvc1() { CtorCount++; }
    virtual ~SubSvc1() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc2
{
public:
    SubSvc2() { CtorCount++; }
    virtual ~SubSvc2() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc3
{
public:
    SubSvc3() { CtorCount++; }
    virtual ~SubSvc3() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc4
{
public:
    SubSvc4() { CtorCount++; }
    virtual ~SubSvc4() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc5
{
public:
    SubSvc5() { CtorCount++; }
    virtual ~SubSvc5() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc6
{
public:
    SubSvc6() { CtorCount++; }
    virtual ~SubSvc6() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc7
{
public:
    SubSvc7() { CtorCount++; }
    virtual ~SubSvc7() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc8
{
public:
    SubSvc8() { CtorCount++; }
    virtual ~SubSvc8() { DtorCount++; }

    static int CtorCount, DtorCount;
};

class SubSvc9
{
public:
    SubSvc9() { }
    virtual ~SubSvc9() { }
};

//////////////////////////////////////////////////////////////////////////
// Utility

void ConsumerTypesResetCounters();

//////////////////////////////////////////////////////////////////////////
// Ioc descriptors

template<
    typename consumer_lifestyle, 
    typename service_lifestyle = consumer_lifestyle, 
    typename subservice_lifestyle = consumer_lifestyle
> struct consumer_types
{
    typedef ioc::descriptor_t<
        SubSvc1,
        subservice_lifestyle
    > _SubSvc1;

    typedef ioc::descriptor_t<
        SubSvc2,
        subservice_lifestyle> 
    _SubSvc2;

    typedef ioc::descriptor_t<
        SubSvc3,
        subservice_lifestyle> 
    _SubSvc3;

    typedef ioc::descriptor_t<
        SubSvc4,
        subservice_lifestyle
    > _SubSvc4;

    typedef ioc::descriptor_t<
        SubSvc5,
        subservice_lifestyle
    > _SubSvc5;

    typedef ioc::descriptor_t<
        SubSvc6,
        subservice_lifestyle
    > _SubSvc6;

    typedef ioc::descriptor_t<
        SubSvc7,
        subservice_lifestyle
    > _SubSvc7;

    typedef ioc::descriptor_t<
        SubSvc8,
        subservice_lifestyle
    > _SubSvc8;

    typedef ioc::descriptor_t<
        SubSvc9,
        subservice_lifestyle
    > _SubSvc9;

    typedef ioc::descriptor_t<
        Svc1,
        service_lifestyle,
        _SubSvc1
    > _Svc1;

    typedef ioc::descriptor_t<
        Svc2,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2
    > _Svc2;

    typedef ioc::descriptor_t<
        Svc3,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2, 
        _SubSvc3
    > _Svc3;

    typedef ioc::descriptor_t<
        Svc4,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2, 
        _SubSvc3, 
        _SubSvc4
    > _Svc4;

    typedef ioc::descriptor_t<
        Svc5,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2, 
        _SubSvc3, 
        _SubSvc4, 
        _SubSvc5
    > _Svc5;

    typedef ioc::descriptor_t<
        Svc6,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2, 
        _SubSvc3, 
        _SubSvc4, 
        _SubSvc5, 
        _SubSvc6
    > _Svc6;

    typedef ioc::descriptor_t<
        Svc7,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2, 
        _SubSvc3, 
        _SubSvc4, 
        _SubSvc5, 
        _SubSvc6, 
        _SubSvc7
    > _Svc7;

    typedef ioc::descriptor_t<
        Svc8,
        service_lifestyle,
        _SubSvc1, 
        _SubSvc2, 
        _SubSvc3, 
        _SubSvc4, 
        _SubSvc5, 
        _SubSvc6, 
        _SubSvc7, 
        _SubSvc8
    > _Svc8;

    typedef ioc::descriptor_t<
        Consumer0, 
        consumer_lifestyle> _Consumer0;

    typedef ioc::descriptor_t<
        Consumer1,
        consumer_lifestyle,
        _Svc1
    > _Consumer1;

    typedef ioc::descriptor_t<
        Consumer2,
        consumer_lifestyle,
        _Svc1, 
        _Svc2
    > _Consumer2;

    typedef ioc::descriptor_t<
        Consumer3,
        consumer_lifestyle,
        _Svc1, 
        _Svc2, 
        _Svc3
    > _Consumer3;

    typedef ioc::descriptor_t<
        Consumer4,
        consumer_lifestyle,
        _Svc1, 
        _Svc2, 
        _Svc3, 
        _Svc4
    > _Consumer4;

    typedef ioc::descriptor_t<
        Consumer5,
        consumer_lifestyle,
        _Svc1, 
        _Svc2, 
        _Svc3, 
        _Svc4, 
        _Svc5
    > _Consumer5;

    typedef ioc::descriptor_t<
        Consumer6,
        consumer_lifestyle,
        _Svc1, 
        _Svc2, 
        _Svc3, 
        _Svc4, 
        _Svc5, 
        _Svc6
    > _Consumer6;

    typedef ioc::descriptor_t<
        Consumer7,
        consumer_lifestyle,
        _Svc1, 
        _Svc2, 
        _Svc3, 
        _Svc4, 
        _Svc5, 
        _Svc6, 
        _Svc7
    > _Consumer7;

    typedef ioc::descriptor_t<
        Consumer8,
        consumer_lifestyle,
        _Svc1, 
        _Svc2, 
        _Svc3, 
        _Svc4, 
        _Svc5, 
        _Svc6, 
        _Svc7, 
        _Svc8
    > _Consumer8;
};

#endif // CONSUMER_TYPES_H