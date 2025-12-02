//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Imbue Items");
    addSpecification("source", "enchanting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to imbue crafted items with enchantments.");
    addSpecification("research type", "granted");
    addSpecification("bonus crafting enchantments", 1);
}
