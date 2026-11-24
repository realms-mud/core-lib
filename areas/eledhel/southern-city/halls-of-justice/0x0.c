//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addItem(
        "/lib/environment/items/objects/battle-morannon-mural.c", "south");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addObject("/areas/eledhel/southern-city/halls-of-justice/characters/"
        "melach.c");

    addExitWithDoor("north", "/areas/eledhel/southern-city/20x7.c",
        "/lib/environment/doors/door.c");
    addExit("down", "/areas/eledhel/under-city/justice-branch/20x2.c");
    addExit("east", "/areas/eledhel/southern-city/halls-of-justice/0x1.c");
    addExit("west", "/areas/eledhel/southern-city/halls-of-justice/1x0.c");
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    string quest = "/areas/eledhel/under-city/escapeQuest.c";

    if (objectp(toLocation) &&
        program_name(toLocation) ==
            "/areas/eledhel/under-city/justice-branch/20x2.c" &&
        (!objectp(user) || user->questState(quest) != "justice reached"))
    {
        ret = 0;
        if (objectp(user))
        {
            tell_object(user, "The Battle of the Morannon mural "
                "shows no opening.\n");
        }
    }

    return ret;
}
