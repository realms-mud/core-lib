//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/groups/baseGroup.c";

int applyWasCalled = 0;

/////////////////////////////////////////////////////////////////////////////
protected nomask void applyGroupDetails()
{
    applyWasCalled = 1;
}

/////////////////////////////////////////////////////////////////////////////
public int ApplyWasCalled()
{
    return applyWasCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void testSetName(string name)
{
    "baseGroup"::setName(name);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddPermission(string path, int permission)
{
    "baseGroup"::addPermission(path, permission);
}
