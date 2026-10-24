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
        "Ren assesses your demonstrated practice before endorsing promotion "
        "to adept. Requires ten qualifying uses of any one of Measured Palm, "
        "Measured Cut, Measured Impact, Focused Pulse, Linked Cut, "
        "Committed Cut, Measured Draw, Measured Hook, or Measured Rake "
        "against already-hostile, non-allied living NPCs in the same room at "
        "least half your effective level. Repeated uses in one encounter "
        "count; partial counts across techniques do not. This free "
        "assessment grants no combat bonus or automatic promotion.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
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
