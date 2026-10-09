//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flash Freeze");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research improves the battlemage's "
        "ability to rapidly crystallize cold energy within a blade.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/frost-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 5
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental water", 2);
    addSpecification("bonus cold attack", 1);
}
