//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Ally;
object Npc;
object Enemy;
object Room;

void Setup()
{
    Room = clone_object("/lib/tests/support/relationships/room.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("alice");
    Player.Str(20);
    Player.Con(20);
    Player.Race("human");
    Player.toggleKillList();
    Player.addCommands();
    Player.clearAttacks();
    Player.hitPoints(1000);
    Ally = clone_object("/lib/tests/support/services/mockPlayer.c");
    Ally.Name("bob");
    Ally.Str(20);
    Ally.Con(20);
    Ally.Race("human");
    Ally.toggleKillList();
    Ally.clearAttacks();
    Ally.hitPoints(1000);
    Npc = clone_object("/lib/tests/support/relationships/npc.c");
    Npc.Str(20);
    Npc.Con(20);
    Npc.Race("human");
    Npc.clearAttacks();
    Npc.maxHitPoints(1000);
    Npc.hitPoints(1000);
    Enemy = clone_object("/lib/realizations/monster.c");
    Enemy.Name("orc");
    Enemy.Str(20);
    Enemy.Con(20);
    Enemy.Race("orc");
    Enemy.clearAttacks();
    Enemy.maxHitPoints(1000);
    Enemy.hitPoints(1000);
    move_object(Player, Room);
    move_object(Ally, Room);
    move_object(Npc, Room);
    move_object(Enemy, Room);
}

void CleanUp()
{
    destruct(Enemy);
    destruct(Npc);
    destruct(Ally);
    destruct(Player);
    destruct(Room);
}

void ProtectCommandDivertsActualCombatAndRecordsARescueOnce()
{
    Ally.hit(Ally.hitPoints() - 1, "magical");
    Ally.registerAttacker(Enemy);
    Enemy.registerAttacker(Ally);
    ExpectTrue(Player.executeCommand("protect bob"));
    ExpectTrue(Player.isInCombatWith(Enemy));
    ExpectTrue(Enemy.isInCombatWith(Player));
    ExpectFalse(Ally.isInCombatWith(Enemy));
    ExpectEq(10, Ally.relationshipValue(Player, "trust"));
    ExpectEq(20, Ally.relationshipValue(Player, "gratitude"));
    ExpectEq(1, Player.countObservations(([ "type":"combat.rescue" ])));
    ExpectFalse(Player.executeCommand("protect bob"));
    ExpectEq(1, Player.countObservations(([ "type":"combat.rescue" ])));
}

void DefaultNpcAiProtectsKnownAlliesButDoesNotHelpStrangers()
{
    Player.registerAttacker(Enemy);
    Enemy.registerAttacker(Player);
    Npc.heart_beat();
    ExpectFalse(Npc.isInCombatWith(Enemy));
    Npc.updateRelationshipToward(Player, ([ "trust":40, "respect":30 ]));
    Npc.heart_beat();
    ExpectTrue(Npc.isInCombatWith(Enemy));
    ExpectFalse(Player.isInCombatWith(Enemy));
    ExpectEq(5, Player.relationshipValue(Npc, "trust"));
    ExpectEq(1, Npc.countObservations(([ "type":"combat.protected" ])));
}

void AttackingATrustedNpcIsOneBetrayalNotOnePerRound()
{
    Npc.updateRelationshipToward(Player,
        ([ "trust":60, "respect":50, "affection":40 ]));
    ExpectFalse(Npc.attack(Player));
    ExpectTrue(Player.attack(Npc));
    ExpectEq(30, Npc.relationshipValue(Player, "trust"));
    ExpectEq(35, Npc.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([ "type":"combat.betrayal" ])));
    Player.attack(Npc);
    ExpectEq(30, Npc.relationshipValue(Player, "trust"));
    ExpectEq(1, Player.countObservations(([ "type":"combat.betrayal" ])));
}

void FearRetreatReportsActualMovementNotAVoidReturnValue()
{
    Npc.modifyRelationship(Player, "fear", 75);
    Npc.registerAttacker(Player);
    Player.registerAttacker(Npc);
    ExpectFalse(Npc.aiCombatAction(Player));
    ExpectEq(Room, environment(Npc));
    Room.testAddExit("north", "/lib/tests/support/environment/fakeEnvironment.c");
    move_object(Npc, load_object(
        "/lib/tests/support/environment/fakeEnvironment.c"));
    move_object(Npc, Room);
    ExpectTrue(Npc.aiCombatAction(Player));
    ExpectFalse(environment(Npc) == Room);
    ExpectFalse(Npc.inCombat());
    ExpectFalse(Player.isInCombatWith(Npc));
    ExpectEq(1, Npc.countObservations(([ "type":"combat.fled" ])));
}

void PeacefulRoomsBlockAssistanceWithoutRelationshipEffects()
{
    Ally.registerAttacker(Enemy);
    Enemy.registerAttacker(Ally);
    Npc.updateRelationshipToward(Ally, ([ "trust":40, "respect":30 ]));
    Room.testSetPeaceful(1);
    ExpectFalse(Player.protectAlly(Ally, Enemy));
    Npc.heart_beat();
    ExpectFalse(Npc.inCombat());
    ExpectEq(0, Ally.relationshipValue(Player, "trust"));
    ExpectEq(0, Ally.relationshipValue(Npc, "trust"));
    ExpectEq(0, Player.countObservations(([ "type":"combat.protected" ])));
}

void LowHealthWithAnotherOpponentIsProtectionNotRescue()
{
    Ally.hit(Ally.hitPoints() - 1, "magical");
    Ally.registerAttacker(Enemy);
    Enemy.registerAttacker(Ally);
    Ally.registerAttacker(Npc);
    Npc.registerAttacker(Ally);
    ExpectTrue(Player.protectAlly(Ally, Enemy));
    ExpectTrue(Ally.isInCombatWith(Npc));
    ExpectEq(1, Player.countObservations(([ "type":"combat.protected" ])));
    ExpectEq(0, Player.countObservations(([ "type":"combat.rescue" ])));
}

void AlliedNpcCanRetaliateWithoutRecordingReverseBetrayal()
{
    Npc.updateRelationshipToward(Player,
        ([ "trust":60, "respect":50, "affection":40 ]));
    Player.registerAttacker(Npc);
    Npc.registerAttacker(Player);
    ExpectTrue(Npc.aiMayAttack(Player));
    ExpectTrue(Npc.attack(Player));
    ExpectEq(60, Npc.relationshipValue(Player, "trust"));
    ExpectEq(0, Npc.countObservations(([ "type":"combat.betrayal" ])));
}
