//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Beat of Baxeros");
    addSpecification("source", "bard");
    addSpecification("description", "This research increases the "
        "effectiveness of the various advanced drumming techniques.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: percussion" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 23
    ]));

    addPrerequisite("/guilds/bard/percussion/fell-beat.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Counterspell Knell": 50,
        "Blast Beat": 50,
        "Blessing of Bhelac": 50,
        "Bhelac's Tune": 50,
        "Rhythm of Landros": 50,
    ]));
    addSpecification("affected research type", "percentage");
}
