//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("mana shield mechanics");
    Description("Forty lessons in ward-dependent defense, recovery, "
        "resource efficiency, and deliberate counterprojections. Foundation, "
        "development, advanced practice, and mastery preserve the existing "
        "Mindful Ward absorption mechanics without another shield layer.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/mana-shield/root.c");
    addResearchElement("/guilds/monk/mana-shield/mindful-ward.c");
    TreeRoot("/guilds/monk/mana-shield/root.c");
    addChild("/guilds/monk/mana-shield/mindful-ward.c",
        "/guilds/monk/mana-shield/root.c");
    mapping lessons = ([
        "ward-anatomy":"mindful-ward",
        "recovery-cycle":"ward-anatomy",
        "guarded-breath":"ward-anatomy",
        "ward-listening":"ward-anatomy",
        "soft-boundary":"ward-anatomy",
        "recovery-habit":"recovery-cycle",
        "ward-mending":"ward-anatomy",
        "breath-conversion":"recovery-cycle",
        "sentry-focus":"ward-anatomy",
        "refuge-theory":"sentry-focus",
        "defensive-timing":"recovery-cycle",
        "economical-refuge":"guarded-breath",
        "stable-footing":"soft-boundary",
        "still-water":"recovery-habit",
        "mindful-casting":"economical-refuge",
        "brace-the-spirit":"refuge-theory",
        "deflecting-palm":"refuge-theory",
        "measured-renewal":"breath-conversion",
        "refuge-posture":"refuge-theory",
        "disruption-theory":"deflecting-palm",
        "renewing-rhythm":"defensive-timing",
        "ward-triage":"ward-mending",
        "intent-reading":"ward-listening",
        "tempered-nerves":"refuge-theory",
        "restorative-watch":"renewing-rhythm",
        "interrupting-thread":"disruption-theory",
        "sheltering-touch":"ward-triage",
        "ward-counterpulse":"disruption-theory",
        "inner-refuge":"restorative-watch",
        "lucid-refuge":"ward-counterpulse",
        "seamless-recovery":"renewing-rhythm",
        "conservation-of-motion":"economical-refuge",
        "imperturbable-center":"tempered-nerves",
        "elastic-defense":"stable-footing",
        "quiet-vigil":"restorative-watch",
        "vigilant-renewal":"measured-renewal",
        "stillpoint-rebuke":"interrupting-thread",
        "shelter-of-intent":"lucid-refuge",
        "sentinel-meditation":"elastic-defense"
    ]);
    foreach (string lesson in m_indices(lessons))
    {
        addResearchElement("/guilds/monk/mana-shield/" + lesson + ".c");
    }
    foreach (string lesson in m_indices(lessons))
    {
        addChild("/guilds/monk/mana-shield/" + lesson + ".c",
            "/guilds/monk/mana-shield/" + lessons[lesson] + ".c");
    }
}
