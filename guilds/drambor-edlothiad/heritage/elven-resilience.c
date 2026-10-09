//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Resilience");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research strengthens the natural "
        "elven resistance to harm.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/trance-meditation.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 30);
    addSpecification("bonus defense", 2);
}
