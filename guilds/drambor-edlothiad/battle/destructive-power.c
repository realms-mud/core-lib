//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Destructive Power");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research increases the raw "
        "destructive  force of all battle magic.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/elven-battle-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus spell points", 50);
}
