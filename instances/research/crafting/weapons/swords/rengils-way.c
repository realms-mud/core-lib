//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Rengil's Way");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "advanced techniques mastered by the great smith Rengil.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/swords/rengils-tradition.c", 
            (["type":"research"]));

        addSpecification("limited by", (["crafting type":"sword"]));

        addSpecification("bonus crafting value multiplier", 10);
        addSpecification("bonus crafting encumberance reduction", 25);
        addSpecification("bonus blacksmithing", 5);
        addSpecification("bonus metal crafting", 5);
        addSpecification("bonus weapon smithing", 5);
    }
}
