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
        "[1] - Construct Building     ..                                         ..   \n"
        "[2] - Construct Keep         .                 .........                 .   \n"
        "[3] - Construct Moat         .    ..............       ..............    .   \n"
        "[4] - Construct Tower        ......            .........            ......   \n"
        "[5] - Construct Wall                                                         \n"
        "[6] - Exit Building Projects Menu\n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}


/////////////////////////////////////////////////////////////////////////////
void CanSelectConstructBuildings()
{
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectEq("Building Projects - Building:\n"
        "From this menu, you can initiate, modify, or abort building projects in your\n"
        "holdings at default.\n\n"
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
        "[1] - Northwest Building      .       .     .?.         .?.     .       .    \n"
        "[2] - Northeast Building      .       .    ........ ........    .       .    \n"
        "[3] - West Building 1         .       ......      ...      ......       .    \n"
        "[4] - West Building 2        ..                                         ..   \n"
        "[5] - East Building 1        .                 .........                 .   \n"
        "[6] - East Building 2        .    ..............       ..............    .   \n"
        "[7] - Southwest Building     ......            .........            ......   \n"
        "[8] - Southeast Building                                                     \n"
        "[9] - Exit Building Projects Menu\n"
        "You must select a number from 1 to 9.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}
