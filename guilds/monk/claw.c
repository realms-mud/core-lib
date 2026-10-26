//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/claw/measured-rake.c");
    addChild("/guilds/monk/claw/measured-rake.c",
        "/guilds/monk/claw/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/claw/claw-grip.c");
    addChild("/guilds/monk/claw/claw-grip.c",
        "/guilds/monk/claw/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/claw/rake-geometry.c");
    addChild("/guilds/monk/claw/rake-geometry.c",
        "/guilds/monk/claw/measured-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-footwork.c");
    addChild("/guilds/monk/claw/claw-footwork.c",
        "/guilds/monk/claw/claw-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-check.c");
    addChild("/guilds/monk/claw/claw-check.c",
        "/guilds/monk/claw/claw-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-leverage.c");
    addChild("/guilds/monk/claw/claw-leverage.c",
        "/guilds/monk/claw/claw-check.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/claw/claw-guard.c");
    addChild("/guilds/monk/claw/claw-guard.c",
        "/guilds/monk/claw/claw-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-distance.c");
    addChild("/guilds/monk/claw/claw-distance.c",
        "/guilds/monk/claw/rake-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-alignment.c");
    addChild("/guilds/monk/claw/claw-alignment.c",
        "/guilds/monk/claw/rake-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/monk/claw/claw-shelter.c");
    addChild("/guilds/monk/claw/claw-shelter.c",
        "/guilds/monk/claw/claw-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/monk/claw/gripping-rake.c");
    addChild("/guilds/monk/claw/gripping-rake.c",
        "/guilds/monk/claw/claw-leverage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/monk/claw/grip-geometry.c");
    addChild("/guilds/monk/claw/grip-geometry.c",
        "/guilds/monk/claw/gripping-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/monk/claw/breath-rake.c");
    addChild("/guilds/monk/claw/breath-rake.c",
        "/guilds/monk/claw/claw-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-breath-theory.c");
    addChild("/guilds/monk/claw/claw-breath-theory.c",
        "/guilds/monk/claw/breath-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/monk/claw/claw-recovery.c");
    addChild("/guilds/monk/claw/claw-recovery.c",
        "/guilds/monk/claw/claw-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/monk/claw/claw-conditioning.c");
    addChild("/guilds/monk/claw/claw-conditioning.c",
        "/guilds/monk/claw/claw-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/monk/claw/claw-recentering.c");
    addChild("/guilds/monk/claw/claw-recentering.c",
        "/guilds/monk/claw/claw-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/monk/claw/claw-composure.c");
    addChild("/guilds/monk/claw/claw-composure.c",
        "/guilds/monk/claw/claw-recentering.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/monk/claw/crossing-rake.c");
    addChild("/guilds/monk/claw/crossing-rake.c",
        "/guilds/monk/claw/claw-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/monk/claw/crossing-talons.c");
    addChild("/guilds/monk/claw/crossing-talons.c",
        "/guilds/monk/claw/crossing-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/monk/claw/forward-talon.c");
    addChild("/guilds/monk/claw/forward-talon.c",
        "/guilds/monk/claw/claw-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/monk/claw/rake-economy.c");
    addChild("/guilds/monk/claw/rake-economy.c",
        "/guilds/monk/claw/rake-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/monk/claw/claw-readiness.c");
    addChild("/guilds/monk/claw/claw-readiness.c",
        "/guilds/monk/claw/claw-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/monk/claw/talon-point.c");
    addChild("/guilds/monk/claw/talon-point.c",
        "/guilds/monk/claw/claw-readiness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/monk/claw/talon-point-theory.c");
    addChild("/guilds/monk/claw/talon-point-theory.c",
        "/guilds/monk/claw/talon-point.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/monk/claw/rising-talon.c");
    addChild("/guilds/monk/claw/rising-talon.c",
        "/guilds/monk/claw/crossing-talons.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/monk/claw/rising-talon-theory.c");
    addChild("/guilds/monk/claw/rising-talon-theory.c",
        "/guilds/monk/claw/rising-talon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/monk/claw/quiet-rake.c");
    addChild("/guilds/monk/claw/quiet-rake.c",
        "/guilds/monk/claw/grip-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/monk/claw/crossing-rhythm.c");
    addChild("/guilds/monk/claw/crossing-rhythm.c",
        "/guilds/monk/claw/crossing-talons.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/monk/claw/circling-talon.c");
    addChild("/guilds/monk/claw/circling-talon.c",
        "/guilds/monk/claw/claw-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/monk/claw/claw-vitality.c");
    addChild("/guilds/monk/claw/claw-vitality.c",
        "/guilds/monk/claw/claw-conditioning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/monk/claw/tiring-rake.c");
    addChild("/guilds/monk/claw/tiring-rake.c",
        "/guilds/monk/claw/claw-composure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/monk/claw/claw-endurance.c");
    addChild("/guilds/monk/claw/claw-endurance.c",
        "/guilds/monk/claw/claw-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/monk/claw/returning-rake.c");
    addChild("/guilds/monk/claw/returning-rake.c",
        "/guilds/monk/claw/rising-talon-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/monk/claw/rake-return-theory.c");
    addChild("/guilds/monk/claw/rake-return-theory.c",
        "/guilds/monk/claw/returning-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/monk/claw/claw-mastery.c");
    addChild("/guilds/monk/claw/claw-mastery.c",
        "/guilds/monk/claw/rake-return-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/monk/claw/final-rake.c");
    addChild("/guilds/monk/claw/final-rake.c",
        "/guilds/monk/claw/claw-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/monk/claw/final-rake-theory.c");
    addChild("/guilds/monk/claw/final-rake-theory.c",
        "/guilds/monk/claw/final-rake.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyNinthLevel()
{
    addResearchElement("/guilds/monk/claw/final-rake-economy.c");
    addChild("/guilds/monk/claw/final-rake-economy.c",
        "/guilds/monk/claw/final-rake-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/claw/patient-claw.c");
    addChild("/guilds/monk/claw/patient-claw.c",
        "/guilds/monk/claw/claw-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("claw discipline");
    Description("Close thrusts, agile guards, and deliberate recovery with tiger "
        "claws. These are weapon techniques, not natural attacks.");
    Source("monk");
    deferResearchLoading();


    addResearchElement("/guilds/monk/claw/root.c");
    TreeRoot("/guilds/monk/claw/root.c");

    FirstLevel();
    SecondLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
    SixthLevel();
    SeventhLevel();
    EighthLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FortyNinthLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftyFifthLevel();
    FiftySeventhLevel();
    FiftyNinthLevel();
    SixtyFirstLevel();
    SixtyThirdLevel();
    SixtyFifthLevel();
    SixtySeventhLevel();
    SixtyNinthLevel();
    SeventiethLevel();
}
