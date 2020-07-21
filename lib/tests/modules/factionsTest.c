//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Faction;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Faction = clone_object("/lib/realizations/player");
    Faction->Name("Bob");
    Faction->Gender("male");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Faction);
}

/////////////////////////////////////////////////////////////////////////////
void JoinFactionJoinsUserToFaction()
{
    ExpectFalse(Faction->memberOfFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectTrue(Faction->joinFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectTrue(Faction->memberOfFaction("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void FactionsReturnsEmptyListWhenNotMemberOfAnyFactions()
{
    ExpectEq(({}), Faction->Factions());
}

/////////////////////////////////////////////////////////////////////////////
void FactionsReturnsListOfFactions()
{
    ExpectTrue(Faction->joinFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectTrue(Faction->joinFaction("/lib/tests/support/factions/anotherFaction.c"));
    ExpectEq(({ "/lib/tests/support/factions/testFaction.c", "/lib/tests/support/factions/anotherFaction.c" }), 
        Faction->Factions());
}

/////////////////////////////////////////////////////////////////////////////
void JoinFactionReturnsFalseIfCalledWhenAlreadyJoined()
{
    ExpectTrue(Faction->joinFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectFalse(Faction->joinFaction("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void FactionDispositionIsNeutralWhenEncounteringInvalidFaction()
{
    ExpectEq("invalid", Faction->factionDispositionToward("/lib/badFaction"));
}

/////////////////////////////////////////////////////////////////////////////
void FactionDispositionIsNeutralWhenEncounteringUnknownFaction()
{
    ExpectEq("neutral", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void FactionDispositionIsAllyWhenFactionJoined()
{
    ExpectTrue(Faction->joinFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectEq("ally", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void FactionDispositionIsBetrayedWhenFactionLeft()
{
    ExpectTrue(Faction->joinFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectTrue(Faction->leaveFaction("/lib/tests/support/factions/testFaction.c"));
    ExpectEq("betrayed", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void UpdateFactionDispositionModifiesReputation()
{
    ExpectEq(0, Faction->factionReputationToward("/lib/tests/support/factions/testFaction.c"));
    Faction->updateFactionDisposition("/lib/tests/support/factions/testFaction.c", 10);
    ExpectEq(10, Faction->factionReputationToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void UpdateFactionDispositionDoesNotModifyDispositionWhenThreshholdNotMet()
{
    ExpectEq("neutral", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
    Faction->updateFactionDisposition("/lib/tests/support/factions/testFaction.c", 1);
    ExpectEq("neutral", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void UpdateFactionDispositionBecomesHostileWhenMemberMurdered()
{
    ExpectEq("neutral", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
    Faction->updateFactionDisposition("/lib/tests/support/factions/testFaction.c", 5, 1);
    ExpectEq("hostile", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CombatUpdatesDispositionToHostileForFightingByDefault()
{
    object foe = clone_object("/lib/realizations/monster.c");
    move_object(Faction, this_object());
    move_object(foe, this_object());
    foe->joinFaction("/lib/tests/support/factions/testFaction.c");
    ExpectEq("neutral", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
    foe->hit(1000, "physical", Faction);
    ExpectEq("hostile", Faction->factionDispositionToward("/lib/tests/support/factions/testFaction.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CombatUpdatesReputationForFighting()
{
    object foe = clone_object("/lib/realizations/monster.c");
    move_object(Faction, this_object());
    move_object(foe, this_object());
    foe->joinFaction("/lib/tests/support/factions/testFaction.c");
    ExpectEq(0, Faction->factionReputationToward("/lib/tests/support/factions/testFaction.c"));
    foe->hit(1000, "physical", Faction);
    ExpectEq(-1, Faction->factionReputationToward("/lib/tests/support/factions/testFaction.c"));
}
