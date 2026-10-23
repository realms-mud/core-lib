//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("claw discipline");
    Description("Close thrusts, agile guards, and deliberate recovery "
        "with tiger claws. These are weapon techniques, not natural attacks.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/claw/root.c");
    TreeRoot("/guilds/monk/claw/root.c");
    mapping items = ([
        "claw-grip":"root",
        "claw-footwork":"claw-grip",
        "claw-distance":"root",
        "claw-guard":"claw-footwork",
        "claw-alignment":"claw-grip",
        "claw-recovery":"claw-guard",
        "claw-conditioning":"claw-footwork",
        "claw-vitality":"claw-conditioning",
        "claw-readiness":"claw-distance",
        "claw-composure":"claw-guard",
        "claw-endurance":"claw-recovery",
        "claw-mastery":"claw-composure",
        "measured-rake":"claw-grip",
        "claw-check":"claw-footwork",
        "crossing-rake":"claw-alignment",
        "breath-rake":"claw-alignment",
        "gripping-rake":"claw-leverage",
        "rising-talon":"crossing-talons",
        "talon-point":"claw-readiness",
        "returning-rake":"crossing-rake",
        "tiring-rake":"claw-composure",
        "final-rake":"claw-mastery",
        "claw-recentering":"claw-recovery",
        "quiet-rake":"grip-geometry",
        "rake-geometry":"measured-rake",
        "claw-leverage":"claw-check",
        "crossing-talons":"crossing-rake",
        "claw-breath-theory":"breath-rake",
        "grip-geometry":"gripping-rake",
        "rising-talon-theory":"rising-talon",
        "talon-point-theory":"talon-point",
        "rake-return-theory":"returning-rake",
        "final-rake-theory":"final-rake",
        "rake-economy":"rake-geometry",
        "crossing-rhythm":"crossing-talons",
        "final-rake-economy":"final-rake-theory",
        "claw-shelter":"claw-footwork",
        "forward-talon":"claw-alignment",
        "circling-talon":"claw-footwork",
        "patient-claw":"claw-mastery"
    ]);
    foreach(string item in m_indices(items))
    {
        addResearchElement("/guilds/monk/claw/" + item + ".c");
    }
    foreach(string item in m_indices(items))
    {
        addChild("/guilds/monk/claw/" + item + ".c",
            "/guilds/monk/claw/" + items[item] + ".c");
    }
}
