//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Resilience");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves the eternal "
        "resilience of the firstborn.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/undying-spirit.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 59
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 125);
    addSpecification("bonus defense", 8);
    addSpecification("bonus constitution", 4);
}
