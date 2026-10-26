//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/odachi/committed-cut.c");
    addChild("/guilds/monk/odachi/committed-cut.c",
        "/guilds/monk/odachi/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-grip.c");
    addChild("/guilds/monk/odachi/longblade-grip.c",
        "/guilds/monk/odachi/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/odachi/commitment-theory.c");
    addChild("/guilds/monk/odachi/commitment-theory.c",
        "/guilds/monk/odachi/committed-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-footing.c");
    addChild("/guilds/monk/odachi/longblade-footing.c",
        "/guilds/monk/odachi/longblade-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-guard.c");
    addChild("/guilds/monk/odachi/longblade-guard.c",
        "/guilds/monk/odachi/longblade-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/odachi/pommel-drive.c");
    addChild("/guilds/monk/odachi/pommel-drive.c",
        "/guilds/monk/odachi/longblade-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/odachi/heavy-leverage.c");
    addChild("/guilds/monk/odachi/heavy-leverage.c",
        "/guilds/monk/odachi/pommel-drive.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-distance.c");
    addChild("/guilds/monk/odachi/longblade-distance.c",
        "/guilds/monk/odachi/commitment-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-alignment.c");
    addChild("/guilds/monk/odachi/longblade-alignment.c",
        "/guilds/monk/odachi/commitment-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/monk/odachi/horizon-cut.c");
    addChild("/guilds/monk/odachi/horizon-cut.c",
        "/guilds/monk/odachi/longblade-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/monk/odachi/horizon-geometry.c");
    addChild("/guilds/monk/odachi/horizon-geometry.c",
        "/guilds/monk/odachi/horizon-cut.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/monk/odachi/horizon-guard.c");
    addChild("/guilds/monk/odachi/horizon-guard.c",
        "/guilds/monk/odachi/longblade-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-recovery.c");
    addChild("/guilds/monk/odachi/longblade-recovery.c",
        "/guilds/monk/odachi/longblade-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/monk/odachi/breath-cleaver.c");
    addChild("/guilds/monk/odachi/breath-cleaver.c",
        "/guilds/monk/odachi/longblade-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-breath-theory.c");
    addChild("/guilds/monk/odachi/longblade-breath-theory.c",
        "/guilds/monk/odachi/breath-cleaver.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-conditioning.c");
    addChild("/guilds/monk/odachi/longblade-conditioning.c",
        "/guilds/monk/odachi/longblade-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/monk/odachi/weight-check.c");
    addChild("/guilds/monk/odachi/weight-check.c",
        "/guilds/monk/odachi/heavy-leverage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-pressure-theory.c");
    addChild("/guilds/monk/odachi/longblade-pressure-theory.c",
        "/guilds/monk/odachi/weight-check.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/monk/odachi/weight-forward.c");
    addChild("/guilds/monk/odachi/weight-forward.c",
        "/guilds/monk/odachi/longblade-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-recentering.c");
    addChild("/guilds/monk/odachi/longblade-recentering.c",
        "/guilds/monk/odachi/longblade-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-composure.c");
    addChild("/guilds/monk/odachi/longblade-composure.c",
        "/guilds/monk/odachi/longblade-recentering.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-sight.c");
    addChild("/guilds/monk/odachi/longblade-sight.c",
        "/guilds/monk/odachi/longblade-distance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/monk/odachi/long-point.c");
    addChild("/guilds/monk/odachi/long-point.c",
        "/guilds/monk/odachi/longblade-sight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-point-theory.c");
    addChild("/guilds/monk/odachi/longblade-point-theory.c",
        "/guilds/monk/odachi/long-point.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/monk/odachi/descending-arc.c");
    addChild("/guilds/monk/odachi/descending-arc.c",
        "/guilds/monk/odachi/longblade-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-descent-theory.c");
    addChild("/guilds/monk/odachi/longblade-descent-theory.c",
        "/guilds/monk/odachi/descending-arc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-vitality.c");
    addChild("/guilds/monk/odachi/longblade-vitality.c",
        "/guilds/monk/odachi/longblade-conditioning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/monk/odachi/rooted-horizon.c");
    addChild("/guilds/monk/odachi/rooted-horizon.c",
        "/guilds/monk/odachi/longblade-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/monk/odachi/stilling-arc.c");
    addChild("/guilds/monk/odachi/stilling-arc.c",
        "/guilds/monk/odachi/longblade-pressure-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-economy.c");
    addChild("/guilds/monk/odachi/longblade-economy.c",
        "/guilds/monk/odachi/commitment-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/monk/odachi/horizon-rhythm.c");
    addChild("/guilds/monk/odachi/horizon-rhythm.c",
        "/guilds/monk/odachi/horizon-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/monk/odachi/heavy-rebuke.c");
    addChild("/guilds/monk/odachi/heavy-rebuke.c",
        "/guilds/monk/odachi/longblade-composure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-endurance.c");
    addChild("/guilds/monk/odachi/longblade-endurance.c",
        "/guilds/monk/odachi/longblade-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/monk/odachi/returning-arc.c");
    addChild("/guilds/monk/odachi/returning-arc.c",
        "/guilds/monk/odachi/longblade-descent-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-return-theory.c");
    addChild("/guilds/monk/odachi/longblade-return-theory.c",
        "/guilds/monk/odachi/returning-arc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-mastery.c");
    addChild("/guilds/monk/odachi/longblade-mastery.c",
        "/guilds/monk/odachi/longblade-return-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/monk/odachi/final-horizon.c");
    addChild("/guilds/monk/odachi/final-horizon.c",
        "/guilds/monk/odachi/longblade-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-final-theory.c");
    addChild("/guilds/monk/odachi/longblade-final-theory.c",
        "/guilds/monk/odachi/final-horizon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyNinthLevel()
{
    addResearchElement("/guilds/monk/odachi/final-horizon-economy.c");
    addChild("/guilds/monk/odachi/final-horizon-economy.c",
        "/guilds/monk/odachi/longblade-final-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/odachi/longblade-stillness.c");
    addChild("/guilds/monk/odachi/longblade-stillness.c",
        "/guilds/monk/odachi/longblade-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("odachi discipline");
    Description("Committed heavy cuts, measured recovery, and costly defensive "
        "choices with an odachi.");
    Source("monk");
    deferResearchLoading();


    addResearchElement("/guilds/monk/odachi/root.c");
    TreeRoot("/guilds/monk/odachi/root.c");

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
