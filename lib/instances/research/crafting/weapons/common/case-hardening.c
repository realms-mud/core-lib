//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Case Hardening - Weapons");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of case hardening metal for use in weapons. The metal "
        "is flash-heated and quenched such that only the outermost "
        "layer of the metal has been hardened. This outside layer is "
        "somewhat brittle, but the core is soft and pliable.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/lib/instances/research/crafting/weapons/common/quenching.c",
        (["type":"research"]));

    addPrerequisite("metal crafting", (["type":"skill", "value" : 8]));
    addPrerequisite("blacksmithing", (["type":"skill", "value" : 6]));
    addPrerequisite("chemistry", (["type":"skill", "value" : 7]));
    addPrerequisite("physics", (["type":"skill", "value" : 5]));
    addPrerequisite("mathematics", (["type":"skill", "value" : 3]));

    addSpecification("limited by", (["crafting type":({ "sword", "dagger",
        "pole arm", "staff", "axe", "hammer", "mace", "flail", "crossbow",
        "bow", "sling", "thrown", "shield" })]));

    addSpecification("bonus crafting attack", 1);
}
