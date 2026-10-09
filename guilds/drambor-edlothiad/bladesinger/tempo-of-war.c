//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tempo of War");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research controls the tempo of "
        "battle through the bladesong.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/fortissimo.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 35
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus defense", 3);
    addSpecification("bonus dodge", 3);
}
