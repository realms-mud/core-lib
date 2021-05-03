//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <functionlist.h>

object Preload;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    string *functions = filter(
        functionlist(this_object(), RETURN_FUNCTION_NAME),
        (: sizeof(regexp(({ $1 }), "__inline")) :));

    ignoreList += functions;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Preload = clone_object("/lib/tests/support/master/preloadHelper.c");
    Preload.SwapInitFile("/lib/tests/support/master/fake_init_file");
    Preload.AutoLoadCoreLib(1);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Preload);
}

/////////////////////////////////////////////////////////////////////////////
void WillAutoLoadCoreLibByDefault()
{
    string *listOfFiles = Preload.epilog(0);

    // Core lib file
    ExpectTrue(member(listOfFiles, "/lib/realizations/player.c") > -1,
        "core lib file loaded");

    // Init File Only
    ExpectTrue(member(listOfFiles, "/guilds/scion/scionOfDhuras.c") > -1,
        "init file entry loaded");

    // Make sure there is only one instance of item in both core lib and init file
    ExpectEq(1, sizeof(filter(listOfFiles,
        (: $1 == "/lib/realizations/wizard.c" :))));
}

/////////////////////////////////////////////////////////////////////////////
void PreloadCompilesNormalFiles()
{
    string logFile = filter(get_dir("/", 0x10),
        (: sizeof(regexp(({ $1 }), ".debug.log")) :))[0];

    string initialLogFile = read_file(logFile);

    Preload.preload("/lib/realizations/player.c");

    string finalLogFile = read_file(logFile);
    finalLogFile = finalLogFile[sizeof(initialLogFile)..];

    ExpectSubStringMatch("Compiling file: /lib/realizations/player.c", 
        finalLogFile);
}

/////////////////////////////////////////////////////////////////////////////
void PreloadExecutesTests()
{
    string logFile = filter(get_dir("/", 0x10),
        (: sizeof(regexp(({ $1 }), ".debug.log")) :))[0];

    string initialLogFile = read_file(logFile);

    Preload.preload("/lib/tests/support/master/fakeTest.c");

    string finalLogFile = read_file(logFile);
    finalLogFile = finalLogFile[sizeof(initialLogFile)..];

    ExpectSubStringMatch("Testing /lib/tests/support/master/fakeTest.*"
        "PASSED", finalLogFile);
}

/////////////////////////////////////////////////////////////////////////////
void PreloadDoesNotExecuteTestFixtureExecuteTestsMethod()
{
    string logFile = filter(get_dir("/", 0x10),
        (: sizeof(regexp(({ $1 }), ".debug.log")) :))[0];

    string initialLogFile = read_file(logFile);

    Preload.preload("/lib/tests/framework/testFixture.c");

    string finalLogFile = read_file(logFile);
    finalLogFile = finalLogFile[sizeof(initialLogFile)..];

    ExpectSubStringMatch("Compiling file: /lib/tests/framework/testFixture", 
        finalLogFile);
}
