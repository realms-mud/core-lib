//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crescendo");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research builds the bladesong to "
        "a crescendo of martial power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-the-ancients.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 27
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus long sword", 3);
}
