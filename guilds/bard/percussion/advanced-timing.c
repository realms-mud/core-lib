//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Advanced Timing");
    addSpecification("source", "bard");
    addSpecification("description", "This research increases the "
        "effectiveness of the various drumming techniques.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: percussion" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 21
    ]));

    addPrerequisite("/guilds/bard/percussion/keeping-time.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Snare of the Soldier": 25,
        "Percussive Blast": 25,
        "Drums of Doom": 25,
        "Drums of Dedication": 25,
        "Beat of the Broken": 25,
        "Mystic Rhythms": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
