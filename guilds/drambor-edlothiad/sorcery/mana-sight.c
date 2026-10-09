//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Sight");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research grants the ability to "
        "perceive  magical energies directly.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/ancient-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical essence", 4);
    addSpecification("bonus spellcraft", 3);
}
