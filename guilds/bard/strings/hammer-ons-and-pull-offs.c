//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hammer-ons and Pull-offs");
    addSpecification("source", "bard");
    addSpecification("description", "This research increases the "
        "effectiveness of the various strumming techniques.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: plucked", "instrument: bowed" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 7
    ]));

    addPrerequisite("/guilds/bard/strings/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Riff of Report": 50,
        "Coronach of Capitulation": 50,
        "Requiem of Release": 50,
        "Dirge of the Damned": 50,
    ]));
    addSpecification("affected research type", "percentage");
}
