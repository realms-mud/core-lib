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
        addSpecification("name", "Mystic Quenching - Weapons");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of mystic quenching metal - a rapid cooling "
            "of the metal in a magically-imbued liquid. This treatment results "
            "in a very hard, brittle, magically-pliable metal.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/common/quenching.c",
            (["type":"research"]));
        
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 10]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 5]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 10]));
        addPrerequisite("physics", (["type":"skill", "value" : 5]));
        addPrerequisite("mathematics", (["type":"skill", "value" : 5]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));

        addSpecification("limited by", (["crafting type":({ "sword", "dagger",
            "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
            "bow", "sling", "thrown", "shield" })]));

        addSpecification("bonus crafting value multiplier", 15);
        addSpecification("bonus crafting weapon class", 1);
        addSpecification("bonus crafting enchantments", 1);
    }
}
