//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit of the Wood");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the spirit of the wood, an "
        "ancient elven communion with the living "
        "forests. The battlemage draws vitality from "
        "the deep roots of the world, gaining a "
        "quiet strength and endurance that mirrors "
        "the patient resilience of ancient trees.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "fey-resistance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus hit points", 20);
    addSpecification("bonus heal hit points rate", 3);
}
