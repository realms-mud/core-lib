//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Slack Quenching - Weapons");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of slack quenching metal for use in weapons - a cooling of "
        "the metal in water. This treatment slightly hardens a metal.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("chemistry", (["type":"skill", "value" : 1]));

    addPrerequisite("lib/instances/research/crafting/weapons/common/annealing.c",
        (["type":"research"]));
    addSpecification("limited by", (["crafting type":({ "sword", "dagger",
        "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
        "bow", "sling", "thrown", "shield" })]));

    addSpecification("bonus crafting weapon class", 1);
}
