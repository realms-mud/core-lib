//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Senior Disciple's Trial");
    addSpecification("source", "monk");
    addSpecification("description",
        "Ren assesses advanced specialist practice before endorsing your "
        "next promotion. Learn one listed technique and its matching "
        "knowledge, and demonstrate 20 qualifying uses of that technique "
        "against already-hostile, non-allied living NPCs in the same room at "
        "least half your effective level. Historical practice counts; "
        "partial counts and knowledge from other routes do not combine. This "
        "free assessment grants no combat bonus or automatic promotion.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":40
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/adepts-focus.c", ([
        "type":"research"
    ]));
    addPrerequisite("specialist mastery", ([
        "type":"any of",
        "prerequisites":({
            ([
                "/guilds/monk/unarmed/sapping-palm.c":([
                    "type":"research"
                ]),
                "/guilds/monk/unarmed/meridian-lore.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/unarmed/sapping-palm.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/katana/rising-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/katana/rising-lines.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/katana/rising-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/sweeping-arc.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/staff-economy.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/sweeping-arc.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/compact-blow.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/mace-recovery.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/compact-blow.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/falling-head.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/hammer-return.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/falling-head.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/pure-chi/driving-wave.c":([
                    "type":"research"
                ]),
                "/guilds/monk/pure-chi/pulse-cadence.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"research.use",
                        "research":"/guilds/monk/pure-chi/driving-wave.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/paired-swords/crossing-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/paired-swords/crossing-lines.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/paired-swords/crossing-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/odachi/horizon-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/odachi/horizon-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/odachi/horizon-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/archery/crosswind-shot.c":([
                    "type":"research"
                ]),
                "/guilds/monk/archery/crosswind-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/archery/crosswind-shot.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/kama/reaping-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/kama/reaping-lines.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/kama/reaping-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ]),
            ([
                "/guilds/monk/claw/crossing-rake.c":([
                    "type":"research"
                ]),
                "/guilds/monk/claw/crossing-talons.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/claw/crossing-rake.c",
                        "qualifying opponent":1
                    ]),
                    "value":20
                ])
            ])
        })
    ]));

    addSpecification("research type", "granted");
    addSpecification("teacher required", 1);
}
