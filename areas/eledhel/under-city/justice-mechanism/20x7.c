//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private int leverPulled = 0;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "south");
    addItem("/lib/environment/items/objects/sighting-tube.c", "north");
    addItem(
        "/lib/environment/items/objects/counterweight-lever.c", "east");
    addItem(
        "/lib/environment/items/objects/counterweight-assembly.c", "west");
    addExit("west", "/areas/eledhel/under-city/southern-city/19x7.c");
    addExit("south", "/areas/eledhel/under-city/southern-city/20x6.c");
    addExit("north", "/areas/eledhel/under-city/justice-branch/20x2.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    underCityRoom::init();
    add_action("pullLever", "pull");
}

/////////////////////////////////////////////////////////////////////////////
public int pullLever(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "lever", "the lever" }), lower_case(target)) > -1)
    {
        ret = 1;
        leverPulled = 1;
        tell_object(this_player(), "The lever lowers the counterweights. "
            "Gears turn, and the stair to the mural door opens.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) &&
        program_name(toLocation) ==
            "/areas/eledhel/under-city/justice-branch/20x2.c" &&
        !leverPulled)
    {
        ret = 0;
        if (objectp(user))
        {
            tell_object(user, "The counterweights hold the stair "
                "to the mural door shut.\n");
        }
    }
    return ret;
}
