//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

int SetupCalled = 0;

/////////////////////////////////////////////////////////////////////////////
public int setupCalled()
{
    return SetupCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    SetupCalled++;
}

/////////////////////////////////////////////////////////////////////////////
public void testAddFeature(string feature, string location)
{
    addFeature(feature, location);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddItem(string feature, string location)
{
    addItem(feature, location);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void testAddObject(string file, string state)
{
    addObject(file, state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void testSetAdditionalLongDescription(
    string description, string state)
{
    setAdditionalLongDescription(description, state);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddExit(string direction, string path, string state)
{
    addExit(direction, path, state);
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

/////////////////////////////////////////////////////////////////////////////
public void testAddShop(string shop)
{
    addShop(shop);
}
