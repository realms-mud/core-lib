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
        addSpecification("name", "Mystic Quenching - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of mystic quenching metal - a rapid cooling "
            "of the metal in a magically-imbued liquid. This treatment results "
            "in a very hard, brittle, magically-pliable metal.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/quenching.c",
            (["type":"research"]));
        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));

        addSpecification("bonus crafting value multiplier", 15);
        addSpecification("bonus crafting armor class", 1);
        addSpecification("bonus crafting enchantments", 1);
    }
}
