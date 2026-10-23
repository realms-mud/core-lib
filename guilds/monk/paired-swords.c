//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("paired sword discipline");
    Description("Coordinate a primary katana and offhand wakizashi without "
        "multiplying ordinary attacks.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/paired-swords/root.c");
    TreeRoot("/guilds/monk/paired-swords/root.c");
    mapping items = ([
        "paired-grip":"root",
        "companion-grip":"paired-grip",
        "paired-distance":"root",
        "paired-guard":"companion-grip",
        "paired-footwork":"paired-distance",
        "paired-recovery":"paired-guard",
        "paired-pressure":"paired-grip",
        "paired-vitality":"paired-recovery",
        "paired-readiness":"paired-footwork",
        "paired-composure":"paired-guard",
        "paired-vigor":"paired-vitality",
        "paired-mastery":"paired-composure",
        "linked-cut":"paired-grip",
        "companion-check":"companion-grip",
        "crossing-cut":"paired-guard",
        "breath-shear":"paired-pressure",
        "blade-bind":"companion-leverage",
        "opening-cut":"crossing-lines",
        "companion-thrust":"paired-footwork",
        "alternating-cut":"paired-pressure",
        "returning-cut":"crossing-cut",
        "close-circle":"paired-readiness",
        "twin-edge":"paired-mastery",
        "paired-recentering":"paired-recovery",
        "linked-lines":"linked-cut",
        "companion-leverage":"companion-check",
        "crossing-lines":"crossing-cut",
        "paired-breath-theory":"breath-shear",
        "binding-lines":"blade-bind",
        "opening-geometry":"opening-cut",
        "paired-point-theory":"companion-thrust",
        "alternating-lines":"alternating-cut",
        "paired-breath-economy":"breath-shear",
        "paired-opening-economy":"opening-geometry",
        "paired-return-rhythm":"returning-cut",
        "twin-edge-theory":"twin-edge",
        "paired-high-guard":"paired-guard",
        "paired-forward-guard":"paired-pressure",
        "paired-flow":"paired-footwork",
        "paired-stillness":"paired-mastery"
    ]);
    foreach(string item in m_indices(items))
    {
        addResearchElement("/guilds/monk/paired-swords/" + item + ".c");
    }
    foreach(string item in m_indices(items))
    {
        addChild("/guilds/monk/paired-swords/" + item + ".c",
            "/guilds/monk/paired-swords/" + items[item] + ".c");
    }
}
