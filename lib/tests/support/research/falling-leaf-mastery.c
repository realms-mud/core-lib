//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addPrerequisite("falling leaf practice", ([
        "type": "observation",
        "criteria": ([
            "type": "combat.kata",
            "target race": "orc",
            "weapon": "katana",
            "kata": "falling-leaf"
        ]),
        "value": 100
    ]));
    addSpecification("name", "falling leaf mastery");
    addSpecification("description", "Mastery earned through kata practice.");
    addSpecification("source", "monk");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
}