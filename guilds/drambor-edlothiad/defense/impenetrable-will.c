//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Impenetrable Will");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research strengthens the "
        "battlemage's magical defenses and protective capabilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/supreme-resistance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 12);
    addSpecification("bonus resist cold", 5);
}
