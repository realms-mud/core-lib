//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/guilds/bard/selectors/songsSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->colorConfiguration("none");
    User->addCommands();

    move_object(Selector, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrect()
{
    Selector->initiateSelector(User);
    ExpectEq("Song - Compose Songs Main Menu:\n"
        "[1] - Create New Song                [2] - Exit Song Menu                 \n"
        "You must select a number from 1 to 2.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CreationDisplayWithCreatedSongsIsCorrect()
{
    mapping compositeElement = ([
        "alias": "weasel",
        "constraint": "/guilds/bard/compositions/root.c",
        "elements": ({
            ([ "research": "lib/tests/support/research/compositeResearchItemA.c",
                "type": "Verse 1",
                "description": "Oh, sing me a song of the weasels, man.",
                "order in sequence": 1
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemB.c",
                "type": "Verse 1",
                "description": "Sing me a song tonight.",
                "order in sequence": 2
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemA.c",
                "type": "Verse 1",
                "description": "For the Mustelidae, they are now mocking me",
                "order in sequence": 3
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemC.c",
                "type": "Verse 1",
                "description": "and eating my intestines in spite.",
                "order in sequence": 4
            ]),
        })
    ]);

    ExpectTrue(User->addCompositeResearch("Flight of the Weasels",
        compositeElement));
    ExpectTrue(User->addCompositeResearch("Reprise the Weasels",
        compositeElement));
    ExpectTrue(User->addCompositeResearch("Weasels Return",
        compositeElement));
    ExpectTrue(User->addCompositeResearch("Weasels are the land-loving mother pigeon of creatures",
        compositeElement));

    compositeElement["constraint"] = "lib/tests/support/research/flightOfWeasels.c";
    ExpectTrue(User->addCompositeResearch("This shouldn't appear in list",
        compositeElement));

    Selector->initiateSelector(User);
    ExpectEq("Song - Compose Songs Main Menu:\n"
        "[1] - Modify 'Flight of the Wea...'  [2] - Modify 'Reprise the Weasels'   \n"
        "[3] - Modify 'Weasels Return'        [4] - Modify 'Weasels are the l...'  \n"
        "[5] - Create New Song                [6] - Exit Song Menu                 \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeASongShowsCorrectDetails()
{
    mapping compositeElement = ([
        "alias": "weasel",
        "constraint": "/guilds/bard/compositions/root.c",
        "elements": ({
            ([ "research": "lib/tests/support/research/compositeResearchItemA.c",
                "type": "Verse 1",
                "description": "Oh, sing me a song of the weasels, man.",
                "order in sequence": 1
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemB.c",
                "type": "Verse 1",
                "description": "Sing me a song tonight.",
                "order in sequence": 2
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemA.c",
                "type": "Verse 1",
                "description": "For the Mustelidae, they are now mocking me",
                "order in sequence": 3
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemC.c",
                "type": "Verse 1",
                "description": "and eating my intestines in spite.",
                "order in sequence": 4
            ]),
        })
    ]);

    ExpectTrue(User->addCompositeResearch("Flight of the Weasels",
        compositeElement));

    Selector->initiateSelector(User);
    command("? 1", User);
    ExpectEq("Song Name       : Flight of the Weasels\n"
        "Alias           : weasel\n"
        "Composition Elements : 4\n"
        "   * Lyric blast\n"
        "     Verse 1 lyric   : Oh, sing me a song of the weasels, man.\n"
        "     Usage effect    : 100% chance to damage hit points 25\n"
        "     \n"
        "   * Lyric verse thingy\n"
        "     Verse 1 lyric   : Sing me a song tonight.\n"
        "     Usage effect    : 100% chance to damage stamina points 25\n"
        "     \n"
        "   * Lyric blast\n"
        "     Verse 1 lyric   : For the Mustelidae, they are now mocking me\n"
        "     Usage effect    : 100% chance to damage hit points 25\n"
        "     \n"
        "   * Singy blast\n"
        "     Verse 1 lyric   : and eating my intestines in spite.\n"
        "     Usage effect    : 100% chance to damage spell points 25\n"
        "     \n",
        User->caughtMessage());
}
