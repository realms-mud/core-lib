//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Warrior");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enhances the "
        "battlemage's martial prowess through arcane warrior techniques.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/elven-swiftness.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 15);
    addSpecification("bonus damage", 10);
}
