//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Melodic Strikes");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches how to weave "
        "melody into each sword stroke.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/melodic-flow.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 1);
    addSpecification("bonus attack", 1);
}
