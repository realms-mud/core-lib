//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef MonkMasteryTrial
#define MonkMasteryTrial

protected void monkMasteryTrial(string name, int level, int count,
    string foundation, string **routes)
{
    string *ranks = ({ "adept", "senior disciple", "master candidate",
        "master" });
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addPrerequisite("level",
        ([ "type":"level", "guild":"monk", "value":level ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":ranks[(level - 20) / 5..]
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c",
        ([ "type":"research" ]));
    addPrerequisite("/guilds/monk/discipline/" + foundation + ".c",
        ([ "type":"research" ]));

    mapping *alternatives = ({});
    foreach(string *route in routes)
    {
        string prefix = "/guilds/monk/" + route[0] + "/";
        string technique = prefix + route[1] + ".c";
        alternatives += ({ ([
            technique:([ "type":"research" ]),
            prefix + route[2] + ".c":([ "type":"research" ]),
            "qualifying practice":([
                "type":"observation",
                "criteria":([
                    "type":route[0] == "pure-chi" ?
                        "research.use" : "combat.kata",
                    "research":technique,
                    "qualifying opponent":1
                ]),
                "value":count
            ])
        ]) });
    }
    addPrerequisite("specialist mastery", ([
        "type":"any of",
        "prerequisites":alternatives
    ]));
    addSpecification("name", name);
    addSpecification("description", sprintf("Ren assesses advanced "
        "specialist practice before endorsing your next promotion. Learn "
        "one listed technique and its matching knowledge, and demonstrate "
        "%d qualifying uses of that technique against already-hostile, "
        "non-allied living NPCs in the same room at least half your "
        "effective level. Historical practice counts; partial counts and "
        "knowledge from other routes do not combine. This free assessment "
        "grants no combat bonus or automatic promotion.", count));
    addSpecification("source", "monk");
    addSpecification("research type", "granted");
    addSpecification("teacher required", 1);
}
#endif
