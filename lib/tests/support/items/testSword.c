//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sword of Weasels");
    set("short", "Sword of Weasels");
    set("aliases", ({ "sword", "long sword" }));
    set("long", "This is the sword of weasels. It's neat.");
    set("weapon type", "long sword");
    set("material", "galvorn");
    set("value", 850);
    set("bonus armor class", 5);
}

/////////////////////////////////////////////////////////////////////////////
public string swordMessage()
{
    return "You can feel a weaselish buzz in the air.";
}
