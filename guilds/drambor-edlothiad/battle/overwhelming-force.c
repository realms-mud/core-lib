//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Overwhelming Force");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the application of "
        " overwhelming magical force in battle.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/destructive-power.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus magical essence", 8);
    addSpecification("bonus spell points", 60);
}
