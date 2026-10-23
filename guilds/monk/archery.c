//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("monastic archery");
    Description("Measured bow practice, controlled releases, and deliberate "
        "tradeoffs between accuracy, defense, and recovery.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/archery/root.c");
    TreeRoot("/guilds/monk/archery/root.c");
    mapping items = ([
        "archers-grip":"root",
        "archers-footing":"archers-grip",
        "archers-distance":"root",
        "archers-guard":"archers-footing",
        "draw-alignment":"archers-grip",
        "draw-recovery":"archers-guard",
        "draw-conditioning":"archers-footing",
        "archers-vitality":"draw-conditioning",
        "archers-sight":"archers-distance",
        "archers-composure":"archers-guard",
        "archers-endurance":"draw-recovery",
        "archers-mastery":"archers-composure",
        "measured-draw":"archers-grip",
        "arresting-shot":"archers-footing",
        "crosswind-shot":"archers-distance",
        "breath-piercing-shot":"draw-alignment",
        "burdening-shot":"bow-leverage",
        "descending-shot":"draw-alignment",
        "narrow-line-shot":"archers-sight",
        "returning-shot":"crosswind-geometry",
        "exhausting-shot":"archers-composure",
        "final-draw":"archers-mastery",
        "archers-recentering":"draw-recovery",
        "quieting-shot":"draw-pressure-theory",
        "draw-geometry":"measured-draw",
        "bow-leverage":"arresting-shot",
        "crosswind-geometry":"crosswind-shot",
        "bow-breath-theory":"breath-piercing-shot",
        "draw-pressure-theory":"burdening-shot",
        "falling-trajectory":"descending-shot",
        "point-of-release":"narrow-line-shot",
        "return-trajectory":"returning-shot",
        "final-trajectory":"final-draw",
        "draw-economy":"draw-geometry",
        "crosswind-rhythm":"crosswind-geometry",
        "final-draw-economy":"final-trajectory",
        "patient-draw":"archers-guard",
        "forward-draw":"draw-alignment",
        "mobile-draw":"archers-footing",
        "still-bow":"archers-mastery"
    ]);
    foreach(string item in m_indices(items))
    {
        addResearchElement("/guilds/monk/archery/" + item + ".c");
    }
    foreach(string item in m_indices(items))
    {
        addChild("/guilds/monk/archery/" + item + ".c",
            "/guilds/monk/archery/" + items[item] + ".c");
    }
}
