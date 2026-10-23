//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("kama discipline");
    Description("Measured sickle cuts, tiring hooks, and guarded recovery "
        "with the kama. Hooking techniques do not immobilize opponents.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/kama/root.c");
    TreeRoot("/guilds/monk/kama/root.c");
    mapping items = ([
        "hooked-grip":"root",
        "sickle-footing":"hooked-grip",
        "sickle-distance":"root",
        "sickle-guard":"sickle-footing",
        "hook-alignment":"hooked-grip",
        "hook-recovery":"sickle-guard",
        "sickle-conditioning":"sickle-footing",
        "sickle-vitality":"sickle-conditioning",
        "sickle-readiness":"sickle-distance",
        "sickle-composure":"sickle-guard",
        "sickle-endurance":"hook-recovery",
        "sickle-mastery":"sickle-composure",
        "measured-hook":"hooked-grip",
        "sickle-check":"sickle-footing",
        "reaping-cut":"hook-alignment",
        "breath-hook":"hook-alignment",
        "binding-hook":"sickle-leverage",
        "crescent-reap":"reaping-lines",
        "sickle-point":"sickle-readiness",
        "returning-hook":"reaping-cut",
        "tiring-reap":"sickle-composure",
        "final-reap":"sickle-mastery",
        "sickle-recentering":"hook-recovery",
        "quiet-hook":"binding-geometry",
        "hook-geometry":"measured-hook",
        "sickle-leverage":"sickle-check",
        "reaping-lines":"reaping-cut",
        "hook-breath-theory":"breath-hook",
        "binding-geometry":"binding-hook",
        "crescent-geometry":"crescent-reap",
        "sickle-point-theory":"sickle-point",
        "hook-return-theory":"returning-hook",
        "final-reap-theory":"final-reap",
        "hook-economy":"hook-geometry",
        "reaping-rhythm":"reaping-lines",
        "final-reap-economy":"final-reap-theory",
        "sickle-ward":"sickle-guard",
        "hook-forward":"hook-alignment",
        "sickle-flow":"sickle-footing",
        "patient-sickle":"sickle-mastery"
    ]);
    foreach(string item in m_indices(items))
    {
        addResearchElement("/guilds/monk/kama/" + item + ".c");
    }
    foreach(string item in m_indices(items))
    {
        addChild("/guilds/monk/kama/" + item + ".c",
            "/guilds/monk/kama/" + items[item] + ".c");
    }
}
