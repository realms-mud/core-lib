//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/kama/measured-hook.c");
    addChild("/guilds/monk/kama/measured-hook.c",
        "/guilds/monk/kama/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/kama/hooked-grip.c");
    addChild("/guilds/monk/kama/hooked-grip.c",
        "/guilds/monk/kama/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/kama/hook-geometry.c");
    addChild("/guilds/monk/kama/hook-geometry.c",
        "/guilds/monk/kama/measured-hook.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-footing.c");
    addChild("/guilds/monk/kama/sickle-footing.c",
        "/guilds/monk/kama/hooked-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-check.c");
    addChild("/guilds/monk/kama/sickle-check.c",
        "/guilds/monk/kama/sickle-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-leverage.c");
    addChild("/guilds/monk/kama/sickle-leverage.c",
        "/guilds/monk/kama/sickle-check.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-guard.c");
    addChild("/guilds/monk/kama/sickle-guard.c",
        "/guilds/monk/kama/sickle-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-distance.c");
    addChild("/guilds/monk/kama/sickle-distance.c",
        "/guilds/monk/kama/hook-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/kama/hook-alignment.c");
    addChild("/guilds/monk/kama/hook-alignment.c",
        "/guilds/monk/kama/hook-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-ward.c");
    addChild("/guilds/monk/kama/sickle-ward.c",
        "/guilds/monk/kama/sickle-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/kama/binding-hook.c");
    addChild("/guilds/monk/kama/binding-hook.c",
        "/guilds/monk/kama/sickle-leverage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/kama/binding-geometry.c");
    addChild("/guilds/monk/kama/binding-geometry.c",
        "/guilds/monk/kama/binding-hook.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/kama/breath-hook.c");
    addChild("/guilds/monk/kama/breath-hook.c",
        "/guilds/monk/kama/hook-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/kama/hook-breath-theory.c");
    addChild("/guilds/monk/kama/hook-breath-theory.c",
        "/guilds/monk/kama/breath-hook.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/kama/hook-recovery.c");
    addChild("/guilds/monk/kama/hook-recovery.c",
        "/guilds/monk/kama/sickle-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-conditioning.c");
    addChild("/guilds/monk/kama/sickle-conditioning.c",
        "/guilds/monk/kama/sickle-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-recentering.c");
    addChild("/guilds/monk/kama/sickle-recentering.c",
        "/guilds/monk/kama/hook-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-composure.c");
    addChild("/guilds/monk/kama/sickle-composure.c",
        "/guilds/monk/kama/sickle-recentering.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/kama/reaping-cut.c");
    addChild("/guilds/monk/kama/reaping-cut.c",
        "/guilds/monk/kama/hook-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/kama/reaping-lines.c");
    addChild("/guilds/monk/kama/reaping-lines.c",
        "/guilds/monk/kama/reaping-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/kama/hook-forward.c");
    addChild("/guilds/monk/kama/hook-forward.c",
        "/guilds/monk/kama/hook-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/kama/hook-economy.c");
    addChild("/guilds/monk/kama/hook-economy.c",
        "/guilds/monk/kama/hook-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-readiness.c");
    addChild("/guilds/monk/kama/sickle-readiness.c",
        "/guilds/monk/kama/sickle-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-point.c");
    addChild("/guilds/monk/kama/sickle-point.c",
        "/guilds/monk/kama/sickle-readiness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-point-theory.c");
    addChild("/guilds/monk/kama/sickle-point-theory.c",
        "/guilds/monk/kama/sickle-point.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/kama/crescent-reap.c");
    addChild("/guilds/monk/kama/crescent-reap.c",
        "/guilds/monk/kama/reaping-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/kama/crescent-geometry.c");
    addChild("/guilds/monk/kama/crescent-geometry.c",
        "/guilds/monk/kama/crescent-reap.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/kama/quiet-hook.c");
    addChild("/guilds/monk/kama/quiet-hook.c",
        "/guilds/monk/kama/binding-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/kama/reaping-rhythm.c");
    addChild("/guilds/monk/kama/reaping-rhythm.c",
        "/guilds/monk/kama/reaping-lines.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-flow.c");
    addChild("/guilds/monk/kama/sickle-flow.c",
        "/guilds/monk/kama/sickle-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-vitality.c");
    addChild("/guilds/monk/kama/sickle-vitality.c",
        "/guilds/monk/kama/sickle-conditioning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/kama/tiring-reap.c");
    addChild("/guilds/monk/kama/tiring-reap.c",
        "/guilds/monk/kama/sickle-composure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-endurance.c");
    addChild("/guilds/monk/kama/sickle-endurance.c",
        "/guilds/monk/kama/hook-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/kama/returning-hook.c");
    addChild("/guilds/monk/kama/returning-hook.c",
        "/guilds/monk/kama/crescent-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/kama/hook-return-theory.c");
    addChild("/guilds/monk/kama/hook-return-theory.c",
        "/guilds/monk/kama/returning-hook.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/kama/sickle-mastery.c");
    addChild("/guilds/monk/kama/sickle-mastery.c",
        "/guilds/monk/kama/hook-return-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/kama/final-reap.c");
    addChild("/guilds/monk/kama/final-reap.c",
        "/guilds/monk/kama/sickle-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/kama/final-reap-theory.c");
    addChild("/guilds/monk/kama/final-reap-theory.c",
        "/guilds/monk/kama/final-reap.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/kama/final-reap-economy.c");
    addChild("/guilds/monk/kama/final-reap-economy.c",
        "/guilds/monk/kama/final-reap-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/kama/patient-sickle.c");
    addChild("/guilds/monk/kama/patient-sickle.c",
        "/guilds/monk/kama/sickle-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("kama discipline");
    Description("Measured sickle cuts, tiring hooks, and guarded recovery with the "
        "kama. Hooking techniques do not immobilize opponents.");
    Source("monk");
    deferResearchLoading();


    addResearchElement("/guilds/monk/kama/root.c");
    TreeRoot("/guilds/monk/kama/root.c");

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
