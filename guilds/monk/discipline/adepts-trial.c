//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Adept's Trial");
    addSpecification("source", "monk");
    addSpecification("description",
        "Ren looks beyond the polished movements of the "
        "practice hall. The trial asks whether patient "
        "instruction has become dependable conduct under real danger.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":30
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/disciples-insight.c", ([
        "type":"research"
    ]));
    addPrerequisite("specialist practice", ([
        "type":"observation",
        "criteria":({
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/unarmed/measured-palm.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/katana/measured-cut.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/bludgeon/measured-impact.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"research.use",
                "research":"/guilds/monk/pure-chi/focused-pulse.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/paired-swords/linked-cut.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/odachi/committed-cut.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/archery/measured-draw.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/kama/measured-hook.c",
                "qualifying opponent":1
            ]),
            ([
                "type":"combat.kata",
                "research":"/guilds/monk/claw/measured-rake.c",
                "qualifying opponent":1
            ])
        }),
        "value":10
    ]));

    addSpecification("research type", "granted");
    addSpecification("teacher required", 1);
}
