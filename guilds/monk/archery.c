//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/archery/measured-draw.c");
    addChild("/guilds/monk/archery/measured-draw.c",
        "/guilds/monk/archery/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/archery/archers-grip.c");
    addChild("/guilds/monk/archery/archers-grip.c",
        "/guilds/monk/archery/measured-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/archery/draw-geometry.c");
    addChild("/guilds/monk/archery/draw-geometry.c",
        "/guilds/monk/archery/measured-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/archery/archers-footing.c");
    addChild("/guilds/monk/archery/archers-footing.c",
        "/guilds/monk/archery/archers-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/archery/archers-guard.c");
    addChild("/guilds/monk/archery/archers-guard.c",
        "/guilds/monk/archery/archers-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/archery/arresting-shot.c");
    addChild("/guilds/monk/archery/arresting-shot.c",
        "/guilds/monk/archery/archers-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/archery/bow-leverage.c");
    addChild("/guilds/monk/archery/bow-leverage.c",
        "/guilds/monk/archery/arresting-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/archery/archers-distance.c");
    addChild("/guilds/monk/archery/archers-distance.c",
        "/guilds/monk/archery/draw-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/archery/patient-draw.c");
    addChild("/guilds/monk/archery/patient-draw.c",
        "/guilds/monk/archery/archers-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/archery/draw-conditioning.c");
    addChild("/guilds/monk/archery/draw-conditioning.c",
        "/guilds/monk/archery/archers-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/archery/burdening-shot.c");
    addChild("/guilds/monk/archery/burdening-shot.c",
        "/guilds/monk/archery/bow-leverage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/archery/draw-pressure-theory.c");
    addChild("/guilds/monk/archery/draw-pressure-theory.c",
        "/guilds/monk/archery/burdening-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/archery/draw-alignment.c");
    addChild("/guilds/monk/archery/draw-alignment.c",
        "/guilds/monk/archery/draw-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/archery/crosswind-shot.c");
    addChild("/guilds/monk/archery/crosswind-shot.c",
        "/guilds/monk/archery/archers-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/archery/crosswind-geometry.c");
    addChild("/guilds/monk/archery/crosswind-geometry.c",
        "/guilds/monk/archery/crosswind-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/archery/draw-economy.c");
    addChild("/guilds/monk/archery/draw-economy.c",
        "/guilds/monk/archery/draw-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/archery/draw-recovery.c");
    addChild("/guilds/monk/archery/draw-recovery.c",
        "/guilds/monk/archery/archers-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/archery/forward-draw.c");
    addChild("/guilds/monk/archery/forward-draw.c",
        "/guilds/monk/archery/draw-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/archery/breath-piercing-shot.c");
    addChild("/guilds/monk/archery/breath-piercing-shot.c",
        "/guilds/monk/archery/draw-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/archery/bow-breath-theory.c");
    addChild("/guilds/monk/archery/bow-breath-theory.c",
        "/guilds/monk/archery/breath-piercing-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/archery/archers-sight.c");
    addChild("/guilds/monk/archery/archers-sight.c",
        "/guilds/monk/archery/archers-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/archery/mobile-draw.c");
    addChild("/guilds/monk/archery/mobile-draw.c",
        "/guilds/monk/archery/archers-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/archery/archers-vitality.c");
    addChild("/guilds/monk/archery/archers-vitality.c",
        "/guilds/monk/archery/draw-conditioning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/archery/archers-recentering.c");
    addChild("/guilds/monk/archery/archers-recentering.c",
        "/guilds/monk/archery/draw-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/archery/crosswind-rhythm.c");
    addChild("/guilds/monk/archery/crosswind-rhythm.c",
        "/guilds/monk/archery/crosswind-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/archery/descending-shot.c");
    addChild("/guilds/monk/archery/descending-shot.c",
        "/guilds/monk/archery/draw-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/archery/falling-trajectory.c");
    addChild("/guilds/monk/archery/falling-trajectory.c",
        "/guilds/monk/archery/descending-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/archery/narrow-line-shot.c");
    addChild("/guilds/monk/archery/narrow-line-shot.c",
        "/guilds/monk/archery/archers-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/archery/point-of-release.c");
    addChild("/guilds/monk/archery/point-of-release.c",
        "/guilds/monk/archery/narrow-line-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/archery/quieting-shot.c");
    addChild("/guilds/monk/archery/quieting-shot.c",
        "/guilds/monk/archery/draw-pressure-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/archery/archers-composure.c");
    addChild("/guilds/monk/archery/archers-composure.c",
        "/guilds/monk/archery/archers-recentering.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/archery/archers-endurance.c");
    addChild("/guilds/monk/archery/archers-endurance.c",
        "/guilds/monk/archery/draw-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/archery/exhausting-shot.c");
    addChild("/guilds/monk/archery/exhausting-shot.c",
        "/guilds/monk/archery/archers-composure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/archery/returning-shot.c");
    addChild("/guilds/monk/archery/returning-shot.c",
        "/guilds/monk/archery/falling-trajectory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/archery/return-trajectory.c");
    addChild("/guilds/monk/archery/return-trajectory.c",
        "/guilds/monk/archery/returning-shot.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/archery/archers-mastery.c");
    addChild("/guilds/monk/archery/archers-mastery.c",
        "/guilds/monk/archery/return-trajectory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/archery/final-draw.c");
    addChild("/guilds/monk/archery/final-draw.c",
        "/guilds/monk/archery/archers-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/archery/final-trajectory.c");
    addChild("/guilds/monk/archery/final-trajectory.c",
        "/guilds/monk/archery/final-draw.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/archery/final-draw-economy.c");
    addChild("/guilds/monk/archery/final-draw-economy.c",
        "/guilds/monk/archery/final-trajectory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/archery/still-bow.c");
    addChild("/guilds/monk/archery/still-bow.c",
        "/guilds/monk/archery/archers-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("monastic archery");
    Description("Measured bow practice, controlled releases, and deliberate "
        "tradeoffs between accuracy, defense, and recovery.");
    Source("monk");
    deferResearchLoading();

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addResearchElement("/guilds/monk/archery/root.c");
    TreeRoot("/guilds/monk/archery/root.c");

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
