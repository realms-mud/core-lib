//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "War Magic Infusion");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enhances the "
        "battlemage's martial prowess through arcane warrior techniques.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/battle-dancer.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 8);
    addSpecification("bonus magical attack", 5);
}
