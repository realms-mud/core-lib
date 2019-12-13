//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/treasure.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        set("name", "rune of doom");
        set("short", "Rune of Doom");
        set("aliases", ({ "rune", "rune of doom", "doom" }));
        set("long", "A fist-sized slab of amethyst has some intricately carved "
            "runes on it. You can distinguish the Khazdic symbol for the word "
            "'doom' and see the words, \x1b[0;35;3mMy doom awaits me\x1b[0m "
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
    return "doom";
}
