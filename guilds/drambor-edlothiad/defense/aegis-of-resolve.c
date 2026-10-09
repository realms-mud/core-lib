//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aegis of Resolve");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of the aegis of "
        "resolve. By anchoring defensive wards to "
        "sheer force of will rather than sustained "
        "concentration, the battlemage creates "
        "protective barriers that strengthen under "
        "duress rather than faltering.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "arcane-barrier.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist physical", 3);
}
