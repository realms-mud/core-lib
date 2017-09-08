//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void testAddFeature(string feature, string location)
{
    addFeature(feature, location);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddExit(string direction, string path)
{
    addExit(direction, path);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddBuilding(string feature, string location, string path)
{
    addBuilding(feature, location, path);
}

/////////////////////////////////////////////////////////////////////////////
public void testSetTerrain(string terrain)
{
    setTerrain(terrain);
}

/////////////////////////////////////////////////////////////////////////////
public void testSetInterior(string terrain)
{
    setInterior(terrain);
}