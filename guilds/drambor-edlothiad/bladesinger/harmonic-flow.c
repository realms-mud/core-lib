//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harmonic Flow");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the bladesinger "
        "to carry the rhythm of a bladesong through every movement, turning "
        "its resonant flow into a defense against incoming attacks.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/shield-of-song.c",
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
    addSpecification("bonus damage reflection", 1);
}
