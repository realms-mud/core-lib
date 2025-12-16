//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/eye-contact.c");
    addResearchElement("/guilds/oneiromancer/projection-methods/whispered-word.c");

    addChild("/guilds/oneiromancer/projection-methods/eye-contact.c",
        "/guilds/oneiromancer/projection-methods/methods-root.c");
    addChild("/guilds/oneiromancer/projection-methods/whispered-word.c",
        "/guilds/oneiromancer/projection-methods/methods-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/focused-intent.c");

    addChild("/guilds/oneiromancer/projection-methods/focused-intent.c",
        "/guilds/oneiromancer/projection-methods/methods-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/gestured-sending.c");

    addChild("/guilds/oneiromancer/projection-methods/gestured-sending.c",
        "/guilds/oneiromancer/projection-methods/eye-contact.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/enhanced-projection.c");

    addChild("/guilds/oneiromancer/projection-methods/enhanced-projection.c",
        "/guilds/oneiromancer/projection-methods/eye-contact.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/subtle-approach.c");

    addChild("/guilds/oneiromancer/projection-methods/subtle-approach.c",
        "/guilds/oneiromancer/projection-methods/methods-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/empathic-bridge.c");

    addChild("/guilds/oneiromancer/projection-methods/empathic-bridge.c",
        "/guilds/oneiromancer/projection-methods/whispered-word.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/penetrating-thought.c");

    addChild("/guilds/oneiromancer/projection-methods/penetrating-thought.c",
        "/guilds/oneiromancer/projection-methods/focused-intent.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/memory-anchor.c");

    addChild("/guilds/oneiromancer/projection-methods/memory-anchor.c",
        "/guilds/oneiromancer/projection-methods/gestured-sending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/refined-conduit.c");

    addChild("/guilds/oneiromancer/projection-methods/refined-conduit.c",
        "/guilds/oneiromancer/projection-methods/enhanced-projection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/misdirection.c");

    addChild("/guilds/oneiromancer/projection-methods/misdirection.c",
        "/guilds/oneiromancer/projection-methods/subtle-approach.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/dream-thread.c");

    addChild("/guilds/oneiromancer/projection-methods/dream-thread.c",
        "/guilds/oneiromancer/projection-methods/empathic-bridge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/amplified-sending.c");

    addChild("/guilds/oneiromancer/projection-methods/amplified-sending.c",
        "/guilds/oneiromancer/projection-methods/penetrating-thought.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/psychic-touch.c");

    addChild("/guilds/oneiromancer/projection-methods/psychic-touch.c",
        "/guilds/oneiromancer/projection-methods/memory-anchor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/amplified-conduit.c");

    addChild("/guilds/oneiromancer/projection-methods/amplified-conduit.c",
        "/guilds/oneiromancer/projection-methods/refined-conduit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/rapid-sending.c");

    addChild("/guilds/oneiromancer/projection-methods/rapid-sending.c",
        "/guilds/oneiromancer/projection-methods/misdirection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/thoughtform-projection.c");

    addChild("/guilds/oneiromancer/projection-methods/thoughtform-projection.c",
        "/guilds/oneiromancer/projection-methods/dream-thread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/resonant-frequency.c");

    addChild("/guilds/oneiromancer/projection-methods/resonant-frequency.c",
        "/guilds/oneiromancer/projection-methods/amplified-sending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/subliminal-insertion.c");

    addChild("/guilds/oneiromancer/projection-methods/subliminal-insertion.c",
        "/guilds/oneiromancer/projection-methods/psychic-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/perfected-conduit.c");

    addChild("/guilds/oneiromancer/projection-methods/perfected-conduit.c",
        "/guilds/oneiromancer/projection-methods/amplified-conduit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/efficient-channeling.c");

    addChild("/guilds/oneiromancer/projection-methods/efficient-channeling.c",
        "/guilds/oneiromancer/projection-methods/rapid-sending.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/overwhelming-presence.c");

    addChild("/guilds/oneiromancer/projection-methods/overwhelming-presence.c",
        "/guilds/oneiromancer/projection-methods/resonant-frequency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/collective-resonance.c");

    addChild("/guilds/oneiromancer/projection-methods/collective-resonance.c",
        "/guilds/oneiromancer/projection-methods/thoughtform-projection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/lingering-trauma.c");

    addChild("/guilds/oneiromancer/projection-methods/lingering-trauma.c",
        "/guilds/oneiromancer/projection-methods/efficient-channeling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/transcendent-conduit.c");

    addChild("/guilds/oneiromancer/projection-methods/transcendent-conduit.c",
        "/guilds/oneiromancer/projection-methods/perfected-conduit.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/perfect-clarity.c");

    addChild("/guilds/oneiromancer/projection-methods/perfect-clarity.c",
        "/guilds/oneiromancer/projection-methods/overwhelming-presence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/cascading-horror.c");

    addChild("/guilds/oneiromancer/projection-methods/cascading-horror.c",
        "/guilds/oneiromancer/projection-methods/lingering-trauma.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/absolute-conviction.c");

    addChild("/guilds/oneiromancer/projection-methods/absolute-conviction.c",
        "/guilds/oneiromancer/projection-methods/perfect-clarity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/defensive-feedback.c");

    addChild("/guilds/oneiromancer/projection-methods/defensive-feedback.c",
        "/guilds/oneiromancer/projection-methods/cascading-horror.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/projection-methods/nightmare-echo.c");

    addChild("/guilds/oneiromancer/projection-methods/nightmare-echo.c",
        "/guilds/oneiromancer/projection-methods/defensive-feedback.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Projection Methods");
    Description("This research tree provides knowledge of various methods "
        "for projecting psionic attacks. These techniques modify how attacks "
        "are delivered and can be combined for enhanced tactical options.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/projection-methods/methods-root.c");
    TreeRoot("/guilds/oneiromancer/projection-methods/methods-root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SixthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FourteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentySecondLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtiethLevel();
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortiethLevel();
    FortyThirdLevel();
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    SixtyFirstLevel();
}
