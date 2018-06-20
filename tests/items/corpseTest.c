//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Corpse;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Corpse = clone_object("/lib/items/corpse");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Corpse);
}
