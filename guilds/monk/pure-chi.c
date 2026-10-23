//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("pure chi");
    Description("Forty lessons in spell-point chi: precision and healing "
        "foundations, circulation, resonance, and unified mastery. Knowledge "
        "opens branches and modifies abilities; sustained channels reserve "
        "the existing spell-point pool.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/pure-chi/root.c");
    addResearchElement("/guilds/monk/pure-chi/focused-pulse.c");
    TreeRoot("/guilds/monk/pure-chi/root.c");
    addChild("/guilds/monk/pure-chi/focused-pulse.c",
        "/guilds/monk/pure-chi/root.c");
    mapping lessons = ([
        "chi-anatomy":"focused-pulse",
        "economical-breath":"chi-anatomy",
        "pulse-geometry":"chi-anatomy",
        "essence-sensitivity":"chi-anatomy",
        "contemplative-focus":"chi-anatomy",
        "reservoir-discipline":"economical-breath",
        "restorative-breath":"chi-anatomy",
        "flowing-current":"essence-sensitivity",
        "needle-of-chi":"chi-anatomy",
        "circulation-theory":"restorative-breath",
        "measured-expenditure":"economical-breath",
        "pulse-cadence":"pulse-geometry",
        "mental-abacus":"pulse-cadence",
        "essence-weaving":"essence-sensitivity",
        "replenishing-stillness":"circulation-theory",
        "driving-wave":"pulse-cadence",
        "cleansing-breath":"circulation-theory",
        "concentrated-channel":"flowing-current",
        "returning-current":"circulation-theory",
        "resonance-theory":"driving-wave",
        "quiet-intervals":"circulation-theory",
        "channel-economy":"measured-expenditure",
        "inward-listening":"contemplative-focus",
        "etheric-poise":"resonance-theory",
        "deep-recollection":"replenishing-stillness",
        "heart-mending":"quiet-intervals",
        "piercing-intent":"resonance-theory",
        "balanced-circulation":"returning-current",
        "centered-release":"resonance-theory",
        "unified-current":"centered-release",
        "stillness-between-pulses":"pulse-cadence",
        "perfect-economy":"channel-economy",
        "lucid-mind":"perfect-economy",
        "unfettered-flow":"deep-recollection",
        "spirit-anchor":"etheric-poise",
        "renewal-of-self":"heart-mending",
        "severing-current":"piercing-intent",
        "boundless-focus":"essence-weaving",
        "silent-thunder":"unified-current"
    ]);
    foreach (string lesson in m_indices(lessons))
    {
        addResearchElement("/guilds/monk/pure-chi/" + lesson + ".c");
    }
    foreach (string lesson in m_indices(lessons))
    {
        addChild("/guilds/monk/pure-chi/" + lesson + ".c",
            "/guilds/monk/pure-chi/" + lessons[lesson] + ".c");
    }
}
