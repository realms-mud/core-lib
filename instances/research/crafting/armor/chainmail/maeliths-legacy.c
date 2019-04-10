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
        addSpecification("name", "Maelith's Legacy");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "arcane techniques mastered by the great smith Maelith.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/chainmail/maeliths-tradition.c", 
            (["type":"research"]));
        addPrerequisite("armorer", (["type":"skill", "value" : 35]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 35]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 25]));

        addSpecification("limited by", (["crafting type":"chainmail"]));

        addSpecification("bonus crafting value multiplier", 20);
        addSpecification("bonus crafting enchantments", 1);
        addSpecification("bonus spellcraft", 3);
        addSpecification("bonus metal crafting", 3);
        addSpecification("bonus armorer", 3);
    }
}
