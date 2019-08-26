//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Region;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("3-bit");
    Player->charsetConfiguration("unicode");

    Region = clone_object("/lib/environment/region.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Region);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionDisplaysCorrectlyForTerrain()
{
    string *ret = Region->createArea(Player);

    Region->displayMap(Player);
}
