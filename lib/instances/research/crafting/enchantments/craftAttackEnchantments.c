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
        addSpecification("name", "Mutate Attack");
        addSpecification("source", "enchanting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to mutate a physical attack into a different form.");
        addSpecification("research type", "granted");

        addSpecification("limited by", (["crafting type":"staff"]));

        addSpecification("bonus crafting enchantments", 1);
        addSpecification("bonus crafting weapon class", 2);
        addSpecification("bonus crafting attack", 3);
    }
}
