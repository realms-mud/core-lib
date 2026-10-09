//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Protection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research strengthens the "
        "battlemage's magical defenses and protective capabilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/invulnerability-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 57
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 18);
    addSpecification("bonus hit points", 100);
}
