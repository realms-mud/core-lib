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
        addSpecification("name", "Case Hardening - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of case hardening metal for use in armor. The metal "
            "is flash-heated and quenched such that only the outermost "
            "layer of the metal has been hardened. This outside layer is "
            "somewhat brittle, but the core is soft and pliable.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/quenching.c",
            (["type":"research"]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 6]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 7]));
        addPrerequisite("physics", (["type":"skill", "value" : 5]));
        addPrerequisite("mathematics", (["type":"skill", "value" : 3]));

        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));

        addSpecification("bonus crafting armor class", 1);
    }
}
