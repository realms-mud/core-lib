//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sorcery Transcendence");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with sorcerous transcendence, the "
        "ultimate achievement of elven magical "
        "study. The battlemage becomes a living "
        "conduit for pure arcane force, their very "
        "existence blurring the line between mortal "
        "spellcaster and elemental embodiment of "
        "magical power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "transcendent-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 69
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 3);
    addSpecification("bonus wisdom", 3);
    addSpecification("bonus spellcraft", 10);
    addSpecification("bonus spell points", 75);
    addSpecification("bonus resist magical", 10);
}
