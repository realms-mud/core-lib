//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Beyond Time");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves a state of mind "
        "beyond the constraints of time.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/timeless-intellect.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 4);
    addSpecification("bonus wisdom", 4);
    addSpecification("bonus spell points", 100);
}
