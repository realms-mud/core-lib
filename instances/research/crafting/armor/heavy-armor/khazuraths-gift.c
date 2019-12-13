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
        addSpecification("name", "Khazurath's Gift");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "master techniques of imbuing the heavy armor with its own essence. "
            "This is a skill mastered by the great smiths of Khazurath.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/heavy-armor/khuz-no-dai.c", 
            (["type":"research"]));
        addPrerequisite("armorer", (["type":"skill", "value" : 46]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 50]));

        addSpecification("limited by", (["crafting type":
            ({ "plate armor", "splint armor", "scale armor" })]));

        addSpecification("bonus crafting magical enchantment", 2);
        addSpecification("bonus crafting enchantments", 1);
    }
}
