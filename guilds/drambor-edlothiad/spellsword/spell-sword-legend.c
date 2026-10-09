//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Sword Legend");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ultimate realization of the "
        "spell sword tradition. The warrior has "
        "become a living legend whose very presence "
        "on the battlefield inspires awe, for blade "
        "and spell have become one inseparable "
        "instrument of destruction in their hands.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "apex-predator.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 67
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 7);
    addSpecification("bonus spellcraft", 6);
    addSpecification("bonus spell points", 50);
    addSpecification("bonus damage", 5);
}
