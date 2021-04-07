//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Folding - Weapons");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of folding metal - a treatment wherein the metal is "
        "hammered thin folded upon itself - typically with a thin dusting "
        "of a powdered strengthening agent such as carbon or saltpeter "
        "placed between the layers. This is done multiple times; the "
        "resultant lamellar metal being much stronger than non-folded "
        "metal.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("lib/instances/research/crafting/weapons/common/annealing.c",
        (["type":"research"]));

    addPrerequisite("metal crafting", (["type":"skill", "value" : 4]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 3]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 3]));
    addPrerequisite("physics", (["type":"skill", "value" : 3]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger",
        "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
        "bow", "sling", "thrown", "shield" })]));

    addSpecification("bonus crafting value multiplier", 15);
    addSpecification("bonus crafting weapon class", 1);
}
