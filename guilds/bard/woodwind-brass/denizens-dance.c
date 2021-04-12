//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dexterous Denizens");
    addSpecification("source", "bard");
    addSpecification("description", "This research attunes the "
        "sundry creature summoning arpeggio research to "
        "bring forth only the mightiest of animals.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: woodwind", "instrument: brass" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 23
    ]));

    addPrerequisite("/guilds/bard/woodwind-brass/denizens-dance.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/bard/woodwind-brass/creatures-of-the-forest.c",
        "/guilds/bard/woodwind-brass/the-wailing-cat.c",
        "/guilds/bard/woodwind-brass/ballad-of-the-bear.c",
        "/guilds/bard/woodwind-brass/ursine-tune.c",
    }));
}
