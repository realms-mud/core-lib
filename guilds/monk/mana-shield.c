//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/mana-shield/mindful-ward.c");
    addChild("/guilds/monk/mana-shield/mindful-ward.c",
        "/guilds/monk/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/mana-shield/ward-anatomy.c");
    addChild("/guilds/monk/mana-shield/ward-anatomy.c",
        "/guilds/monk/mana-shield/mindful-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/mana-shield/recovery-cycle.c");
    addChild("/guilds/monk/mana-shield/recovery-cycle.c",
        "/guilds/monk/mana-shield/ward-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/recovery-habit.c");
    addChild("/guilds/monk/mana-shield/recovery-habit.c",
        "/guilds/monk/mana-shield/recovery-cycle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/guarded-breath.c");
    addChild("/guilds/monk/mana-shield/guarded-breath.c",
        "/guilds/monk/mana-shield/recovery-habit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/sentry-focus.c");
    addChild("/guilds/monk/mana-shield/sentry-focus.c",
        "/guilds/monk/mana-shield/ward-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/mana-shield/soft-boundary.c");
    addChild("/guilds/monk/mana-shield/soft-boundary.c",
        "/guilds/monk/mana-shield/ward-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/ward-listening.c");
    addChild("/guilds/monk/mana-shield/ward-listening.c",
        "/guilds/monk/mana-shield/sentry-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/ward-mending.c");
    addChild("/guilds/monk/mana-shield/ward-mending.c",
        "/guilds/monk/mana-shield/recovery-cycle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/breath-conversion.c");
    addChild("/guilds/monk/mana-shield/breath-conversion.c",
        "/guilds/monk/mana-shield/ward-mending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/defensive-timing.c");
    addChild("/guilds/monk/mana-shield/defensive-timing.c",
        "/guilds/monk/mana-shield/recovery-cycle.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/economical-refuge.c");
    addChild("/guilds/monk/mana-shield/economical-refuge.c",
        "/guilds/monk/mana-shield/guarded-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/measured-renewal.c");
    addChild("/guilds/monk/mana-shield/measured-renewal.c",
        "/guilds/monk/mana-shield/breath-conversion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/mindful-casting.c");
    addChild("/guilds/monk/mana-shield/mindful-casting.c",
        "/guilds/monk/mana-shield/economical-refuge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/mana-shield/refuge-theory.c");
    addChild("/guilds/monk/mana-shield/refuge-theory.c",
        "/guilds/monk/mana-shield/sentry-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/mana-shield/brace-the-spirit.c");
    addChild("/guilds/monk/mana-shield/brace-the-spirit.c",
        "/guilds/monk/mana-shield/refuge-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/deflecting-palm.c");
    addChild("/guilds/monk/mana-shield/deflecting-palm.c",
        "/guilds/monk/mana-shield/refuge-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/refuge-posture.c");
    addChild("/guilds/monk/mana-shield/refuge-posture.c",
        "/guilds/monk/mana-shield/refuge-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/stable-footing.c");
    addChild("/guilds/monk/mana-shield/stable-footing.c",
        "/guilds/monk/mana-shield/soft-boundary.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/mana-shield/still-water.c");
    addChild("/guilds/monk/mana-shield/still-water.c",
        "/guilds/monk/mana-shield/recovery-habit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/mana-shield/intent-reading.c");
    addChild("/guilds/monk/mana-shield/intent-reading.c",
        "/guilds/monk/mana-shield/ward-listening.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/disruption-theory.c");
    addChild("/guilds/monk/mana-shield/disruption-theory.c",
        "/guilds/monk/mana-shield/intent-reading.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/interrupting-thread.c");
    addChild("/guilds/monk/mana-shield/interrupting-thread.c",
        "/guilds/monk/mana-shield/disruption-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/renewing-rhythm.c");
    addChild("/guilds/monk/mana-shield/renewing-rhythm.c",
        "/guilds/monk/mana-shield/measured-renewal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/mana-shield/restorative-watch.c");
    addChild("/guilds/monk/mana-shield/restorative-watch.c",
        "/guilds/monk/mana-shield/renewing-rhythm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/mana-shield/inner-refuge.c");
    addChild("/guilds/monk/mana-shield/inner-refuge.c",
        "/guilds/monk/mana-shield/restorative-watch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/tempered-nerves.c");
    addChild("/guilds/monk/mana-shield/tempered-nerves.c",
        "/guilds/monk/mana-shield/refuge-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/ward-counterpulse.c");
    addChild("/guilds/monk/mana-shield/ward-counterpulse.c",
        "/guilds/monk/mana-shield/disruption-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/ward-triage.c");
    addChild("/guilds/monk/mana-shield/ward-triage.c",
        "/guilds/monk/mana-shield/ward-mending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/mana-shield/sheltering-touch.c");
    addChild("/guilds/monk/mana-shield/sheltering-touch.c",
        "/guilds/monk/mana-shield/ward-triage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/mana-shield/conservation-of-motion.c");
    addChild("/guilds/monk/mana-shield/conservation-of-motion.c",
        "/guilds/monk/mana-shield/mindful-casting.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/elastic-defense.c");
    addChild("/guilds/monk/mana-shield/elastic-defense.c",
        "/guilds/monk/mana-shield/stable-footing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/imperturbable-center.c");
    addChild("/guilds/monk/mana-shield/imperturbable-center.c",
        "/guilds/monk/mana-shield/tempered-nerves.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/lucid-refuge.c");
    addChild("/guilds/monk/mana-shield/lucid-refuge.c",
        "/guilds/monk/mana-shield/ward-counterpulse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/mana-shield/quiet-vigil.c");
    addChild("/guilds/monk/mana-shield/quiet-vigil.c",
        "/guilds/monk/mana-shield/inner-refuge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/mana-shield/seamless-recovery.c");
    addChild("/guilds/monk/mana-shield/seamless-recovery.c",
        "/guilds/monk/mana-shield/inner-refuge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/sentinel-meditation.c");
    addChild("/guilds/monk/mana-shield/sentinel-meditation.c",
        "/guilds/monk/mana-shield/elastic-defense.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/shelter-of-intent.c");
    addChild("/guilds/monk/mana-shield/shelter-of-intent.c",
        "/guilds/monk/mana-shield/lucid-refuge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/mana-shield/stillpoint-rebuke.c");
    addChild("/guilds/monk/mana-shield/stillpoint-rebuke.c",
        "/guilds/monk/mana-shield/interrupting-thread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/mana-shield/vigilant-renewal.c");
    addChild("/guilds/monk/mana-shield/vigilant-renewal.c",
        "/guilds/monk/mana-shield/measured-renewal.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("mana shield mechanics");
    Description("Forty lessons in ward-dependent defense, recovery, resource "
        "efficiency, and deliberate counterprojections. Foundation, "
        "development, advanced practice, and mastery span levels one through "
        "seventy and preserve the existing Mindful Ward absorption mechanics "
        "without another shield layer.");
    Source("monk");
    deferResearchLoading();


    addResearchElement("/guilds/monk/mana-shield/root.c");
    TreeRoot("/guilds/monk/mana-shield/root.c");

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
