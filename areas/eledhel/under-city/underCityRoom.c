//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";

public int moveFromIsAllowed(object user, object fromLocation)
{
    int ret = 0;

    if (objectp(user) && user->questIsInProgress(EscapeQuest))
    {
        ret = 1;
        if (user->questState(EscapeQuest) == "escape begun")
        {
            object quest = load_object(EscapeQuest);
            quest->receiveEvent(user, "enteredUnderCity", user);
            user->onStateChanged(quest, user->questState(EscapeQuest));
        }
    }
    else if (objectp(user))
    {
        tell_object(user, "The concealed way remains sealed to you.\n");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string escapeQuestPath()
{
    return EscapeQuest;
}
