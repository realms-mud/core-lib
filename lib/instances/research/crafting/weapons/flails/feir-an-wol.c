//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Feir-an-wol");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "advanced techniques of imbuing the flail with their own essence. "
            "This is a skill mastered by the great smiths of Helcarnath.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/maces/baed-un-frolich.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 40]));
        addPrerequisite("gem crafting", (["type":"skill", "value" : 30]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 33]));

        addSpecification("limited by", (["crafting type": "flail"]));

        addSpecification("bonus crafting magical enchantment", 2);
    }
}
