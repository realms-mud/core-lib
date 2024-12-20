//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tempering - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of tempering metal for use in armor. The metal "
        "is heated to a temperature lower than that used for "
        "working or quenching it and then allowed to slowly cool. This "
        "will reduce the metal's brittleness.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/armor/common/quenching.c",
        (["type":"research"]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 6]));
    addPrerequisite("physics", (["type":"skill", "value" : 3]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting armor class", 1);
    addSpecification("penalty to crafting encumberance reduction", 5);
}
