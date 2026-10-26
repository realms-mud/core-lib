//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Leverage Study");
    addSpecification("source", "monk");
    addSpecification("description",
        "Move the hands along the haft and feel how the world "
        "changes around their meeting point. Distance and weight "
        "become partners when their leverage is understood.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":40
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/returning-guard.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Impact":1,
        "Draining Impact":1,
        "Sweeping Arc":1,
        "Compact Blow":1,
        "Falling Head":1,
        "Pressing Shaft":1,
        "Taxing Contact":1,
        "Burdening Blow":1,
        "Horizon Stroke":1,
        "Centerline Crush":1,
        "Anvil Descent":1
    ]));
}
