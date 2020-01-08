//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Preload;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Preload = clone_object("/lib/tests/support/master/preloadHelper.c");
    Preload->SwapInitFile("/lib/tests/support/master/fake_init_file");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Preload);
}

/////////////////////////////////////////////////////////////////////////////
void WillAutoLoadCoreLibByDefault()
{
    string *listOfFiles = Preload->epilog(0);

    // Core lib file
    ExpectTrue(member(listOfFiles, "/lib/realizations/player.c") > -1);

    // Init File Only
    ExpectTrue(member(listOfFiles, "/guilds/scion/scionOfDhuras.c") > -1);

    // Make sure there is only one instance of item in both core lib and init file
    ExpectEq(1, sizeof(filter(listOfFiles,
        (: $1 == "/lib/realizations/wizard.c" :))));
}
