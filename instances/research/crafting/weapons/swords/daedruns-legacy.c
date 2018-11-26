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
        addSpecification("name", "Daedrun's Legacy");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "arcane techniques mastered by the great smith Daedrun.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/swords/daedruns-way.c", 
            (["type":"research"]));

        addSpecification("limited by", (["crafting type":"sword"]));

        addSpecification("bonus crafting value multiplier", 20);
        addSpecification("bonus crafting enchantments", 1);
        addSpecification("bonus spellcraft", 5);
        addSpecification("bonus metal crafting", 3);
        addSpecification("bonus weapon smithing", 3);
    }
}
