//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quenching - Weapons");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of quenching metal for use in weapons - a rapid cooling "
        "of the metal in water or oil. This treatment results in a very hard,"
        "brittle, amorphous metal.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 1]));

    addPrerequisite("/lib/instances/research/crafting/weapons/common/slack-quenching.c",
        (["type":"research"]));
    addSpecification("limited by", (["crafting type":({ "sword", "dagger",
        "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
        "bow", "sling", "thrown", "shield" })]));

    addSpecification("bonus crafting defense class", 1);
    addSpecification("bonus crafting weapon class", 1);
    addSpecification("penalty to crafting attack", 1);
}
