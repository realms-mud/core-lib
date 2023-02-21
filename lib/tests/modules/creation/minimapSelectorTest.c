//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/minimapSelector.c");
    Selector.init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.colorConfiguration("none");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapSelectorDisplayCorrectMenu()
{
    Selector.initiateSelector(User);
    ExpectSubStringMatch("Character creation - Would you like to display a mini map in room\n"
        "descriptions that support it. \n"
        "Without mini map: \n"
        ".* a gate house. To the east and west is a lit sconce. To the north\n"
        "and south is a raised portcullis.\n"
        " -=-=- There are two obvious exits: north, south\n"
        "        \n"
        "With mini map: \n"
        "    |    ' .* a gate house. To the east and\n"
        "-o--o--o-' west is a lit sconce. To the north and south is a raised\n"
        "    |  | ' portcullis.\n"
        "==..|..==' \n"
        "  ||o||  '\n"
        "  ..|.|  '\n"
        "  | | |  '\n"
        "  | o |  '\n"
        "==+ | +=='\n"
        " -=-=- There are two obvious exits: north, south\n\n\n"
        "    .1. - Turn Mini Map On    \n"
        "    .2. - Leave Mini Map Off  \n"
        "You must select a number from 1 to 2.\n"
        "For details on a given choice, type 'describe X' (or '. X') where\n"
        "X is the option about which you would like further details.\n"
        "You can change this value after character creation using the 'set' command.\n",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnDisplayIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 1");
    ExpectEq("\This option turns on mini map display.\n", 
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OffDisplayIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("describe 2");
    ExpectEq("This option turns off mini map display.\n",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UserMiniMapIsSetToOn()
{
    Selector.initiateSelector(User);
    Selector.applySelection("1");
    ExpectTrue(User.displayMiniMap());
}

/////////////////////////////////////////////////////////////////////////////
void UserMiniMapIsSetToOff()
{
    Selector.initiateSelector(User);
    Selector.applySelection("2");
    ExpectFalse(User.displayMiniMap());
}
