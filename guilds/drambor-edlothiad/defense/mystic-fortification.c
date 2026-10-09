//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Fortification");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the mystic fortification "
        "technique. By weaving threads of protective "
        "energy directly into the body's own aura, "
        "the battlemage creates a second skin of "
        "magical resistance that hardens against "
        "impact without impeding movement.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "resilient-aura.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus resist physical", 3);
}
