//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("katana discipline");
    Description("Deliberate katana cuts and control of the recovering blade.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/katana/root.c");
    addResearchElement("/guilds/monk/katana/measured-cut.c");
    addResearchElement("/guilds/monk/katana/settled-edge.c");
    TreeRoot("/guilds/monk/katana/root.c");
    addChild("/guilds/monk/katana/measured-cut.c",
        "/guilds/monk/katana/root.c");
    addChild("/guilds/monk/katana/settled-edge.c",
        "/guilds/monk/katana/measured-cut.c");
    mapping additions = ([
        "grip-discipline":"measured-cut",
        "blade-awareness":"measured-cut",
        "guard-lines":"grip-discipline",
        "quiet-draw":"blade-awareness",
        "traveling-guard":"guard-lines",
        "rooted-cut":"grip-discipline",
        "measured-distance":"blade-awareness",
        "resilient-grip":"rooted-cut",
        "unwavering-eye":"settled-edge",
        "polished-defense":"traveling-guard",
        "tempered-resolve":"resilient-grip",
        "master-balance":"measured-distance",
        "quick-draw":"grip-discipline",
        "hilt-check":"guard-lines",
        "rising-cut":"quiet-draw",
        "descending-cut":"rooted-cut",
        "breath-cut":"unwavering-eye",
        "drawn-circle":"rising-cut",
        "guard-breaker":"hilt-leverage",
        "needle-thrust":"measured-distance",
        "decisive-cut":"descending-lines",
        "silent-edge":"master-balance",
        "draw-theory":"quick-draw",
        "hilt-leverage":"hilt-check",
        "rising-lines":"rising-cut",
        "descending-lines":"descending-cut",
        "breath-timing":"breath-cut",
        "circular-mechanics":"drawn-circle",
        "guard-pressure":"guard-breaker",
        "point-alignment":"needle-thrust",
        "decisive-angle":"decisive-cut",
        "draw-economy":"draw-theory",
        "decisive-rhythm":"decisive-angle",
        "silent-economy":"silent-edge",
        "high-guard":"guard-lines",
        "forward-guard":"quiet-draw",
        "low-guard":"traveling-guard",
        "still-edge":"unwavering-eye"
    ]);
    foreach(string item in m_indices(additions))
    {
        addResearchElement("/guilds/monk/katana/" + item + ".c");
    }
    foreach(string item in m_indices(additions))
    {
        addChild("/guilds/monk/katana/" + item + ".c",
            "/guilds/monk/katana/" + additions[item] + ".c");
    }
}
