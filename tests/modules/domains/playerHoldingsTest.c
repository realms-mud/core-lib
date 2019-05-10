//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    Player = clone_object("/lib/realizations/player.c");
    Player->charsetConfiguration("unicode");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void castleDrawing()
{
//    ExpectEq("x", "\n" + implode(Dictionary->getPlayerDomain(
//        Player, "weasel", "castle")["layout"], "\n"));
}
