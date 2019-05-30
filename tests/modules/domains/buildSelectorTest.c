//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;
object Location;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/buildSelector.c");
    Selector->setLocation("argalach castle");

	Location = load_object("/lib/dictionaries/domains/rooms/keep-1x1.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");
    Player->addPlayerHolding("argalach castle");

	Location->enterEnvironment(Player);

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Selector);
    destruct(Player);
	destruct(Location);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("Building Projects - Main Menu:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "                                                                             \n"
        "                             ......            .........            ......   \n"
        "                             .    ..............       ..............    .   \n"
        "                             .     .?.         .........         .?.     .   \n"
        "                             ..    ...                           ...    ..   \n"
        "                              . ..    ......      ...      ......    .. .    \n"
        "                              . ?.    .    ........ ........    .    .? .    \n"
        "                              . ..    .     .?.         .?.     .    .. .    \n"
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
        "                              . ..    .     .?.         .?.     .    .. .    \n"
        "                              . ?.    .    ........ ........    .    .? .    \n"
        "                              . ..    ......      ...      ......    .. .    \n"
        "[1] - Construct Building     ..    ...                           ...    ..   \n"
        "[2] - Construct Keep         .     .?.         .........         .?.     .   \n"
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
        "holdings at Argalach Castle.\n\n"
        "                                                                              \n"
        "                              ......            .........            ......   \n"
        "                              .    ..............       ..............    .   \n"
        "                              .     .?.         .........         .?.     .   \n"
        "                              ..    ...                           ...    ..   \n"
        "                               . ..    ......      ...      ......    .. .    \n"
        "                               . ?.    .    ........ ........    .    .? .    \n"
        "                               . ..    .     .?.         .?.     .    .. .    \n"
        "                               .       ..    ...         ...    ..       .    \n"
        "                               .        . ..                 .. .        .    \n"
        "[1]  - Northwest Building     ....      . ?.    .........    .? .      ....   \n"
        "[2]  - Northeast Building     .  .      . ..    .       .    .. .      .  .   \n"
        "[3]  - West Building 1        .  .     ...      .       .      ...     .  .   \n"
        "[4]  - West Building 2        .  .     ...      .       .      ...     .  .   \n"
        "[5]  - East Building 1        .  .      . ..    .........    .. .      .  .   \n"
        "[6]  - East Building 2        ....      . ?.                 .? .      ....   \n"
        "[7]  - Southwest Building      .        . ..                 .. .        .    \n"
        "[8]  - Southeast Building      .       ..    ...         ...    ..       .    \n"
        "[9]  - NW Castle Building      . ..    .     .?.         .?.     .    .. .    \n"
        "[10] - NE Castle Building      . ?.    .    ........ ........    .    .? .    \n"
        "[11] - W Castle Building 1     . ..    ......      ...      ......    .. .    \n"
        "[12] - W Castle Building 2    ..    ...                           ...    ..   \n"
        "[13] - E Castle Building 1    .     .?.         .........         .?.     .   \n"
        "[14] - E Castle Building 2    .    ..............       ..............    .   \n"
        "[15] - SW Castle Building     ......            .........            ......   \n"
        "[16] - SE Castle Building                                                     \n"
        "[17] - Exit Building Projects Menu\n"
        "You must select a number from 1 to 17.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectConstructASpecificBuilding()
{
    Player->colorConfiguration("8-bit");

    Selector->initiateSelector(Player);
    command("4", Player);
    command("1", Player);

    ExpectEq("\x1b[0;38;5;80mBuilding Projects - \x1b[0m\x1b[0;38;5;15;1mTower:\n"
        "\x1b[0;38;5;116mFrom this menu, you can initiate, modify, or abort tower projects in your\n"
        "holdings at Argalach Castle.\n"
        "\x1b[0m\x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m......\x1b[0m            \x1b[0;38;5;9m.........\x1b[0m            \x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.       .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;9m.........\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m                           \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;48;5;52;38;5;9m......\x1b[0m      \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m......\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m   \x1b[0;48;5;52;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m. .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m   \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;48;5;52;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;48;5;52;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m         \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m               \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m....\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m   \x1b[0;38;5;9m.........\x1b[0m   \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m....\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m.       .\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m.       .\x1b[0m      \x1b[0;38;5;9m...\x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m.       .\x1b[0m      \x1b[0;38;5;9m...\x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m.........\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m....\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m               \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m....\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m               \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m         \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n" +
        "                          \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m1\x1b[0m] - \x1b[0;38;5;2mArcher's Tower      \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m   \x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m. .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m   \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m2\x1b[0m] - \x1b[0;38;5;2mBallista Tower      \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m......\x1b[0m      \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m......\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m3\x1b[0m] - \x1b[0;38;5;2mBasic Tower         \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m                           \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m4\x1b[0m] - \x1b[0;38;5;2mCatapult Tower      \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;9m.........\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m5\x1b[0m] - \x1b[0;38;5;2mMage Tower          \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.       .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m6\x1b[0m] - \x1b[0;38;5;2mTall Tower          \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m......\x1b[0m            \x1b[0;38;5;9m.........\x1b[0m            \x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m7\x1b[0m] - \x1b[0;38;5;2mTrebuchet Tower     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
        "[\x1b[0;38;5;9;1m8\x1b[0m] - \x1b[0;38;5;2mExit Building Projects Menu\x1b[0m\n"
        "\x1b[0;38;5;2;1mYou must select a number from 1 to 8.\n"
        "\x1b[0m\x1b[0;38;5;144mType 'exit' if you do not wish to make a selection at this time.\n"
        "\x1b[0m\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;38;5;2;1m\x1b[0m",

        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectFromConstructComponentMenu()
{
	Player->colorConfiguration("8-bit");

	Selector->initiateSelector(Player);
	command("4", Player);
	command("1", Player);
	command("1", Player);

	ExpectEq("\x1b[0;38;5;80mBuilding Projects - \x1b[0m\x1b[0;38;5;15;1mTower:\n"
		"\x1b[0;38;5;116mFrom this menu, you can initiate, modify, or abort tower projects in your\n"
		"holdings at Argalach Castle.\n"
		"\x1b[0m\x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m......\x1b[0m            \x1b[0;38;5;9m.........\x1b[0m            \x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.       .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;9m.........\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m                           \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;103m+====+\x1b[0m      \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m......\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m   \x1b[0;38;5;103m|+\x1b[0;38;5;199m--\x1b[0;38;5;103m+|\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m. .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m   \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;103m|+--+ \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;103m+=    \x1b[0m\x1b[0;38;5;1m...\x1b[0m         \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"                           \x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m               \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m1\x1b[0m]  - \x1b[0;38;5;2mNorthwest Tower     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m....\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m   \x1b[0;38;5;9m.........\x1b[0m   \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m....\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n" + 
		"[\x1b[0;38;5;9;1m2\x1b[0m]  - \x1b[0;38;5;2mNorth Tower         \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m.       .\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m3\x1b[0m]  - \x1b[0;38;5;2mNortheast Tower     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m.       .\x1b[0m      \x1b[0;38;5;9m...\x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m4\x1b[0m]  - \x1b[0;38;5;2mWest Tower          \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m.       .\x1b[0m      \x1b[0;38;5;9m...\x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m5\x1b[0m]  - \x1b[0;38;5;2mEast Tower          \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.  .\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m.........\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m.  .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m6\x1b[0m]  - \x1b[0;38;5;2mSouthwest Tower     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m....\x1b[0m     \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m               \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m     \x1b[0;38;5;9m....\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m7\x1b[0m]  - \x1b[0;38;5;2mSouth Tower         \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m               \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m8\x1b[0m]  - \x1b[0;38;5;2mSoutheast Tower     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m      \x1b[0;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m         \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m      \x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n" +
		"[\x1b[0;38;5;9;1m9\x1b[0m]  - \x1b[0;38;5;2mOuter Tower (NW)    \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m10\x1b[0m] - \x1b[0;38;5;2mOuter Tower (N)     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m?. \x1b[0m   \x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m. .\x1b[0m\x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m   \x1b[0;38;5;9m .?\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m11\x1b[0m] - \x1b[0;38;5;2mOuter Tower (NE)    \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m.. \x1b[0m   \x1b[0;38;5;9m......\x1b[0m      \x1b[0;38;5;9m...\x1b[0m      \x1b[0;38;5;9m......\x1b[0m   \x1b[0;38;5;9m ..\x1b[0m\x1b[0;38;5;9m . \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m12\x1b[0m] - \x1b[0;38;5;2mOuter Tower (W)     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m..    \x1b[0m\x1b[0;38;5;1m...\x1b[0m                           \x1b[0;38;5;1m...\x1b[0m\x1b[0;38;5;9m    ..\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m13\x1b[0m] - \x1b[0;38;5;2mOuter Tower (E)     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.     \x1b[0m\x1b[0;38;5;1m.?.\x1b[0m         \x1b[0;38;5;9m.........\x1b[0m         \x1b[0;38;5;1m.?.\x1b[0m\x1b[0;38;5;9m     .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m14\x1b[0m] - \x1b[0;38;5;2mOuter Tower (SW)    \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.       .\x1b[0m\x1b[0;38;5;9m............\x1b[0m\x1b[0;38;5;9m.    .\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m15\x1b[0m] - \x1b[0;38;5;2mOuter Tower (S)     \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m......\x1b[0m            \x1b[0;38;5;9m.........\x1b[0m            \x1b[0;38;5;9m......\x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m16\x1b[0m] - \x1b[0;38;5;2mOuter Tower (SE)    \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\x1b[0;38;5;9m   \x1b[0m\n"
		"[\x1b[0;38;5;9;1m17\x1b[0m] - \x1b[0;38;5;2mExit Building Projects Menu\x1b[0m\n"
		"\x1b[0;38;5;2;1mYou must select a number from 1 to 17.\n"
		"\x1b[0m\x1b[0;38;5;144mType 'exit' if you do not wish to make a selection at this time.\n"
		"\x1b[0m\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') where\n"
		"X is the option about which you would like further details.\n"
		"\x1b[0m\x1b[0;38;5;2;1m\x1b[0m",
		Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplayCastleWithPreVuiltComponents()
{
	Player->buildDomainUpgrade("argalach castle", "keep", "stone keep");
	Player->buildDomainUpgrade("argalach castle", "northwest tower", "mage northwest tower");
	Player->buildDomainUpgrade("argalach castle", "northeast tower", "mage northeast tower");
	Player->buildDomainUpgrade("argalach castle", "southwest tower", "mage southwest tower");
	Player->buildDomainUpgrade("argalach castle", "southeast tower", "mage southeast tower");
	Player->buildDomainUpgrade("argalach castle", "northwest castle tower", "mage northwest castle tower");
	Player->buildDomainUpgrade("argalach castle", "northeast castle tower", "mage northeast castle tower");
	Player->buildDomainUpgrade("argalach castle", "southwest castle tower", "ballista southwest castle tower");
	Player->buildDomainUpgrade("argalach castle", "north castle tower", "gate north castle tower");
	Player->buildDomainUpgrade("argalach castle", "south castle tower", "gate south castle tower");
	Player->buildDomainUpgrade("argalach castle", "west castle tower", "archer's west castle tower");
	Player->buildDomainUpgrade("argalach castle", "east castle tower", "gate east castle tower");
	Player->buildDomainUpgrade("argalach castle", "southeast castle tower", "mage southeast castle tower");
	Player->buildDomainUpgrade("argalach castle", "north tower", "ballista north tower");
	Player->buildDomainUpgrade("argalach castle", "south tower", "ballista south tower");
	Player->buildDomainUpgrade("argalach castle", "west tower", "gate west tower");
	Player->buildDomainUpgrade("argalach castle", "east tower", "ballista east tower");
	Player->buildDomainUpgrade("argalach castle", "western north wall", "stone western north wall");
	Player->buildDomainUpgrade("argalach castle", "eastern north wall", "stone eastern north wall");
	Player->buildDomainUpgrade("argalach castle", "western south wall", "stone western south wall");
	Player->buildDomainUpgrade("argalach castle", "eastern south wall", "stone eastern south wall");
	Player->buildDomainUpgrade("argalach castle", "northern west wall", "stone northern west wall");
	Player->buildDomainUpgrade("argalach castle", "southern west wall", "stone southern west wall");
	Player->buildDomainUpgrade("argalach castle", "northern east wall", "stone northern east wall");
	Player->buildDomainUpgrade("argalach castle", "southern east wall", "stone southern east wall");
	Player->buildDomainUpgrade("argalach castle", "western north castle wall", "stone western north castle wall");
	Player->buildDomainUpgrade("argalach castle", "western south castle wall", "stone western south castle wall");
	Player->buildDomainUpgrade("argalach castle", "eastern north castle wall", "stone eastern north castle wall");
	Player->buildDomainUpgrade("argalach castle", "eastern south castle wall", "stone eastern south castle wall");
	Player->buildDomainUpgrade("argalach castle", "northern west castle wall", "stone northern west castle wall");
	Player->buildDomainUpgrade("argalach castle", "northern east castle wall", "stone northern east castle wall");
	Player->buildDomainUpgrade("argalach castle", "southern west castle wall", "stone southern west castle wall");
	Player->buildDomainUpgrade("argalach castle", "southern east castle wall", "stone southern east castle wall");

	Player->colorConfiguration("none");
	Selector->initiateSelector(Player);

	ExpectEq("Building Projects - Main Menu:\n"
		"From this menu, you can initiate, modify, or abort projects in your holdings\n"
		"at Argalach Castle.\n\n"
		"                                                                             \n"
		"                             +====+            +==---==+            +====+   \n"
		"                             |+~~+|============| x x x |============|+~~+|   \n"
		"                             |+~~+ .?.         +=======+         .?. +~~+|   \n"
		"                             +=    ...                           ...    =+   \n"
		"                              | ..    +====+      +-+      +====+    .. |    \n"
		"                              | ?.    |+~~+|======+ +======|+~~+|    .? |    \n"
		"                              | ..    |+~~+ .?.         .?. +~~+|    .. |    \n"
		"                              |       +=    ...         ...    =+       |    \n"
		"                              |        | ..                 .. |        |    \n"
		"                             +==+      | ?.    +=======+    .? |      +==+   \n"
		"                             |x |      | ..    | +---+ |    .. |      | x|   \n"
		"                             |  |     +-+      | |   | |      +-+     |  |   \n"
		"                             |  |     +-+      | +---+ |      +-+     |  |   \n"
		"                             |x |      | ..    +=======+    .. |      | x|   \n"
		"                             +==+      | ?.                 .? |      +==+   \n"
		"                              |        | ..                 .. |        |    \n"
		"                              |       +=    ...         ...    =+       |    \n"
		"                              | ..    |+~~+ .?.         .?. +~~+|    .. |    \n"
		"                              | ?.    |+~~+|======+ +======|+~~+|    .? |    \n"
		"                              | ..    +====+      +-+      +====+    .. |    \n"
		"[1] - Construct Building     +=    ...                           ...    =+   \n"
		"[2] - Construct Keep         |+~~+ .?.         +==---==+         .?. +~~+|   \n"
		"[3] - Construct Moat         |+~~+|============| x x x |============|+~~+|   \n"
		"[4] - Construct Tower        +====+            +=======+            +====+   \n"
		"[5] - Construct Wall                                                         \n"
		"[6] - Exit Building Projects Menu\n"
		"You must select a number from 1 to 6.\n"
		"Type 'exit' if you do not wish to make a selection at this time.\n"
		"For details on a given choice, type 'describe X' (or '? X') where\n"
		"X is the option about which you would like further details.\n",
		Player->caughtMessage());
}