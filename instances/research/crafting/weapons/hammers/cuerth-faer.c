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
        addSpecification("name", "Cuerth-faer");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "arcane techniques of imbuing the hammer with their own essence. "
            "This is a skill mastered by the great smiths of Dhurgil.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/hammers/dhurgils-legacy.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 42]));
        addPrerequisite("gem crafting", (["type":"skill", "value" : 30]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 35]));

        addSpecification("limited by", (["crafting type":"hammer"]));

        addSpecification("bonus crafting value multiplier", 10);
        addSpecification("bonus crafting magical enchantment", 3);
    }
}
