//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Craft Swords");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft knives, daggers, and swords out of "
            "typical bladed weapon materials such as iron, bronze, and steel.");
        addSpecification("research type", "granted");
        addSpecification("limited by", (["crafting type":"sword"]));

        addSpecification("bonus crafting value multiplier", 30);
        addSpecification("bonus crafting encumberance reduction", 50);
        addSpecification("bonus crafting weight reduction", 25);
        addSpecification("bonus crafting weapon class", 1);
        addSpecification("bonus crafting defense class", 1);
        addSpecification("bonus crafting attack", 1);
        addSpecification("bonus crafting armor class", 1);
        addSpecification("bonus crafting enchantments", 3);
        addSpecification("bonus crafting fire enchantment", 1);
    }
}
