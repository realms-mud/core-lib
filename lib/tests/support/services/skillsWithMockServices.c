//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/realization.c";
virtual inherit "/lib/core/events.c";
virtual inherit "/lib/modules/materialAttributes.c";
virtual inherit "/lib/modules/inventory.c";
virtual inherit "/lib/modules/combat.c";
virtual inherit "/lib/modules/attributes.c";
virtual inherit "/lib/modules/factions.c";
virtual inherit "/lib/modules/skills.c";
virtual inherit "/lib/modules/races.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/movement.c";

virtual inherit "/lib/tests/support/services/mockBackgroundModule.c";
virtual inherit "/lib/tests/support/services/mockBiologicalModule.c";
virtual inherit "/lib/tests/support/services/mockTraitsModule.c";
virtual inherit "/lib/tests/support/services/mockResearchModule.c";

/////////////////////////////////////////////////////////////////////////////
public int has(string service)
{
    if (member(({ "guilds", "research", "traits", "biological", "background" }), service) > -1)
    {
        return 1;
    }
    else
    {
        return "thing"::has(service);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (arg)
    {
        return;
    }
    enable_commands();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfPlayer()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfLiving()
{
    return 1;
}
