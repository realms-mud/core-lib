//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blood of the Firstborn");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the purest expression of elven "
        "heritage. The battlemage awakens the blood "
        "of the firstborn elves who walked beneath "
        "the first stars, gaining a measure of their "
        "legendary might and the near-divine "
        "resilience that once shaped the world.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "wisdom-of-trees.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 2);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus charisma", 2);
}
