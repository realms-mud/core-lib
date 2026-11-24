//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem(
        "/lib/environment/items/objects/battle-morannon-mural.c", "north");
    addExit("south", "/areas/eledhel/under-city/justice-mechanism/20x7.c");
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
