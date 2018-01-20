//*****************************************************************************
// Class: living
// File Name: living.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/realization.c";
virtual inherit "/lib/core/events.c";
virtual inherit "/lib/modules/materialAttributes.c";
virtual inherit "/lib/modules/inventory.c";
virtual inherit "/lib/modules/combat.c";
virtual inherit "/lib/modules/attributes.c";
virtual inherit "/lib/modules/biological.c";
virtual inherit "/lib/modules/factions.c";
virtual inherit "/lib/modules/skills.c";
virtual inherit "/lib/modules/races.c";
virtual inherit "/lib/modules/movement.c";
virtual inherit "/lib/modules/traits.c";
virtual inherit "/lib/modules/state.c";

private nosave string *heartBeatMethods = ({});

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfLiving()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
static nomask int registerHeartBeat(string method)
{
    int ret = 0;
    if (method && stringp(method))
    {
        string hbMethod = sprintf("%sHeartBeat", method);
        if (function_exists(hbMethod, this_object()))
        {
            heartBeatMethods += ({ hbMethod });
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (arg)
    {
        return;
    }
    enable_commands();

    registerHeartBeat("combat");
    registerHeartBeat("healing");
    registerHeartBeat("materialAttributes");
    registerHeartBeat("research");
    registerHeartBeat("traits");
    registerHeartBeat("biological");
}

/////////////////////////////////////////////////////////////////////////////
public void heart_beat()
{
    foreach(string method in heartBeatMethods)
    {
        call_other(this_object(), method);
    }
}
