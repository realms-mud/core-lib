//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/state.h"

public nomask string stateFor(object caller);

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
        string previousState = stateFor(caller);
        object persistence = getModule("secure/persistence");
        if (objectp(persistence))
        {
            persistence->characterState(caller, newState);
        }
        else
        {
            characterStates[getKey(caller)] = newState;
        }
        if ((previousState != newState) &&
            (stateFor(caller) == newState) &&
            function_exists("recordObservation", this_object()))
        {
            this_object()->recordObservation(([
                "type": "state.changed",
                "subject": getKey(caller),
                "context": ([
                    "previous state": previousState,
                    "state": newState
                ])
            ]));
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
