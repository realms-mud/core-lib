//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Welding - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of mystic welding metal - a treatment wherein multiple "
        "different metals are hammered thin and welded together with a "
        "magical flux. The resultant lamellar metal is extremely hard and "
        "can maintain a tremendously sharp edge and is able to hold extreme "
        "enchantments. It often has beautiful  and much-sought surface "
        "texturing.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/common/mystic-wrapping.c",
        (["type":"research"]));
    addPrerequisite("weapon smithing", (["type":"skill", "value" : 12]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 10]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 15]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
    addPrerequisite("physics", (["type":"skill", "value" : 10]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 5]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 20]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting value multiplier", 500);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus crafting armor class", 1);
    addSpecification("bonus crafting weight reduction", 1);
    addSpecification("bonus crafting encumberance reduction", 5);
}
