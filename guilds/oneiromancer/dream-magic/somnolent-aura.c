//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Somnolent Aura");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of emanating a constant aura of drowsiness that saps "
        "the strength of nearby enemies while fortifying the oneiromancer.");

    addPrerequisite("/guilds/oneiromancer/dream-magic/oneiric-blast.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 31
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus resist psionic", 10);
    addSpecification("bonus defense", 3);
    addSpecification("bonus spell points", 30);
}
