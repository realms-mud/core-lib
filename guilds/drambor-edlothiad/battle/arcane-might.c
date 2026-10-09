//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Might");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research increases the raw power "
        "of the battlemage's offensive spells.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/mana-efficiency.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 4);
    addSpecification("bonus magical essence", 3);
}
