//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bladestorm Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides supreme "
        "understanding  of bladestorm techniques, dramatically enhancing all "
            "active abilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spell-weave-transcendence.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mana Strike": 25,
        "Arcane Slash": 25,
        "Runic Blade": 25,
        "Spellstorm Strike": 25,
        "Arcane Annihilation": 25,
        "Blade of Eternity": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
