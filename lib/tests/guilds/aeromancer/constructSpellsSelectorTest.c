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
                "description": "This is the form."
            ]),
            ([ "research": "/guilds/aeromancer/functions/lightning.c",
                "type": "function",
                "description": "This is the function."
            ]),
            ([ "research": "/guilds/aeromancer/effects/damage-hp.c",
                "type": "effect",
                "description": "This is the effect."
            ]),
        })
    ]);
//
//    ExpectTrue(User.setCompositeResearch("Zappy Thing",
//        compositeElement));
//    ExpectTrue(User.setCompositeResearch("Reprise the Weasels",
//        compositeElement));
//    ExpectTrue(User.setCompositeResearch("Weasels Return",
//        compositeElement));
//    ExpectTrue(User.setCompositeResearch("Weasels are the land-loving mother pigeon of creatures",
//        compositeElement));
//
//    compositeElement["constraint"] = "/lib/tests/support/research/flightOfWeasels.c";
//    ExpectTrue(User.setCompositeResearch("This shouldn't appear in list",
//        compositeElement));
//
//    Selector.initiateSelector(User);
//    ExpectEq("Song - Compose Songs Main Menu:\n"
//        "[1] - Modify 'Flight of the Wea...'  [2] - Modify 'Reprise the Weasels'   \n"
//        "[3] - Modify 'Weasels Return'        [4] - Modify 'Weasels are the l...'  \n"
//        "[5] - Create New Song                [6] - Exit Song Menu                 \n"
//        "You must select a number from 1 to 6.\n"
//        "Type 'exit' if you do not wish to make a selection at this time.\n"
//        "For details on a given choice, type 'describe X' (or '? X') where\n"
//        "X is the option about which you would like further details.\n",
//        User.caughtMessage());
}
