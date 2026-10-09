//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immortal Constitution");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research unlocks the immortal "
        "constitution of the elder elves.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/ageless-endurance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 75);
    addSpecification("bonus constitution", 3);
}
