//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/treasure.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "rune of death");
    set("short", "Rune of Death");
    set("aliases", ({ "rune", "rune of death", "death" }));
    set("long", "A fist-sized slab of amethyst has some intricately carved "
        "runes on it. You can distinguish the Khazdic symbol for the word "
        "'death' and see the words, 'I feel death's loving caress' "
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
    return "death";
}
