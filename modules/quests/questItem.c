//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";

private nosave string Cyan = "[0;36m%s[0m";
private nosave string Red = "[0;31m%s[0m";
private nosave string Green = "[0;32m%s[0m";
private string BaseQuest = "lib/modules/quests/questItem.c";

private string Name = "";
private string InitialState = "";
private object *questActors = ({});
private object *Questers = ({});
private string CurrentState = 0;

private mapping questPathTree = ([
    // "<state>" : ([
    //     "description": <some text>
    //     "is final state": if it exists, it can be either "success" or
    //                       "failure"
    //     "registered quest items": ({ }) - array of objects to register
    //                                in the player event handler. Final states
    //                                should not have objects listening to events
    //     "transitions": ([
    //         "<event>": "<new state>"
    //     ])
    // ])
    //
    // Example:
    // "meet the king": ([
    //     "description": "I've been asked to meet the king!",
    //     "possible next states": ({ "met the king", "king is dead" }),
    //     "registered quest items": ({ kingObject, chamberlainObject, 
    //         assassinObject })
    // ]),
    // "met the king": ([
    //     "description": "I met King Tantor the Unclean of Thisplace. He seems to "
    //         "like me.",
    //     "possible next states": ({ "serve the king", "ignore the king", 
    //         "king is dead" }),
    //     "registered quest items": ({ kingObject, chamberlainObject, 
    //         assassinObject })
    // ]),
    // "serve the king": ([
    //     "description": "The king asked me - ME - to be his personal manservant."
    //         " Yay me!",
    //     "possible next states": ({ "save the king", "king is dead" }),
    //     "registered quest items": ({ kingObject, chamberlainObject, 
    //         assassinObject })
    // ]),
    // "ignore the king": ([
    //     "description": "I told the king to piss off. I have socks to fold."
    //     "is final state": "failure",
    // ]),
    // "save the king": ([
    //     "description": "Earl the Grey tried to kill the king but I gutted him "
    //         "like a fish.",
    //     "is final state": "success",
    // ]),
    // "king is dead": ([
    //     "descrptions": "I must lay off the sauce - and the wenches. King Tantor"
    //         " is dead because of my night of debauchery.",
    //     "is final state": "failure",
]);

/////////////////////////////////////////////////////////////////////////////
private nomask void onEnter(string state)
{
    if (member(questPathTree[state], "entry action"))
    {
        call_other(this_object(), questPathTree[state]["entry action"]);
    }
    if (member(questPathTree[state], "event"))
    {
        filter_objects(questActors, "notify", questPathTree[state]["event"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void onExit(string state)
{
    if (member(questPathTree[state], "exit action"))
    {
        call_other(this_object(), questPathTree[state]["exit action"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int receiveEvent(object initiator, string eventName)
{
    int ret = 0;
    if (initiator && objectp(initiator) && eventName && stringp(eventName) &&
        member(questPathTree, CurrentState) && 
        member(questPathTree[CurrentState], "transitions") &&
        member(questPathTree[CurrentState]["transitions"], eventName))
    {
        mapping transition = questPathTree[CurrentState]["transitions"][eventName];
        ret = member(transition, initiator) ?
            (transition["initiator"] == program_name(initiator)) : 1;

        if(ret)
        {
            onExit(CurrentState);
            CurrentState = transition["transition"];
            onEnter(CurrentState);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidQuest()
{
    // TODO: Does anything really need to be done here?
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string initialState(string state)
{
    if(state && stringp(state) && (state != ""))
    {
        if(!member(questPathTree, state))
        {
            raise_error("ERROR - questItem: the initial state must have been added first.");
        }
        InitialState = state;
    }
    return InitialState;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addAction(string state, string action, string type)
{
    if (state && stringp(state) && action && stringp(action) &&
        member(questPathTree, state) && function_exists(action))
    {
        questPathTree[state][type] = action;
    }
    else
    {
        raise_error(sprintf("ERROR - questItem: an %s can only be added "
            "if the both the state exists and the method to call has "
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
    if (result && state && stringp(state) && member(questPathTree, state))
    {
        if (stringp(result) &&
            (member(({ "success", "failure" }), result) > -1))
        {
            questPathTree[state]["is final state"] = result;
        }
        else
        {
            raise_error("ERROR - questItem: the final state result must be 'success' or 'failure'.");
        }
    }
    else
    {
        raise_error("ERROR - questItem: the quest state must exist for it to be set as a final state.");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addState(string state, string description, string entryEvent, string isFinalState)
{
    if(state && stringp(state) && description && stringp(description) &&
        !member(questPathTree, state))
    {
        questPathTree[state] = ([ "description": description ]);
        if (entryEvent)
        {
            if (stringp(entryEvent))
            {
                questPathTree[state]["event"] = entryEvent;
            }
            else
            {
                raise_error("ERROR - questItem: the entry event must be a string.");
            }
        }
    }
    else if(member(questPathTree, state))
    {
        raise_error(sprintf("ERROR - questItem: the %s state has already been added.", state));   
    }
    else
    {
        raise_error("ERROR - questItem: the quest state could not be added.");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void registerQuestActor(object actor)
{
    if(actor && objectp(actor))
    {
        questActors += ({ actor });
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addTransition(string state, string newState, string eventName, string initiator)
{
    if (state && stringp(state) && eventName && stringp(eventName) &&
        newState && stringp(newState) && member(questPathTree, state) &&
        member(questPathTree, newState))
    {
        if(!member(questPathTree[state], "transitions"))
        {
            questPathTree[state]["transitions"] = ([]);
        }

        if(!member(questPathTree[state]["transitions"], eventName))
        {
            questPathTree[state]["transitions"][eventName] = ([
                "transition": newState
            ]);
        }
        else
        {
            raise_error("ERROR - questItem: a transition for that event already exists.");
        }

        if(initiator && stringp(initiator))
        {
            if(load_object(initiator))
            {
                questPathTree[state]["transitions"][eventName]["initiator"] = initiator;
            }
            else
            {
                raise_error("ERROR - questItem: the transition initiator must be a valid program name.");
            }
        }
    }
    else
    {
        raise_error("ERROR - questItem: the quest transition could not be added.");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string questStory(string *stateList)
{
    // WARNING: This array MUST be passed in the order in which the states
    // were completed or the story will be nonsensical!
    string ret = "The quest has just begun.";
    if(sizeof(stateList))
    {
        ret = sprintf(Cyan, implode(map_array(stateList, 
            (: (member(questPathTree, $1) ? questPathTree[$1]["description"] : "") :))," "));

        if(member(questPathTree[stateList[sizeof(stateList) - 1]], "is final state"))
        {
            string result = questPathTree[stateList[sizeof(stateList) - 1]]["is final state"];
            string colorFormat = (result == "success") ? Green : Red;
            ret += sprintf(colorFormat, " [" + capitalize(result) + "]");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canBeginQuest(object questor)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int triggerNewQuestState(object questor, string newState)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questInCompletionState(string state)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questSucceeded(object questor)
{
    return CurrentState && stringp(CurrentState) && 
        member(questPathTree[CurrentState], "is final state") &&
        (questPathTree[CurrentState]["is final state"] == "success");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAdvanceQuestState(object questor, string oldState, string newState)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getStateDescription(string state)
{
    return "";
}


