//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/falling-terror.c");

    addChild("/guilds/oneiromancer/dream-imagery/falling-terror.c",
        "/guilds/oneiromancer/dream-imagery/imagery-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/grasping-tentacles.c");

    addChild("/guilds/oneiromancer/dream-imagery/grasping-tentacles.c",
        "/guilds/oneiromancer/dream-imagery/imagery-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/burning-alive.c");

    addChild("/guilds/oneiromancer/dream-imagery/burning-alive.c",
        "/guilds/oneiromancer/dream-imagery/falling-terror.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/lightning-strike.c");

    addChild("/guilds/oneiromancer/dream-imagery/lightning-strike.c",
        "/guilds/oneiromancer/dream-imagery/grasping-tentacles.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/dissolving-flesh.c");

    addChild("/guilds/oneiromancer/dream-imagery/dissolving-flesh.c",
        "/guilds/oneiromancer/dream-imagery/burning-alive.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/paralytic-dread.c");

    addChild("/guilds/oneiromancer/dream-imagery/paralytic-dread.c",
        "/guilds/oneiromancer/dream-imagery/lightning-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/teeth-crumbling.c");

    addChild("/guilds/oneiromancer/dream-imagery/teeth-crumbling.c",
        "/guilds/oneiromancer/dream-imagery/dissolving-flesh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/buried-alive.c");

    addChild("/guilds/oneiromancer/dream-imagery/buried-alive.c",
        "/guilds/oneiromancer/dream-imagery/paralytic-dread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/exposed-judged.c");

    addChild("/guilds/oneiromancer/dream-imagery/exposed-judged.c",
        "/guilds/oneiromancer/dream-imagery/teeth-crumbling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/endless-void.c");

    addChild("/guilds/oneiromancer/dream-imagery/endless-void.c",
        "/guilds/oneiromancer/dream-imagery/buried-alive.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/inescapable-maze.c");

    addChild("/guilds/oneiromancer/dream-imagery/inescapable-maze.c",
        "/guilds/oneiromancer/dream-imagery/exposed-judged.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/drowning-depths.c");

    addChild("/guilds/oneiromancer/dream-imagery/drowning-depths.c",
        "/guilds/oneiromancer/dream-imagery/endless-void.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/loved-ones-twisted.c");

    addChild("/guilds/oneiromancer/dream-imagery/loved-ones-twisted.c",
        "/guilds/oneiromancer/dream-imagery/inescapable-maze.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/frozen-wasteland.c");

    addChild("/guilds/oneiromancer/dream-imagery/frozen-wasteland.c",
        "/guilds/oneiromancer/dream-imagery/drowning-depths.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/forgotten-identity.c");

    addChild("/guilds/oneiromancer/dream-imagery/forgotten-identity.c",
        "/guilds/oneiromancer/dream-imagery/loved-ones-twisted.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/death-of-self.c");

    addChild("/guilds/oneiromancer/dream-imagery/death-of-self.c",
        "/guilds/oneiromancer/dream-imagery/frozen-wasteland.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/unraveling-reality.c");

    addChild("/guilds/oneiromancer/dream-imagery/unraveling-reality.c",
        "/guilds/oneiromancer/dream-imagery/forgotten-identity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/dream-imagery/nightmare-apocalypse.c");

    addChild("/guilds/oneiromancer/dream-imagery/nightmare-apocalypse.c",
        "/guilds/oneiromancer/dream-imagery/death-of-self.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Dream Imagery");
    Description("This research tree provides knowledge of weaving nightmare "
        "imagery into psionic attacks. These terrifying visions enhance "
        "combination attacks with additional damage types and debilitating "
        "effects drawn from the deepest fears of mortal minds.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/dream-imagery/imagery-root.c");
    TreeRoot("/guilds/oneiromancer/dream-imagery/imagery-root.c");

    FirstLevel();
    ThirdLevel();
    SeventhLevel();
    NinthLevel();
    ThirteenthLevel();
    FifteenthLevel();
    NineteenthLevel();
    TwentyThirdLevel();
    TwentySeventhLevel();
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtyNinthLevel();
    FortyThirdLevel();
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftyFifthLevel();
    FiftyNinthLevel();
    SixtySeventhLevel();
}
