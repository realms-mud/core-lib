//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object User;
object Target;
object Friend;

object Room;

mapping compositeElement = ([
    "alias": "weasel",
    "constraint": "/lib/tests/support/research/compositeRoot.c",
    "type": "/guilds/bard/compositions/simple-ballad.c",
    "elements": ({
        ([ "research": "/lib/tests/support/research/compositeResearchItemA.c",
            "type": "Verse 1",
            "description": "Oh, sing me a song of the weasels, man.",
            "order in sequence": 1
        ]),
        ([ "research": "/lib/tests/support/research/compositeResearchItemB.c",
            "type": "Verse 1",
            "description": "Sing me a song tonight.",
            "order in sequence": 2
        ]),
        ([ "research": "/lib/tests/support/research/compositeResearchItemD.c",
            "type": "Verse 1",
            "description": "For the Mustelidae, they are now mocking me",
            "order in sequence": 3
        ]),
        ([ "research": "/lib/tests/support/research/compositeResearchItemC.c",
            "type": "Verse 1",
            "description": "and eating my intestines in spite.",
            "order in sequence": 4
        ]),
    })
]);

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.addAlias("bob");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.hitPoints(User.maxHitPoints());
    User.spellPoints(User.maxSpellPoints());
    User.staminaPoints(User.maxStaminaPoints());
    User.addCommands();
    User.addSkillPoints(200);
    User.advanceSkill("long sword", 16);
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/compositeRoot.c");
    User.initiateResearch("/lib/tests/support/research/compositeResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/compositeResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/compositeResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/compositeResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/compositeResearchItemE.c");

    Friend = clone_object("/lib/realizations/henchman.c");
    Friend.Name("Earl");
    Friend.addAlias("earl");
    Friend.Str(20);
    Friend.Int(20);
    Friend.Dex(20);
    Friend.Con(20);
    Friend.Wis(20);
    Friend.Chr(20);
    Friend.hitPoints(User.maxHitPoints());
    Friend.spellPoints(User.maxSpellPoints());
    Friend.staminaPoints(User.maxStaminaPoints());
    Friend.setLeader(User);

    Target = clone_object("/lib/realizations/monster.c");
    Target.Name("Frank");
    Target.addAlias("frank");
    Target.Str(20);
    Target.Int(20);
    Target.Dex(20);
    Target.Con(20);
    Target.Wis(20);
    Target.Chr(20);
    Target.hitPoints(Target.maxHitPoints());
    Target.spellPoints(Target.maxSpellPoints());
    Target.staminaPoints(Target.maxStaminaPoints());

    Room = clone_object("/lib/environment/environment");
    move_object(User, Room);
    move_object(Friend, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User.getParty());
    destruct(Target);
    destruct(Friend);
    destruct(User);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteCompositeActiveResearch()
{
    object instrument =
        clone_object("/lib/instances/items/instruments/strings/lute.c");
    move_object(instrument, User);
    command("equip lute", User);

    ExpectTrue(User.setCompositeResearch("Flight of the Weasels",
        compositeElement));

    ExpectFalse(User.hasActiveCompositeResearch());

    command("perform Flight of the Weasels", User);
    ExpectEq("You begin to play a song...\n", User.caughtMessage());
    ExpectTrue(User.hasActiveCompositeResearch());

    object compositeResearch = 
        load_object("/lib/tests/support/research/compositeRoot.c");

    ExpectEq(150, User.hitPoints());
    ExpectEq(150, Friend.hitPoints());
    ExpectEq(150, Target.hitPoints());

    ExpectEq(20, User.Str());
    ExpectEq(20, Friend.Str());
    ExpectEq(20, Target.Str());

    ExpectEq(-31, User.calculateDefendAttack());
    ExpectEq(-21, Friend.calculateDefendAttack());
    ExpectEq(-21, Target.calculateDefendAttack());

    User.heart_beat();
    ExpectEq("You sing, 'Oh, sing me a song of the weasels, man.'\n", 
        User.caughtMessage());

    ExpectEq(150, User.hitPoints());
    ExpectEq(150, Friend.hitPoints());
    ExpectEq(129, Target.hitPoints());
    User.heart_beat();

    ExpectEq("You drone on, 'Sing me a song tonight.'\n",
        User.caughtMessage());

    ExpectEq(22, User.Str());
    ExpectEq(22, Friend.Str());
    ExpectEq(20, Target.Str());

    User.heart_beat();

    ExpectEq("You squeal, 'For the Mustelidae, they are now mocking me'\n",
        User.caughtMessage());

    ExpectEq(-31, User.calculateDefendAttack(), "user");
    ExpectEq(-21, Friend.calculateDefendAttack(), "friend");
    ExpectEq(-71, Target.calculateDefendAttack(), "foe");

    User.heart_beat();

    ExpectEq("You yowl, 'and eating my intestines in spite.'\n",
        User.caughtMessage());
    ExpectEq(22, User.Str());
    ExpectEq(22, Friend.Str());
    ExpectEq(18, Target.Str());

    User.resetCatchList();
    User.heart_beat();
    ExpectEq(0, User.caughtMessage());

    ExpectFalse(compositeResearch.executeCompositeResearch(User));
}

