//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private int Peaceful;

public void Setup()
{
    setTerrain("/lib/tests/support/environment/fakeTerrain.c");
}

protected int alwaysLight()
{
    return 10;
}

public void testAddExit(string direction, string destination)
{
    addExit(direction, destination);
}

public void testSetPeaceful(int value)
{
    Peaceful = value;
}

public int violenceIsProhibited()
{
    return Peaceful;
}
