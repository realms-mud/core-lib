//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/mind-spike.c");
    addResearchElement("/guilds/oneiromancer/psionic-focus/psychic-lash.c");

    addChild("/guilds/oneiromancer/psionic-focus/mind-spike.c",
        "/guilds/oneiromancer/psionic-focus/focus-root.c");
    addChild("/guilds/oneiromancer/psionic-focus/psychic-lash.c",
        "/guilds/oneiromancer/psionic-focus/focus-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/focused-intent.c");

    addChild("/guilds/oneiromancer/psionic-focus/focused-intent.c",
        "/guilds/oneiromancer/psionic-focus/mind-spike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/thought-crush.c");

    addChild("/guilds/oneiromancer/psionic-focus/thought-crush.c",
        "/guilds/oneiromancer/psionic-focus/mind-spike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/neural-sever.c");

    addChild("/guilds/oneiromancer/psionic-focus/neural-sever.c",
        "/guilds/oneiromancer/psionic-focus/psychic-lash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/penetrating-thought.c");

    addChild("/guilds/oneiromancer/psionic-focus/penetrating-thought.c",
        "/guilds/oneiromancer/psionic-focus/focused-intent.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/ego-rend.c");

    addChild("/guilds/oneiromancer/psionic-focus/ego-rend.c",
        "/guilds/oneiromancer/psionic-focus/thought-crush.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/dream-fang.c");

    addChild("/guilds/oneiromancer/psionic-focus/dream-fang.c",
        "/guilds/oneiromancer/psionic-focus/neural-sever.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/ruthless-precision.c");

    addChild("/guilds/oneiromancer/psionic-focus/ruthless-precision.c",
        "/guilds/oneiromancer/psionic-focus/neural-sever.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/memory-shatter.c");

    addChild("/guilds/oneiromancer/psionic-focus/memory-shatter.c",
        "/guilds/oneiromancer/psionic-focus/ego-rend.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/overwhelming-presence.c");

    addChild("/guilds/oneiromancer/psionic-focus/overwhelming-presence.c",
        "/guilds/oneiromancer/psionic-focus/ego-rend.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/cognitive-fracture.c");

    addChild("/guilds/oneiromancer/psionic-focus/cognitive-fracture.c",
        "/guilds/oneiromancer/psionic-focus/dream-fang.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/nightmare-affinity.c");

    addChild("/guilds/oneiromancer/psionic-focus/nightmare-affinity.c",
        "/guilds/oneiromancer/psionic-focus/ruthless-precision.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/will-breaker.c");

    addChild("/guilds/oneiromancer/psionic-focus/will-breaker.c",
        "/guilds/oneiromancer/psionic-focus/memory-shatter.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/sanity-erosion.c");

    addChild("/guilds/oneiromancer/psionic-focus/sanity-erosion.c",
        "/guilds/oneiromancer/psionic-focus/cognitive-fracture.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/cognitive-mastery.c");

    addChild("/guilds/oneiromancer/psionic-focus/cognitive-mastery.c",
        "/guilds/oneiromancer/psionic-focus/overwhelming-presence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/perception-warp.c");

    addChild("/guilds/oneiromancer/psionic-focus/perception-warp.c",
        "/guilds/oneiromancer/psionic-focus/will-breaker.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/existential-dread.c");

    addChild("/guilds/oneiromancer/psionic-focus/existential-dread.c",
        "/guilds/oneiromancer/psionic-focus/sanity-erosion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/existential-insight.c");

    addChild("/guilds/oneiromancer/psionic-focus/existential-insight.c",
        "/guilds/oneiromancer/psionic-focus/nightmare-affinity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/nightmare-fist.c");

    addChild("/guilds/oneiromancer/psionic-focus/nightmare-fist.c",
        "/guilds/oneiromancer/psionic-focus/perception-warp.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/psychic-scream.c");

    addChild("/guilds/oneiromancer/psionic-focus/psychic-scream.c",
        "/guilds/oneiromancer/psionic-focus/existential-dread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/psychic-resonance.c");

    addChild("/guilds/oneiromancer/psionic-focus/psychic-resonance.c",
        "/guilds/oneiromancer/psionic-focus/cognitive-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/soul-flense.c");

    addChild("/guilds/oneiromancer/psionic-focus/soul-flense.c",
        "/guilds/oneiromancer/psionic-focus/nightmare-fist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/mind-annihilation.c");

    addChild("/guilds/oneiromancer/psionic-focus/mind-annihilation.c",
        "/guilds/oneiromancer/psionic-focus/psychic-scream.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/annihilating-will.c");

    addChild("/guilds/oneiromancer/psionic-focus/annihilating-will.c",
        "/guilds/oneiromancer/psionic-focus/existential-insight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/dream-eater.c");

    addChild("/guilds/oneiromancer/psionic-focus/dream-eater.c",
        "/guilds/oneiromancer/psionic-focus/soul-flense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/void-thought.c");

    addChild("/guilds/oneiromancer/psionic-focus/void-thought.c",
        "/guilds/oneiromancer/psionic-focus/mind-annihilation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-focus/void-mastery.c");

    addChild("/guilds/oneiromancer/psionic-focus/void-mastery.c",
        "/guilds/oneiromancer/psionic-focus/annihilating-will.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Psionic Focus");
    Description("This research tree provides knowledge of focusing psychic "
        "energy into offensive mental attacks. These techniques form the "
        "foundation of psionic combat and can be used alone or combined "
        "with dream imagery and projection methods.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/psionic-focus/focus-root.c");
    TreeRoot("/guilds/oneiromancer/psionic-focus/focus-root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    EighthLevel();
    NinthLevel();
    EleventhLevel();
    TwelfthLevel();
    ThirteenthLevel();
    FourteenthLevel();
    FifteenthLevel();
    SixteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentiethLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFourthLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyEighthLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtySecondLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySixthLevel();
}