/////////////////////////////////////////////////////////////////////////////
void CanGiveBonusAttackTypes()
{
    User.initiateResearch("/lib/tests/support/research/compositeResearchItemG.c");

    mapping research = ([
        "alias": "attack",
        "constraint": "/lib/tests/support/research/compositeRoot.c",
        "type": "/guilds/bard/compositions/simple-ballad.c",
        "elements": ({
            ([ "research": "/lib/tests/support/research/compositeResearchItemG.c",
                "type": "Verse 1",
                "description": "Sing me a song tonight.",
                "order in sequence": 1
            ]),
            ([ "research": "/lib/tests/support/research/compositeResearchItemA.c",
                "type": "Verse 1",
                "description": "Oh, sing me a song of the weasels, man.",
                "order in sequence": 2
            ]),
        })
    ]);
    object instrument =
        clone_object("/lib/instances/items/instruments/strings/lute.c");
    move_object(instrument, User);
    command("equip lute", User);

    ExpectTrue(User.setCompositeResearch("Weasel Blast",
        research));

    ExpectFalse(User.hasActiveCompositeResearch());

    command("perform Weasel Blast", User);
    ExpectEq("You begin to play a song...\n", User.caughtMessage());
    ExpectTrue(User.hasActiveCompositeResearch());

    object compositeResearch = 
        load_object("/lib/tests/support/research/compositeRoot.c");

    ExpectEq(1, sizeof(User.getAttacks()));
    ExpectEq(1, sizeof(Friend.getAttacks()));
    ExpectEq(1, sizeof(Target.getAttacks()));

    User.heart_beat();
    ExpectEq("You riff, 'Sing me a song tonight.'\n", 
        User.caughtMessage());

    ExpectEq(2, sizeof(User.getAttacks()));
    ExpectEq(1, sizeof(Friend.getAttacks()));
    ExpectEq(1, sizeof(Target.getAttacks()));
}

/////////////////////////////////////////////////////////////////////////////
void CanDisplayResearchInfo()
{
    object effect = clone_object("/lib/tests/support/research/compositeRoot.c");
    ExpectTrue(User.setCompositeResearch("Flight of the Weasels",
        compositeElement));

    set_this_player(User);
    User.colorConfiguration("none");

    ExpectEq("Research Name   : Musical Compositions\n"
        "This skill provides the user with the knowledge of composing and playing songs\n"
        "that can provide complex effects.\n"
        "\n"
        "This research item is granted to the user at a pre-defined time.\n"
        "Research Type   : Active\n"
        "Scope           : Area\n"
        "Command syntax  : perform <name or alias of song>\n"
        "Creation Rules  : Template must be one of:\n"
        "                  AAA (Verse, Verse, Verse)\n"
        "                      base cost - 25 SP 25 ST\n"
        "                  AABA (Verse, Verse, Bridge, Verse)\n"
        "                      base cost - 25 SP 25 ST\n"
        "                  ABAB (Verse/Chorus)\n"
        "                      base cost - 25 SP 25 ST\n"
        "Available Songs : \n"
        "                  Flight of the Weasels - alias: weasel\n",
        effect.researchDetails());
}

/////////////////////////////////////////////////////////////////////////////
void ExecutionBlockedWhenLimitorsNotMet()
{
    ExpectTrue(User.setCompositeResearch("Flight of the Weasels",
        compositeElement));
    User.colorConfiguration("none");
    User.resetCatchList();

    ExpectFalse(User.hasActiveCompositeResearch());

    command("perform Flight of the Weasels", User);
    ExpectEq(({ "", "You must be using the proper equipment for that "
        "(instrument: plucked).\n" }), User.caughtMessages());
    ExpectFalse(User.hasActiveCompositeResearch());
}

/////////////////////////////////////////////////////////////////////////////
void ExecutionBlockedWhenLimitorsNotMetAfterActivated()
{
    object instrument =
        clone_object("/lib/instances/items/instruments/strings/lute.c");
    move_object(instrument, User);
    command("equip lute", User);

    User.colorConfiguration("none");
    User.resetCatchList();

    ExpectTrue(User.setCompositeResearch("Flight of the Weasels",
        compositeElement));

    ExpectFalse(User.hasActiveCompositeResearch());

    command("perform Flight of the Weasels", User);
    ExpectEq("You begin to play a song...\n", User.caughtMessage());
    ExpectTrue(User.hasActiveCompositeResearch());

    User.heart_beat();
    ExpectEq("You sing, 'Oh, sing me a song of the weasels, man.'\n", 
        User.caughtMessage());

    ExpectFalse(member(User.caughtMessages(),
        "Your performance has been aborted.\n") > -1);

    destruct(instrument);
    User.heart_beat();

    ExpectTrue(member(User.caughtMessages(),
        "Your performance has been aborted.\n") > -1);
    ExpectFalse(User.hasActiveCompositeResearch());
}
