//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Baxeros' Meter");
    addSpecification("source", "bard");
    addSpecification("description", "This research increases the "
        "effectiveness of the various advanced drumming techniques.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: percussion" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 33
    ]));

    addPrerequisite("/guilds/bard/percussion/beat-of-baxeros.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Counterspell Knell": 25,
        "Blast Beat": 25,
        "Blessing of Bhelac": 25,
        "Bhelac's Tune": 25,
        "Rhythm of Landros": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
