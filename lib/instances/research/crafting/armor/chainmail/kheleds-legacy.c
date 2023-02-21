//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kheled's Legacy");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "amazing techniques mastered by the great dwarven smith Kheled.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/chainmail/kheleds-way.c", 
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 30]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 25]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 25]));
    addPrerequisite("gem crafting", (["type":"skill", "value" : 20]));

    addSpecification("limited by", (["crafting type":"chainmail"]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus metal crafting", 5);
    addSpecification("bonus gem crafting", 5);
}
