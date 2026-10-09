//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancient Knowledge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides knowledge passed "
        "down through millennia of elven tradition.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/elven-insight.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical essence", 3);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus spell points", 15);
}
