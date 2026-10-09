//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven War Dance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the ancient "
        "elven war dance, a precursor to "
        "advanced bladesinging.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-valor.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus attack", 2);
}
