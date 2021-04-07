//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "A Mephit's Ballad");
    addSpecification("source", "bard");
    addSpecification("description", "This research attunes the "
        "'Pan's Mephit' and 'Majesty's Mephit' research to "
        "bring forth only more capable mephits.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: woodwind", "instrument: brass" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 27
    ]));

    addPrerequisite("guilds/bard/woodwind-brass/lay-of-mephias.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "guilds/bard/woodwind-brass/pans-mephit.c",
        "guilds/bard/woodwind-brass/majestys-mephit.c",
        "guilds/bard/woodwind-brass/minstrels-muse.c",
    }));
}
