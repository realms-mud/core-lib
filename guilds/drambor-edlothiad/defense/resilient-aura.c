//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Resilient Aura");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with a resilient protective aura. The "
        "battlemage learns to maintain a subtle but "
        "persistent field of defensive energy that "
        "clings close to the skin, absorbing the "
        "force of glancing blows and reducing the "
        "severity of wounds that penetrate other "
        "defenses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "mystic-resilience.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus hit points", 15);
}
