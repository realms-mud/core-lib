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
    Selector->setLocation("argalach castle");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");
    Player->addPlayerHolding("argalach castle");

    /*       "type": "castle",
       "upgrades": ([
           "keep": ([ "name" : "stone keep"]),
           "northwest tower": ([ "name" : "mage northwest tower"]),
           "northeast tower": ([ "name" : "mage northeast tower"]),
           "southwest tower": ([ "name" : "mage southwest tower"]),
           "southeast tower": ([ "name" : "mage southeast tower"]),
           "northwest castle tower": ([ "name" : "mage northwest castle tower"]),
           "northeast castle tower": ([ "name" : "mage northeast castle tower"]),
           "southwest castle tower": ([ "name" : "ballista southwest castle tower"]),
           "north castle tower": ([ "name" : "gate north castle tower"]),
           "south castle tower": ([ "name" : "gate south castle tower"]),
           "west castle tower": ([ "name" : "archer's west castle tower"]),
           "east castle tower": ([ "name" : "gate east castle tower"]),
           "southeast castle tower": ([ "name" : "mage southeast castle tower"]),
           "north tower": ([ "name" : "ballista north tower"]),
           "south tower": ([ "name" : "ballista south tower"]),
           "west tower": ([ "name" : "gate west tower"]),
           "east tower": ([ "name" : "ballista east tower"]),
           "western north wall": ([ "name" : "western north wall"]),
           "eastern north wall": ([ "name" : "eastern north wall"]),
           "western south wall": ([ "name" : "western south wall"]),
           "eastern south wall": ([ "name" : "eastern south wall"]),
           "northern west wall": ([ "name" : "northern west wall"]),
           "southern west wall": ([ "name" : "southern west wall"]),
           "northern east wall": ([ "name" : "northern east wall"]),
           "southern east wall": ([ "name" : "southern east wall"]),
           "western north castle wall": ([ "name" : "western north castle wall"]),
           "western south castle wall": ([ "name" : "western south castle wall"]),
           "eastern north castle wall": ([ "name" : "eastern north castle wall"]),
           "eastern south castle wall": ([ "name" : "eastern south castle wall"]),
           "northern west castle wall": ([ "name" : "northern west castle wall"]),
           "northern east castle wall": ([ "name" : "northern east castle wall"]),
           "southern west castle wall": ([ "name" : "southern west castle wall"]),
           "southern east castle wall": ([ "name" : "southern east castle wall"]),
       ])*/

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
//    */
        Player->caughtMessage());
}
