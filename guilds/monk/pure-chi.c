//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/pure-chi/focused-pulse.c");
    addChild("/guilds/monk/pure-chi/focused-pulse.c",
        "/guilds/monk/pure-chi/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/pure-chi/chi-anatomy.c");
    addChild("/guilds/monk/pure-chi/chi-anatomy.c",
        "/guilds/monk/pure-chi/focused-pulse.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/pure-chi/economical-breath.c");
    addChild("/guilds/monk/pure-chi/economical-breath.c",
        "/guilds/monk/pure-chi/chi-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/essence-sensitivity.c");
    addChild("/guilds/monk/pure-chi/essence-sensitivity.c",
        "/guilds/monk/pure-chi/chi-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/flowing-current.c");
    addChild("/guilds/monk/pure-chi/flowing-current.c",
        "/guilds/monk/pure-chi/essence-sensitivity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/pulse-geometry.c");
    addChild("/guilds/monk/pure-chi/pulse-geometry.c",
        "/guilds/monk/pure-chi/chi-anatomy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/needle-of-chi.c");
    addChild("/guilds/monk/pure-chi/needle-of-chi.c",
        "/guilds/monk/pure-chi/pulse-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/reservoir-discipline.c");
    addChild("/guilds/monk/pure-chi/reservoir-discipline.c",
        "/guilds/monk/pure-chi/economical-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/contemplative-focus.c");
    addChild("/guilds/monk/pure-chi/contemplative-focus.c",
        "/guilds/monk/pure-chi/reservoir-discipline.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/restorative-breath.c");
    addChild("/guilds/monk/pure-chi/restorative-breath.c",
        "/guilds/monk/pure-chi/economical-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/circulation-theory.c");
    addChild("/guilds/monk/pure-chi/circulation-theory.c",
        "/guilds/monk/pure-chi/restorative-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/cleansing-breath.c");
    addChild("/guilds/monk/pure-chi/cleansing-breath.c",
        "/guilds/monk/pure-chi/circulation-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/concentrated-channel.c");
    addChild("/guilds/monk/pure-chi/concentrated-channel.c",
        "/guilds/monk/pure-chi/flowing-current.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/essence-weaving.c");
    addChild("/guilds/monk/pure-chi/essence-weaving.c",
        "/guilds/monk/pure-chi/concentrated-channel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/monk/pure-chi/measured-expenditure.c");
    addChild("/guilds/monk/pure-chi/measured-expenditure.c",
        "/guilds/monk/pure-chi/economical-breath.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/monk/pure-chi/pulse-cadence.c");
    addChild("/guilds/monk/pure-chi/pulse-cadence.c",
        "/guilds/monk/pure-chi/needle-of-chi.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/driving-wave.c");
    addChild("/guilds/monk/pure-chi/driving-wave.c",
        "/guilds/monk/pure-chi/pulse-cadence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/mental-abacus.c");
    addChild("/guilds/monk/pure-chi/mental-abacus.c",
        "/guilds/monk/pure-chi/pulse-cadence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/replenishing-stillness.c");
    addChild("/guilds/monk/pure-chi/replenishing-stillness.c",
        "/guilds/monk/pure-chi/circulation-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/monk/pure-chi/returning-current.c");
    addChild("/guilds/monk/pure-chi/returning-current.c",
        "/guilds/monk/pure-chi/circulation-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/monk/pure-chi/balanced-circulation.c");
    addChild("/guilds/monk/pure-chi/balanced-circulation.c",
        "/guilds/monk/pure-chi/returning-current.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/channel-economy.c");
    addChild("/guilds/monk/pure-chi/channel-economy.c",
        "/guilds/monk/pure-chi/measured-expenditure.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/deep-recollection.c");
    addChild("/guilds/monk/pure-chi/deep-recollection.c",
        "/guilds/monk/pure-chi/replenishing-stillness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/inward-listening.c");
    addChild("/guilds/monk/pure-chi/inward-listening.c",
        "/guilds/monk/pure-chi/contemplative-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/monk/pure-chi/quiet-intervals.c");
    addChild("/guilds/monk/pure-chi/quiet-intervals.c",
        "/guilds/monk/pure-chi/returning-current.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/monk/pure-chi/heart-mending.c");
    addChild("/guilds/monk/pure-chi/heart-mending.c",
        "/guilds/monk/pure-chi/quiet-intervals.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/resonance-theory.c");
    addChild("/guilds/monk/pure-chi/resonance-theory.c",
        "/guilds/monk/pure-chi/driving-wave.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/centered-release.c");
    addChild("/guilds/monk/pure-chi/centered-release.c",
        "/guilds/monk/pure-chi/resonance-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/etheric-poise.c");
    addChild("/guilds/monk/pure-chi/etheric-poise.c",
        "/guilds/monk/pure-chi/resonance-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/monk/pure-chi/piercing-intent.c");
    addChild("/guilds/monk/pure-chi/piercing-intent.c",
        "/guilds/monk/pure-chi/resonance-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/monk/pure-chi/perfect-economy.c");
    addChild("/guilds/monk/pure-chi/perfect-economy.c",
        "/guilds/monk/pure-chi/channel-economy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/lucid-mind.c");
    addChild("/guilds/monk/pure-chi/lucid-mind.c",
        "/guilds/monk/pure-chi/perfect-economy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/renewal-of-self.c");
    addChild("/guilds/monk/pure-chi/renewal-of-self.c",
        "/guilds/monk/pure-chi/heart-mending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/severing-current.c");
    addChild("/guilds/monk/pure-chi/severing-current.c",
        "/guilds/monk/pure-chi/piercing-intent.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/monk/pure-chi/spirit-anchor.c");
    addChild("/guilds/monk/pure-chi/spirit-anchor.c",
        "/guilds/monk/pure-chi/etheric-poise.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/monk/pure-chi/boundless-focus.c");
    addChild("/guilds/monk/pure-chi/boundless-focus.c",
        "/guilds/monk/pure-chi/spirit-anchor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/stillness-between-pulses.c");
    addChild("/guilds/monk/pure-chi/stillness-between-pulses.c",
        "/guilds/monk/pure-chi/pulse-cadence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/monk/pure-chi/unfettered-flow.c");
    addChild("/guilds/monk/pure-chi/unfettered-flow.c",
        "/guilds/monk/pure-chi/deep-recollection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyNinthLevel()
{
    addResearchElement("/guilds/monk/pure-chi/unified-current.c");
    addChild("/guilds/monk/pure-chi/unified-current.c",
        "/guilds/monk/pure-chi/centered-release.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/pure-chi/silent-thunder.c");
    addChild("/guilds/monk/pure-chi/silent-thunder.c",
        "/guilds/monk/pure-chi/unified-current.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("pure chi");
    Description("Forty lessons in spell-point chi: precision and healing "
        "foundations, circulation, resonance, and unified mastery. Knowledge "
        "opens branches and modifies abilities across levels one through "
        "seventy; sustained channels reserve the existing spell-point pool.");
    Source("monk");
    deferResearchLoading();


    addResearchElement("/guilds/monk/pure-chi/root.c");
    TreeRoot("/guilds/monk/pure-chi/root.c");

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
