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
        addSpecification("name", "Khazurath's Gift");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "master techniques of imbuing the blade with their own essence. "
            "This is a skill mastered by the great smiths of Khazurath.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/axes/khuz-no-dai.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 45]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 40]));

        addSpecification("limited by", (["crafting type":"axe"]));

        addSpecification("bonus crafting magical enchantment", 2);
        addSpecification("bonus crafting enchantments", 1);
    }
}
