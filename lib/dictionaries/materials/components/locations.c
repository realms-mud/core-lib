//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _locations_c
#define _locations_c

#include "/lib/dictionaries/materials/components/core.c"
#include "/lib/include/inventory.h"

/////////////////////////////////////////////////////////////////////////////
public nomask string *slotsUsedByItemMask(int mask)
{
    string *items = ({});

    if (mask & Armor)
    {
        items += ({ "armor" });
    }
    if (mask & Cloak)
    {
        items += ({ "cloak" });
    }
    if (mask & Helmet)
    {
        items += ({ "helmet" });
    }
    if (mask & Amulet)
    {
        items += ({ "amulet" });
    }
    if (mask & Belt)
    {
        items += ({ "belt" });
    }
    if (mask & ArmGreaves)
    {
        items += ({ "arm greaves" });
    }
    if (mask & LegGreaves)
    {
        items += ({ "leg greaves" });
    }
    if (mask & Gloves)
    {
        items += ({ "gloves" });
    }
    if (mask & Bracers)
    {
        items += ({ "bracers" });
    }
    if (mask & Boots)
    {
        items += ({ "boots" });
    }
    if (mask & Ring1)
    {
        items += ({ "ring 1" });
    }
    if (mask & Ring2)
    {
        items += ({ "ring 2" });
    }
    if (mask & PrimaryWeapon)
    {
        items += ({ "wielded primary" });
    }
    if (mask & OffhandWeapon)
    {
        items += ({ "wielded offhand" });
    }

    return items + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidArmorLocation(string type)
{
    return (member(validArmorLocations, type) > -1);
}

#endif
