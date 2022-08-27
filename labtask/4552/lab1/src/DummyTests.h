#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <numeric>

#define MACRO_ABS(X) ((X) < 0 ? -(X) : (X)) 
#define DOUBLE_EQ(X, Y) (MACRO_ABS(X - Y) < 1e-15)

#ifdef COLORED_TESTS
    #define WARNING_MARK "[\033[93mWarning\033[0m]"
    #define OK_MARK "[\033[92mOK\033[0m]"
    #define FAILED_MARK "[\033[91mFAILED!\033[0m]"
    #define BLUE_BEGIN "\033[94m"
    #define BLUE_END "\033[0m"
#else
    #define WARNING_MARK "[Warning]"
    #define OK_MARK "[OK]"
    #define FAILED_MARK "[FAILED!]"
    #define BLUE_BEGIN ""
    #define BLUE_END ""
#endif

static std::string g_CurrentTest = "None";
static std::unordered_map<std::string, bool> g_ResultMap;
#define TEST_UNIT(X) g_CurrentTest = X;
#define TEST_CURRENT g_CurrentTest
#define TEST_SUCCESS g_ResultMap[TEST_CURRENT] = true
#define TEST_FAIL g_ResultMap[TEST_CURRENT] = false
#define TEST_ASSERT(X) if((X)) TEST_SUCCESS; else TEST_FAIL
#define TEST_REQUIRES(X) if(!g_ResultMap[X]) std::cout << WARNING_MARK " Requirement <" BLUE_BEGIN X BLUE_END "> failure in <" << BLUE_BEGIN << TEST_CURRENT << BLUE_END << ">" << std::endl

static void PrintTestResults(const std::unordered_map<std::string, bool>& resultMap)
{
    std::cout << "--------------------------------------------------\n";

    size_t successCount = 0u;
    size_t totalCount = resultMap.size();

    for(auto& kvp : resultMap)
    {
        if(kvp.second)
        {
            std::cout << OK_MARK " " << kvp.first << std::endl;
            successCount++;
        }
        else
        {
            std::cout << FAILED_MARK " " << kvp.first << std::endl;
        }
    }

    std::cout << "--------------------------------------------------\n";
    if(successCount == totalCount)
        std::cout << "All " << totalCount << " test(s) passed." << std::endl;
    else if(successCount == 0u)
        std::cout << "All " << totalCount <<  " test(s) FAILED!" << std::endl;
    else
        std::cout << "Test Result: " << successCount << "/" << totalCount << " test(s) passed." << std::endl;
}

#define TESTS_BEGIN int main(){
#define TESTS_END PrintTestResults(g_ResultMap); return 0; }

#define TEST_MAIN(X) int main(){ X PrintTestResults(g_ResultMap); return 0; }