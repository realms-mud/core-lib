//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addPrerequisite("social practice", ([
        "type": "observation",
        "criteria": ([
            "type": "social.emote",
            "action": "smile"
        ]),
        "value": 1
    ]));
    addSpecification("name", "observant diplomat");
    addSpecification("description", "Understanding earned through interaction.");
    addSpecification("source", "background");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
}