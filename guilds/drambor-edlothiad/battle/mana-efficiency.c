//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Efficiency");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research improves mana efficiency "
        "for battle magic.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/spell-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 30);
    addSpecification("bonus spellcraft", 2);
}
