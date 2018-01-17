//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include <functionlist.h>

string Pass = "[0;36m[  PASSED  ][0m ";
string Fail = "[0;31m[  FAILED  ][0m ";

int CurrentTestPassed = 0;
int AnyFailure = 0;
string *ignoreList = ({ "__INIT", "Init", "Setup", "CleanUp" });

/////////////////////////////////////////////////////////////////////////////
public void Init()
{
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void CleanUp()
{
}

/////////////////////////////////////////////////////////////////////////////
public int executeTests()
{
    Init();
    mixed *tests = functionlist(this_object(), RETURN_FUNCTION_NAME | NAME_INHERITED);
    tests -= ignoreList;

    debug_message(sprintf("\nTesting %s\n", object_name()));
    foreach(string test in tests)
    {
        Setup();
        CurrentTestPassed = 1;

        call_other(this_object(), test);
        debug_message(sprintf("%s %s\n", CurrentTestPassed ? Pass : Fail, test));
        CleanUp();
    }
    debug_message(sprintf("Test executed: %s -> %s\n", object_name(),
        AnyFailure ? Fail : Pass));

    return AnyFailure;
}

/////////////////////////////////////////////////////////////////////////////
public void validateExpect(mixed val1, mixed val2, string msg)
{
    if (!CurrentTestPassed)
    {
        AnyFailure = 1;
        debug_message(Fail + (stringp(msg) ? msg : "") + " -> Actual: " + val2 + 
            ", Expected: " + val1 + "\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public int sortArray(mixed a, mixed b)
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
public string convertDataToString(mixed data)
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
public varargs void ExpectEq(mixed val1, mixed val2, string msg)
{
    string parsedVal1 = convertDataToString(val1);
    string parsedVal2 = convertDataToString(val2);

    CurrentTestPassed = parsedVal1 == parsedVal2;
    validateExpect(parsedVal1, parsedVal2, msg);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void ExpectSubStringMatch(string val1, string val2, string msg)
{
    CurrentTestPassed = sizeof(regexp(({ val2 }), val1));
    validateExpect(val1, val2, msg);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void ExpectNotEq(mixed val1, mixed val2, string msg)
{
    string parsedVal1 = convertDataToString(val1);
    string parsedVal2 = convertDataToString(val2);

    CurrentTestPassed = parsedVal1 != parsedVal2;
    validateExpect(parsedVal1, parsedVal2, msg);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void ExpectTrue(mixed val1, string msg)
{
    CurrentTestPassed = val1;
    validateExpect("true", "false", msg);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void ExpectFalse(mixed val1, string msg)
{
    CurrentTestPassed = !val1;
    validateExpect("false", "true", msg);
}
