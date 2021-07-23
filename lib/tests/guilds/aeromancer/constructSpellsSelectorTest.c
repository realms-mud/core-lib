//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
int AdvanceToLevel(int level, string guild)
{
    int runningLevel = User.guildLevel(guild);
    while ((User.guildLevel(guild) < level) && User.memberOfGuild(guild))
    {
        User.addExperience(1000 * runningLevel);
        User.advanceLevel(guild);
        command("exit", User);
        runningLevel = User.guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "AdvanceToLevel" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object(
        "/lib/modules/guilds/selectors/constructedResearchSelector.c");
    Selector.setType("Aeromancer Spell");
    Selector.setCompositeGrouping("/guilds/aeromancer/construct/root.c");
    Selector.InitializeSelector();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.colorConfiguration("none");
    User.addCommands();

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
    Selector.initiateSelector(User);
    ExpectEq("Aeromancer Spell - Construct Spell Main Menu:\n"
        "[1] - Create New Aeromancer Spell    [2] - Exit Construct Spell Menu      \n"
        "You must select a number from 1 to 2.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void ConstructionDisplayWithCreatedSpellsIsCorrect()
{
    mapping compositeElement = ([
        "alias": "weasel",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form",
                "description": "This is the form.",
                "unordered": 1
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function",
                "description": "This is the function.",
                "unordered": 1
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect",
                "description": "This is the effect.",
                "unordered": 1
            ]),
        })
    ]);

    ExpectTrue(User.setCompositeResearch("Zappy Thing",
        compositeElement));
    ExpectTrue(User.setCompositeResearch("Weaselstrike",
        compositeElement));
    ExpectTrue(User.setCompositeResearch("Weasel Blast",
        compositeElement));
    ExpectTrue(User.setCompositeResearch("Weasels are the land-loving mother pigeon of creatures",
        compositeElement));

    compositeElement["constraint"] = "/lib/tests/support/research/flightOfWeasels.c";
    ExpectTrue(User.setCompositeResearch("This shouldn't appear in list",
        compositeElement));

    Selector.initiateSelector(User);
    ExpectEq("Aeromancer Spell - Construct Spell Main Menu:\n"
        "[1] - Modify 'Weasel Blast'          [2] - Modify 'Weasels are the l...'  \n"
        "[3] - Modify 'Weaselstrike'          [4] - Modify 'Zappy Thing'           \n"
        "[5] - Create New Aeromancer Spell    [6] - Exit Construct Spell Menu      \n"
        "You must select a number from 1 to 6.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeASpellShowsCorrectDetails()
{
    mapping compositeElement = ([
        "alias": "weasel",
        "constraint": "/guilds/aeromancer/construct/root.c",
        "type": "/guilds/aeromancer/construct/root.c",
        "elements": ({
            ([ "research": "/guilds/aeromancer/forms/arc.c",
                "type": "form",
                "description": "This is the form.",
                "unordered": 1
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function",
                "description": "This is the function.",
                "unordered": 1
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect",
                "description": "This is the effect.",
                "unordered": 1
            ]),
        })
    ]);

    ExpectTrue(User.setCompositeResearch("Flight of the Weasels",
        compositeElement));

    Selector.initiateSelector(User);
    command("? 1", User);
    //ExpectEq("Song Name       : Flight of the Weasels\n"
    //    "Alias           : weasel\n"
    //    "Composition Elements : 4\n"
    //    "    * Lyric blast\n"
    //    "      Verse 1 lyric   : Oh, sing me a song of the weasels, man.\n"
    //    "      Usage effect    : 100% chance to damage hit points 25\n"
    //    "      \n"
    //    "    * Lyric verse thingy\n"
    //    "      Verse 1 lyric   : Sing me a song tonight.\n"
    //    "                        (+2) Bonus strength\n"
    //    "      \n"
    //    "    * Lyric blast\n"
    //    "      Verse 1 lyric   : For the Mustelidae, they are now mocking me\n"
    //    "      Usage effect    : 100% chance to damage hit points 25\n"
    //    "      \n"
    //    "    * Singy blast\n"
    //    "      Verse 1 lyric   : and eating my intestines in spite.\n"
    //    "                        (-2) Penalty to strength\n"
    //    "      This is only applied when you're using: instrument: plucked.\n"
    //    "      \n",
    //    User.caughtMessage());
}
