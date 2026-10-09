//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Instinct");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with an understanding of arcane combat "
        "instincts. Through deep attunement to the "
        "flows of magical energy during battle, the "
        "battlemage develops a preternatural awareness "
        "of incoming threats and openings in an "
        "opponent's defenses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "arcane-warrior-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus dodge", 2);
}
