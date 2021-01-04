//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Stepped Tempering - Weapons");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of stepped tempering metal for use in weapons. The metal "
            "is repeatedly heated to a low temperature and then allowed to "
            "slowly cool. This will reduce the metal's brittleness without "
            "sacrificing the hardness .");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/common/tempering.c",
            (["type":"research"]));

        addPrerequisite("metal crafting", (["type":"skill", "value" : 5]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 8]));
        addPrerequisite("physics", (["type":"skill", "value" : 3]));
        addPrerequisite("mathematics", (["type":"skill", "value" : 3]));

        addSpecification("limited by", (["crafting type":({ "sword", "dagger",
            "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
            "bow", "sling", "thrown", "shield" })]));

        addSpecification("bonus crafting value multiplier", 15);
        addSpecification("bonus crafting attack", 1);
    }
}
