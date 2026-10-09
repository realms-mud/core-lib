//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fey Ancestry");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with a deeper connection to their fey "
        "ancestry. The ancient blood of the fey "
        "realms still runs in elven veins, and by "
        "awakening this heritage the battlemage "
        "gains resistance to enchantments and a "
        "natural affinity for the magical.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "elven-intuition.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus intelligence", 1);
}
