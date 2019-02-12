//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->Con(10);
    Player->hitPoints(Player->maxHitPoints());
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void WimpyNotificationDisplayedWhenNoValueSent()
{
    command("wimpy", Player);
    ExpectEq("Wimpy: 0%\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WimpyValueCanBeSet()
{
    command("wimpy -v 50", Player);
    ExpectEq("Wimpy set to: 50%\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WimpyCannotBeSetHigherThanSeventyPercent()
{
    command("wimpy -v 75", Player);
    ExpectEq(({ "Valid wimpy values range from 0-70. ", "Wimpy set to: 70%\n" }), Player->caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void WimpyCannotBeSetLowerThanZeroPercent()
{
    command("wimpy -v -7", Player);
    ExpectEq(({ "Valid wimpy values range from 0-70. ", "Wimpy set to: 0%\n" }), Player->caughtMessages());
}
