//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/treasure.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        set("name", "rune of strength");
        set("short", "Rune of Strength");
        set("aliases", ({ "rune", "rune of strength", "strength" }));
        set("long", "A fist-sized slab of amethyst has some intricately carved "
            "runes on it. You can distinguish the Khazdic symbol for the word "
            "'strength' and see the words, [0;35;3mI am strong[0m "
            "next to it.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public int isObedienceRune()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string getRuneType()
{
    return "strength";
}
