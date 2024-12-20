//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/treasure.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "rune of negation");
    set("short", "Rune of Negation");
    set("aliases", ({ "rune", "rune of negation", "negation" }));
    set("long", "A fist-sized slab of amethyst has some intricately carved "
        "runes on it. You can distinguish the Khazdic symbol for the word "
        "'negation' and see the words, 'I negate my greatest fears' "
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
    return "negation";
}
