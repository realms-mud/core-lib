//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Slack Quenching - Armor");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of slack quenching metal for use in armor - a cooling of "
        "the metal in water. This treatment slightly hardens a metal.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("lib/instances/research/crafting/armor/common/annealing.c",
        (["type":"research"]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 1]));

    addSpecification("limited by", (["crafting type":({ "chainmail",
        "plate armor", "splint armor", "scale armor", "helmet" })]));

    addSpecification("bonus crafting armor class", 1);
}
