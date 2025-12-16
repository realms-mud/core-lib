//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/layered-assault.c");

    addChild("/guilds/oneiromancer/psionic-combinations/layered-assault.c",
        "/guilds/oneiromancer/psionic-combinations/combination-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/mental-momentum.c");

    addChild("/guilds/oneiromancer/psionic-combinations/mental-momentum.c",
        "/guilds/oneiromancer/psionic-combinations/layered-assault.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/triple-thread.c");
    addResearchElement("/guilds/oneiromancer/psionic-combinations/cascading-thoughts.c");

    addChild("/guilds/oneiromancer/psionic-combinations/triple-thread.c",
        "/guilds/oneiromancer/psionic-combinations/mental-momentum.c");
    addChild("/guilds/oneiromancer/psionic-combinations/cascading-thoughts.c",
        "/guilds/oneiromancer/psionic-combinations/mental-momentum.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/swift-nightmare.c");
    addResearchElement("/guilds/oneiromancer/psionic-combinations/amplified-horror.c");

    addChild("/guilds/oneiromancer/psionic-combinations/swift-nightmare.c",
        "/guilds/oneiromancer/psionic-combinations/cascading-thoughts.c");
    addChild("/guilds/oneiromancer/psionic-combinations/amplified-horror.c",
        "/guilds/oneiromancer/psionic-combinations/cascading-thoughts.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/woven-terror.c");

    addChild("/guilds/oneiromancer/psionic-combinations/woven-terror.c",
        "/guilds/oneiromancer/psionic-combinations/triple-thread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/quadruple-thread.c");
    addResearchElement("/guilds/oneiromancer/psionic-combinations/efficient-weaving.c");

    addChild("/guilds/oneiromancer/psionic-combinations/quadruple-thread.c",
        "/guilds/oneiromancer/psionic-combinations/woven-terror.c");
    addChild("/guilds/oneiromancer/psionic-combinations/efficient-weaving.c",
        "/guilds/oneiromancer/psionic-combinations/swift-nightmare.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/relentless-horror.c");
    addResearchElement("/guilds/oneiromancer/psionic-combinations/devastating-focus.c");

    addChild("/guilds/oneiromancer/psionic-combinations/relentless-horror.c",
        "/guilds/oneiromancer/psionic-combinations/efficient-weaving.c");
    addChild("/guilds/oneiromancer/psionic-combinations/devastating-focus.c",
        "/guilds/oneiromancer/psionic-combinations/amplified-horror.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/quintuple-thread.c");

    addChild("/guilds/oneiromancer/psionic-combinations/quintuple-thread.c",
        "/guilds/oneiromancer/psionic-combinations/quadruple-thread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/nightmare-mastery.c");
    addResearchElement("/guilds/oneiromancer/psionic-combinations/terror-weaver.c");

    addChild("/guilds/oneiromancer/psionic-combinations/nightmare-mastery.c",
        "/guilds/oneiromancer/psionic-combinations/devastating-focus.c");
    addChild("/guilds/oneiromancer/psionic-combinations/terror-weaver.c",
        "/guilds/oneiromancer/psionic-combinations/relentless-horror.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/sextuple-thread.c");

    addChild("/guilds/oneiromancer/psionic-combinations/sextuple-thread.c",
        "/guilds/oneiromancer/psionic-combinations/quintuple-thread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psionic-combinations/dream-lord.c");

    addChild("/guilds/oneiromancer/psionic-combinations/dream-lord.c",
        "/guilds/oneiromancer/psionic-combinations/nightmare-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Psionic Combinations");
    Description("This research tree provides knowledge of weaving multiple "
        "psionic techniques into devastating combination attacks. Master "
        "the art of layering mental assaults, dream imagery, and projection "
        "methods for maximum effect.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/psionic-combinations/combination-root.c");
    TreeRoot("/guilds/oneiromancer/psionic-combinations/combination-root.c");

    FifthLevel();
    NinthLevel();
    ThirteenthLevel();
    SeventeenthLevel();
    TwentyFirstLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
}
