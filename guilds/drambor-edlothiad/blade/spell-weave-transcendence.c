//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Weave Transcendence");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents transcendent "
        "understanding of spell weaving, dramatically boosting all "
        "spellblade combat abilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/spell-weave-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mana Strike": 25,
        "Arcane Slash": 25,
        "Runic Blade": 25,
        "Spellstorm Strike": 25,
        "Arcane Annihilation": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
