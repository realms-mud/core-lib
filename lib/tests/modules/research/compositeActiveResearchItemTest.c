//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object User;
object Target;
object Room;

mapping compositeElement = ([
    "alias": "weasel",
    "constraint": "lib/tests/support/research/compositeRoot.c",
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

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->addAlias("bob");
    User->Str(20);
    User->Int(20);
    User->Dex(20);
    User->Con(20);
    User->Wis(20);
    User->Chr(20);
    User->hitPoints(User->maxHitPoints());
    User->spellPoints(User->maxSpellPoints());
    User->staminaPoints(User->maxStaminaPoints());
    User->addSkillPoints(200);
    User->advanceSkill("long sword", 16);
    User->toggleKillList();
    User->ToggleMockResearch();
    User->addResearchPoints(50);
    User->initiateResearch("lib/tests/support/research/compositeRoot.c");
    User->initiateResearch("lib/tests/support/research/compositeResearchItemA.c");
    User->initiateResearch("lib/tests/support/research/compositeResearchItemB.c");
    User->initiateResearch("lib/tests/support/research/compositeResearchItemC.c");
    User->initiateResearch("lib/tests/support/research/compositeResearchItemD.c");
    User->initiateResearch("lib/tests/support/research/compositeResearchItemE.c");

    Target = clone_object("/lib/realizations/monster.c");
    Target->Name("Frank");
    Target->addAlias("frank");
    Target->Str(20);
    Target->Int(20);
    Target->Dex(20);
    Target->Con(20);
    Target->Wis(20);
    Target->Chr(20);
    Target->hitPoints(Target->maxHitPoints());
    Target->spellPoints(Target->maxSpellPoints());
    Target->staminaPoints(Target->maxStaminaPoints());

    Room = clone_object("/lib/environment/environment");
    move_object(User, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Target);
    destruct(User);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void DamageHitPointsWillExecuteAttack()
{
    ExpectTrue(User->setCompositeResearch("Flight of the Weasels",
        compositeElement));

    ExpectFalse(User->hasActiveCompositeResearch());
    command("perform Flight of the Weasels", User);
    ExpectEq("You begin to play a song...\n", User->caughtMessage());
    ExpectTrue(User->hasActiveCompositeResearch());

    object blah = load_object("lib/tests/support/research/compositeRoot.c");
    ExpectTrue(blah->executeCompositeResearch(User));
    ExpectEq("You sing, 'Oh, sing me a song of the weasels, man.'\n", 
        User->caughtMessage());

    ExpectTrue(blah->executeCompositeResearch(User));
    ExpectEq("You drone on, 'Sing me a song tonight.'\n",
        User->caughtMessage());

    ExpectTrue(blah->executeCompositeResearch(User));
    ExpectEq("You sing, 'For the Mustelidae, they are now mocking me'\n",
        User->caughtMessage());

    ExpectTrue(blah->executeCompositeResearch(User));
    ExpectEq("You yowl, 'and eating my intestines in spite.'\n",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanDisplayResearchInfo()
{
    //object effect = clone_object("lib/tests/support/research/compositeRoot.c");

    //ExpectEq("Research Name   : Combo blarg\n"
    //    "This is combo active research\n"
    //    "\n"
    //    "This research item is granted to the user at a pre-defined time.\n"
    //    "Research Type   : Active\n"
    //    "Scope           : Targeted\n"
    //    "Cost to use     : 10 stamina points\n"
    //    "Usage cooldown  : 1 second\n"
    //    "Command syntax  : do stuff [.*]\n"
    //    "Combination Rule : Can include any of:\n"
    //    "                  hruf: This will hruf stuff.\n"
    //    "                  muclid: This muclidifies stuff.\n"
    //    "Combination Rule : Can include only one of:\n"
    //    "                  surlac: This surily surlacs stuff.\n"
    //    "                  clerb: Beware the clerb.\n"
    //    "Combination Rule : Must include any of:\n"
    //    "                  gurg: This inverse gurgs stuff.\n"
    //    "                  frumbus: This unfrumbuses stuff.\n"
    //    "                  fargle: This fargles with the fresh scent of Brute.\n"
    //    "Combination Rule : Must include only one of:\n"
    //    "                  blarg: This blargifies stuff.\n"
    //    "                  rarg: This de-rargulates stuff.\n"
    //    "Max Combo Size  : 3\n"
    //    "Combo Damage    : Modified -> 1.25 * your Combo stuff research (multiplicative)\n",
    //    effect->researchDetails());
}
