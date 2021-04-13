//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/events.c";

protected string InitialState = "";
protected string CurrentState = "default";
protected object *stateActors = ({});
protected mapping stateTree = ([]);

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    InitialState = "";
    CurrentState = "default";
    stateActors = ({});
    stateTree = ([]);
    Setup();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void onEnter(string state, object initiator)
{
    if (member(stateTree[state], "entry action"))
    {
        call_other(this_object(), stateTree[state]["entry action"], initiator);
    }
    if (member(stateTree[state], "event"))
    {
        filter_objects(stateActors, "notify", stateTree[state]["event"], initiator);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void onExit(string state, object initiator)
{
    if (member(stateTree[state], "exit action"))
    {
        call_other(this_object(), stateTree[state]["exit action"], initiator);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void startStateMachine()
{
    if (sizeof(stateTree))
    {
        string *states = m_indices(stateTree);
        foreach(string state in states)
        {
            if (member(stateTree[state], "event"))
            {
                filter_objects(stateActors, "registerEventHandler", 
                    stateTree[state]["event"]);
            }
        }
    }
    CurrentState = InitialState;
    onEnter(InitialState);
    notify("onStateChanged", InitialState);
}

/////////////////////////////////////////////////////////////////////////////
public varargs string getCurrentState(object caller)
{
    return CurrentState;
}

/////////////////////////////////////////////////////////////////////////////
protected void advanceState(object caller, string newState)
{
    CurrentState = newState;
    notify("onStateChanged", newState);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int receiveEvent(object caller, string eventName, object initiator)
{
    int ret = 0;

    if (caller && objectp(caller) && eventName && stringp(eventName))
    {
        string currentState = getCurrentState(caller);

        if (currentState && member(stateTree, currentState) &&
            member(stateTree[currentState], "transitions") &&
            member(stateTree[currentState]["transitions"], eventName))
        {
            mapping transition = stateTree[currentState]["transitions"][eventName];
            ret = initiator && objectp(initiator) && member(transition, initiator) ?
                (transition["initiator"] == program_name(initiator)) : 1;

            if (ret)
            {
                onExit(currentState, caller);
                currentState = transition["transition"];
                notify("onStateChanged", currentState);
                advanceState(caller, currentState);
                onEnter(currentState, caller);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string setInitialState(string state)
{
    if (state && stringp(state) && (state != ""))
    {
        if (!member(stateTree, state))
        {
            raise_error("ERROR - stateMachine: the initial state must have been added first.");
        }
        InitialState = state;
    }
    return InitialState;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string initialState()
{
    return InitialState;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addAction(string state, string action, string type)
{
    if (state && stringp(state) && action && stringp(action) &&
        member(stateTree, state) && function_exists(action))
    {
        stateTree[state][type] = action;
    }
    else
    {
        raise_error(sprintf("ERROR - stateMachine: an %s can only be added "
            "if both the state exists and the method to call has "
            "been implemented on this object.", type));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addEntryAction(string state, string action)
{
    addAction(state, action, "entry action");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addExitAction(string state, string action)
{
    addAction(state, action, "exit action");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addFinalState(string state, string result)
{
    if (result && state && stringp(state) && member(stateTree, state))
    {
        if (stringp(result) &&
            (member(({ "success", "failure" }), result) > -1))
        {
            stateTree[state]["is final state"] = result;
        }
        else
        {
            raise_error("ERROR - stateMachine: the final state result must be 'success' or 'failure'.");
        }
    }
    else
    {
        raise_error("ERROR - stateMachine: the state must exist for it to be set as a final state.");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addState(string state, string description, string entryEvent, string isFinalState)
{
    if (state && stringp(state) && description && stringp(description) &&
        !member(stateTree, state))
    {
        stateTree[state] = (["description":description]);
        if (entryEvent)
        {
            if (stringp(entryEvent))
            {
                stateTree[state]["event"] = entryEvent;
            }
            else
            {
                raise_error("ERROR - stateMachine: the entry event must be a string.");
            }
        }
        if (isFinalState)
        {
            addFinalState(state, isFinalState);
        }
    }
    else if (member(stateTree, state))
    {
        raise_error(sprintf("ERROR - stateMachine: the '%s' state has already been added.", state));
    }
    else
    {
        raise_error("ERROR - stateMachine: the state could not be added.");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void registerStateActor(object actor)
{
    if (actor && objectp(actor))
    {
        registerEvent(actor);
        stateActors += ({ actor });
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void unregisterStateActor(object actor)
{
    if (actor && objectp(actor))
    {
        unregisterEvent(actor);
        stateActors -= ({ actor });
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addTransition(string state, string newState, string eventName, string initiator)
{
    if (state && stringp(state) && eventName && stringp(eventName) &&
        newState && stringp(newState) && member(stateTree, state) &&
        member(stateTree, newState))
    {
        if (!member(stateTree[state], "transitions"))
        {
            stateTree[state]["transitions"] = ([]);
        }

        registerEventHandler(eventName);

        // This is a way around guards - send a different event to transition
        // to a different state.
        if (!member(stateTree[state]["transitions"], eventName))
        {
            stateTree[state]["transitions"][eventName] = ([
                "transition":newState
            ]);
        }
        else
        {
            raise_error("ERROR - stateMachine: a transition for that event already exists.");
        }

        if (initiator && stringp(initiator))
        {
            if ((file_size(initiator) > -1) && !catch (load_object(initiator)))
            {
                stateTree[state]["transitions"][eventName]["initiator"] = initiator;
            }
            else
            {
                raise_error("ERROR - stateMachine: the transition initiator must be a valid program name.");
            }
        }
    }
    else
    {
        raise_error("ERROR - stateMachine: the transition could not be added.");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getStateDescription(string state)
{
    return member(stateTree, state) ? stateTree[state]["description"] : 0;
}
