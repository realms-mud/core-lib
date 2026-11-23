//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A hidden stair climbs behind an old battle "
        "mural in the Halls of Justice.");
    addExit("south", "/areas/eledhel/under-city/justice-mechanism/0x0.c");
    addExit("up", "/areas/eledhel/southern-city/halls-of-justice/0x0.c");
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    int ret = underCityRoom::moveFromIsAllowed(user, fromLocation);

    if (ret && user->questState(EscapeQuest) == "under city")
    {
        object quest = load_object(EscapeQuest);
        quest->receiveEvent(user, "reachedJustice", user);
        user->onStateChanged(quest, user->questState(EscapeQuest));
    }

    return ret;
}
