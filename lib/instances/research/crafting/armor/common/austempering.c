//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Austempering - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of austempering metal for use in armor. The metal "
        "is heated to a temperature wherein the resultant crystals "
        "have a plate-like form and then slowly cooled.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/common/quenching.c",
        (["type":"research"]));
    addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 7]));
    addPrerequisite("physics", (["type":"skill", "value" : 3]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting value multiplier", 20);
    addSpecification("bonus crafting armor class", 1);
    addSpecification("bonus crafting encumberance reduction", 1);
}
