//*****************************************************************************
// Class: quests
// File Name: quests.c
//
// Copyright (c) 2011 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave string BaseQuest = "lib/modules/quests/questItem.c";

private mapping quests = ([
// "path to quest object" : ([
//      "name": "<name>",
//      "state": "<state>",
//      "is active", true/false
//      "is completed", true/false
// ]),
]);

//-----------------------------------------------------------------------------
// Method: questNotification
// Description: This method is used to broadcast all quest-related events
//              as they occur. See events.c for details.
//
// Parameters: event - the event that has occured. 
//-----------------------------------------------------------------------------
private nomask void questNotification(string event, string questItem)
{
    object eventObj = getService("events");
    
    if(event && stringp(event) && eventObj && objectp(eventObj))
    {
        eventObj->notify(event, questItem);
    }
}

private nomask int isValidQuest(string questItem)
{
    return (questItem && stringp(questItem) &&
        member(quests, questItem) && mappingp(quests[questItem]) && 
        member(quests[questItem], "state") && 
        stringp(quests[questItem]["state"]) &&
        member(quests[questItem], "name") && 
        stringp(quests[questItem]["name"]) &&
        member(quests[questItem], "is active") && 
        intp(quests[questItem]["is active"]) &&
        member(quests[questItem], "is completed") && 
        intp(quests[questItem]["is completed"]));
}

private nomask object getQuestObject(string questItem)
{
    // The passed in value for questItem must be a file containing a valid
    // questItem object.
    object ret = 0;
    if(questItem && stringp(questItem) && (file_size(questItem) > 0))
    { 
        ret = load_object(questItem);
        if(!ret || (member(inherit_list(ret), BaseQuest) < 0))
        {
            ret = 0;
        }
    }
    return ret;
}


public nomask int questIsInProgress(string questItem)
{
    return (isValidQuest(questItem) && getQuestObject(questItem) &&
        !quests[questItem]["is completed"]);
}

public nomask int questIsActive(string questItem)
{
    return (isValidQuest(questItem) && getQuestObject(questItem) &&
        quests[questItem]["is active"]);
}

public nomask int questIsCompleted(string questItem)
{
    return (isValidQuest(questItem) && getQuestObject(questItem) &&
        member(quests[questItem], "is completed") && quests[questItem]["is completed"]);
}

public nomask string questState(string questItem)
{
    string ret = 0;

    if(isValidQuest(questItem) && getQuestObject(questItem))
    {
        ret = quests[questItem]["state"];
    }
    return ret;
}

public nomask mapping activeQuests()
{
    return (filter_indices(quests, #'questIsActive) + ([ ]));
}

public nomask mapping completedQuests()
{
    return (filter_indices(quests, #'questIsCompleted) + ([ ]));
}

public nomask mapping questsInProgress()
{
    return (filter_indices(quests, #'questIsInProgress) + ([ ]));
}

public nomask int activateQuest(string questItem)
{
    int ret = 0;

    if(isValidQuest(questItem) && getQuestObject(questItem) && 
        !quests[questItem]["is completed"])
    {
        ret = 1;
        quests[questItem]["is active"] = 1;
        questNotification("onQuestActivated", questItem);
    }
    return ret;
}


public nomask int deactivateQuest(string questItem)
{
    int ret = 0;

    if(isValidQuest(questItem) && getQuestObject(questItem) && 
        !quests[questItem]["is completed"])
    {
        ret = 1;
        quests[questItem]["is active"] = 0;
        questNotification("onQuestDeactivated", questItem);
    }
    return ret;
}

public nomask int advanceQuestState(string questItem, string newState)
{
    int ret = 0;
    if(isValidQuest(questItem))
    {
        object questObj = getQuestObject(questItem);
        if(questObj && objectp(questObj) && 
           questObj->canAdvanceQuestState(this_object(),
           quests[questItem]["state"], newState))
        {
            ret = 1;
            quests[questItem]["state"] = newState;
            quests[questItem]["state description"] = 
                questObj->getStateDescription(newState);

            questObj->triggerNewQuestState(this_object(), newState);
            questNotification("onQuestAdvancedState", questItem);
            if(questObj->questInCompletionState(newState))
            {
                quests[questItem]["is active"] = 0;
                quests[questItem]["is completed"] = 1;
                questNotification("onQuestCompleted", questItem);

                if(questObj->questSucceeded(this_object()))
                {
                    questNotification("onQuestSucceeded", questItem);
                }
                else
                {
                    questNotification("onQuestFailed", questItem);
                }
            }
        }
    }
    return ret;
}

public nomask int beginQuest(string questItem)
{
    int ret = 0;
    object questObj = getQuestObject(questItem);

    if(!member(quests, questItem) && questObj && objectp(questObj) && 
        questObj->canBeginQuest(this_object()))
    {
        ret = 1;
        quests[questItem] = ([
            "name": questObj->name(),
            "state": questObj->initialState(),
            "state description": 
                questObj->getStateDescription(questObj->initialState()),
            "is active": 1,
            "is completed": 0
        ]);

        questObj->triggerNewQuestState(this_object(), quests[questItem]["state"]);
        questNotification("onQuestStarted", questItem);
    }
    return ret;
}


