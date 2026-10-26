//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Momentum Mastery");
    addSpecification("source", "monk");
    addSpecification("description",
        "Learn to keep the weapon's story unbroken from one "
        "stroke to the next. What once required a halt and "
        "a fresh effort becomes a single continuing motion.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":62
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "master candidate",
        "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/draining-impact.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Impact":2,
        "Draining Impact":2,
        "Sweeping Arc":2,
        "Compact Blow":2,
        "Falling Head":2,
        "Pressing Shaft":2,
        "Taxing Contact":2,
        "Burdening Blow":2,
        "Horizon Stroke":2,
        "Centerline Crush":2,
        "Anvil Descent":2
    ]));
}
