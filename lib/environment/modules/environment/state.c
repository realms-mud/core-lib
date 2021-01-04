//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";

protected object StateMachineDictionary =
    load_object("/lib/dictionaries/stateMachineDictionary.c");

private string State = "default";
protected nosave object StateMachine = 0;
protected nosave string StateMachinePath = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string currentState(string newState)
{
    if (newState && stringp(newState))
    {
        State = newState;
    }
    return State;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void pruneStateObjects()
{
    if (member(environmentalElements["objects"], currentState()) &&
        sizeof(environmentalElements["objects"][currentState()]))
    {
        foreach(string stateObjectBlueprint in 
            environmentalElements["objects"][currentState()])
        {
            object stateObject = present_clone(stateObjectBlueprint);
            if (stateObject)
            {
                if (StateMachine)
                {
                    StateMachine->unregisterStateActor(stateObject);
                }

                object *stateObjectItems = deep_inventory(stateObject);
                if (sizeof(stateObjectItems))
                {
                    foreach(object item in stateObjectItems)
                    {
                        destruct(item);
                    }
                }
                destruct(stateObject);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void createStateObjects()
{
    string *stateObjects = ({});
    if (member(environmentalElements["objects"], currentState()) && 
        sizeof(environmentalElements["objects"][currentState()]))
    {
        stateObjects += environmentalElements["objects"][currentState()];
    }
    if (member(environmentalElements["objects"], "default") && 
        sizeof(environmentalElements["objects"]["default"]))
    {
        stateObjects += environmentalElements["objects"]["default"];
    }

    if (sizeof(stateObjects))
    {
        stateObjects = filter(m_indices(mkmapping(stateObjects)),
            (: return !present_clone($1); :));
        foreach(string stateObjectBlueprint in stateObjects)
        {
            object stateObject = clone_object(stateObjectBlueprint);
            if (StateMachine)
            {
                StateMachine->registerStateActor(stateObject);
            }
            move_object(stateObject, this_object());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onStateChanged(object caller, string newState)
{
    if (caller == StateMachine)
    {
        pruneStateObjects();
        currentState(newState);
        init();
        createStateObjects();
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string stateMachinePath()
{
    return StateMachinePath;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object stateMachine()
{
    return StateMachine;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setupStateMachine(string owner)
{
    object newSM = StateMachineDictionary->getStateMachine(
        StateMachinePath, owner);

    if (objectp(newSM) && (newSM != StateMachine))
    {
        if (StateMachine)
        {
            StateMachine->unregisterStateActor(this_object());
        }
        StateMachine = newSM;
        StateMachine->registerStateActor(this_object());
        pruneStateObjects();
        currentState(StateMachine->getCurrentState());
        createStateObjects();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setStateMachine(string machinePath,
    int useSingleStateMachine)
{
    StateMachinePath = machinePath;

    if (useSingleStateMachine)
    {
        setupStateMachine();
    }
}
