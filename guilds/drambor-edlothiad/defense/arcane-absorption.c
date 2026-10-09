//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Absorption");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the technique of arcane "
        "absorption. Rather than simply deflecting "
        "incoming magical attacks, the battlemage "
        "learns to draw the hostile energy into "
        "their own reserves, converting an enemy's "
        "assault into fuel for continued defense.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "fortified-will.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 23
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus spell points", 15);
}
