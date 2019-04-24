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
        addSpecification("name", "Serach's Way");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "advanced techniques mastered by the great smiths of Serach.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/maces/serachs-tradition.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 31]));
        addPrerequisite("gem crafting", (["type":"skill", "value" : 25]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 25]));

        addSpecification("limited by", (["crafting type": "mace"]));

        addSpecification("bonus crafting value multiplier", 20);
        addSpecification("bonus gem crafting", 5);
        addSpecification("bonus spellcraft", 5);
        addSpecification("bonus weapon smithing", 5);
    }
}
