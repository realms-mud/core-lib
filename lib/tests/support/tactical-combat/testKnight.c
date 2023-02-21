//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/tests/support/tactical-combat/unitNotRandom.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "knights");
    set("short", "Knights");
    set("long", "This is a powerful unit of knights.");
    set("ground attack", 600);
    set("air attack", 0);
    set("defense", 400);
    set("move", 4);
    set("unit morale", 5);
    set("troop count", 10);
    set("range", 1);
    set("unit type", "ground");
}
