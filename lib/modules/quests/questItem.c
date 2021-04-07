//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/core/stateMachine.c";

private string BaseQuest = "lib/modules/quests/questItem.c";

private string Name = 0;
private string Description = 0;
private string Type = "secondary";

private object configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");

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

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        Name = 0;
        Description = "";
        "stateMachine"::reset(arg);
    }
}

/////////////////////////////////////////////////////////////////////////////
public varargs string getCurrentState(object caller)
{
    return (caller && function_exists("questState", caller)) ? 
        caller->questState(program_name(this_object())) :
        "stateMachine"::getCurrentState(caller);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidQuest()
{
    return Name && (InitialState != "");
}

/////////////////////////////////////////////////////////////////////////////
protected void advanceState(object caller, string newState)
{
    "stateMachine"::advanceState(caller, newState);
    caller->advanceQuestState(program_name(this_object()), newState);

    if (isValidQuest() && member(stateTree[newState], "is final state"))
    {
        string colorConfig = (objectp(caller) && caller->colorConfiguration()) ?
            caller->colorConfiguration() : "none";

        string questFinish = stateTree[newState]["is final state"];
        string message = configuration->decorate(
            sprintf("[ Quest %s ]: %s.\n", questFinish, Name),
            questFinish, "quests", colorConfig);

        tell_object(caller, message);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setName(string name)
{
    if(name && stringp(name))
    {
        Name = name;
    }
    else
    {
        raise_error("ERROR - questItem: the name must be a string.");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string description()
{
    return Description;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setDescription(string description)
{
    if (description && stringp(description))
    {
        Description = description;
    }
    else
    {
        raise_error("ERROR - questItem: the description must be a string.");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string type()
{
    return Type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    object dictionary = load_object("/lib/dictionaries/questsDictionary.c");
    if (type && stringp(type) && (member(dictionary->questTypes(), type) > -1))
    {
        Type = type;
    }
    else
    {
        raise_error("ERROR - questItem: the type must be listed in questTypes.");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string questStory(string *stateList, object user)
{
    string colorConfiguration = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";

    // WARNING: This array MUST be passed in the order in which the states
    // were completed or the story will be nonsensical!
    string ret = "The quest has just begun.";
    if(sizeof(stateList))
    {
        string story = implode(map(stateList,
            (: (member(stateTree, $1) ? stateTree[$1]["description"] : "") :))," ");

        ret = configuration->decorate(story, "description", "quests", 
            colorConfiguration);

        if(member(stateTree[stateList[sizeof(stateList) - 1]], "is final state"))
        {
            string result = stateTree[stateList[sizeof(stateList) - 1]]["is final state"];
            ret += configuration->decorate(" [" + capitalize(result) + "]", 
                result, "quests", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canBeginQuest(object quester)
{
    return checkPrerequisites(quester);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int beginQuest(object quester)
{
    int ret = member(stateTree, InitialState) && canBeginQuest(quester);
    if(ret)
    {
        startStateMachine();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questInCompletionState(string state)
{
    return state && member(stateTree, state) && 
        member(stateTree[state], "is final state");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questSucceeded(object quester)
{
    int ret = quester && objectp(quester);
    if(ret)
    {
        string currentState = quester->questState(program_name(this_object()));

        ret = currentState && stringp(currentState) &&
            member(stateTree[currentState], "is final state") &&
            (stateTree[currentState]["is final state"] == "success");
    }
    return ret;
}
