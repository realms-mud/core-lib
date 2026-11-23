//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

private int doorOpened = 0;

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A false stone door is held shut by a tapered "
        "stalagmite wedged against its lower edge.");
    addItem("/lib/environment/items/objects/stone-pile.c", "north");
    configureFoxRouteSegment(29);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    underCityRoom::init();
    add_action("pushStalagmite", "push");
}

/////////////////////////////////////////////////////////////////////////////
public int pushStalagmite(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "stalagmite", "the stalagmite" }),
            lower_case(target)) > -1)
    {
        ret = 1;
        doorOpened = 1;
        tell_object(this_player(), "The stalagmite rolls away. The "
            "stone door shifts open into a natural cavern.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) &&
        program_name(toLocation) ==
            "/areas/eledhel/under-city/fox-route/30x0.c" &&
        !doorOpened)
    {
        ret = 0;
        if (objectp(user))
        {
            tell_object(user, "The stone door is blocked by the "
                "wedged stalagmite.\n");
        }
    }
    return ret;
}
