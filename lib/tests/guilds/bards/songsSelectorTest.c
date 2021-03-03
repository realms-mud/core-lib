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
        "type": "/guilds/bard/compositions/simple-ballad.c",
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

    ExpectTrue(User->setCompositeResearch("Flight of the Weasels",
        compositeElement));
    ExpectTrue(User->setCompositeResearch("Reprise the Weasels",
        compositeElement));
    ExpectTrue(User->setCompositeResearch("Weasels Return",
        compositeElement));
    ExpectTrue(User->setCompositeResearch("Weasels are the land-loving mother pigeon of creatures",
        compositeElement));

    compositeElement["constraint"] = "lib/tests/support/research/flightOfWeasels.c";
    ExpectTrue(User->setCompositeResearch("This shouldn't appear in list",
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
        "type": "/guilds/bard/compositions/simple-ballad.c",
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

    ExpectTrue(User->setCompositeResearch("Flight of the Weasels",
        compositeElement));

    Selector->initiateSelector(User);
    command("? 1", User);
    ExpectEq("Song Name       : Flight of the Weasels\n"
        "Alias           : weasel\n"
        "Composition Elements : 4\n"
        "    * Lyric blast\n"
        "      Verse 1 lyric   : Oh, sing me a song of the weasels, man.\n"
        "      Usage effect    : 100% chance to damage hit points 25\n"
        "      \n"
        "    * Lyric verse thingy\n"
        "      Verse 1 lyric   : Sing me a song tonight.\n"
        "      Usage effect    : 100% chance to damage stamina points 25\n"
        "      \n"
        "    * Lyric blast\n"
        "      Verse 1 lyric   : For the Mustelidae, they are now mocking me\n"
        "      Usage effect    : 100% chance to damage hit points 25\n"
        "      \n"
        "    * Singy blast\n"
        "      Verse 1 lyric   : and eating my intestines in spite.\n"
        "      Usage effect    : 100% chance to damage spell points 25\n"
        "      \n",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectCreateASong()
{
    Selector->initiateSelector(User);
    command("1", User);
    ExpectEq("Song - Select Song Structure Menu:\n"
        "[1]  - AAA (Verse, Verse, Verse)      \n"
        "[2]  - AABA (Verse, Verse, Bridge, Verse) \n"
        "[3]  - ABAB (Verse/Chorus)            \n"
        "[4]  - ABABCB (Verse/Chorus/Bridge/Solo) \n"
        "[5]  - ABAC (4 eight bar sections)    \n"
        "[6]  - ABACBAA (Chorus/Verse/Chorus/Bridge) \n"
        "[7]  - Freeform                       \n"
        "[8]  - Simple Ballad                  \n"
        "[9]  - Verse/Chorus/Bridge            \n"
        "[10] - Verse/Pre-Chorus/Chorus        \n"
        "[11] - Return To Previous Menu        \n"
        "You must select a number from 1 to 11.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n", 
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CreateSongTransitionsToModifyMenu()
{
    Selector->initiateSelector(User);
    command("1", User);
    command("1", User);
    ExpectEq("Song - Create Song Menu\n"
        "Song Type: AAA (Verse, Verse, Verse)\n"
        "Song Name: <Name Missing>\n"
        "Song Alias: <No Alias>\n"
        "\n"
        "[1] - Add verse 1 segment              \n"
        "[2] - Add verse 2 segment              \n"
        "[3] - Add verse 3 segment              \n"
        "[4] - Set/change song name             \n"
        "[5] - Set/change song alias            \n"
        "[6] - Save the song                 (X)\n"
        "[7] - Exit Menu                        \n"
        "You must select a number from 1 to 7.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectModifyForASong()
{
    mapping compositeElement = ([
        "alias": "weasel",
        "constraint": "/guilds/bard/compositions/root.c",
        "type": "/guilds/bard/compositions/simple-ballad.c",
        "elements": ({
            (["research":"lib/tests/support/research/compositeResearchItemE.c",
                "type" : "intro",
                "description" : "Gittern, Cm7b5 arpeggio",
                "order in sequence" : 1
            ]),
            (["research":"lib/tests/support/research/compositeResearchItemD.c",
                "type" : "verse 1",
                "description" : "I'm walking through a reliquary",
                "order in sequence" : 2
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemD.c",
                "type": "verse 1",
                "description": "Family of weasels snuck in...",
                "order in sequence": 3
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemB.c",
                "type": "verse 1",
                "description": "A big one sidled up next to me",
                "order in sequence": 4
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemB.c",
                "type": "verse 1",
                "description": "Climbed my body and chewed on my chin.",
                "order in sequence": 5
            ]),
            (["research":"lib/tests/support/research/compositeResearchItemE.c",
                "type" : "verse 1",
                "description" : "Gittern, chords: Am, D7, Cm7b5",
                "order in sequence" : 6
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemA.c",
                "type": "chorus 1",
                "description": "Oh, sing me a song of the weasels, man.",
                "order in sequence": 7
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemB.c",
                "type": "chorus 1",
                "description": "Sing me a song tonight.",
                "order in sequence": 8
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemA.c",
                "type": "chorus 1",
                "description": "For the Mustelidae, they are now mocking me",
                "order in sequence": 9
            ]),
            ([ "research": "lib/tests/support/research/compositeResearchItemC.c",
                "type": "chorus 1",
                "description": "and eating my intestines in spite.",
                "order in sequence": 10
            ]),
        })
    ]);

    ExpectTrue(User->setCompositeResearch("Flight of the Weasels",
        compositeElement));

    Selector->initiateSelector(User);
    command("1", User);
    ExpectEq("Song - Modify Song Menu\n"
        "Song Type: Simple Ballad\n"
        "Song Name: Flight of the Weasels\n"
        "Song Alias: weasel\n"
        "\n"
        "[1]  - Gittern bedazzlement\n"
        "       Intro instrumental : Gittern, Cm7b5 arpeggio\n"
        "                         (-5) Penalty to attack   \n"
        "[2]  - Add intro segment                \n"
        "[3]  - Lyric of doom\n"
        "       Verse 1 lyric   : I'm walking through a reliquary\n"
        "                         (-2) Penalty to intelligence   \n"
        "[4]  - Lyric of doom\n"
        "       Verse 1 lyric   : Family of weasels snuck in...\n"
        "                         (-2) Penalty to intelligence   \n"
        "[5]  - Lyric verse thingy\n"
        "       Verse 1 lyric   : A big one sidled up next to me\n"
        "       Usage effect    : 100% chance to damage stamina points 25   \n"
        "[6]  - Lyric verse thingy\n"
        "       Verse 1 lyric   : Climbed my body and chewed on my chin.\n"
        "       Usage effect    : 100% chance to damage stamina points 25   \n"
        "[7]  - Gittern bedazzlement\n"
        "       Verse 1 instrumental : Gittern, chords: Am, D7, Cm7b5\n"
        "                         (-5) Penalty to attack   \n"
        "[8]  - Add verse 1 segment              \n"
        "[9]  - Lyric blast\n"
        "       Chorus 1 lyric  : Oh, sing me a song of the weasels, man.\n"
        "       Usage effect    : 100% chance to damage hit points 25   \n"
        "[10] - Lyric verse thingy\n"
        "       Chorus 1 lyric  : Sing me a song tonight.\n"
        "       Usage effect    : 100% chance to damage stamina points 25   \n"
        "[11] - Lyric blast\n"
        "       Chorus 1 lyric  : For the Mustelidae, they are now mocking me\n"
        "       Usage effect    : 100% chance to damage hit points 25   \n"
        "[12] - Singy blast\n"
        "       Chorus 1 lyric  : and eating my intestines in spite.\n"
        "       Usage effect    : 100% chance to damage spell points 25   \n"
        "[13] - Add chorus 1 segment             \n"
        "[14] - Add verse 2 segment              \n"
        "[15] - Add chorus 2 segment             \n"
        "[16] - Add outro segment                \n"
        "[17] - Set/change song name             \n"
        "[18] - Set/change song alias            \n"
        "[19] - Save the song                    \n"
        "[20] - Exit Menu                        \n"
        "You must select a number from 1 to 20.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User->caughtMessage());
}
