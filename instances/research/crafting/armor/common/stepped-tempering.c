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
        addSpecification("name", "Stepped Tempering - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of stepped tempering metal for use in armor. The metal "
            "is repeatedly heated to a low temperature and then allowed to "
            "slowly cool. This will reduce the metal's brittleness without "
            "sacrificing the hardness .");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/tempering.c",
            (["type":"research"]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 5]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 8]));
        addPrerequisite("physics", (["type":"skill", "value" : 3]));
        addPrerequisite("mathematics", (["type":"skill", "value" : 3]));

        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));

        addSpecification("bonus crafting value multiplier", 15);
        addSpecification("bonus crafting armor class", 1);
    }
}
