//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string HiddenRoom =
    "/areas/eledhel/northern-city/phaedra-headquarters/1x3.c";
private mapping openedHiddenRooms = ([]);

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("A statue-lined hall of former Phaedra commanders");
    addDecorator("keep interior floor");
    addItem(
        "/lib/environment/items/objects/phaedra-memorial-statues.c",
        "west");
    addItem(
        "/lib/environment/items/objects/worn-pressure-tile.c", "none");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addRandomCreature(({ "knight of the storm" }));
    addExit("north",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c");
    addExit("south",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c");
    addExit("west", HiddenRoom);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();
    add_action("pressHiddenTile", "press");
}

/////////////////////////////////////////////////////////////////////////////
public int pressHiddenTile(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "tile", "floor tile", "loose floor tile",
            "pressure tile" }), lower_case(target)) > -1)
    {
        ret = 1;
        if (objectp(this_player()))
        {
            openedHiddenRooms[object_name(this_player())] = 1;
            tell_object(this_player(), "The tile sinks with a muted "
                "click. A narrow recess opens in the west wall.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) && program_name(toLocation) == HiddenRoom &&
        (!objectp(user) ||
            !member(openedHiddenRooms, object_name(user))))
    {
        ret = 0;
        if (objectp(user))
        {
            tell_object(user, "The west wall is seamless stone. "
                "Something in the floor may release it.\n");
        }
    }
    return ret;
}
