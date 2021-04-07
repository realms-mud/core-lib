//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Keeping Time");
    addSpecification("source", "bard");
    addSpecification("description", "This research increases the "
        "effectiveness of the various drumming techniques that "
        "affect the user's allies.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: percussion" }) ]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 11
    ]));

    addPrerequisite("guilds/bard/percussion/snare-of-the-soldier.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Snare of the Soldier": 50,
        "Percussive Blast": 50,
        "Drums of Doom": 50,
        "Drums of Dedication": 50,
        "Beat of the Broken": 50,
        "Mystic Rhythms": 50,
    ]));
    addSpecification("affected research type", "percentage");
}
