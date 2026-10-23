//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    if (guildName() == "BaseGuild")
    {
        guildName("monk");
        guildClass("combat");
        addPreferredSkillType("combat");

        addRank("initiate", ([
            "name":"initiate",
            "title":"the Monk",
            "pretitle":"Initiate",
            "next rank":"student"
        ]));
        addRank("student", ([
            "name":"student",
            "title":"the Monk",
            "pretitle":"Student",
            "previous rank":"initiate",
            "next rank":"disciple"
        ]));
        addRank("disciple", ([
            "name":"disciple",
            "title":"the Monk",
            "pretitle":"Disciple",
            "previous rank":"student",
            "next rank":"adept"
        ]));
        addRank("adept", ([
            "name":"adept",
            "title":"the Monk",
            "pretitle":"Adept",
            "previous rank":"disciple",
            "next rank":"senior disciple"
        ]));
        addRank("senior disciple", ([
            "name":"senior disciple",
            "title":"the Monk",
            "pretitle":"Senior Disciple",
            "previous rank":"adept",
            "next rank":"master candidate"
        ]));
        addRank("master candidate", ([
            "name":"master candidate",
            "title":"the Monk",
            "pretitle":"Master Candidate",
            "previous rank":"senior disciple",
            "next rank":"master"
        ]));
        addRank("master", ([
            "name":"master",
            "title":"the Monk",
            "pretitle":"Master",
            "previous rank":"master candidate"
        ]));
        setDefaultRank("initiate");

        addRankPrerequisite("student", ([
            "level":([ "type":"level", "guild":"monk", "value":5 ]),
            "/guilds/monk/discipline/disciplined-breath.c":([
                "type":"research"
            ])
        ]));
        addRankPrerequisite("disciple", ([
            "level":([ "type":"level", "guild":"monk", "value":10 ]),
            "/guilds/monk/discipline/students-awareness.c":([
                "type":"research"
            ])
        ]));
        addRankPrerequisite("adept", ([
            "level":([ "type":"level", "guild":"monk", "value":15 ]),
            "/guilds/monk/discipline/disciples-insight.c":([
                "type":"research"
            ]),
            "/guilds/monk/discipline/adepts-trial.c":([
                "type":"research"
            ])
        ]));
        addRankPrerequisite("senior disciple", ([
            "level":([ "type":"level", "guild":"monk", "value":20 ]),
            "/guilds/monk/discipline/adepts-focus.c":([
                "type":"research"
            ]),
            "/guilds/monk/discipline/senior-disciples-trial.c":([
                "type":"research"
            ])
        ]));
        addRankPrerequisite("master candidate", ([
            "level":([ "type":"level", "guild":"monk", "value":25 ]),
            "/guilds/monk/discipline/inner-discipline.c":([
                "type":"research"
            ]),
            "/guilds/monk/discipline/master-candidates-trial.c":([
                "type":"research"
            ])
        ]));
        addRankPrerequisite("master", ([
            "level":([ "type":"level", "guild":"monk", "value":30 ]),
            "/guilds/monk/discipline/mastery-of-fundamentals.c":([
                "type":"research"
            ]),
            "/guilds/monk/discipline/masters-trial.c":([
                "type":"research"
            ])
        ]));

        addCriteria("hit points", ([
            "type":"modifier",
            "apply":"4 every level"
        ]));
        addCriteria("spell points", ([
            "type":"modifier",
            "apply":"3 every level"
        ]));
        addCriteria("stamina points", ([
            "type":"modifier",
            "apply":"3 every level"
        ]));
        addCriteria("weapon attack", ([
            "type":"attack",
            "apply":"1 every 15 levels"
        ]));
        addCriteria("attribute points", ([
            "type":"attribute points",
            "apply":"1 every 5 levels"
        ]));
        addCriteria("skill points", ([
            "type":"skill points",
            "apply":"5 every level"
        ]));
        addCriteria("initial research points", ([
            "type":"research points",
            "apply":"5 every level",
            "end at level":1
        ]));
        addCriteria("research points", ([
            "type":"research points",
            "apply":"1 every level"
        ]));
        addCriteria("discipline", ([
            "type":"research tree",
            "apply":"at level 1",
            "research tree":"/guilds/monk/discipline.c"
        ]));
        addCriteria("unarmed discipline", ([
            "type":"research tree",
            "apply":"at level 5",
            "research tree":"/guilds/monk/unarmed.c"
        ]));
        addCriteria("katana discipline", ([
            "type":"research tree",
            "apply":"at level 5",
            "research tree":"/guilds/monk/katana.c"
        ]));
        addCriteria("pure chi", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/pure-chi.c"
        ]));
        addCriteria("mana shield mechanics", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/mana-shield.c"
        ]));
        addCriteria("bludgeon discipline", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/bludgeon.c"
        ]));
        addCriteria("paired sword discipline", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/paired-swords.c"
        ]));
        addCriteria("odachi discipline", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/odachi.c"
        ]));
        addCriteria("monastic archery", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/archery.c"
        ]));
        addCriteria("kama discipline", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/kama.c"
        ]));
        addCriteria("claw discipline", ([
            "type":"research tree",
            "apply":"at level 10",
            "research tree":"/guilds/monk/claw.c"
        ]));
    }
}
