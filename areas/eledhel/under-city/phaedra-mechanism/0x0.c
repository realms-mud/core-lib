//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private int doorDisabled = 0;

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A counterweight machine fills the room. A heavy "
        "cotter pin secures the gear that opens the map door.");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addExit("south", "/areas/eledhel/under-city/phaedra-landing/0x0.c");
    addExit("north", "/areas/eledhel/under-city/phaedra-branch/0x0.c");
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
            "/areas/eledhel/under-city/phaedra-branch/0x0.c" &&
        doorDisabled)
    {
        ret = 0;
        tell_object(user, "The disabled counterweight holds the way "
            "to the map door shut.\n");
    }
    return ret;
}
