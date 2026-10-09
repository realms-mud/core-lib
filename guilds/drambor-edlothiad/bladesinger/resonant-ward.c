//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Resonant Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research maintains a constant "
        "resonant ward around the blade singer.");

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
    addSpecification("bonus defense", 3);
    addSpecification("bonus armor class", 2);
}
