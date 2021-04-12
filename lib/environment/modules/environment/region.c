//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";

private object Region = 0;
private int xCoordinate = 0;
private int yCoordinate = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask object getRegion()
{
    return Region;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRegion(object region)
{
    Region = region;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCoordinates(object region, int x, int y)
{
    if (objectp(region) && 
        (member(inherit_list(region), "/lib/environment/region.c") > -1))
    {
        setRegion(region);
        xCoordinate = x;
        yCoordinate = y;
    }
    else
    {
        raise_error("ERROR in environment.c: You must specify a valid region "
            "when setting coordinates.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getCoordinates()
{
    return sprintf("%dx%d", xCoordinate, yCoordinate);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int xCoordinate()
{
    return xCoordinate;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int yCoordinate()
{
    return yCoordinate;
}
