//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addExit("south", "/areas/eledhel/under-city/phaedra-landing/2x1.c");
    addExit("up",
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    underCityRoom::init();
    add_action("pullMapLever", "pull");
}

/////////////////////////////////////////////////////////////////////////////
public int pullMapLever(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "lever", "the lever" }), lower_case(target)) > -1)
    {
        ret = 1;
        load_object(
            "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c")->
                closeMapDoor(this_player());
        tell_object(this_player(), "You pull the lever and the map "
            "panel closes flush with the wall.\n");
    }
    return ret;
}
