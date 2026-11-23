//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private int leverPulled = 0;

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A sighting tube points toward the Halls of "
        "Justice. A lever waits beside the counterweights.");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addExit("north", "/areas/eledhel/under-city/justice-branch/0x0.c");
    addExit("south", "/areas/eledhel/under-city/trunk/100x0.c");
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
            "/areas/eledhel/under-city/justice-branch/0x0.c" &&
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
