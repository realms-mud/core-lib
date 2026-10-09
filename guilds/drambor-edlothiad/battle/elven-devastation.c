//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Devastation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research channels millennia of "
        "elven  magical tradition into devastating combat power.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/transcendent-power.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 49
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 12);
    addSpecification("bonus magical essence", 10);
}
