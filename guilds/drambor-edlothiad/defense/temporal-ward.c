//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Temporal Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the knowledge of temporal warding. "
        "By subtly warping the flow of time around "
        "oneself, the battlemage causes incoming "
        "attacks to arrive fractionally slower than "
        "expected, granting precious moments to "
        "parry, dodge, or reinforce other defenses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "spell-deflection.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus parry", 3);
}
