//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;
object Room;
object AttackerEvents;
object TargetEvents;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->Str(10);
    Player->Dex(10);
    Player->Con(10);
    Player->Int(10);
    Player->Wis(10);
    Player->hitPoints(Player->maxHitPoints());

    Target = clone_object("/lib/realizations/monster.c");
    Target->Name("fred");
    Target->Con(10);
    Target->hitPoints(Target->maxHitPoints());

    move_object(Player, Room);
    move_object(Target, Room);

    AttackerEvents = clone_object("/lib/tests/support/events/killEventSubscriber.c");
    Player->registerEvent(AttackerEvents);

    TargetEvents = clone_object("/lib/tests/support/events/killEventSubscriber.c");
    Target->registerEvent(TargetEvents);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(AttackerEvents);
    destruct(TargetEvents);
    destruct(Player);
    destruct(Target);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("killl"), "killl");
    ExpectFalse(Player->executeCommand("akill"), "akill");
}

/////////////////////////////////////////////////////////////////////////////
void KillInitiatesCombat()
{
    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());

    ExpectTrue(Player->executeCommand("kill fred"));

    ExpectTrue(AttackerEvents->wasAttacker());
    ExpectTrue(TargetEvents->wasAttacked());
    ExpectTrue(Player->isInCombatWith(Target));
    ExpectTrue(Target->isInCombatWith(Player));
}

/////////////////////////////////////////////////////////////////////////////
void KillFailsForInvalidTarget()
{
    ExpectFalse(Player->executeCommand("kill henry"));
    ExpectTrue(Player->executeCommand("kill fred"));
}

/////////////////////////////////////////////////////////////////////////////
void KillDoesNotInitiateCombatIfNeitherPlayerNorFoeOnKillList()
{
    destruct(Target);
    Target = clone_object("/lib/realizations/player.c");
    Target->Name("fred");
    Target->registerEvent(TargetEvents);
    move_object(Target, Room);

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());

    ExpectFalse(Player->executeCommand("kill fred"));

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());
    ExpectFalse(Player->isInCombatWith(Target));
    ExpectFalse(Target->isInCombatWith(Player));
}

/////////////////////////////////////////////////////////////////////////////
void KillDoesNotInitiateCombatIfPlayerButNotFoeOnKillList()
{
    destruct(Target);
    Target = clone_object("/lib/realizations/player.c");
    Target->Name("fred");
    Target->registerEvent(TargetEvents);
    move_object(Target, Room);

    Player->toggleKillList();

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());

    ExpectFalse(Player->executeCommand("kill fred"));

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());
    ExpectFalse(Player->isInCombatWith(Target));
    ExpectFalse(Target->isInCombatWith(Player));
}

/////////////////////////////////////////////////////////////////////////////
void KillDoesNotInitiateCombatIfFoeButNotPlayerOnKillList()
{
    destruct(Target);
    Target = clone_object("/lib/realizations/player.c");
    Target->Name("fred");
    Target->registerEvent(TargetEvents);
    move_object(Target, Room);

    Target->toggleKillList();

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());

    ExpectFalse(Player->executeCommand("kill fred"));

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());
    ExpectFalse(Player->isInCombatWith(Target));
    ExpectFalse(Target->isInCombatWith(Player));
}

/////////////////////////////////////////////////////////////////////////////
void KillInitiatesCombatIfFoeAndPlayerOnKillList()
{
    destruct(Target);
    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("fred");
    Target->Con(20);
    Target->hitPoints(Target->maxHitPoints());
    Target->registerEvent(TargetEvents);
    move_object(Target, Room);

    Target->toggleKillList();
    Player->toggleKillList();

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());

    ExpectTrue(Player->executeCommand("kill fred"));

    ExpectTrue(AttackerEvents->wasAttacker(), "was attacker event fired");
    ExpectTrue(TargetEvents->wasAttacked(), "was attacked event fired");

    ExpectTrue(Player->isInCombatWith(Target), "player isInCombatWith target");
    ExpectTrue(Target->isInCombatWith(Player), "target isInCombatWith player");
}

/////////////////////////////////////////////////////////////////////////////
void KillDoesNotInitiateCombatIfTargetNotInEnvironmentWithPlayer()
{
    destruct(Target);
    Target = clone_object("/lib/realizations/player.c");
    Target->Name("fred");
    Target->registerEvent(TargetEvents);

    Target->toggleKillList();
    Player->toggleKillList();

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());

    ExpectFalse(Player->executeCommand("kill fred"));

    ExpectFalse(AttackerEvents->wasAttacker());
    ExpectFalse(TargetEvents->wasAttacked());
    ExpectFalse(Player->isInCombatWith(Target));
    ExpectFalse(Target->isInCombatWith(Player));
}

/////////////////////////////////////////////////////////////////////////////
void KillDoesNotAllowCallsInRapidSuccession()
{
    ExpectTrue(Player->executeCommand("kill fred"));
    ExpectTrue(Player->isInCombatWith(Target));
    ExpectTrue(Target->isInCombatWith(Player));

    ExpectFalse(Player->executeCommand("kill fred"));
    ExpectFalse(Player->executeCommand("kill fred"));
    ExpectFalse(Player->executeCommand("kill fred"));
    ExpectTrue(Player->isInCombatWith(Target));
    ExpectTrue(Target->isInCombatWith(Player));
}
