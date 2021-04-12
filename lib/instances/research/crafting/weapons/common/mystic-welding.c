//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Welding - Weapons");
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

    addPrerequisite("/lib/instances/research/crafting/weapons/common/mystic-wrapping.c",
        (["type":"research"]));

    addPrerequisite("weapon smithing", (["type":"skill", "value" : 12]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 10]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 15]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
    addPrerequisite("physics", (["type":"skill", "value" : 10]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 5]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 20]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger",
        "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
        "bow", "sling", "thrown", "shield" })]));

    addSpecification("bonus crafting value multiplier", 500);
    addSpecification("bonus crafting enchantments", 1);
    addSpecification("bonus crafting weapon class", 1);
    addSpecification("bonus crafting defense class", 1);
    addSpecification("bonus crafting attack", 1);
}
