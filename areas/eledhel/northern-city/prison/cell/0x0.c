//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string CellPassage =
    "/areas/eledhel/northern-city/prison/2x2.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/prison-cell.c");
    setShortDescription("A small holding cell with a narrow cot and "
        "iron bars looking onto the passage.");
    addDecorator("keep interior west wall entry");
    addItem("/lib/environment/items/furniture/bed.c", "west");
    addExit("west", CellPassage);
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) && program_name(toLocation) == CellPassage)
    {
        ret = load_object(CellPassage)->cellsAreOpenFor(user);
        if (!ret && objectp(user))
        {
            tell_object(user, "The cell bolts hold fast until the "
                "guard-room winch is pulled.\n");
        }
        else if (ret)
        {
            load_object(CellPassage)->closeCellsFor(user);
        }
    }
    return ret;
}
