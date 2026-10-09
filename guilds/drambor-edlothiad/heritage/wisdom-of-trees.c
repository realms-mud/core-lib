//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wisdom of Trees");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the wisdom of trees, an elven "
        "contemplative tradition. By meditating upon "
        "the patient endurance of ancient forests, "
        "the battlemage attains a deep inner calm "
        "that steadies the mind against confusion "
        "and sharpens all magical perception.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "elven-longevity.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 53
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus spellcraft", 4);
}
