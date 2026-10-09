//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Knowledge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with transcendent knowledge that "
        "bridges the gap between mortal sorcery and "
        "divine power. The battlemage's understanding "
        "of magic reaches such heights that they can "
        "reshape reality itself through force of "
        "intellect and will alone.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "immortal-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 67
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus spell points", 60);
}
