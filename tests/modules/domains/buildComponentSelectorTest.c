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
    Selector = clone_object("/lib/modules/domains/buildComponentSelector.c");
    Selector->setLocation("argalach castle");
    Selector->setConstructionData((["type":"keep", "name" : "stone keep"]));

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

    ExpectEq("Building Projects - Stone Keep:\n"
        "From this menu, you can initiate, modify, or abort projects in your holdings\n"
        "at Argalach Castle.\n\n"
        "Layout: +=======+                                                               \n"
        "        | +---+ |               ......            .........            ......   \n"
        "        | |   | |               .    ..............       ..............    .   \n"
        "        | +---+ |               .     .?.         .........         .?.     .   \n"
        "        +=======+               ..    ...                           ...    ..   \n"
        "Completion time: 1000            . ..    ......      ...      ......    .. .    \n"
        "                                 . ?.    .    ........ ........    .    .? .    \n"
        "Stone Battlement:                . ..    .     .?.         .?.     .    .. .    \n"
        "    <select>                     .       ..    ...         ...    ..       .    \n"
        "Central Stone Tower:             .        . ..                 .. .        .    \n"
        "    <select>                    ....      . ?.    .........    .? .      ....   \n"
        "Main Stone Keep:                .  .      . ..    .       .    .. .      .  .   \n"
        "    <select>                    .  .     ...      .       .      ...     .  .   \n"
        "                                .  .     ...      .       .      ...     .  .   \n"
        "Needed workers:                 .  .      . ..    .........    .. .      .  .   \n"
        "    Architect         -  0/1    ....      . ?.                 .? .      ....   \n"
        "    Blacksmith        -  0/1     .        . ..                 .. .        .    \n"
        "    Carpenter         -  0/3     .       ..    ...         ...    ..       .    \n"
        "    Foreman           -  0/1     . ..    .     .?.         .?.     .    .. .    \n"
        "    Stonemason        -  0/10    . ?.    .    ........ ........    .    .? .    \n"
        "                                 . ..    ......      ...      ......    .. .    \n"
        "                                ..    ...                           ...    ..   \n"
        "Select building options for:    .     .?.         .........         .?.     .   \n"
        "[1] - Central Stone Tower       .    ..............       ..............    .   \n"
        "[2] - Main Stone Keep           ......            .........            ......   \n"
        "[3] - Stone Battlement                                                          \n"                           
        "[4] - Select Workers      \n"
        "[5] - Create Building     \n"
        "[6] - Exit Building Menu  \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysWorkerMenu()
{
    Selector->initiateSelector(Player);

    command("4", Player);

    ExpectEq("Building Projects - Assign Workers:\n"
        "From this menu, you can select the workers who will be executing your Stone\n"
        "Keep project in your holdings at Argalach Castle.\n"
        "\n"
        "[1] - Auto-Select Workers \n"
        "[2] - Confirm Selected Workers\n"
        "[3] - Exit Building Menu  \n"
        "You must select a number from 1 to 3.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysSectionMenu()
{

}
