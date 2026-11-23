//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The prison guard room");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addItem("/lib/environment/items/military/weapon-rack.c", "east");
    addObject("/areas/eledhel/northern-city/characters/prison-jailer.c");
    addExit("south", "/areas/eledhel/northern-city/prison/2x2.c");
    addExit("east", "/areas/eledhel/northern-city/prison/3x3.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();
    add_action("operateCellWinch", "pull");
}

/////////////////////////////////////////////////////////////////////////////
public int operateCellWinch(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "winch", "the winch" }), lower_case(target)) > -1)
    {
        ret = 1;
        if (!load_object(
            "/areas/eledhel/northern-city/prison/2x2.c")->
                openCellsFor(this_player()))
        {
            tell_object(this_player(), "The winch is secured. Without "
                "an escape underway, there is no reason to open the cells.\n");
        }
    }
    return ret;
}
