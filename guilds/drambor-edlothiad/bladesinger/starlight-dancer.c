//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Starlight Dancer");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the blade singer "
        "to dance among the starlight.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/celestial-bladesong.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 57
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 6);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus damage", 5);
}
