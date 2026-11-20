//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
}

/////////////////////////////////////////////////////////////////////////////
public void configure(int level, string *creatures)
{
    setEncounterLevel(level);
    addRandomCreature(creatures);
}

/////////////////////////////////////////////////////////////////////////////
public void configureResidents(int level, string *creatures)
{
    setEncounterLevel(level);
    addNonCombatCreature(creatures);
}

/////////////////////////////////////////////////////////////////////////////
public void configureState(string state, string *creatures)
{
    addRandomCreature(creatures, state);
}

/////////////////////////////////////////////////////////////////////////////
public void configureResidentState(string state, string *creatures)
{
    addNonCombatCreature(creatures, state);
}

/////////////////////////////////////////////////////////////////////////////
public void spawnFor(object visitor)
{
    setUpEncounter(visitor);
}
