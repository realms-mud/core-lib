//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Folding - Weapons");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of mystic folding metal - a treatment wherein the metal is "
        "hammered thin folded upon itself with a thin dusting "
        "of a magical agent such as kirluin placed between the layers. "
        "This is done multiple times; the resultant lamellar metal being "
        "both much stronger than non-folded metal and more receptive to "
        "magical enchantments.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/common/folding.c",
        (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/armor/common/forge-welding.c",
        (["type":"research"]));

    addPrerequisite("weapon smithing", (["type":"skill", "value" : 10]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 10]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 5]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
    addPrerequisite("physics", (["type":"skill", "value" : 10]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 5]));
    addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting value multiplier", 10);
    addSpecification("bonus crafting armor class", 1);
    addSpecification("bonus crafting encumberance reduction", 5);
    addSpecification("bonus crafting enchantments", 1);
}
