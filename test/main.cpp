#include <crtdbg.h>
#include <gtest/gtest.h>

namespace testing
{
#ifdef _DEBUG
    class MemoryLeakDetector : public EmptyTestEventListener
    {

    public:
        virtual void OnTestStart(const TestInfo&)
        {
            _CrtMemCheckpoint(&m_onStart);
        }

        virtual void OnTestEnd(const TestInfo& test_info)
        {
            if (test_info.result()->Passed())
            {
                _CrtMemState now, diff;
                _CrtMemCheckpoint(&now);
                int diffResult = _CrtMemDifference(&diff, &m_onStart, &now);
                if (diffResult)
                {
                    FAIL() << "Memory leak of " << diff.lSizes[1] << " byte(s) detected.";
                }
            }
        }

    private:
        _CrtMemState m_onStart;
    };
#endif
}

int wmain(int argc, wchar_t** argv)
{
    using namespace testing;
    
    InitGoogleTest(&argc, argv);

#ifdef _DEBUG
    UnitTest::GetInstance()->listeners().Append(new MemoryLeakDetector());
#endif // _DEBUG

    return RUN_ALL_TESTS();
}
