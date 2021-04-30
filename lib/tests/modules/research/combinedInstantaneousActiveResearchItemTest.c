//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object User;
object Target;
object Room;

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
    User.addSkillPoints(200);
    User.advanceSkill("long sword", 16);
    User.toggleKillList();
    User.addResearchPoints(50);
    User.initiateResearch("/lib/tests/support/research/comboResearchItem.c");
    User.colorConfiguration("none");
    User.resetCatchList();

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
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    ExpectEq(150, Target.hitPoints(), "Frank's initial HP");
    command("do stuff blarg frumbus clerb at frank", User);
    ExpectEq(103, Target.hitPoints(), "Frank has taken damage");

    ExpectEq("You ready a turnip and blarg swimmingly, clerb at Frank with fiery "
        "death, and\nfrumbus with great conviction.\n", User.caughtMessage());

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void WillNotExecuteInvalidCombinations()
{
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    ExpectEq(150, Target.hitPoints(), "Frank's initial HP");
    command("do stuff blarg rarg clerb at frank", User);
    ExpectEq(150, Target.hitPoints(), "Frank has taken damage");

    // The empty message is due to the notify_fail / the way execute is handled
    ExpectEq(({ "",
        "That is an invalid combination. You must use exactly one of: blarg or rarg.\n" }),
        User.caughtMessages());

    // Proof that Bob and Frank are not fighting
    ExpectFalse(Target.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void NotSpecifyingTargetWillTargetCurrentForDamageResearch()
{
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    ExpectEq(150, Target.hitPoints(), "Frank's initial HP");
    command("do stuff blarg frumbus clerb at frank", User);
    ExpectEq(103, Target.hitPoints(), "Frank has taken damage");

    ExpectEq("You ready a turnip and blarg swimmingly, clerb at Frank with fiery "
        "death, and\nfrumbus with great conviction.\n", User.caughtMessage());

    User.heart_beat();
    Target.hitPoints(Target.maxHitPoints());

    User.resetCatchList();

    command("do stuff blarg frumbus clerb", User);
    ExpectEq("You ready a turnip and blarg swimmingly, clerb at Frank with fiery "
        "death, and\nfrumbus with great conviction.\n", User.caughtMessage());

    ExpectEq(103, Target.hitPoints(), "Frank has taken damage");
}

/////////////////////////////////////////////////////////////////////////////
void NotSpecifyingTargetWillTargetOwnerForBeneficialResearch()
{
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemI.c");

    User.hit(130);
    ExpectEq(24, User.hitPoints());

    command("do stuff rarg rarg fargle", User);
    ExpectEq("You ready a turnip and fargle mightily, rarg with conviction, and "
        "rarg with\nconviction.\n", User.caughtMessage());

    ExpectEq(129, User.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CanUseSelfTargetCombinations()
{
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemI.c");
    User.initiateResearch("/lib/tests/support/research/comboSelfResearchItem.c");

    User.hit(130);
    ExpectEq(24, User.hitPoints());

    command("do to self rarg rarg fargle", User);
    ExpectEq("You ready a turnip and fargle mightily, rarg with conviction, and "
        "rarg with\nconviction.\n", User.caughtMessage());

    ExpectEq(129, User.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteAreaCombinations()
{
    object herman = clone_object("/lib/realizations/monster.c");
    herman.Name("Herman");
    herman.addAlias("herman");
    herman.Str(20);
    herman.Int(20);
    herman.Dex(20);
    herman.Con(20);
    herman.Wis(20);
    herman.Chr(20);
    herman.hitPoints(herman.maxHitPoints());
    herman.spellPoints(herman.maxSpellPoints());
    herman.staminaPoints(herman.maxStaminaPoints());
    move_object(herman, Room);

    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");
    User.initiateResearch("/lib/tests/support/research/comboAreaResearchItem.c");

    ExpectEq(150, Target.hitPoints(), "Frank's initial HP");
    ExpectEq(150, herman.hitPoints(), "Frank's initial HP");
    command("do to area blarg frumbus clerb", User);
    ExpectEq(103, Target.hitPoints(), "Frank has taken damage");
    ExpectEq(103, herman.hitPoints(), "Herman has taken damage");

    ExpectEq("You ready a turnip and blarg swimmingly, clerb at Bob with fiery "
        "death, and\nfrumbus with great conviction.\n", User.caughtMessage());

    // Proof that Bob and Frank are now fighting
    ExpectTrue(Target.unregisterAttacker(User));
    ExpectTrue(herman.unregisterAttacker(User));
}

/////////////////////////////////////////////////////////////////////////////
void CostCorrectlyApplied()
{
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    ExpectEq(150, User.hitPoints());
    ExpectEq(150, User.spellPoints());
    ExpectEq(150, User.staminaPoints());
    command("do stuff blarg frumbus clerb at frank", User);

    ExpectEq(140, User.hitPoints());
    ExpectEq(120, User.spellPoints());
    ExpectEq(140, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void ActionBlockedIfCostNotMet()
{
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemA.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemB.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemC.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemD.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemE.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemF.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemG.c");
    User.initiateResearch("/lib/tests/support/research/comboPartResearchItemH.c");

    User.spellPoints(-125);

    ExpectEq(150, User.hitPoints());
    ExpectEq(25, User.spellPoints());
    ExpectEq(150, User.staminaPoints());
    command("do stuff blarg frumbus clerb at frank", User);

    // The empty message is due to the notify_fail / the way execute is handled
    ExpectEq(({ "",
        "You do not have the required energy reserve to use 'combo blarg'.\n" }), 
        User.caughtMessages());

    ExpectEq(150, User.hitPoints());
    ExpectEq(25, User.spellPoints());
    ExpectEq(150, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CanDisplayResearchInfo()
{
    object effect = clone_object("/lib/tests/support/research/comboResearchItem.c");

    ExpectEq("Research Name   : Combo blarg\n"
        "This is combo active research\n"
        "\n"
        "This research item is granted to the user at a pre-defined time.\n"
        "Research Type   : Active\n"
        "Scope           : Targeted\n"
        "Cost to use     : 10 stamina points\n"
        "Usage cooldown  : 1 second\n"
        "Command syntax  : do stuff [.*]\n"
        "Combination Rule : Can include any of:\n"
        "                  hruf: This will hruf stuff.\n"
        "                  muclid: This muclidifies stuff.\n"
        "Combination Rule : Can include only one of:\n"
        "                  surlac: This surily surlacs stuff.\n"
        "                  clerb: Beware the clerb.\n"
        "Combination Rule : Must include any of:\n"
        "                  gurg: This inverse gurgs stuff.\n"
        "                  frumbus: This unfrumbuses stuff.\n"
        "                  fargle: This fargles with the fresh scent of Brute.\n"
        "Combination Rule : Must include only one of:\n"
        "                  blarg: This blargifies stuff.\n"
        "                  rarg: This de-rargulates stuff.\n"
        "Max Combo Size  : 3\n"
        "Combo Damage    : Modified -> +25% if Combo stuff is researched\n",
        effect.researchDetails());
}
