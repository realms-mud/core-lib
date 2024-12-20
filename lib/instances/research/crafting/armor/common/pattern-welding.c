//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pattern Welding - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of pattern welding metal - a treatment wherein multiple "
        "different metals are hammered thin and welded together with an "
        "acidic flux. The resultant lamellar metal is extremely hard and "
        "can maintain a tremendously sharp edge. It often has beautiful "
        "and much-sought surface texturing.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/common/folding.c",
        (["type":"research"]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 10]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 9]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
    addPrerequisite("physics", (["type":"skill", "value" : 5]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 5]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting value multiplier", 150);
    addSpecification("bonus crafting armor class", 2);
}
