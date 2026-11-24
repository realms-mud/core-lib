//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/calcite-rib.c", "west");
    addItem("/lib/environment/items/objects/paired-climbing-ropes.c",
        "north");
    addExit("east", "/areas/eledhel/under-city/natural-caverns/5x5.c");
    addExit("up", "/areas/eledhel/west-rural-two/fox-den/0x0.c");
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    int ret = underCityCaveRoom::moveFromIsAllowed(user, fromLocation);
    if (ret && objectp(user) &&
        user->questState(EscapeQuest) == "justice reached")
    {
        object quest = load_object(EscapeQuest);
        quest->receiveEvent(user, "reachedFoxDen", user);
        user->onStateChanged(quest, user->questState(EscapeQuest));
    }
    return ret;
}
