//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/region.c";
virtual inherit "/lib/environment/modules/environment/state.c";

private mapping possibleEncounters = ([]);
private mapping currentEncounters = ([]);
private mapping possibleNonCombatEncounters = ([]);
private mapping currentNonCombatEncounters = ([]);
private mapping timeUntilNextEncounter = ([]);
private int isSpawningEncounters = 0;
private int fixedEncounterLevel = 0;

/////////////////////////////////////////////////////////////////////////////
protected nomask void setEncounterLevel(int level)
{
    if (level < 1)
    {
        raise_error("Encounter levels must be positive.\n");
    }
    fixedEncounterLevel = level;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addRandomCreature(string *creatures,
    string state)
{
    if (sizeof(creatures))
    {
        state = (stringp(state) && sizeof(state)) ? state : "default";
        possibleEncounters[state] = creatures + ({});
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addNonCombatCreature(string *creatures,
    string state)
{
    if (sizeof(creatures))
    {
        state = (stringp(state) && sizeof(state)) ? state : "default";
        possibleNonCombatEncounters[state] = creatures + ({});
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void removeInactiveEncounters(mapping activeEncounters,
    string activeState)
{
    foreach (string state, object *encounters in activeEncounters)
    {
        if (state != activeState)
        {
            foreach (object encounter in encounters)
            {
                if (objectp(encounter) &&
                    (environment(encounter) == this_object()))
                {
                    destruct(encounter);
                }
            }
            m_delete(activeEncounters, state);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int encounterBaseLevel(object player)
{
    int level = fixedEncounterLevel;
    if (!level)
    {
        level = (objectp(getRegion()) && getRegion()->regionLevel()) ?
            getRegion()->regionLevel() : player->effectiveLevel();
    }
    return level;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *encountersForState(mapping encounterPools,
    string state)
{
    string *ret = pointerp(encounterPools["default"]) ?
        encounterPools["default"] + ({}) : ({});
    if (state != "default" && pointerp(encounterPools[state]))
    {
        ret += encounterPools[state];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int stateHasEncounterPool(mapping encounterPools,
    string state)
{
    return member(encounterPools, "default") ||
        member(encounterPools, state);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int encounterLevel(object player, int nonCombat)
{
    int level = fixedEncounterLevel;
    if (!level)
    {
        int baseLevel = encounterBaseLevel(player);
        level = (objectp(getRegion()) && getRegion()->regionLevel()) ?
            (baseLevel - 2 + random(5)) :
            (nonCombat ? baseLevel - 3 + random(7) :
                baseLevel - 5 + random(11));
    }
    if (level < 1)
    {
        level = 1;
    }
    return level;
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpNonCombatEncounter(object player)
{
    string state = currentState();
    if (!pointerp(currentNonCombatEncounters[state]))
    {
        currentNonCombatEncounters[state] = ({});
    }
    currentNonCombatEncounters[state] = filter(
        currentNonCombatEncounters[state] || ({}),
        (: objectp($1) && (environment($1) == this_object()) :));

    if (objectp(player) &&
        stateHasEncounterPool(possibleNonCombatEncounters, state) &&
        !sizeof(currentNonCombatEncounters[state]))
    {
        string *possible = encountersForState(possibleNonCombatEncounters,
            state);
        object personaService = getService("persona");
        string name = possible[random(sizeof(possible))];
        int level = encounterLevel(player, 1);
        object npc = clone_object("/lib/realizations/npc.c");
        npc->SetUpPersonaOfLevel(
            personaService->getRandomPersona(name, level), level, 1);
        npc->Gender(random(2) ? "female" : "male");
        npc->addAlias(name);
        if (npc->Race() == "deity")
        {
            npc->apparentRace("human");
        }
        npc->Name(capitalize(name));
        currentNonCombatEncounters[state] += ({ npc });
        move_object(npc, this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpEncounter(object player)
{
    if (!isSpawningEncounters)
    {
        string state = currentState();
        removeInactiveEncounters(currentEncounters, state);
        removeInactiveEncounters(currentNonCombatEncounters, state);
        if (!pointerp(currentEncounters[state]))
        {
            currentEncounters[state] = ({});
        }
        currentEncounters[state] = filter(currentEncounters[state],
            (: objectp($1) && (environment($1) == this_object()) :));
        int nextEncounterTime = member(timeUntilNextEncounter, state) ?
            timeUntilNextEncounter[state] : 0;

        if (objectp(player) &&
            (time() > nextEncounterTime) &&
            stateHasEncounterPool(possibleEncounters, state) &&
            !sizeof(currentEncounters[state]))
        {
            timeUntilNextEncounter[state] = time() + 300;
            object personaService = getService("persona");
            string *possible = encountersForState(possibleEncounters, state);
            string *encounterList = personaService->filterEncountersForLevel(
                possible, encounterBaseLevel(player));
            if (sizeof(encounterList))
            {
                string name = encounterList[random(sizeof(encounterList))];
                int count = 1;
                if (member(({ "outlaw", "ruffian", "undead", "timber wolf",
                    "gray wolf", "red wolf", "coyote", "zombie",
                    "skeleton" }), name) > -1)
                {
                    count = 1 + random(3);
                }
                currentEncounters[state] = ({});
                isSpawningEncounters = 1;
                for (int i = 0; i < count; i++)
                {
                    int level = encounterLevel(player, 0);
                    object encounter =
                        clone_object("/lib/realizations/monster.c");
                    encounter->SetUpPersonaOfLevel(
                        personaService->getRandomPersona(name, level),
                        level, 1);
                    encounter->Gender(random(2) ? "female" : "male");
                    encounter->addAlias(name);
                    if (encounter->Race() == "deity")
                    {
                        encounter->apparentRace("human");
                    }
                    string realName = name;
                    if (encounter->apparentRace() &&
                        (member(({ "outlaw", "ruffian", "skeleton",
                            "zombie" }), name) > -1))
                    {
                        realName = sprintf("%s (%s)", name,
                            capitalize(encounter->apparentRace()));
                    }
                    encounter->Name(realName);
                    encounter->setUpRandomEquipment(5 +
                        (encounter->effectiveLevel() * 3));
                    move_object(encounter, this_object());
                    currentEncounters[state] += ({ encounter });
                }
                isSpawningEncounters = 0;
            }
        }
        setUpNonCombatEncounter(player);
    }
}
