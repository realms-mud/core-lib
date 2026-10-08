//*****************************************************************************
// Class: quests
// File Name: quests.c
//
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/quests.h"

private object questsService = getService("quests");

/////////////////////////////////////////////////////////////////////////////
private void recordQuestObservation(string type, string questItem,
    mapping context)
{
    if (function_exists("recordObservation", this_object()))
    {
        this_object()->recordObservation(([
            "type": type,
            "subject": questItem,
            "context": context + ([ "state": quests[questItem]["state"] ])
        ]));
    }
}

//-----------------------------------------------------------------------------
// Method: questNotification
// Description: This method is used to broadcast all quest-related events
//              as they occur. See events.c for details.
//
// Parameters: event - the event that has occured. 
//-----------------------------------------------------------------------------
private nomask void questNotification(string event, string questItem)
{
    object eventObj = getModule("events");
    
    if(event && stringp(event) && eventObj && objectp(eventObj))
    {
        eventObj->notify(event, questItem);
    }
}

/////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////
private nomask object getQuestObject(string questItem)
{
    return questsService->questObject(questItem);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questIsInProgress(string questItem)
{
    return (isValidQuest(questItem) && getQuestObject(questItem) &&
        !quests[questItem]["is completed"]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questIsActive(string questItem)
{
    return (isValidQuest(questItem) && getQuestObject(questItem) &&
        quests[questItem]["is active"]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questIsCompleted(string questItem)
{
    return (isValidQuest(questItem) && getQuestObject(questItem) &&
        member(quests[questItem], "is completed") && quests[questItem]["is completed"]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string questStory(string questItem)
{
    string ret = "";
    object quest = getQuestObject(questItem);

    if (isValidQuest(questItem) && getQuestObject(questItem))
    {
        ret = quest->questStory(quests[questItem]["states completed"] +
            ({ quests[questItem]["state"] }), this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string questState(string questItem)
{
    string ret = 0;

    if(isValidQuest(questItem) && getQuestObject(questItem))
    {
        ret = quests[questItem]["state"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *activeQuests()
{
    return (filter(m_indices(quests), #'questIsActive) + ({ }));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *completedQuests()
{
    return (filter(m_indices(quests), #'questIsCompleted) + ({ }));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *questsInProgress()
{
    return (filter(m_indices(quests), #'questIsInProgress) + ({ }));
}

/////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////
private void checkQuestCompletion(string questItem, object questObj)
{
    if (questObj->questInCompletionState(quests[questItem]["state"]))
    {
        int wasCompleted = quests[questItem]["is completed"];
        quests[questItem]["is active"] = 0;
        quests[questItem]["is completed"] = 1;
        if (!wasCompleted)
        {
            recordQuestObservation("quest.completed", questItem, ([]));
        }
        questNotification("onQuestCompleted", questItem);

        if (questObj->questSucceeded(this_object()))
        {
            if (!wasCompleted)
            {
                recordQuestObservation("quest.succeeded", questItem, ([]));
            }
            questNotification("onQuestSucceeded", questItem);
        }
        else
        {
            if (!wasCompleted)
            {
                recordQuestObservation("quest.failed", questItem, ([]));
            }
            questNotification("onQuestFailed", questItem);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int advanceQuestState(string questItem, string newState)
{
    int ret = 0;
    if(isValidQuest(questItem))
    {
        object questObj = getQuestObject(questItem);
        if(questObj && objectp(questObj))
        {
            string previousState = quests[questItem]["state"];
            ret = 1;
            quests[questItem]["states completed"] +=
                ({ quests[questItem]["state"] });

            quests[questItem]["state"] = newState;

            if (previousState != newState)
            {
                if (member(quests[questItem]["states completed"], newState) < 0)
                {
                    questObj->applyRelationshipEffects(this_object(), newState);
                }
                recordQuestObservation("quest.advanced", questItem, ([
                    "previous state": previousState
                ]));
            }
            questNotification("onQuestAdvancedState", questItem);
            checkQuestCompletion(questItem, questObj);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
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
            "states completed": ({ }),
            "is active" : 1,
            "is completed": 0
        ]);
        questObj->applyRelationshipEffects(this_object(), questObj->initialState());
        recordQuestObservation("quest.started", questItem, ([]));
        questNotification("onQuestStarted", questItem);

        checkQuestCompletion(questItem, questObj);

        questObj->beginQuest(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int resetQuest(string questItem)
{
    int ret = 0;
    if (member(quests, questItem))
    {
        ret = 1;
        m_delete(quests, questItem);
    }
    return ret;
}
