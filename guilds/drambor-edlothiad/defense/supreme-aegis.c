//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Aegis");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the supreme aegis, the highest "
        "form of passive magical protection known "
        "to the Drambor. This technique creates an "
        "omnidirectional barrier of such density "
        "that even the most powerful spells struggle "
        "to penetrate its interlocking layers of "
        "woven energy.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "immortal-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 63
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 8);
    addSpecification("bonus resist physical", 8);
    addSpecification("bonus resist magical", 8);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist cold", 5);
}
