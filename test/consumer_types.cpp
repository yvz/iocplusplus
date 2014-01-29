#include "consumer_types.h"

int Consumer0::CtorCount = 0, Consumer0::DtorCount = 0;    
int Consumer1::CtorCount = 0, Consumer1::DtorCount = 0;
int Consumer2::CtorCount = 0, Consumer2::DtorCount = 0;
int Consumer3::CtorCount = 0, Consumer3::DtorCount = 0;
int Consumer4::CtorCount = 0, Consumer4::DtorCount = 0;
int Consumer5::CtorCount = 0, Consumer5::DtorCount = 0;
int Consumer6::CtorCount = 0, Consumer6::DtorCount = 0;
int Consumer7::CtorCount = 0, Consumer7::DtorCount = 0;
int Consumer8::CtorCount = 0, Consumer8::DtorCount = 0;

int Svc1::CtorCount = 0, Svc1::DtorCount = 0;
int Svc2::CtorCount = 0, Svc2::DtorCount = 0;
int Svc3::CtorCount = 0, Svc3::DtorCount = 0;
int Svc4::CtorCount = 0, Svc4::DtorCount = 0;
int Svc5::CtorCount = 0, Svc5::DtorCount = 0;
int Svc6::CtorCount = 0, Svc6::DtorCount = 0;
int Svc7::CtorCount = 0, Svc7::DtorCount = 0;
int Svc8::CtorCount = 0, Svc8::DtorCount = 0;

int SubSvc1::CtorCount = 0, SubSvc1::DtorCount = 0;
int SubSvc2::CtorCount = 0, SubSvc2::DtorCount = 0;
int SubSvc3::CtorCount = 0, SubSvc3::DtorCount = 0;
int SubSvc4::CtorCount = 0, SubSvc4::DtorCount = 0;
int SubSvc5::CtorCount = 0, SubSvc5::DtorCount = 0;
int SubSvc6::CtorCount = 0, SubSvc6::DtorCount = 0;
int SubSvc7::CtorCount = 0, SubSvc7::DtorCount = 0;
int SubSvc8::CtorCount = 0, SubSvc8::DtorCount = 0;

void ConsumerTypesResetCounters()
{
    Consumer0::CtorCount = Consumer0::DtorCount =     
    Consumer1::CtorCount = Consumer1::DtorCount = 
    Consumer2::CtorCount = Consumer2::DtorCount = 
    Consumer3::CtorCount = Consumer3::DtorCount = 
    Consumer4::CtorCount = Consumer4::DtorCount = 
    Consumer5::CtorCount = Consumer5::DtorCount = 
    Consumer6::CtorCount = Consumer6::DtorCount = 
    Consumer7::CtorCount = Consumer7::DtorCount = 
    Consumer8::CtorCount = Consumer8::DtorCount = 

    Svc1::CtorCount = Svc1::DtorCount = 
    Svc2::CtorCount = Svc2::DtorCount = 
    Svc3::CtorCount = Svc3::DtorCount = 
    Svc4::CtorCount = Svc4::DtorCount = 
    Svc5::CtorCount = Svc5::DtorCount = 
    Svc6::CtorCount = Svc6::DtorCount = 
    Svc7::CtorCount = Svc7::DtorCount = 
    Svc8::CtorCount = Svc8::DtorCount = 

    SubSvc1::CtorCount = SubSvc1::DtorCount = 
    SubSvc2::CtorCount = SubSvc2::DtorCount = 
    SubSvc3::CtorCount = SubSvc3::DtorCount = 
    SubSvc4::CtorCount = SubSvc4::DtorCount = 
    SubSvc5::CtorCount = SubSvc5::DtorCount = 
    SubSvc6::CtorCount = SubSvc6::DtorCount = 
    SubSvc7::CtorCount = SubSvc7::DtorCount = 
    SubSvc8::CtorCount = SubSvc8::DtorCount = 0;
}