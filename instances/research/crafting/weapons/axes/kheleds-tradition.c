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
        addSpecification("name", "Kheled's Tradition");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "techniques mastered by the great dwarven smith Kheled.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/axes/craftBasicAxes.c", 
            (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/weapons/common/folding.c",
            (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/weapons/common/austempering.c",
            (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/weapons/common/differential-hardening.c",
            (["type":"research"]));

        addSpecification("limited by", (["crafting type":"axe"]));

        addSpecification("bonus crafting value multiplier", 30);
        addSpecification("bonus crafting encumberance reduction", 10);
        addSpecification("bonus crafting weight reduction", 10);
        addSpecification("bonus crafting weapon class", 1);
        addSpecification("bonus crafting defense class", 1);
        addSpecification("bonus blacksmithing", 5);
        addSpecification("bonus metal crafting", 5);
        addSpecification("bonus weapon smithing", 5);
    }
}
