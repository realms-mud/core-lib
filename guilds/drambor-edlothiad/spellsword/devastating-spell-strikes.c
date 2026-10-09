//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Devastating Spell Strikes");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research makes all spell strikes "
        "devastatingly powerful.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/annihilation-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 5);
    addSpecification("bonus attack", 4);
}
