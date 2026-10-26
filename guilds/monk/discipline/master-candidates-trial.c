//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master Candidate's Trial");
    addSpecification("source", "monk");
    addSpecification("description",
        "Before a disciple may approach mastery, Ren "
        "asks for understanding that survives beyond "
        "rehearsal. Knowledge and hard-earned practice must speak together.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":55
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/inner-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("specialist mastery", ([
        "type":"any of",
        "prerequisites":({
            ([
                "/guilds/monk/unarmed/hammer-fist.c":([
                    "type":"research"
                ]),
                "/guilds/monk/unarmed/fist-compression.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/unarmed/hammer-fist.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/katana/drawn-circle.c":([
                    "type":"research"
                ]),
                "/guilds/monk/katana/circular-mechanics.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/katana/drawn-circle.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/draining-impact.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/leverage-study.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/draining-impact.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/pure-chi/piercing-intent.c":([
                    "type":"research"
                ]),
                "/guilds/monk/pure-chi/resonance-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"research.use",
                        "research":"/guilds/monk/pure-chi/piercing-intent.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/paired-swords/opening-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/paired-swords/opening-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/paired-swords/opening-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/odachi/descending-arc.c":([
                    "type":"research"
                ]),
                "/guilds/monk/odachi/longblade-descent-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/odachi/descending-arc.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/archery/descending-shot.c":([
                    "type":"research"
                ]),
                "/guilds/monk/archery/falling-trajectory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/archery/descending-shot.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/kama/crescent-reap.c":([
                    "type":"research"
                ]),
                "/guilds/monk/kama/crescent-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/kama/crescent-reap.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ]),
            ([
                "/guilds/monk/claw/rising-talon.c":([
                    "type":"research"
                ]),
                "/guilds/monk/claw/rising-talon-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/claw/rising-talon.c",
                        "qualifying opponent":1
                    ]),
                    "value":30
                ])
            ])
        })
    ]));

    addSpecification("research type", "granted");
    addSpecification("teacher required", 1);
}
