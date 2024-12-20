//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bear's Dance");
    addSpecification("source", "bard");
    addSpecification("description", "This research attunes the "
        "'Creatures of the Forest' research to "
        "bring forth only the mightiest of animals.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: woodwind", "instrument: brass" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 25
    ]));

    addPrerequisite("/guilds/bard/woodwind-brass/creatures-of-might.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/bard/woodwind-brass/ballad-of-the-bear.c",
        "/guilds/bard/woodwind-brass/ursine-tune.c",
    }));
}
