//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";

public void Setup()
{
    underCityCaveRoom::Setup();
    setShortDescription("The cramped climb ends at a fox-den mouth "
        "screened by brush and roots.");
    configureFoxRouteSegment(41);
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    int ret = underCityCaveRoom::moveFromIsAllowed(user, fromLocation);

    if (ret && user->questState(EscapeQuest) != "justice reached")
    {
        ret = 0;
        tell_object(user, "The steep climb is blocked by a fall of "
            "loose stone.\n");
    }
    else if (ret)
    {
        object quest = load_object(EscapeQuest);
        quest->receiveEvent(user, "reachedFoxDen", user);
        user->onStateChanged(quest, user->questState(EscapeQuest));
        tell_object(user, "You climb through the crack and emerge "
            "in the fox den beyond Eledhel.\n");
    }

    return ret;
}
