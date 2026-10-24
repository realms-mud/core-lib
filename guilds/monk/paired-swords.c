//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/paired-swords/linked-cut.c");
    addChild("/guilds/monk/paired-swords/linked-cut.c",
        "/guilds/monk/paired-swords/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-grip.c");
    addChild("/guilds/monk/paired-swords/paired-grip.c",
        "/guilds/monk/paired-swords/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/paired-swords/linked-lines.c");
    addChild("/guilds/monk/paired-swords/linked-lines.c",
        "/guilds/monk/paired-swords/linked-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/companion-grip.c");
    addChild("/guilds/monk/paired-swords/companion-grip.c",
        "/guilds/monk/paired-swords/paired-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/companion-check.c");
    addChild("/guilds/monk/paired-swords/companion-check.c",
        "/guilds/monk/paired-swords/companion-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/companion-leverage.c");
    addChild("/guilds/monk/paired-swords/companion-leverage.c",
        "/guilds/monk/paired-swords/companion-check.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-distance.c");
    addChild("/guilds/monk/paired-swords/paired-distance.c",
        "/guilds/monk/paired-swords/linked-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-footwork.c");
    addChild("/guilds/monk/paired-swords/paired-footwork.c",
        "/guilds/monk/paired-swords/paired-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-guard.c");
    addChild("/guilds/monk/paired-swords/paired-guard.c",
        "/guilds/monk/paired-swords/companion-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-high-guard.c");
    addChild("/guilds/monk/paired-swords/paired-high-guard.c",
        "/guilds/monk/paired-swords/paired-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/blade-bind.c");
    addChild("/guilds/monk/paired-swords/blade-bind.c",
        "/guilds/monk/paired-swords/companion-leverage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/binding-lines.c");
    addChild("/guilds/monk/paired-swords/binding-lines.c",
        "/guilds/monk/paired-swords/blade-bind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-pressure.c");
    addChild("/guilds/monk/paired-swords/paired-pressure.c",
        "/guilds/monk/paired-swords/linked-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/breath-shear.c");
    addChild("/guilds/monk/paired-swords/breath-shear.c",
        "/guilds/monk/paired-swords/paired-pressure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-breath-theory.c");
    addChild("/guilds/monk/paired-swords/paired-breath-theory.c",
        "/guilds/monk/paired-swords/breath-shear.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-recovery.c");
    addChild("/guilds/monk/paired-swords/paired-recovery.c",
        "/guilds/monk/paired-swords/paired-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-recentering.c");
    addChild("/guilds/monk/paired-swords/paired-recentering.c",
        "/guilds/monk/paired-swords/paired-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-composure.c");
    addChild("/guilds/monk/paired-swords/paired-composure.c",
        "/guilds/monk/paired-swords/paired-recentering.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/crossing-cut.c");
    addChild("/guilds/monk/paired-swords/crossing-cut.c",
        "/guilds/monk/paired-swords/paired-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/paired-swords/crossing-lines.c");
    addChild("/guilds/monk/paired-swords/crossing-lines.c",
        "/guilds/monk/paired-swords/crossing-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-forward-guard.c");
    addChild("/guilds/monk/paired-swords/paired-forward-guard.c",
        "/guilds/monk/paired-swords/paired-pressure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/alternating-cut.c");
    addChild("/guilds/monk/paired-swords/alternating-cut.c",
        "/guilds/monk/paired-swords/paired-pressure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/alternating-lines.c");
    addChild("/guilds/monk/paired-swords/alternating-lines.c",
        "/guilds/monk/paired-swords/alternating-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/companion-thrust.c");
    addChild("/guilds/monk/paired-swords/companion-thrust.c",
        "/guilds/monk/paired-swords/paired-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-point-theory.c");
    addChild("/guilds/monk/paired-swords/paired-point-theory.c",
        "/guilds/monk/paired-swords/companion-thrust.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/paired-swords/opening-cut.c");
    addChild("/guilds/monk/paired-swords/opening-cut.c",
        "/guilds/monk/paired-swords/crossing-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/opening-geometry.c");
    addChild("/guilds/monk/paired-swords/opening-geometry.c",
        "/guilds/monk/paired-swords/opening-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-breath-economy.c");
    addChild("/guilds/monk/paired-swords/paired-breath-economy.c",
        "/guilds/monk/paired-swords/breath-shear.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-flow.c");
    addChild("/guilds/monk/paired-swords/paired-flow.c",
        "/guilds/monk/paired-swords/paired-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-readiness.c");
    addChild("/guilds/monk/paired-swords/paired-readiness.c",
        "/guilds/monk/paired-swords/paired-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/paired-swords/close-circle.c");
    addChild("/guilds/monk/paired-swords/close-circle.c",
        "/guilds/monk/paired-swords/paired-readiness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-vitality.c");
    addChild("/guilds/monk/paired-swords/paired-vitality.c",
        "/guilds/monk/paired-swords/paired-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-vigor.c");
    addChild("/guilds/monk/paired-swords/paired-vigor.c",
        "/guilds/monk/paired-swords/paired-vitality.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-opening-economy.c");
    addChild("/guilds/monk/paired-swords/paired-opening-economy.c",
        "/guilds/monk/paired-swords/opening-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/paired-swords/returning-cut.c");
    addChild("/guilds/monk/paired-swords/returning-cut.c",
        "/guilds/monk/paired-swords/opening-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-return-rhythm.c");
    addChild("/guilds/monk/paired-swords/paired-return-rhythm.c",
        "/guilds/monk/paired-swords/returning-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-mastery.c");
    addChild("/guilds/monk/paired-swords/paired-mastery.c",
        "/guilds/monk/paired-swords/paired-return-rhythm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/paired-stillness.c");
    addChild("/guilds/monk/paired-swords/paired-stillness.c",
        "/guilds/monk/paired-swords/paired-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/paired-swords/twin-edge.c");
    addChild("/guilds/monk/paired-swords/twin-edge.c",
        "/guilds/monk/paired-swords/paired-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/paired-swords/twin-edge-theory.c");
    addChild("/guilds/monk/paired-swords/twin-edge-theory.c",
        "/guilds/monk/paired-swords/twin-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("paired sword discipline");
    Description("Coordinate a primary katana and offhand wakizashi without "
        "multiplying ordinary attacks.");
    Source("monk");
    deferResearchLoading();

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addResearchElement("/guilds/monk/paired-swords/root.c");
    TreeRoot("/guilds/monk/paired-swords/root.c");

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
