//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Aegis");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves eternal "
        "protection through elven magic.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/immortal-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus armor class", 8);
    addSpecification("bonus hit points", 100);
    addSpecification("bonus defense", 10);
}
