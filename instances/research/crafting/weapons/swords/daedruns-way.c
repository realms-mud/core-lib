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
        addSpecification("name", "Daedrun's Way");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "advanced techniques mastered by the great smith Daedrun.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/swords/daedruns-tradition.c", 
            (["type":"research"]));

        addSpecification("limited by", (["crafting type":"sword"]));

        addSpecification("bonus crafting value multiplier", 20);
        addSpecification("bonus gem crafting", 5);
        addSpecification("bonus spellcraft", 5);
        addSpecification("bonus weapon smithing", 5);
    }
}
