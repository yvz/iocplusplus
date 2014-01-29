#include <ctime>
#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>

#include "container.hpp"

//////////////////////////////////////////////////////////////////////////
// Output

class IOutput
{
public:
    virtual ~IOutput() {}
    virtual void Write(const std::string& content) = 0;
};

class ConsoleOutput : public IOutput
{
public:
    virtual ~ConsoleOutput() {}
    virtual void Write(const std::string& content) { std::cout << content << std::endl; }
};

typedef ioc::descriptor_t<
    ConsoleOutput,
    ioc::transient_t
> _ConsoleOutput;

//////////////////////////////////////////////////////////////////////////
// DateWriter

class IDateWriter
{
public:
    virtual ~IDateWriter() {}
    virtual void WriteDate() = 0;
};

class TodayWriter : public IDateWriter
{
public:
    TodayWriter(boost::shared_ptr<IOutput> output) : m_output(output) {}
    virtual ~TodayWriter() {}

    virtual void WriteDate() 
    { 
        struct tm now;
        time_t rawtime;
        char dateString[128];

        time(&rawtime);
        localtime_s(&now, &rawtime);
        strftime(dateString, 128, "%x", &now);

        m_output->Write(dateString);
    }

private:
    boost::shared_ptr<IOutput> m_output;
};

typedef ioc::descriptor_t<
    TodayWriter,
    ioc::transient_t,
    _ConsoleOutput
> _TodayWriter;

//////////////////////////////////////////////////////////////////////////
// Demo

void WriteDate(const boost::shared_ptr<IDateWriter>& dateWriter)
{
    dateWriter->WriteDate();
}

int wmain(int /*argc*/, wchar_t** /*argv*/)
{
    ioc::container container;
    container.registerType<_TodayWriter>();
    
    WriteDate(container.resolve<TodayWriter>());

    return 0;
}
