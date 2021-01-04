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
        addSpecification("name", "Aegrath's Legacy");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "amazing techniques mastered by the great dwarven smith Aegrath.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/hammers/aegraths-way.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 25]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 22]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 22]));
        addPrerequisite("gem crafting", (["type":"skill", "value" : 20]));

        addSpecification("limited by", (["crafting type":"hammer"]));

        addSpecification("bonus crafting value multiplier", 20);
        addSpecification("bonus crafting enchantments", 1);
        addSpecification("bonus metal crafting", 5);
        addSpecification("bonus gem crafting", 3);
    }
}
