//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/treasure.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "rune of resistance");
    set("short", "Rune of Resistance");
    set("aliases", ({ "rune", "rune of resistance", "resistance" }));
    set("long", "A fist-sized slab of amethyst has some intricately carved "
        "runes on it. You can distinguish the Khazdic symbol for the word "
        "'resistance' and see the words, 'Resisting no longer' "
        "next to it.\n");
}

/////////////////////////////////////////////////////////////////////////////
public int isObedienceRune()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string getRuneType()
{
    return "resistance";
}
