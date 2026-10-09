//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rhythm of Battle");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the blade singer "
        "to find the rhythm in any combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/song-of-steel.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus parry", 3);
    addSpecification("bonus attack", 2);
}
