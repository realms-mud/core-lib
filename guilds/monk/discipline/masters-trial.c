//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master's Trial");
    addSpecification("source", "monk");
    addSpecification("description",
        "Ren assesses advanced specialist practice before endorsing your "
        "next promotion. Learn one listed technique and its matching "
        "knowledge, and demonstrate 40 qualifying uses of that technique "
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
        "value":70
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/discipline/mastery-of-fundamentals.c", ([
        "type":"research"
    ]));
    addPrerequisite("specialist mastery", ([
        "type":"any of",
        "prerequisites":({
            ([
                "/guilds/monk/unarmed/empty-hand.c":([
                    "type":"research"
                ]),
                "/guilds/monk/unarmed/empty-hand-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/unarmed/empty-hand.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/katana/decisive-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/katana/decisive-angle.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/katana/decisive-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/pressing-shaft.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/long-reach-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/pressing-shaft.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/taxing-contact.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/contact-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/taxing-contact.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/bludgeon/burdening-blow.c":([
                    "type":"research"
                ]),
                "/guilds/monk/bludgeon/anvil-geometry.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/bludgeon/burdening-blow.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/pure-chi/centered-release.c":([
                    "type":"research"
                ]),
                "/guilds/monk/pure-chi/resonance-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"research.use",
                        "research":"/guilds/monk/pure-chi/centered-release.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/paired-swords/returning-cut.c":([
                    "type":"research"
                ]),
                "/guilds/monk/paired-swords/paired-return-rhythm.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/paired-swords/returning-cut.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/odachi/returning-arc.c":([
                    "type":"research"
                ]),
                "/guilds/monk/odachi/longblade-return-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/odachi/returning-arc.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/archery/returning-shot.c":([
                    "type":"research"
                ]),
                "/guilds/monk/archery/return-trajectory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/archery/returning-shot.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/kama/returning-hook.c":([
                    "type":"research"
                ]),
                "/guilds/monk/kama/hook-return-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/kama/returning-hook.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ]),
            ([
                "/guilds/monk/claw/returning-rake.c":([
                    "type":"research"
                ]),
                "/guilds/monk/claw/rake-return-theory.c":([
                    "type":"research"
                ]),
                "qualifying practice":([
                    "type":"observation",
                    "criteria":([
                        "type":"combat.kata",
                        "research":"/guilds/monk/claw/returning-rake.c",
                        "qualifying opponent":1
                    ]),
                    "value":40
                ])
            ])
        })
    ]));

    addSpecification("research type", "granted");
    addSpecification("teacher required", 1);
}
