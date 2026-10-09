//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elder Knowledge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research unlocks knowledge "
        "preserved from the Elder Days.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/mind-of-the-ancients.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus intelligence", 3);
    addSpecification("bonus spellcraft", 5);
}
