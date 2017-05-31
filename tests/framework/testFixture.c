//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include <functionlist.h>

string Pass = "[0;36m[  PASSED  ][0m ";
string Fail = "[0;31m[  FAILED  ][0m ";

int CurrentTestPassed = 0;
int AnyFailure = 0;
string *ignoreList = ({ "__INIT", "Init", "Setup", "CleanUp" });

/////////////////////////////////////////////////////////////////////////////
void Init()
{
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
}

/////////////////////////////////////////////////////////////////////////////
int executeTests()
{
    Init();
    mixed *tests = functionlist(this_object(), RETURN_FUNCTION_NAME | NAME_INHERITED);
    tests -= ignoreList;

    debug_message(sprintf("\nTesting %s\n", file_name()));
    foreach(string test in tests)
    {
        Setup();
        CurrentTestPassed = 1;

        call_other(this_object(), test);
        debug_message(sprintf("%s %s\n", CurrentTestPassed ? Pass : Fail, test));
        CleanUp();
    }
    debug_message(sprintf("Test executed: %s -> %s\n", file_name(), 
        AnyFailure ? Fail : Pass));

    return AnyFailure;
}

/////////////////////////////////////////////////////////////////////////////
void validateExpect(mixed val1, mixed val2, string msg)
{
    if (!CurrentTestPassed)
    {
        AnyFailure = 1;
        debug_message(Fail + (stringp(msg) ? msg : "") + " -> Actual: " + val2 + 
            ", Expected: " + val1 + "\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
int sortArray(mixed a, mixed b)
{
    string compA;
    string compB;

    if (mappingp(a) && mappingp(b))
    {
        compA = this_object()->convertDataToString(a);
        compB = this_object()->convertDataToString(b);
    }
    else
    {
        compA = to_string(a);
        compB = to_string(b);
    }

    return compA > compB;
}

/////////////////////////////////////////////////////////////////////////////
string convertDataToString(mixed data)
{
    string ret = "";

    if (objectp(data))
    {
        ret += program_name(data);
    }
    else if (pointerp(data) && sizeof(data))
    {
        ret += "({ ";
        data = sort_array(data, "sortArray");
        foreach(mixed element in data)
        {
            ret += convertDataToString(element) + ", ";
        }
        ret += "})";
    }
    else if (mappingp(data))
    {
        ret += "([ ";
        mixed *indices = sort_array(m_indices(data), "sortArray");
        foreach(mixed index in indices)
        {
            ret += convertDataToString(index) + ": " + convertDataToString(data[index]) + ", ";
        }
        ret += "])";
    }
    else
    {
        ret += to_string(data);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void ExpectEq(mixed val1, mixed val2, string msg)
{
    string parsedVal1 = convertDataToString(val1);
    string parsedVal2 = convertDataToString(val2);

    CurrentTestPassed = parsedVal1 == parsedVal2;
    validateExpect(parsedVal1, parsedVal2, msg);
}

/////////////////////////////////////////////////////////////////////////////
void ExpectNotEq(mixed val1, mixed val2, string msg)
{
    string parsedVal1 = convertDataToString(val1);
    string parsedVal2 = convertDataToString(val2);

    CurrentTestPassed = parsedVal1 != parsedVal2;
    validateExpect(parsedVal1, parsedVal2, msg);
}

/////////////////////////////////////////////////////////////////////////////
void ExpectTrue(mixed val1, string msg)
{
    CurrentTestPassed = val1;
    validateExpect("true", "false", msg);
}

/////////////////////////////////////////////////////////////////////////////
void ExpectFalse(mixed val1, string msg)
{
    CurrentTestPassed = !val1;
    validateExpect("false", "true", msg);
}


