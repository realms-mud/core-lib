//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "King Rodent");
    addSpecification("source", "bard");
    addSpecification("description", "This research attunes the "
        "'A Rat's Serenade' research to bring forth king-sized "
        "rats.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 10
    ]));

    addPrerequisite("/guilds/bard/woodwind-brass/rous.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/bard/woodwind-brass/a-rats-serenade.c" }));
}
