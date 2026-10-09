//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Martial Precision");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with an understanding of martial "
        "precision as refined through arcane awareness. "
        "By perceiving the subtle magical signatures "
        "of an opponent's movements, the battlemage "
        "can predict and exploit weaknesses with "
        "unerring accuracy.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "enhanced-reflexes.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus long sword", 3);
}
