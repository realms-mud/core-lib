//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelNorthGateTest.c";

void Init()
{
    selectTestMethods(({ "RunSelectedTests" }));
}

void RunSelectedTests()
{
    runSelectedTests(({ "NorthGateRegionsAreAuthored" }));
}
