//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("odachi discipline");
    Description("Committed heavy cuts, measured recovery, and costly "
        "defensive choices with an odachi.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/odachi/root.c");
    TreeRoot("/guilds/monk/odachi/root.c");
    mapping items = ([
        "longblade-grip":"root",
        "longblade-footing":"longblade-grip",
        "longblade-distance":"root",
        "longblade-guard":"longblade-footing",
        "longblade-alignment":"longblade-grip",
        "longblade-recovery":"longblade-guard",
        "longblade-conditioning":"longblade-footing",
        "longblade-vitality":"longblade-conditioning",
        "longblade-sight":"longblade-distance",
        "longblade-composure":"longblade-guard",
        "longblade-endurance":"longblade-recovery",
        "longblade-mastery":"longblade-composure",
        "committed-cut":"longblade-grip",
        "pommel-drive":"longblade-footing",
        "horizon-cut":"longblade-distance",
        "breath-cleaver":"longblade-alignment",
        "weight-check":"heavy-leverage",
        "descending-arc":"longblade-alignment",
        "long-point":"longblade-sight",
        "returning-arc":"horizon-geometry",
        "heavy-rebuke":"longblade-composure",
        "final-horizon":"longblade-mastery",
        "longblade-recentering":"longblade-recovery",
        "stilling-arc":"longblade-pressure-theory",
        "commitment-theory":"committed-cut",
        "horizon-geometry":"horizon-cut",
        "heavy-leverage":"pommel-drive",
        "longblade-breath-theory":"breath-cleaver",
        "longblade-pressure-theory":"weight-check",
        "longblade-descent-theory":"descending-arc",
        "longblade-point-theory":"long-point",
        "longblade-return-theory":"returning-arc",
        "longblade-final-theory":"final-horizon",
        "longblade-economy":"commitment-theory",
        "horizon-rhythm":"horizon-geometry",
        "final-horizon-economy":"longblade-final-theory",
        "horizon-guard":"longblade-guard",
        "weight-forward":"longblade-alignment",
        "rooted-horizon":"longblade-footing",
        "longblade-stillness":"longblade-mastery"
    ]);
    foreach(string item in m_indices(items))
    {
        addResearchElement("/guilds/monk/odachi/" + item + ".c");
    }
    foreach(string item in m_indices(items))
    {
        addChild("/guilds/monk/odachi/" + item + ".c",
            "/guilds/monk/odachi/" + items[item] + ".c");
    }
}
