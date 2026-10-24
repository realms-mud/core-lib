//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/katana/measured-cut.c");
    addChild("/guilds/monk/katana/measured-cut.c",
        "/guilds/monk/katana/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/katana/grip-discipline.c");
    addChild("/guilds/monk/katana/grip-discipline.c",
        "/guilds/monk/katana/measured-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/katana/blade-awareness.c");
    addChild("/guilds/monk/katana/blade-awareness.c",
        "/guilds/monk/katana/measured-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/katana/guard-lines.c");
    addChild("/guilds/monk/katana/guard-lines.c",
        "/guilds/monk/katana/grip-discipline.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/katana/quick-draw.c");
    addChild("/guilds/monk/katana/quick-draw.c",
        "/guilds/monk/katana/grip-discipline.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/katana/settled-edge.c");
    addChild("/guilds/monk/katana/settled-edge.c",
        "/guilds/monk/katana/measured-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/katana/draw-theory.c");
    addChild("/guilds/monk/katana/draw-theory.c",
        "/guilds/monk/katana/quick-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/katana/quiet-draw.c");
    addChild("/guilds/monk/katana/quiet-draw.c",
        "/guilds/monk/katana/blade-awareness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/katana/hilt-check.c");
    addChild("/guilds/monk/katana/hilt-check.c",
        "/guilds/monk/katana/guard-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/katana/hilt-leverage.c");
    addChild("/guilds/monk/katana/hilt-leverage.c",
        "/guilds/monk/katana/hilt-check.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/katana/high-guard.c");
    addChild("/guilds/monk/katana/high-guard.c",
        "/guilds/monk/katana/guard-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/katana/rooted-cut.c");
    addChild("/guilds/monk/katana/rooted-cut.c",
        "/guilds/monk/katana/grip-discipline.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/katana/rising-cut.c");
    addChild("/guilds/monk/katana/rising-cut.c",
        "/guilds/monk/katana/quiet-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/katana/rising-lines.c");
    addChild("/guilds/monk/katana/rising-lines.c",
        "/guilds/monk/katana/rising-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/katana/traveling-guard.c");
    addChild("/guilds/monk/katana/traveling-guard.c",
        "/guilds/monk/katana/guard-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/katana/measured-distance.c");
    addChild("/guilds/monk/katana/measured-distance.c",
        "/guilds/monk/katana/blade-awareness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/katana/resilient-grip.c");
    addChild("/guilds/monk/katana/resilient-grip.c",
        "/guilds/monk/katana/rooted-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/katana/descending-cut.c");
    addChild("/guilds/monk/katana/descending-cut.c",
        "/guilds/monk/katana/rooted-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/katana/descending-lines.c");
    addChild("/guilds/monk/katana/descending-lines.c",
        "/guilds/monk/katana/descending-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/katana/draw-economy.c");
    addChild("/guilds/monk/katana/draw-economy.c",
        "/guilds/monk/katana/draw-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/katana/forward-guard.c");
    addChild("/guilds/monk/katana/forward-guard.c",
        "/guilds/monk/katana/quiet-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/katana/unwavering-eye.c");
    addChild("/guilds/monk/katana/unwavering-eye.c",
        "/guilds/monk/katana/settled-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/katana/breath-cut.c");
    addChild("/guilds/monk/katana/breath-cut.c",
        "/guilds/monk/katana/unwavering-eye.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/katana/breath-timing.c");
    addChild("/guilds/monk/katana/breath-timing.c",
        "/guilds/monk/katana/breath-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/katana/drawn-circle.c");
    addChild("/guilds/monk/katana/drawn-circle.c",
        "/guilds/monk/katana/rising-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/katana/circular-mechanics.c");
    addChild("/guilds/monk/katana/circular-mechanics.c",
        "/guilds/monk/katana/drawn-circle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/katana/guard-breaker.c");
    addChild("/guilds/monk/katana/guard-breaker.c",
        "/guilds/monk/katana/hilt-leverage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/katana/guard-pressure.c");
    addChild("/guilds/monk/katana/guard-pressure.c",
        "/guilds/monk/katana/guard-breaker.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/katana/low-guard.c");
    addChild("/guilds/monk/katana/low-guard.c",
        "/guilds/monk/katana/traveling-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/katana/needle-thrust.c");
    addChild("/guilds/monk/katana/needle-thrust.c",
        "/guilds/monk/katana/measured-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/katana/point-alignment.c");
    addChild("/guilds/monk/katana/point-alignment.c",
        "/guilds/monk/katana/needle-thrust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/katana/polished-defense.c");
    addChild("/guilds/monk/katana/polished-defense.c",
        "/guilds/monk/katana/traveling-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/katana/decisive-cut.c");
    addChild("/guilds/monk/katana/decisive-cut.c",
        "/guilds/monk/katana/descending-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/katana/decisive-angle.c");
    addChild("/guilds/monk/katana/decisive-angle.c",
        "/guilds/monk/katana/decisive-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/katana/tempered-resolve.c");
    addChild("/guilds/monk/katana/tempered-resolve.c",
        "/guilds/monk/katana/polished-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/katana/still-edge.c");
    addChild("/guilds/monk/katana/still-edge.c",
        "/guilds/monk/katana/unwavering-eye.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/katana/decisive-rhythm.c");
    addChild("/guilds/monk/katana/decisive-rhythm.c",
        "/guilds/monk/katana/decisive-angle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/katana/master-balance.c");
    addChild("/guilds/monk/katana/master-balance.c",
        "/guilds/monk/katana/point-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/katana/silent-edge.c");
    addChild("/guilds/monk/katana/silent-edge.c",
        "/guilds/monk/katana/master-balance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/katana/silent-economy.c");
    addChild("/guilds/monk/katana/silent-economy.c",
        "/guilds/monk/katana/silent-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("katana discipline");
    Description("Deliberate katana cuts and control of the recovering blade.");
    Source("monk");
    deferResearchLoading();

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addResearchElement("/guilds/monk/katana/root.c");
    TreeRoot("/guilds/monk/katana/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
    SixthLevel();
    SeventhLevel();
    EighthLevel();
    NinthLevel();
    TenthLevel();
    TwelfthLevel();
    FourteenthLevel();
    SixteenthLevel();
    EighteenthLevel();
    TwentiethLevel();
    TwentySecondLevel();
    TwentyFourthLevel();
    TwentySixthLevel();
    TwentyEighthLevel();
    ThirtiethLevel();
    ThirtySecondLevel();
    ThirtyFourthLevel();
    ThirtySixthLevel();
    ThirtyEighthLevel();
    FortiethLevel();
    FortySecondLevel();
    FortyFourthLevel();
    FortySixthLevel();
    FortyEighthLevel();
    FiftiethLevel();
    FiftySecondLevel();
    FiftyFourthLevel();
    FiftySixthLevel();
    FiftyEighthLevel();
    SixtiethLevel();
    SixtySecondLevel();
    SixtyFourthLevel();
    SixtySixthLevel();
    SixtyEighthLevel();
    SeventiethLevel();
}
