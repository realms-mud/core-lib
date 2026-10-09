//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Deathbringer Mastery");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research completes the Disciple's mastery of the death arts, making them a true deathbringer - one of Argloth's most feared instruments.");

    addPrerequisite("/guilds/disciple-of-argloth/death/deathbringer.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 62
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 10);
    addSpecification("bonus magical essence", 6);
    addSpecification("bonus intelligence", 3);
    addSpecification("bonus wisdom", 3);
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Killing Word": 20,
        "Deathbringer": 20,
        "Argloth's Reaper": 15,
    ]));
}
