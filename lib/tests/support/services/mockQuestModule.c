//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useQuests = 0;
private object QuestItem;
private string CurrentState;

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockQuests()
{
    useQuests = !useQuests;
}

/////////////////////////////////////////////////////////////////////////////
public int questIsCompleted(string quest)
{
    return useQuests;
}

/////////////////////////////////////////////////////////////////////////////
public void StartQuest(object questItem)
{
    QuestItem = questItem;
    CurrentState = QuestItem.initialState();
}

/////////////////////////////////////////////////////////////////////////////
public int advanceQuestState(string questItem, string newState)
{
    int ret = 0;
    if(questItem == program_name(QuestItem))
    {
        CurrentState = newState;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string questState(string questItem)
{
    return (questItem == program_name(QuestItem)) ? CurrentState : 0;
}

/////////////////////////////////////////////////////////////////////////////
public string beginQuest(string questItem)
{
    return (questItem == program_name(QuestItem)) ? CurrentState : 0;
}
