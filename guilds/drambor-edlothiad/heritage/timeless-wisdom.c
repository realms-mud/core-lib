//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Timeless Wisdom");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with timeless wisdom accumulated over "
        "an elven lifetime. The battlemage draws "
        "upon centuries of experience and reflection "
        "to achieve a clarity of thought that "
        "transcends mortal understanding, seeing "
        "patterns in chaos and truth in deception.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "elder-blood.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus spellcraft", 3);
}
