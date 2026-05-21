#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/conference.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:

        // Тест 1: один доклад — индекс максимального это 0
        TEST_METHOD(Test_OneReport_Index0)
        {
            Report reports[1];
            reports[0].startHour = 9;  reports[0].startMin = 0;
            reports[0].endHour = 9;    reports[0].endMin = 30;
            Assert::AreEqual(0, findMaxDurationIndex(reports, 1));
        }

        // Тест 2: три доклада — самый длинный второй (индекс 1)
        TEST_METHOD(Test_ThreeReports_Index1)
        {
            Report reports[3];
            reports[0].startHour = 9;  reports[0].startMin = 0;
            reports[0].endHour = 9;    reports[0].endMin = 20;
            reports[1].startHour = 10; reports[1].startMin = 0;
            reports[1].endHour = 10;   reports[1].endMin = 50;
            reports[2].startHour = 11; reports[2].startMin = 0;
            reports[2].endHour = 11;   reports[2].endMin = 30;
            Assert::AreEqual(1, findMaxDurationIndex(reports, 3));
        }

        // Тест 3: самый длинный последний (индекс 2)
        TEST_METHOD(Test_ThreeReports_Index2)
        {
            Report reports[3];
            reports[0].startHour = 9;  reports[0].startMin = 0;
            reports[0].endHour = 9;    reports[0].endMin = 10;
            reports[1].startHour = 10; reports[1].startMin = 0;
            reports[1].endHour = 10;   reports[1].endMin = 15;
            reports[2].startHour = 11; reports[2].startMin = 0;
            reports[2].endHour = 12;   reports[2].endMin = 0;
            Assert::AreEqual(2, findMaxDurationIndex(reports, 3));
        }
    };
}
