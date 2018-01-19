//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping Quests = ([]);

/////////////////////////////////////////////////////////////////////////////
public mapping quests()
{
    return Quests;
}

/////////////////////////////////////////////////////////////////////////////
public void clearEvents()
{
    Quests = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestStarted(object caller, string data)
{
    Quests["onQuestStarted"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestAdvancedState(object caller, string data)
{
    Quests["onQuestAdvancedState"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestCompleted(object caller, string data)
{
    Quests["onQuestCompleted"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestSucceeded(object caller, string data)
{
    Quests["onQuestSucceeded"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestFailed(object caller, string data)
{
    Quests["onQuestFailed"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestActivated(object caller, string data)
{
    Quests["onQuestActivated"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestDeactivated(object caller, string data)
{
    Quests["onQuestDeactivated"] = data;
}
