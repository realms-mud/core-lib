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
        addSpecification("name", "Pattern Welding - Weapons");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of pattern welding metal - a treatment wherein multiple "
            "different metals are hammered thin and welded together with an "
            "acidic flux. The resultant lamellar metal is extremely hard and "
            "can maintain a tremendously sharp edge. It often has beautiful "
            "and much-sought surface texturing.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/common/folding.c",
            (["type":"research"]));

        addSpecification("bonus crafting value multiplier", 150);
        addSpecification("bonus crafting weapon class", 1);
        addSpecification("bonus crafting defense class", 1);
        addSpecification("bonus crafting attack", 1);
    }
}
