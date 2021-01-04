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
        addSpecification("name", "Differential Hardening - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of differential hardening metal for use in armor. "
            "Portions of the metal are heated and cooled at varying rates "
            "such that the edge is very hard, but the base of the blade is "
            "much more pliable.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/stepped-tempering.c",
            (["type":"research"]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 7]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 8]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 10]));
        addPrerequisite("physics", (["type":"skill", "value" : 5]));
        addPrerequisite("mathematics", (["type":"skill", "value" : 4]));

        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));

        addSpecification("bonus crafting armor class", 1);
    }
}
