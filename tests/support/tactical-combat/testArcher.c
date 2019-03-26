//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/tests/support/tactical-combat/unitNotRandom.c";

/////////////////////////////////////////////////////////////////////////////
void reset(int arg)
{
    if (!arg)
    {
        set("name", "archers");
        set("short", "Archers");
        set("long", "This is a powerful unit of archers.");
        set("ground attack", 800);
        set("air attack", 400);
        set("defense", 100);
        set("move", 6);
        set("unit morale", 5);
        set("troop count", 10);
        set("range", 1);
        set("unit type", "ground");
    }
}
