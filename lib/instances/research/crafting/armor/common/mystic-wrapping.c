//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Wrapping - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of mystic wrapping metal - a treatment wherein multiple "
        "different metals are hammered thin and folded in alternating "
        "layers - typically with a thin dusting of a powdered "
        "strengthening agent such as carbon or saltpeter placed between "
        "the layers. The resultant lamellar metal is extremely hard, yet "
        "quite pliable.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/common/mystic-folding.c",
        (["type":"research"]));
    addPrerequisite("armorer", (["type":"skill", "value" : 10]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 10]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 10]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
    addPrerequisite("physics", (["type":"skill", "value" : 10]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 5]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting armor class", 1);
    addSpecification("bonus crafting value multiplier", 25);
    addSpecification("bonus crafting encumberance reduction", 10);
    addSpecification("bonus crafting weight reduction", 5);
}
