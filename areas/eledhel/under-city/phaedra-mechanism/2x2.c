//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private int doorDisabled = 0;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "west");
    addItem(
        "/lib/environment/items/objects/counterweight-assembly.c", "north");
    addItem(
        "/lib/environment/items/objects/iron-cotter-pin.c", "east");
    addExit("north", "/areas/eledhel/under-city/phaedra-landing/2x1.c");
    addExit("east", "/areas/eledhel/under-city/northern-city/5x6.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    underCityRoom::init();
    add_action("removeCotterPin", "remove");
    add_action("removeCotterPin", "pull");
}

/////////////////////////////////////////////////////////////////////////////
public int removeCotterPin(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "cotter pin", "the cotter pin" }), lower_case(target)) > -1)
    {
        ret = 1;
        doorDisabled = 1;
        tell_object(this_player(), "The cotter pin slides free. The "
            "counterweight settles, disabling the hidden door mechanism.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) &&
        program_name(toLocation) ==
            "/areas/eledhel/under-city/phaedra-branch/2x3.c" &&
        doorDisabled)
    {
        ret = 0;
        tell_object(user, "The disabled counterweight holds the way "
            "to the map door shut.\n");
    }
    return ret;
}
