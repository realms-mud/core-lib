//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Fortitude");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the legendary fortitude of the "
        "elven race. Drawing upon the deep vitality "
        "inherent in elven blood, the battlemage "
        "greatly enhances natural resistance to "
        "poison, disease, and the ravages of hostile "
        "magic.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "mystic-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist disease", 15);
    addSpecification("bonus resist poison", 10);
}
