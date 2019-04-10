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

        addPrerequisite("lib/instances/research/crafting/weapons/common/folding.c",
            (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/weapons/common/forge-welding.c",
            (["type":"research"]));

        addPrerequisite("weapon smithing", (["type":"skill", "value" : 10]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 5]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
        addPrerequisite("physics", (["type":"skill", "value" : 10]));
        addPrerequisite("mathematics", (["type":"skill", "value" : 5]));
        addPrerequisite("spellcraft", (["type":"skill", "value" : 15]));

        addSpecification("limited by", (["crafting type":({ "sword", "dagger",
            "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
            "bow", "sling", "thrown", "shield" })]));

        addSpecification("bonus crafting value multiplier", 10);
        addSpecification("bonus crafting attack", 1);
        addSpecification("bonus crafting defense class", 1);
        addSpecification("bonus crafting enchantments", 1);
    }
}
