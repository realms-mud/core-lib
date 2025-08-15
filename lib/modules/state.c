//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/state.h"

/////////////////////////////////////////////////////////////////////////////
public void executeStateChange(object caller, string newState)
{
    // Overload or shadow this method to do custom state change processing
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getKey(object caller)
{
    return sprintf("%s#%s", program_name(caller),
        caller->Name() ? caller->Name() : "any");
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onStateChanged(object caller, string newState)
{
    if (objectp(caller))
    {
        object persistence = getModule("secure/persistence");
        if (objectp(persistence))
        {
            persistence->characterState(caller, newState);
        }
        else
        {
            characterStates[getKey(caller)] = newState;
        }
        executeStateChange(caller, newState);

        object conversations = getModule("conversations");
        if (conversations)
        {
            conversations->updateConversationState(caller, newState);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string stateFor(object caller)
{
    string ret = 0;

    object persistence = getModule("secure/persistence");
    if (objectp(persistence))
    {
        ret = persistence->characterState(caller);
    }
    else
    {
        string key = getKey(caller);
        if (member(characterStates, key))
        {
            ret = characterStates[key];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void resetCaches()
{
    object inventory = getModule("inventory");
    if (inventory)
    {
        inventory->resetInventoryCache();
    }

    object combat = getModule("combat");
    if (combat)
    {
        combat->resetCombatCache();
    }
}
