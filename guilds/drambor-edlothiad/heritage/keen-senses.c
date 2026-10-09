//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Keen Senses");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the keen senses that are the "
        "hallmark of elven kind. Sight, hearing, "
        "and even the subtle awareness of nearby "
        "magical auras are sharpened to a razor "
        "edge, granting the battlemage awareness "
        "that borders on omniscience.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "elven-grace.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 5
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 3);
    addSpecification("bonus wisdom", 2);
}
