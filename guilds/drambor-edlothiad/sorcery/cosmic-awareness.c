//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cosmic Awareness");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with cosmic awareness, a state of "
        "heightened perception that extends beyond "
        "the physical. The battlemage becomes "
        "attuned to the vast currents of magical "
        "energy that flow between stars, drawing "
        "upon celestial power to fuel their arts.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "sorcery-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus spellcraft", 4);
}
