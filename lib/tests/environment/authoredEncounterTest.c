//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Environment;
object Holding;
object Player;
object StrongVisitor;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");
    ToggleCallOutBypass();
    Environment = clone_object("/lib/tests/support/environment/"
        "authored-encounter-environment.c");
    Holding = clone_object("/lib/tests/support/environment/"
        "authored-encounter-environment.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    StrongVisitor = clone_object("/lib/realizations/monster.c");
    StrongVisitor.effectiveLevel(30);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach (object room in ({ Environment, Holding }))
    {
        foreach (object item in all_inventory(room))
        {
            if ((item != Player) && (item != StrongVisitor))
            {
                destruct(item);
            }
        }
    }
    destruct(StrongVisitor);
    destruct(Player);
    destruct(Environment);
    destruct(Holding);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void FixedLevelIgnoresVisitorLevel()
{
    Environment.configure(3, ({ "chipmunk" }));
    Holding.configure(3, ({ "chipmunk" }));
    ExpectEq(30, StrongVisitor.effectiveLevel());
    ExpectTrue(Player.effectiveLevel() < 3);
    Environment.spawnFor(Player);
    Holding.spawnFor(StrongVisitor);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    ExpectEq(1, sizeof(all_inventory(Holding)));
    ExpectEq(3, all_inventory(Environment)[0]->effectiveLevel());
    ExpectEq(3, all_inventory(Holding)[0]->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void EnteringAuthoredRoomSpawnsWithoutGeneratedInheritance()
{
    Environment.configure(2, ({ "chipmunk" }));
    ExpectEq(-1, member(inherit_list(Environment),
        "/lib/environment/generatedEnvironment.c"));
    move_object(Player, Environment);
    ExpectEq(2, sizeof(all_inventory(Environment)));
    foreach (object item in all_inventory(Environment))
    {
        if (item != Player)
        {
            ExpectTrue(item->id("chipmunk"));
            ExpectEq(2, item->effectiveLevel());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void ReenteringDoesNotDuplicateOrImmediatelyReplaceWildlife()
{
    Environment.configure(2, ({ "chipmunk" }));
    move_object(Player, Environment);
    move_object(Player, Holding);
    move_object(Player, Environment);
    ExpectEq(2, sizeof(all_inventory(Environment)));
    foreach (object item in all_inventory(Environment))
    {
        if (item != Player)
        {
            move_object(item, Holding);
        }
    }
    move_object(Player, Holding);
    move_object(Player, Environment);
    ExpectEq(({ Player }), all_inventory(Environment));
}

/////////////////////////////////////////////////////////////////////////////
void NonCombatResidentsUseFixedLevelAndAreNotDuplicated()
{
    Environment.configureResidents(3, ({ "farmer" }));
    Environment.spawnFor(StrongVisitor);
    Environment.spawnFor(Player);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    object resident = all_inventory(Environment)[0];
    ExpectTrue(resident->id("farmer"));
    ExpectEq(3, resident->effectiveLevel());
    ExpectTrue(member(inherit_list(resident),
        "/lib/realizations/npc.c") >= 0);
}

/////////////////////////////////////////////////////////////////////////////
void InvalidFixedLevelRaisesAnExplicitError()
{
    string error = catch(Environment.configure(0, ({ "chipmunk" })); nolog);
    ExpectEq("*Encounter levels must be positive.\n", error);
}

/////////////////////////////////////////////////////////////////////////////
void CreaturePoolsFollowTheirRegisteredState()
{
    Environment.configure(2, ({}));
    Environment.configureState("peaceful", ({ "chipmunk" }));
    Environment.configureState("ravaged", ({ "bat" }));
    Environment.currentState("peaceful");
    Environment.spawnFor(Player);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    ExpectTrue(all_inventory(Environment)[0]->id("chipmunk"));

    Environment.currentState("ravaged");
    Environment.spawnFor(Player);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    ExpectTrue(all_inventory(Environment)[0]->id("bat"));
}

/////////////////////////////////////////////////////////////////////////////
void NonCombatCreaturePoolsFollowTheirRegisteredState()
{
    Environment.configureResidents(3, ({}));
    Environment.configureResidentState("peaceful", ({ "farmer" }));
    Environment.configureResidentState("ravaged", ({ "miller" }));
    Environment.currentState("peaceful");
    Environment.spawnFor(Player);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    ExpectTrue(all_inventory(Environment)[0]->id("farmer"));

    Environment.currentState("ravaged");
    Environment.spawnFor(Player);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    ExpectTrue(all_inventory(Environment)[0]->id("miller"));
}
