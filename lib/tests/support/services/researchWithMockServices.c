//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
virtual inherit "/lib/core/events.c";
virtual inherit "/lib/modules/materialAttributes.c";
virtual inherit "/lib/modules/inventory.c";
virtual inherit "/lib/modules/combat.c";
virtual inherit "/lib/modules/attributes.c";
virtual inherit "/lib/modules/skills.c";
virtual inherit "/lib/modules/races.c";
virtual inherit "/lib/modules/movement.c";
virtual inherit "/lib/modules/research.c";
virtual inherit "/lib/modules/biological.c";
virtual inherit "/lib/modules/state.c";
virtual inherit "/lib/modules/settings.c";

virtual inherit "/lib/tests/support/services/mockBackgroundModule.c";
virtual inherit "/lib/tests/support/services/mockGuildsModule.c";
virtual inherit "/lib/tests/support/services/mockTraitsModule.c";
virtual inherit "/lib/tests/support/services/mockQuestModule.c";
virtual inherit "/lib/tests/support/services/mockFactionModule.c";

/////////////////////////////////////////////////////////////////////////////
public int has(string service)
{
    if (member(({ "guilds", "traits", "biological", "background", "quests", "factions" }), service) > -1)
    {
        return 1;
    }
    else
    {
        return thing::has(service);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    enable_commands();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOf(string type)
{
    return type == "player" || type == "living";
}

/////////////////////////////////////////////////////////////////////////////
public void heart_beat()
{
    call_other(this_object(), "combatHeartBeat");
    call_other(this_object(), "healingHeartBeat");
    call_other(this_object(), "researchHeartBeat");
}
