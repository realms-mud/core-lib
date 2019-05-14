//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/buildSelector.c");
    Selector->setLocation("default");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Main Menu:\n"
        "                                                                             \n"
        "                             ......            .........            ......   \n"
        "                             .    ..............       ..............    .   \n"
        "                             .                 .........                 .   \n"
        "                             ..                                         ..   \n"
        "                              .       ......      ...      ......       .    \n"
        "                              .       .    ........ ........    .       .    \n"
        "                              .       .     .?.         .?.     .       .    \n"
        "                              .       ..    ...         ...    ..       .    \n"
        "                              .        . ..                 .. .        .    \n"
        "                             ....      . ?.    .........    .? .      ....   \n"
        "                             .  .      . ..    .       .    .. .      .  .   \n"
        "                             .  .     ...      .       .      ...     .  .   \n"
        "                             .  .     ...      .       .      ...     .  .   \n"
        "                             .  .      . ..    .........    .. .      .  .   \n"
        "                             ....      . ?.                 .? .      ....   \n"
        "                              .        . ..                 .. .        .    \n"
        "                              .       ..    ...         ...    ..       .    \n"
        "                              .       .     .?.         .?.     .       .    \n"
        "                              .       .    ........ ........    .       .    \n"
        "                              .       ......      ...      ......       .    \n"
        "[1] - Building               ..                                         ..   \n"
        "[2] - Keep                   .                 .........                 .   \n"
        "[3] - Moat                   .    ..............       ..............    .   \n"
        "[4] - Tower                  ......            .........            ......   \n"
        "[5] - Wall                                                                   \n"
        "[6] - Exit Building Projects Menu\n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}