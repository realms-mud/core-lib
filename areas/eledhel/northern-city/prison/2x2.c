//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";
private string CellRoom =
    "/areas/eledhel/northern-city/prison/cell/0x0.c";
private mapping cellsOpenedFor = ([]);

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The prison cell passage");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("west", "/areas/eledhel/northern-city/prison/1x2.c");
    addExit("north", "/areas/eledhel/northern-city/prison/2x3.c");
    addExit("east", CellRoom);
}

/////////////////////////////////////////////////////////////////////////////
public int openCellsFor(object user)
{
    int ret = 0;
    if (objectp(user) && user->questIsInProgress(EscapeQuest))
    {
        cellsOpenedFor[object_name(user)] = 1;
        ret = 1;
        tell_object(user, "The counterweight winch raises the cell "
            "bolts with a heavy clank.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int cellsAreOpenFor(object user)
{
    int ret = 0;
    if (objectp(user))
    {
        ret = member(cellsOpenedFor, object_name(user));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void closeCellsFor(object user)
{
    if (objectp(user))
    {
        m_delete(cellsOpenedFor, object_name(user));
    }
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) && program_name(toLocation) == CellRoom &&
        !cellsAreOpenFor(user))
    {
        ret = 0;
        if (objectp(user))
        {
            tell_object(user, "The cell bolts are still secured by "
                "the guard-room winch.\n");
        }
    }
    return ret;
}
