//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Kheled's Legacy");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "amazing techniques mastered by the great dwarven smith Kheled.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/axes/kheleds-way.c", 
            (["type":"research"]));

        addSpecification("limited by", (["crafting type":"axe"]));

        addSpecification("bonus crafting value multiplier", 20);
        addSpecification("bonus crafting enchantments", 1);
        addSpecification("bonus metal crafting", 5);
        addSpecification("bonus gem crafting", 3);
    }
}
