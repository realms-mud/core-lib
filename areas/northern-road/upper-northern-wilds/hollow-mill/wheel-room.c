//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string Cellar =
    "/areas/northern-road/upper-northern-wilds/hollow-mill/cellar-entry.c";
private mapping openedCellars = ([]);

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The wheel room beneath the mill's stone store");
    addItem("/lib/environment/items/crafts/mill-gears.c", "north");
    addItem("/lib/environment/items/crafts/millstone.c", "east");
    addItem("/lib/environment/items/objects/mill-cellar-ring.c", "south");
    addExit("west",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/grain-store.c");
    addExit("south",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheelhouse.c");
    addExit("east",
        "/areas/northern-road/upper-northern-wilds/inland/ridge-path.c");
    addExit("down", Cellar);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();
    add_action("pullCellarRing", "pull");
}

/////////////////////////////////////////////////////////////////////////////
public int pullCellarRing(string target)
{
    int ret = 0;
    if (stringp(target) &&
        member(({ "ring", "iron ring", "hatch ring" }),
            lower_case(target)) > -1)
    {
        ret = 1;
        if (objectp(this_player()))
        {
            openedCellars[object_name(this_player())] = 1;
            tell_object(this_player(), "The ring lifts the stone hatch "
                "with a reluctant scrape. A breath of cold air rises "
                "from below.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) && program_name(toLocation) == Cellar &&
        (!objectp(user) || !member(openedCellars, object_name(user))))
    {
        ret = 0;
        if (objectp(user))
        {
            tell_object(user, "The heavy millstone leaves no visible "
                "stairway. A small iron ring is set into the floor.\n");
        }
    }
    return ret;
}
