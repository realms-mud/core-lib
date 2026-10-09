//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Resilience");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with elven magical resilience. The "
        "battlemage's innate connection to the "
        "weave of magic grants a natural resistance "
        "to hostile spellwork, causing enemy "
        "enchantments to lose potency as they "
        "encounter the deep well of power within.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "elven-meditation.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus spell points", 10);
}
