//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/legacy.c");
    setAdditionalLongDescription("##LongDescription##");

    /* AddItems */
    /* AddExits */
    /* AddObjects */
}

/////////////////////////////////////////////////////////////////////////////
protected int alwaysLight()
{
    return /* IsLight */0;
}

/* AddMethods */