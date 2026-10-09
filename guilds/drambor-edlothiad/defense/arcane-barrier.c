//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Barrier");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage "
        "to layer arcane wards into a resilient barrier that turns aside "
        "incoming attacks and dampens hostile magic.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/arcane-absorption.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 23
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist magical", 4);
}
