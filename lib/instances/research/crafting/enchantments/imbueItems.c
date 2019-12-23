//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Imbue Items");
        addSpecification("source", "enchanting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to imbue crafted items with enchantments.");
        addSpecification("research type", "granted");
        addSpecification("bonus crafting enchantments", 1);
    }
}
