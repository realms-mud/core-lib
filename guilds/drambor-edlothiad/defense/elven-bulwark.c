//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Bulwark");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the elven bulwark technique. The "
        "battlemage projects a shimmering field of "
        "condensed magical energy outward from the "
        "body, creating a visible barrier of pale "
        "silver light that turns aside physical "
        "and magical attacks alike.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "arcane-absorption.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist physical", 4);
}
